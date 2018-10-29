/**
 * 1）链式栈的操作：入栈，出栈以及返回栈的大小；
 * 2）采用模板的方法实现存储任意类型的数据
 * 3）采用单链表实现栈
 * 4）pop和peek 出栈的返回值稍微有点问题，当栈为空的时候，返回null，cpp默认返回的是0。
 *    * 改进方法就是不用函数的返回值返回栈顶元素，而是采用参数列表的形式返回，这样稍微有点麻烦
 *    * 或者就是在使用的时候先调用size函数判断以下
 * Author：caozx
 * time ；2018年10月11日
 */

#include <iostream>
#include "StackBasedOnLinkedList.h"
using namespace std;

template<class T> LinkedListStack<T>::LinkedListStack()
{
    this -> count = 0;
    this -> head = new LinkedNode;
    this -> head -> next = NULL;
}

template<class T> LinkedListStack<T>::~LinkedListStack()
{
    LinkedNode * ptr, * temp;
    ptr = head;
    while(ptr -> next != NULL){
        temp = ptr -> next;
        ptr -> next = temp -> next;
        delete temp;   
    }
    delete head ; //删除头节点
    this -> head = NULL;
    this -> count = 0;
}

// 入栈
template<class T> void LinkedListStack<T>::push(const T & data)
{
    LinkedNode * insertPtr = new LinkedNode;
    insertPtr -> data = data;
    insertPtr -> next = this -> head -> next;
    head -> next = insertPtr;
    this -> count ++;
    cout << "push data : " << this -> head -> next -> data << endl;  
}

//返回栈顶元素，即出栈，不删除栈顶元素
template<class T> T LinkedListStack<T>::peek()
{
    if(this -> count == 0 || this -> head -> next == NULL){
        cout << " stack is empty, peek fail"<< endl;
        return NULL;
    }
    else{
        return this -> head -> next -> data;
    }
}

//出栈，删除栈顶元素
template<class T> T LinkedListStack<T>::pop()
{
    if(this -> count == 0 || this -> head -> next == NULL){
        cout << " stack is empty, pop fail"<< endl;
        return NULL;
    }
    else{
        LinkedNode * temp = this -> head -> next;
        this -> head -> next = temp -> next;
        T data = temp -> data;
        delete temp;
        this -> count --;
        return  data;
    }

}

//返回栈的大小
template<class T> int LinkedListStack<T>::size() const
{
    return this -> count;
}             

int main(int argc, char const *argv[])
{
    cout << " === StackBasedOnLinkedList test begin ===" << endl;
    LinkedListStack <float> stack;
    cout << "size==="<<stack.size()<<endl;
    stack.push(10.1);
    stack.push(20.2);
    stack.push(30.);
    stack.push(40.4);
    stack.push(50.5);
    stack.push(60.6);
    cout << "size==="<<stack.size()<<endl;
    cout << "stack peek  " << stack.peek() << endl;
    cout << "stack pop  " << stack.pop() << endl;
    cout << "size==="<<stack.size()<<endl;
    cout << "stack pop  " << stack.pop() << endl;
    cout << "stack pop  " << stack.pop() << endl;
    cout << "stack pop  " << stack.pop() << endl;
    cout << "stack pop  " << stack.pop() << endl;
    cout << "stack pop  " << stack.pop() << endl;
    cout << "size==="<<stack.size()<<endl;
    cout << "stack pop  " << stack.pop() << endl;
    cout << "stack peek  " << stack.peek() << endl;
    stack.push(110.1);
    stack.push(120.2);
    stack.push(130.3);
    stack.push(140.4);
    stack.push(150.5);
    stack.push(160.6);
    cout << "size==="<<stack.size()<<endl;
    cout << "stack peek  " << stack.peek() << endl;
    cout << "stack pop  " << stack.pop() << endl;
    cout << "stack pop  " << stack.pop() << endl;
    cout << "stack pop  " << stack.pop() << endl;
    cout << "stack peek  " << stack.peek() << endl;   //peek
    cout << "stack pop  " << stack.pop() << endl;
    cout << "stack pop  " << stack.pop() << endl;
    cout << "stack pop  " << stack.pop() << endl;
    cout << "size==="<<stack.size()<<endl;
    cout << "stack peek  " << stack.peek() << endl;   //peek
    cout << "stack pop  " << stack.pop() << endl;    
    system("pause");
    return 0;
}
