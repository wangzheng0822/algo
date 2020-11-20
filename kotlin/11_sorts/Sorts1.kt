package com.will.myapplication

import java.util.*
import kotlin.math.abs

/**
 * 插入排序（插入位置，从头至尾搜索）
 * @Author： will
 */
object Sorts1 {
    @JvmStatic
    fun main(args: Array<String>) {
        val data = intArrayOf(4, 6, 5, 3, 7, 1, 2)
        fromStartToEnd(data.copyOf(data.size))
        println(data.contentToString())
    }

    /**
     * 查询插入位置时， 从头至尾搜索
     * @param data
     */
    private fun fromStartToEnd(data: IntArray) {
        for (i in 1 until data.size) {
            val value = data[i]
            val tmp = IntArray(2)
            var change = i
            for (j in 0 until i) {
                if (value >= data[j]) {
                    continue
                }
                val index = j % 2
                if (change == i) {
                    tmp[abs(index - 1)] = data[j]
                    change = j
                }
                tmp[index] = data[j + 1]
                if (0 == index) {
                    data[j + 1] = tmp[index + 1]
                } else {
                    data[j + 1] = tmp[index - 1]
                }
            }
            data[change] = value
        }
    }
}