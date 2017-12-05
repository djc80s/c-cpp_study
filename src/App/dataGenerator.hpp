#ifndef GENERATIONDATA_HPP
#define GENERATIONDATA_HPP

#include "Job/measuredObj.hpp"
#include "Job/measuredObjList.hpp"
#include "Job/board.hpp"
#include "Job/inspectionData.hpp"

#define FILE_NAME_LEN 20 //文件名长度
#define IC_CNT        30 //ic 的数量
#define RANDOM_NUM(MAX,MIN) (float)(rand()%((int)(MAX-MIN)*100)+MIN*100)/100 //随机生成大小在MAX和MIN之间的浮点型数据

namespace App
{
/**
 *  @brief 数据生成器
 *         1.随机生成矩形相关数据（包括矩形左上角坐标、长、宽）
 *          1.1 其中左上角坐标范围是：x & y:0.01-150.00
 *          1.2 长范围：0.01-100.00
 *          1.3 宽范围：0.01-100.00
 *         2.随机生成测量目标
 *          2.1 测量目标个数通过参数传入
 *          2.2 测量目标名称前 IC_CNT 个前缀是 "chip_" ，之后前缀名是 "ic_"
 *
 *  @author grace
 *  @version 1.00 2017-11-29 grace
 *                note:create it
 */
class DataGenerator
{

public:

    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //constructor & destructor

    DataGenerator();
    ~DataGenerator();

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //operate function

    /*
    *  @brief 随机生成矩形，包括矩形左上角坐标、长、宽
    *  @param obj：把obj内的成员变量用生成的矩形赋值
    *  @return NA
    */
    void generateRectRandomly(Job::MeasuredObj &obj);

    /*
    *  @brief 随机生成测量目标
    *  @param size：生成测量目标的个数
    *         measuredObj：测量目标组成的数组
    *  @return NA
    */
    void generateObjsRandomly(int size, Job::MeasuredObj measuredObj[]);

    /*
    *  @brief 生成默认的检测数据
    *  @param inspectionData： 使用指针方式传入一个inspectionData实例
    *  @return
    */
    void generateObjInspetionData(int measured_size, Job::InspectionData &inspectionData);

    /*
    *  @brief 生成默认的Board数据
    *  @param boardName：Board的名字
    *         board：存储Board信息的数据实例
    *  @return
    */
    void generateBoard(std::string boardName, Job::Board & board);
    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

private:
    std::string m_defaultBoardName {"COMUNICATION_CARD172506"};
    Job::MeasuredObj *m_pmeasuredObj{nullptr};
};
}


#endif // GENERATIONDATA_HPP
