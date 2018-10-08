typedef int DataType;

//定义
class SNode
{
public:
    DataType data;
    SNode * next;
};

class SList 
{
public:
    SList();
    SList(int MaxSize);
    ~SList();
    void intsertElemAtBegin(DataType x);      //头部插入节点
    bool findElem(DataType x);              //查找x，存在则返回1，不存在则返回0
    void deleteElemAtEnd();             //删除尾节点
    bool deleteElem(DataType x);    //删除指定节点，如果存在则删除，返回1，如果不存在，则删除失败返回0
    bool isEmpty();                  // 查看链表是否为空，1表示不为空，0表示为空
    bool isFull();                   // 查看链表是否满，1表示不满，0表示满
    void printAll();             

    void * findElemOptim(DataType x);     //针对此应用的优化，查找,返回指定元素的前一个节点的指针
    void deleteElemOptim(void * snode);     //针对此应用的优化，删除
private:
    int MaxSize;       // 链表可以存放最大的数据
    int length;             // 链表的长度
    SNode * head;          // 指向头节点

};


/**
 * 1）单链表的插入，删除，查找操作；
 * 2）链表中存储的是 int 类型
 * 
 * Author：caozx
 */
#include<iostream>
using namespace std;

// 初始化单链表
SList::SList(){
    head = new SNode;     //申请头节点
    head -> next = NULL;
    this -> MaxSize = 10;
    this -> length = 0;
}
SList::SList(int MaxSize){
    head = new SNode;     //申请头节点
    head -> next = NULL;
    this -> MaxSize = MaxSize;
    this -> length = 0;
}

// 销毁单链表，要把开辟的空间都释放，然后再销毁。
SList::~SList(){
    SNode * ptr, * temp;
    ptr = head;
    while(ptr -> next != NULL){
        temp = ptr -> next;
        ptr -> next = ptr -> next -> next;
        delete temp;   
    }
    delete head ; //删除头节点
    this -> head = NULL;
    this -> length = 0;
}

//链表头部插入节点
void SList::intsertElemAtBegin(DataType x){
    SNode * ptr = new SNode;
    ptr -> data = x;

    ptr -> next = head ->next;
    head -> next = ptr;

    this -> length ++;
}

//查找x，存在则返回1，不存在则返回0

bool SList::findElem(DataType x)
{
    SNode * ptr;
    ptr = head;
    while(ptr -> next != NULL){
        if(ptr -> next ->data == x){
            return 1;
        }
        ptr = ptr -> next;
    }
    return 0;
}

// 删除尾结点
void SList::deleteElemAtEnd(){
    SNode * ptr , * temp;
    ptr = head;
    while(ptr -> next != NULL && ptr -> next -> next != NULL){   //倒数第二个节点
        ptr = ptr -> next;
    }
    temp = ptr -> next;
    ptr -> next = temp -> next;
    this -> length --;
    delete temp;
}

//删除指定节点，
//如果存在则删除，返回1，表示存在且删除成功；
//如果不存在则不删除，返回0，表示不存在该元素，不需要删除，也即删除失败
bool SList::deleteElem(DataType x)
{
    SNode * ptr, * temp;
    ptr = head;
    while(ptr -> next != NULL){
        if(ptr -> next ->data == x){
            temp = ptr -> next;
            ptr -> next = temp -> next;
            delete temp;
            this -> length --;
            return 1;
        }
        ptr = ptr -> next;
    }
    return 0;
}

// 查看链表是否为空，1表示不为空，0表示为空
bool SList::isEmpty()
{
    if(this -> length == 0){  //空
        return 0;
    }
    else{
        return 1;
    }
}

// 查看链表是否满，1表示不满，0表示满
bool SList::isFull()
{   
    if(this -> length == this -> MaxSize){  //满
        return 0;
    }
    else{
        return 1;
    }
}

// 打印
void SList::printAll()
{
    SNode * ptr;
    ptr = head;
    while(ptr -> next != NULL){
        ptr = ptr -> next;
        cout << ptr-> data <<"   ";
    }
    cout << endl;
}     

//针对此应用的优化，查找,
//若存在则返回指定元素的前一个节点的指针
//若不存在，则返回NULL

void * SList::findElemOptim(DataType x)
{
    SNode * ptr;
    ptr = head;
    while(ptr -> next != NULL){
        if(ptr -> next ->data == x){
            return (void *)ptr;
        }
        ptr = ptr -> next;
    }
    return NULL;
}

//针对此应用的优化，删除

void SList::deleteElemOptim(void * snode)
{
     SNode * ptr, * temp;
     ptr = (SNode *)snode;
     temp =  ptr -> next;
     ptr -> next = temp -> next;
     this -> length --;
     delete temp;
}
int main(int argc, char const *argv[])
{
    cout << "test "<< endl;   
    SList slist(10);     //缓存最大10个。
    int num = 0;
    while(1)
    {
        cout << "please enter a number,99999== exit" << endl;
        cin >> num;
        if(num == 99999)
            break;
        /* 未优化
        if(slist.findElem(num)){    //存在
            slist.deleteElem(num);     //把原来的位置删除
            slist.intsertElemAtBegin(num); //在链表头插入
        }
        */
       //优化
       SNode * prePtr = (SNode *)slist.findElemOptim(num);
       if(prePtr != NULL){    //存在
            slist.deleteElemOptim(prePtr);     //把原来的位置删除
            slist.intsertElemAtBegin(num); //在链表头插入
        }
        else{      //不存在
            if(slist.isFull()){    //不满
                slist.intsertElemAtBegin(num);
            }
            else{                   //满
                slist.deleteElemAtEnd();
                slist.intsertElemAtBegin(num);
            }
        }
        slist.printAll();
    }
    return 0;
    system("pause");
}
