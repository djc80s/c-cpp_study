#include "inspectionData.hpp"

Job::InspectionData::InspectionData()
{

}

Job::InspectionData::~InspectionData()
{

}

void Job::InspectionData::writeToXml(const QString &fileName)
{
    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //step1.判断文件名是否存在

    if(fileName.isEmpty())
    {
        std::cout << "FileName is not existed!" << std::endl;
        return;
    }

    QFile file(fileName);

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //step2.以可写方式打开或创建文件

    if(!file.open(QFile::WriteOnly|QFile::Text))
    {
        std::cout << "Create file failed ！" << std::endl;
        return;
    }
    QDomDocument xmlDoc; //创建xml文档在内存中

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //step3.添加处理命令(xml文件行首)

    QDomProcessingInstruction instruction;
    instruction = xmlDoc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\"");
    xmlDoc.appendChild(instruction);

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //step4.添加根节点及根节点下信息

    QDomElement root=xmlDoc.createElement("程式基本信息");
    root.setAttribute("版本",QString::fromStdString(this->m_version));
    root.setAttribute("最后修改时间",QString::fromStdString(this->m_lastEditingTime));
    xmlDoc.appendChild(root);

    this->m_board.writeToXml(xmlDoc); //调用函数写入board数据

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //step5.把数据输出到文件

    QTextStream out_stream(&file);
    xmlDoc.save(out_stream,4);

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
}
