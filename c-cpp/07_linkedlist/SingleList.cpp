#include <iostream>
#include <string>
#include <functional>
using namespace std;


class CElement;
/***
 * @brief 单链表容器
*/
class CSingleList
{
public:
    CSingleList();
    ~CSingleList();

    /**
     * @brief 插入..链表末尾插入
     * @return 成功返回非空指针,否则失败
    */
    CElement* Insert(void* lpData, int iDataSize);
    /**
     * @brief 插入..链表指定位置插入
     * @return 成功返回非空指针,否则失败
    */
    CElement* Insert(CElement* lpElement, void* lpData, int iDataSize);
    /**
     * @brief 删除
    */
    void Delete(CElement*);

    /**
     * @brief 链首
    */
    CElement* Begin();
    /**
     * @brief 下一个元素
    */
    CElement* Next();
    /***
     * @brief 链尾
    */
    CElement* End();

    /**
     * @brief 是否是空链表
     * @return 空返回TRUE，否则返回FALSE
    */
    bool Empty();

    /**
     * @brief 反转
    */
    void Reverse();

    /**
     * @brief 检测环
     * @return 返回TRUE时表示链表存在环,否则不存在环.
    */
    bool CheckCircle();

    /**
     * @brief 合并2个有序的链表
    */
    void Merge(CSingleList& lst, std::function<int(void* t1, void* t2)>);

    /**
     * @brief 删除倒数第K个结点
    */
    void DeleteLastKth(int k);
    /**
     * @brief 求中间节点
    */
    CElement* Center();
private:
    void Insert(CElement* lpNewElement, CElement* lpCurElement, bool bBack = true);
    void Insert(CElement* lpNewElement);
    CElement* Tail();

	CSingleList(CSingleList const & rhs);
	CSingleList& operator= (CSingleList const& rhs);
private:
    /**头结点*/
    CElement* m_lpHead;
    /**哨兵*/
    CElement* m_lpSentinel;
    /**空结点，用于End()返回 */
    CElement* m_lpNull;
    /**当前结点. 枚举时使用. */
    CElement* m_lpCur;
};

/***
 * @brief 单链表结点元素.
*/
class CElement
{
    friend class CSingleList;
protected:
    CElement();
    ~CElement();
public:
    /***
     * @brief 获取数据指针
    */
    void* GetDataPtr();
protected:
    /**下一个结点*/
    CElement* m_lpNext;
    void* m_lpData;
};


void CreateList(CSingleList& lst)
{
    //循环插入元素到链表尾
    for(int i=1; i<10;i++)
    {
        int* p = new int();
        *p = i;
        lst.Insert(p, 4);
    }
}
void PrintList(CSingleList& lst)
{
    CElement* lpElement = lst.Begin();
    while(lpElement != lst.End())
    {
        std::cout<<*((int*)lpElement->GetDataPtr())<<std::endl;
        lpElement = lst.Next();
    }
}

int main()
{
    {
        /// 链表的基本操作，插入/枚举/删除
        CSingleList lst;
        CElement* lpElement = NULL;
        CreateList(lst);

        std::cout<<"枚举链表当前的元素"<<std::endl;
        PrintList(lst);

        std::cout<<"查找指定元素,并在指定元素后面插入新元素"<<std::endl;
        lpElement = lst.Begin();
        while(lpElement != lst.End())
        {
            if(*((int*)lpElement->GetDataPtr()) == 5)
            {
                int* p = new int();
                *p = 55;
                lst.Insert(lpElement,p, 4);
                break;
            }else{
                lpElement = lst.Next();
            }
        }

        std::cout<<"枚举链表当前的元素"<<std::endl;
        PrintList(lst);

        std::cout<<"查找指定元素(数字是7的元素),并删除指定元素"<<std::endl;
        lpElement = lst.Begin();
        while(lpElement != lst.End())
        {
            if(*((int*)lpElement->GetDataPtr()) == 7)
            {
                lst.Delete(lpElement);
                break;
            }else{
                lpElement = lst.Next();
            }
        }
        std::cout<<"枚举链表当前的元素"<<std::endl;
        PrintList(lst);
    }

    std::cout<<"--------------------------"<<std::endl;
    {
        /// 链表的反转
        CSingleList lst;
        CElement* lpElement = NULL;
        CreateList(lst);
        std::cout<<"反转"<<std::endl;
        lst.Reverse();
        PrintList(lst);
    }

    std::cout<<"--------------------------"<<std::endl;
    {
        /// 检测环
        CSingleList lst;
        CElement* lpElement = NULL;
        CreateList(lst);
        std::cout<<"检测环"<<std::endl;
        bool bRet = lst.CheckCircle();
        if(bRet){
            std::cout<<"存在环."<<std::endl;
        }else{
            std::cout<<"不存在环."<<std::endl;
        }
    }

    std::cout<<"--------------------------"<<std::endl;
    {
        /// 有序链表合并
        CSingleList lst,lst2;
        CElement* lpElement = NULL;
        for(int i=1; i<30;i++)
        {
            int* p = new int();
            *p = i;
            if(i%4){
                lst2.Insert(p, 4);
            }else{
                lst.Insert(p, 4);
            }
        }
        std::cout<<"枚举链表当前的元素"<<std::endl;
        PrintList(lst);
        std::cout<<"......"<<std::endl;
        PrintList(lst2);
        lst.Merge(lst2,[](void* lpT1, void* lpT2) -> int{
            if(*((int*)lpT1) < *((int*)lpT2)){
                return -1;
            }else if(*((int*)lpT1) == *((int*)lpT2)){
                return 0;
            }else if(*((int*)lpT1) > *((int*)lpT2)){
                return 1;
            }
            return 0;
        });
        std::cout<<"合并之后，打印当前链表."<<std::endl;
        PrintList(lst);
    }
    std::cout<<"--------------------------"<<std::endl;
    {
        /// 删除倒数第K个结点,并查看中间节点
        CSingleList lst;
        CreateList(lst);
        std::cout<<"删除倒数第0个结点"<<std::endl;
        lst.DeleteLastKth(0);
        PrintList(lst);
        CElement* lpCenter = lst.Center();
        std::cout<<"中间节点:"<<*((int*)lpCenter->GetDataPtr())<<std::endl;

        std::cout<<"删除倒数第1个结点"<<std::endl;
        lst.DeleteLastKth(1);
        PrintList(lst);
        lpCenter = lst.Center();
        std::cout<<"中间节点:"<<*((int*)lpCenter->GetDataPtr())<<std::endl;

        std::cout<<"删除倒数第3个结点"<<std::endl;
        lst.DeleteLastKth(3);
        PrintList(lst);
        lpCenter = lst.Center();
        std::cout<<"中间节点:"<<*((int*)lpCenter->GetDataPtr())<<std::endl;
    }
    std::cin.ignore();

    return 0;
}

