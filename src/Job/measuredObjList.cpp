#include "Job/measuredObjList.hpp"
#include "Job/measuredObj.hpp"

Job::MeasuredObjList::MeasuredObjList()
{

}

Job::MeasuredObjList::~MeasuredObjList()
{
    this->m_pHead = nullptr;
}

void Job::MeasuredObjList::pushHeadNode(MeasuredObj *ptr)
{
    MeasuredObj *pOrigPos = this->m_pHead; //保存链表头地址

    this->m_pHead = ptr;     //将待插入节点设为首个节点
    ptr->setPNext(pOrigPos); //链表后一节点设为原来的头节点

    if(pOrigPos != nullptr)  //链表不为空
    {
        pOrigPos->setPPre(ptr);
    }

    this->m_size ++;         //节点个数增一
}

void Job::MeasuredObjList::pushTailNode(MeasuredObj *ptr)
{
    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //step1.保存头地址

    MeasuredObj *pOrigPos = this->m_pHead;

    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //step2.判断 如果之前链表为空，直接插入，链表长度增1

    if(this->m_pHead == nullptr)
    {
        this->m_pHead = ptr;
        ptr->setPNext(nullptr);
        ptr->setPPre(nullptr);
        this->m_size ++;      //链表长度加1
        return;
    }

    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //step3.判断 如果之前链表不为空，找到最后一个元素在后面插入目标节点，链表长度增1

    while (this->m_pHead->pNext() != nullptr)
    {
        this->m_pHead = this->m_pHead->pNext();
    }

    this->m_pHead->setPNext(ptr); //在链表最后一个节点插入目标节点
    ptr->setPPre(this->m_pHead);
    ptr->setPNext(nullptr);

    this->m_pHead = pOrigPos; //还原头地址
    this->m_size ++;          //链表长度加1
}

void Job::MeasuredObjList::pullHeadNode()
{
    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //如果链表为空，直接退出

    if(this->m_pHead == nullptr)
    {
        return;
    }

    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //链表不为空，删除第一个节点

    MeasuredObj *pOrigPos = this->m_pHead;
    this->m_pHead = this->m_pHead->pNext();
    if(pOrigPos->pNext() != nullptr)
    {
       pOrigPos->pNext()->setPPre(nullptr);
    }

    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //链表长度减1

    this->m_size --;
}

void Job::MeasuredObjList::pullTailNode()
{
    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //step1.链表为空，直接退出

    if(this->m_pHead == nullptr)
    {
        return;
    }

    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //step2.链表不为空，删除最后一个节点

    MeasuredObj *pDelete;
    pDelete = this->m_pHead;
    while (pDelete->pNext() != nullptr) //找到最后一个节点
    {
        pDelete = (*pDelete).pNext();
    }
    if(pDelete->pPre() != nullptr) //如果链表不是只有一个节点
    {
        pDelete->pPre()->setPNext(nullptr);
        pDelete->setPPre(nullptr);
        pDelete->setPNext(nullptr);
    }
    else //链表只有一个节点
    {
        this->m_pHead = nullptr;
    }

    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //step3.链表长度减1

    this->m_size --; //链表长度加1
}

void Job::MeasuredObjList::print()
{
    MeasuredObj *pTemp;
    pTemp = this->m_pHead;
    while (pTemp != nullptr) //遍历所有节点
    {
        std::cout << (*pTemp).name() << std::endl;
        std::cout << (*pTemp).body().xCoord() << std::endl;
        std::cout << (*pTemp).body().yCoord() << std::endl;
        std::cout << (*pTemp).body().height() << std::endl;
        std::cout << (*pTemp).body().width() << std::endl;
        pTemp = pTemp->pNext();
    }
    std::cout << std::endl;
}

