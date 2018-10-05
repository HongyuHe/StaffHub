#include "viewBasic.h"


#include <QString>
#include <QDebug>

ViewBasic::ViewBasic()
{
    basicHeaderList << "工号" << "姓名" << "性别" << "出生日期" << "年龄"
                        << "政治面貌" << "身份证号" << "户籍所在地" << "简历" << "联系方式"
                        << "全日制学历" << "在职学历" <<"毕业院校及专业";
//    qDebug() << staffHeaderList;
    basicAttrNameList <<  "stf_no" << "stf_name" << "stf_gender" << "stf_birthday" << "stf_age"
                       << "stf_group" << "stf_status" << "stf_politicalStatus" << "stf_IDno" << "stf_domicile"
                       << "stf_resume"<< "stf_tel" <<  "edu_fullTime" << "edu_inService" << "edu_SchlandMajor";
    formType = "view";
}

void ViewBasic::printRecord () const
{
    qDebug() << stf_no << stf_name << stf_gender << stf_birthday << stf_age
                 << stf_politicalStatus << stf_IDno << stf_domicile << stf_resume << stf_tel
                 <<  edu_fullTime << edu_inService << edu_SchlandMajor;
}

//////////////////////////////////////////////////// get ////////////////////////////////////////////////////////
QString ViewBasic::get_stf_no () const
{
    return stf_no;
}

QString ViewBasic::get_stf_name () const
{
    return stf_name;
}

QString ViewBasic::get_stf_gender () const
{
    return stf_gender;
}

QString ViewBasic::get_stf_birthday() const
{
    return stf_birthday;
}

QString ViewBasic::get_stf_age () const
{
    return stf_age;
}

QString ViewBasic::get_stf_politicalStatus () const
{
    return stf_politicalStatus;
}

QString ViewBasic::get_stf_IDno () const
{
    return stf_IDno;
}

QString ViewBasic::get_stf_domicile () const
{
    return stf_domicile;
}

QString ViewBasic::get_stf_resume () const
{
    return stf_resume;
}

QString ViewBasic::get_stf_tel () const
{
    return stf_tel;
}

QString ViewBasic::get_edu_fullTime () const
{
    return edu_fullTime;
}

QString ViewBasic::get_edu_inService () const
{
    return edu_inService;
}

QString ViewBasic::get_edu_SchlandMajor () const
{
    return edu_SchlandMajor;
}

QString ViewBasic::getformType (void) const
{
    return formType;
}

//////////////////////////////////////////////////// get ////////////////////////////////////////////////////////
void ViewBasic::set_stf_no (QString no)
{
    stf_no = no;
}
void ViewBasic::set_stf_name (QString stfname)
{
    stf_name = stfname;
}

void ViewBasic::set_stf_gender (QString gender)
{
    stf_gender = gender;
}

void ViewBasic::set_stf_birthday(QString birthday)
{
    stf_birthday = birthday;
}

void ViewBasic::set_stf_age (QString stfage)
{
    stf_age = stfage;
}

void ViewBasic::set_stf_politicalStatus (QString politicalStatus)
{
    stf_politicalStatus = politicalStatus;
}

void ViewBasic::set_stf_IDno (QString IDno)
{
    stf_IDno = IDno;
}

void ViewBasic::set_stf_domicile (QString domicile)
{
    stf_domicile = domicile;
}

void ViewBasic::set_stf_resume (QString resume)
{
    stf_resume = resume;
}

void ViewBasic::set_stf_tel (QString tel)
{
    stf_tel = tel;
}

void ViewBasic::set_edu_fullTime (QString eduFulltime)
{
    edu_fullTime = eduFulltime;
}

void ViewBasic::set_edu_inService (QString eduInservice)
{
    edu_inService = eduInservice;
}

void ViewBasic::set_edu_SchlandMajor (QString eduSchlandMajor)
{
    edu_SchlandMajor = eduSchlandMajor;
}
