# 1.数组的插入、删除、按照下标随机访问操作；
# 2.数组中的数据类型是Int
#
# Author:Lee

class Array():

    def __init__(self):
        '''数组类初始化方法.'''
        self.__data = []  # 数据存储List

    def find(self, index):
        '''数组的查找方法.

        参数：
            index:将要查找的数据的下标

        返回：
            如果查找成功，则返回找到的数据
            如果查找失败，则返回False
        '''
        if index > len(self.__data) or index < 0:
            return False
        else:
            return self.__data[index]

    def delete(self, index):
        '''数组的删除方法.

        参数：
            index:将要删除的数据的下标

        返回：
            如果删除成功，则返回True
            如果删除失败，则返回False
        '''
        if index > len(self.__data) or index < 0:
            return False
        else:
            self.__data.pop(index)
            return True

    def insert(self, index, value):
        '''数组插入数据操作.

        参数：
            index:将要插入的下标
            value：将要插入的数据

        返回：
            如果插入成功，则返回True
            如果插入失败，则返回False
        '''
        if index > len(self.__data) or index < 0:
            return False
        else:
            self.__data.insert(index, value)
            return True

    def insertToTail(self, value):
        '''直接在数组尾部插入数据.

        参数：
            value:将要插入的数据
        '''
        self.__data.append(value)

    def printAll(self):
        '''打印当前数组所有数据'''
        print(self.__data)
