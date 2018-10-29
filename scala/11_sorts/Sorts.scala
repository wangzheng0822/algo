import scala.util.control.Breaks._

/**
  * 冒泡排序、插入排序、选择排序
  *
  * Author: yangchuz
  */
object Sorts {
  def main(args: Array[String]): Unit ={
//    println(bubbleSort(Array(0, 6, 2, 3, 8, 5, 6, 7), 8).mkString(", "))
//    println(insertSort(Array(0, 6, 2, 3, 8, 5, 6, 7), 8).mkString(", "))
    println(selectionSort(Array(0, 6, 2, 3, 8, 5, 6, 7), 8).mkString(", "))
  }

  def bubbleSort(arr: Array[Int], n:Int): Array[Int] = {
    val n = arr.length
    breakable {
      for(i <- (n-1) to (1, -1)){
        var flag = false
        for(j <- 0 until i){
          if(arr(j) > arr(j+1)){
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

  def insertSort(arr: Array[Int], n:Int): Array[Int] = {
    for(i <- 1 until n){
      val tmp = arr(i)
      breakable{
        for(j <- (i-1) to (0, -1)){
          if(tmp < arr(j)){
            arr(j+1) = arr(j)
          }else{
            arr(j+1) = tmp
            break
          }
        }
      }
    }
    arr
  }

  def selectionSort(arr: Array[Int], n:Int): Array[Int] = {
    for(i <- 0 until n){
      var min = i
      for(j <- (i + 1) until n){
        if(arr(j) < arr(min)){
          min = j
        }
      }

      val tmp = arr(i)
      arr(i) = arr(min)
      arr(min) = tmp
    }
    arr
  }
}
