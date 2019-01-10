package ch29_heap_solutions

import java.io.{BufferedWriter, File, FileWriter}

import org.scalatest.{FlatSpec, Matchers}

import scala.io.Source
import scala.util.Random

class FileMergerTest extends FlatSpec with Matchers {

  behavior of "FileMergerTest"

  it should "mergeFiles" in {
    val num = 10
    val contentCount = 10
    val random = Random.alphanumeric
    val files = new Array[File](num)
    for (i <- Range(0, num)) {
      val file = File.createTempFile(i + "-small", ".txt")
      files(i) = file
      val writer = new BufferedWriter(new FileWriter(file))
      val content = random.take((i + 1) * contentCount).toArray.slice(i * contentCount, (i + 1) * contentCount)

      writer.write(content.sorted)
      writer.flush()
      writer.close()
    }
    println("small files below")
    files.foreach(printFile)

    val mergedFile = FileMerger.mergeFiles(files.toList)

    val raw = Source.fromFile(mergedFile).toArray
    raw should equal(raw.sorted)
    raw.length should equal(num * contentCount)

    println("")
    println("merged file below")
    printFile(mergedFile)

    //clean up
    files.foreach(_.delete())
    mergedFile.delete()

  }

  def printFile(file: File): Unit = {
    val source = Source.fromFile(file)
    source.getLines().foreach(println)
  }

}
