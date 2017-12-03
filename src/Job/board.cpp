#include "board.hpp"

Job::Board::Board()
{

}

Job::Board::Board(double xSize, double ySize, double xOriginal, double yOriginal)
{
    this->m_sizeX = xSize;
    this->m_sizeY = ySize;
    this->m_originalX = xOriginal;
    this->m_originalY =yOriginal;
}

Job::Board::~Board()
{

}

void Job::Board::writeToXml( QDomDocument& qXmlDoc)
{
    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //step1.创建根节点

    QDomElement root = qXmlDoc.documentElement();

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //step2.创建子节点node

    QDomElement node = qXmlDoc.createElement(QString::fromStdString(this->m_name));
    node.setAttribute("板宽",QString::number(this->m_sizeX));
    node.setAttribute("板长",QString::number(this->m_sizeY));
    node.setAttribute("x原点",QString::number(this->m_originalX));
    node.setAttribute("y原点",QString::number(this->m_originalY));

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //step3.写入数据

    //3.1 获取链表首地址
    Job::MeasuredObj *pListHead = this->m_measuredObjList.headMeasuredObjs();

    //3.2 创建node的子节点object
    QDomElement object;

    //3.3 存入所有元件的数据
    for ( int i = 1; i <= this->m_measuredObjList.size(); ++i)
    {
        //3.3.1 存入一个元件的数据：
        object = qXmlDoc.createElement(QString::fromStdString(pListHead->name()));
        object.setAttribute("高度",QString::number(pListHead->body().height()));
        object.setAttribute("宽度",QString::number(pListHead->body().width()));
        object.setAttribute("x坐标",QString::number(pListHead->body().xCoord()));
        object.setAttribute("y坐标",QString::number(pListHead->body().yCoord()));
        //3.3.1 添加object到node节点
        node.appendChild(object);
        pListHead = pListHead->pNext();
    }
    root.appendChild(node); //添加node到根节点

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
}
