#ifndef INSPECTIONJOB_H
#define INSPECTIONJOB_H

namespace Job
{
class InspectionJob
{
public:
    InspectionJob();
    virtual ~InspectionJob();

    /*
    *  @brief 创建程式到数据库
    *  @param path：写程式所在路径
    *  @return NA
    */
    void createJob(std::string path);

    /*
    *  @brief 读程式
    *  @param path:读的程式所在路径
    *  @return
    */
    void readJob(std::string path);
};
}

#endif // INSPECTIONJOB_H
