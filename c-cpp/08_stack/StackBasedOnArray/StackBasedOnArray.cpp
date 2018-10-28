/**
 * 1）顺序栈的操作：入栈和出栈；
 * 2）采用模板的方法实现存储任意类型的数据
 * 3）采用数组的栈，支持动态扩容，每次扩容1.5 倍，初始栈的大小是 10 。
 * 
 * Author：caozx
 * time ；2018年10月11日
 */

#include <iostream>
#include "StackBasedOnArray.h"
using namespace std;

//构造函数，创建栈
//类模板成员函数的写法  template<class T> 返回值类型 类名<T>::成员函数名(参数列表){}
template<class T> ArrayStack<T>::ArrayStack()   
{   
    this -> count = 10;
    this -> flag = 0;
    this -> array = new T[this -> count];
    if (! this -> array){
        cout << "array malloc memory failure" << endl;
    }
}


//有参构造函数，创建栈
template<class T> ArrayStack<T>::ArrayStack(int count)   
{   
    this -> count = count;
    this -> flag = 0;
    this -> array = new T[this -> count];
    if (! this -> array){
        cout << "array malloc memory failure" << endl;
    }
}

//析构函数，销毁栈
template <class T> ArrayStack<T>::~ArrayStack(){
    this -> count = 0;
    this -> flag = 0;
    if(this -> array){
        delete [] this -> array;
        this -> array = NULL;
    }
    
} 

// 入栈
template<class T> void ArrayStack<T>::push(T data){
    if(this -> flag == this -> count){
        cout << "The stack is full , so need to enlarge 1.5x! "<< endl;
        this -> count = int (1.5 * this -> count);
        T * temp = new T [this -> count];
        for(int i = 0; i < this -> flag ; i++){
            temp[i] = this -> array[i];
            //cout << temp[i] <<endl;
        }
        delete [] this -> array;       //释放原来的空间
        temp[this -> flag] = data;
        this -> flag ++;
        this -> array = temp;
    }
    else{
        this -> array [this -> flag] = data;
        this -> flag ++ ;
    }
}

//出栈，并删除栈顶元素
template<class T> T ArrayStack<T>::pop(){
    this -> flag --;
    T temp = this -> array[this -> flag];
    return temp;
}

//出栈，不删除栈顶元素
template<class T> T ArrayStack<T>::peek(){
    T temp = this -> array[this -> flag - 1];
    return temp;
}

template<class T> int ArrayStack<T>::stackSize(){
    return this -> flag;
}

template<class T> int ArrayStack<T>::stackMaxSize(){
    return this -> count;
}

int main(int argc, char const *argv[])
{
    cout << " === test begin ===" << endl;
    ArrayStack <int> arrstack(12);
    arrstack.push(10);
    arrstack.push(20);
    arrstack.push(30);
    arrstack.push(40);
    arrstack.push(50);
    arrstack.push(60);
    arrstack.push(70);
    arrstack.push(80);
    arrstack.push(90);
    arrstack.push(100);
    arrstack.push(110);
    arrstack.push(120);
    arrstack.push(130);
    arrstack.push(140);
    arrstack.push(150);

    cout << "peek , not delete " << arrstack.peek() << endl;
    cout << "pop , delete " << arrstack.pop()<<endl;
    
    arrstack.push(210);
    arrstack.push(220);

    cout << "peek , not delete " << arrstack.peek() << endl;
    cout << "pop , delete " << arrstack.pop()<<endl;    
   
    system("pause");
    return 0;
}
