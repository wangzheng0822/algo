import scala.util.control.Breaks._
object Sorts {
  def main(args: Array[String]): Unit ={
    println(bubbleSort(Array(0, 1, 2, 3, 4, 5, 6, 7)).mkString(", "))
  }

  def bubbleSort(arr: Array[Int]): Array[Int] = {
    val l = arr.length
    breakable {
      for(i <- (l-1) to (1, -1)){
        var flag = false
        for(j <- 0 until i){
          if(arr(j) < arr(j+1)){
            val tmp = arr(j)
            arr(j) = arr(j+1)
            arr(j+1) = tmp
            flag = true
          }
        }
        if(!flag){
          break
        }
      }
    }
    arr
  }
}
