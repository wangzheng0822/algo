package ch29_heap_solutions

import java.io.{BufferedWriter, File, FileWriter}

import scala.collection.mutable
import scala.io.Source
import scala.util.control.Breaks._

object FileMerger {

  /**
    * each given file has sorted String as content, we need to merge them together
    *
    * @param smallFiles - small files with sorted content
    * @return merged file
    */
  def mergeFiles(smallFiles: List[File]): File = {
    //init output file
    val output = File.createTempFile("merged-file", ".txt")
    val writer = new BufferedWriter(new FileWriter(output))
    //init small top heap
    val priorityQueue = new mutable.PriorityQueue[(Char, Source)]()(Ordering.by((_: (Char, Source))._1).reverse)
    val sources = smallFiles.toArray.map(smallFile => Source.fromFile(smallFile))
    //init fill the priority queue from each file
    sources.foreach(source => priorityQueue.enqueue((source.next(), source)))

    breakable {
      while (true) {
        val next = priorityQueue.dequeue()
        val output: Char = next._1
        val source = next._2
        writer.append(output)
        if (source.hasNext) {
          priorityQueue.enqueue((source.next(), source))
        }
        //determine the end of merge
        if (sources.forall(!_.hasNext) && priorityQueue.isEmpty) {
          break
        }
      }
    }

    writer.close()
    output
  }
}