CSingleList::CSingleList()
{
    m_lpHead = new CElement();
    m_lpSentinel = new CElement();
    m_lpNull = new CElement();
    m_lpCur = NULL;
    m_lpHead->m_lpNext = m_lpSentinel;
}
CSingleList::~CSingleList()
{
    if(NULL != m_lpSentinel)
    {
        delete m_lpSentinel;
        m_lpSentinel = NULL;
    }
    if(NULL != m_lpNull)
    {
        delete m_lpNull;
        m_lpNull = NULL;
    }
    if(NULL != m_lpHead)
    {
        delete m_lpHead;
        m_lpHead = NULL;
    }
}
CElement* CSingleList::Insert(void* lpData, int iDataSize)
{
    CElement* lpNewElement = new CElement();
    if(NULL == lpNewElement)
    {
        return NULL;
    }
    lpNewElement->m_lpData = lpData;
    Insert(lpNewElement, Tail());
    return lpNewElement;
}
CElement* CSingleList::Insert(CElement* lpElement, void* lpData, int iDataSize)
{
    if((NULL == lpElement) || (End() == lpElement))
    {
        return NULL;
    }
    CElement* lpNewElement = new CElement();
    if(NULL == lpNewElement)
    {
        return NULL;
    }
    lpNewElement->m_lpData = lpData;
    Insert(lpNewElement, lpElement);
    return lpNewElement;
}
void CSingleList::Insert(CElement* lpNewElement, CElement* lpCurElement, bool bBack /*= true*/)
{
    if(bBack){//插入到指定元素的后面
        lpNewElement->m_lpNext = lpCurElement->m_lpNext;
        lpCurElement->m_lpNext = lpNewElement;
    }else{//插入到指定元素的前面
        CElement* lpIter = m_lpSentinel;
        while(NULL != lpIter)
        {
            if(lpIter->m_lpNext == lpCurElement)
            {
                lpNewElement->m_lpNext = lpIter->m_lpNext;
                lpIter->m_lpNext = lpNewElement;
                break;
            }else{
                lpIter = lpIter->m_lpNext;
            }
        }
    }
}

void CSingleList::Delete(CElement* lpElement)
{
    if((NULL == lpElement) || (End() == lpElement))
    {
        return;
    }
    CElement* lpCurElement = m_lpHead->m_lpNext;
    while(NULL != lpCurElement->m_lpNext)
    {
        if(lpCurElement->m_lpNext == lpElement)
        {
            lpCurElement->m_lpNext = lpCurElement->m_lpNext->m_lpNext;
            break;
        }else{
            lpCurElement = lpCurElement->m_lpNext;
        }
    }
}

CElement* CSingleList::Tail()
{
    CElement* lpCurElement = m_lpHead->m_lpNext;
    while(NULL != lpCurElement->m_lpNext)
    {
        lpCurElement = lpCurElement->m_lpNext;
    }
    return lpCurElement;
}

