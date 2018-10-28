// 类模板的声明，关键字 class 也可以更换成 typename
template<class T> class LinkedListStack
{
public:
    LinkedListStack();
    ~LinkedListStack();

    void push(const T & data);     //入栈
    T peek();                    //返回栈顶元素，即出栈，不删除栈顶元素
    T pop();                      //出栈，删除栈顶元素
    int size() const;             //返回栈的大小
private:
    int count;                   //存放栈的大小，因为是单链表所以这里不规定栈的最大可承载量
    struct LinkedNode
    {
        T data;
        LinkedNode * next;
    };
    LinkedNode * head;    // 单链表的头指针，不带头节点
};