CElement* CSingleList::Begin()
{
    m_lpCur = NULL;
    if(NULL == m_lpHead->m_lpNext->m_lpNext)
    {
        m_lpCur = End();
    }else{
        m_lpCur = m_lpHead->m_lpNext->m_lpNext;
    }
    return m_lpCur;
}

CElement* CSingleList::Next()
{
    if((NULL == m_lpCur) || (End() == m_lpCur))
    {
        return m_lpCur;
    }
    m_lpCur = m_lpCur->m_lpNext;
    if(NULL == m_lpCur)
    {
        m_lpCur = End();
    }
    return m_lpCur;
}

CElement* CSingleList::End()
{
    return m_lpNull;
}

bool CSingleList::Empty()
{
    return Begin() == End();
}

void CSingleList::Reverse()
{
    if(Empty())
    {
        return;
    }
    CElement* lpPre = NULL;
    CElement* lpTmp = NULL;
    CElement* lpCurElement = m_lpSentinel->m_lpNext;
    while(1)
    {
        lpTmp = lpCurElement->m_lpNext;
        lpCurElement->m_lpNext = lpPre;
        if(NULL == lpTmp)
        {
            break;
        }
        lpPre = lpCurElement;
        lpCurElement = lpTmp;
    }
    m_lpSentinel->m_lpNext = lpCurElement;
}

bool CSingleList::CheckCircle()
{
    if(Empty())
    {
        return false;
    }
    CElement* lpFast = m_lpSentinel->m_lpNext;
    CElement* lpSlow = m_lpSentinel->m_lpNext;
    while ((NULL != lpFast) && (NULL != lpFast->m_lpNext)) 
    {
        lpFast = lpFast->m_lpNext->m_lpNext;
        lpSlow = lpSlow->m_lpNext;
        if (lpFast == lpSlow)
        {
            return true;
        }
    }
    return false;
}

/**
 * 合并的2个链表必须是有序的
*/
void CSingleList::Merge(CSingleList& lst, std::function<int(void* t1, void* t2)> fnCompare)
{
    CElement* lpL1 = Begin();
    CElement* lpL2 = lst.Begin();

    if(!fnCompare)
    {
        return;
    }
    int iRet = 0;
    while((lpL2 != lst.End()))
    {
        if(lpL1 != End())
        {
            /**
             * 查找需要插入的正确位置
             * 
             * 链表1,链表2; 链表1 <- 链表2, 链表2被合并到链表1中
             * 
             * 如果链表1的元素小于链表2中的元素，则循环查找链表1中大于链表2中的当前元素的元素
             * 如果在链表1中找到满足上面条件的的元素位置[A]时，则把链表2中的当前元素插入到元素位置[A]的前面;
             * 如果在链表1中不存在这个位置则在链表1的末位插入元素
            */
            iRet = fnCompare(lpL1->GetDataPtr(), lpL2->GetDataPtr());
            if(iRet < 0){
                lpL1 = Next();
                while(lpL1 != End()){
                    iRet = fnCompare(lpL1->GetDataPtr(), lpL2->GetDataPtr());
                    if(iRet > 0){
                        break;
                    }
                    lpL1 = Next();
                }
            }
        }else{
            iRet = -1;
        }
        CElement* lpNewElement = new CElement();
        if(NULL != lpNewElement)
        {
            lpNewElement->m_lpData = lpL2->GetDataPtr();
            if(lpL1 != End())
            {
                Insert(lpNewElement,lpL1, iRet < 0);
            }else{
                CElement* lpTail = Tail();
                Insert(lpNewElement,lpTail);
            }
        }
        lpL2 = lst.Next();
    }
}

void CSingleList::DeleteLastKth(int k)
{
    int i = 1;
    if(k <= 0)
    {
        return;
    }
    CElement* lpFast = Begin();
    while((lpFast != End()) && (i < k))
    {
        lpFast = Next();
        ++i;
    }
    if (lpFast == End())
    {
        return;
    }
    CElement* lpSlow = Begin();
    CElement* lpPrev = NULL;
    while (NULL != lpFast->m_lpNext)
    {
        lpFast = lpFast->m_lpNext;
        lpPrev = lpSlow;
        lpSlow = Next();
    }
    if(NULL != lpPrev)
    {
        lpPrev->m_lpNext = lpPrev->m_lpNext->m_lpNext;
    }
}

CElement* CSingleList::Center()
{
    CElement* lpFast = Begin();
    CElement* lpSlow = lpFast;
    while((NULL != lpFast->m_lpNext) && (NULL != lpFast->m_lpNext->m_lpNext))
    {
        lpFast = lpFast->m_lpNext->m_lpNext;
        lpSlow = lpSlow->m_lpNext;
    }
    return lpSlow;
}

CElement::CElement()
{
    m_lpNext = NULL;
    m_lpData = NULL;
}
CElement::~CElement()
{

}

void* CElement::GetDataPtr()
{
    return m_lpData;
}