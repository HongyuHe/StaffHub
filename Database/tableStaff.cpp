#include "tableStaff.h"

#include <QString>
#include <QDebug>

TableStaff::TableStaff()
{
    staffHeaderList << "工号" << "姓名" << "性别" << "出生日期" << "年龄" << "人员分组" << "员工状态"
                        << "政治面貌" << "身份证号" << "户籍所在地" << "科室名"<< "部门名" << "简历" << "联系方式" << "备注";
//    qDebug() << staffHeaderList;
    staffAttrNameList <<  "stf_no" << "stf_name" << "stf_gender" << "stf_birthday" << "stf_age"
                       << "stf_group" << "stf_status" << "stf_politicalStatus" << "stf_IDno" << "stf_domicile"
                       << "stf_resume"<< "stf_tel" << "sec_name" << "dept_name" << "stf_notes";
//    staffRecordList.clear();
    formType = "table";
}

void TableStaff::printRecord () const
{
    qDebug() << stf_no << stf_name << stf_gender << stf_birthday << stf_age << stf_group
                 << stf_status << stf_politicalStatus << stf_IDno << stf_domicile << stf_resume << stf_tel
                     << sec_name << dept_name << stf_notes << endl;
}

//////////////////////////////////////////////////// get ////////////////////////////////////////////////////////
QString TableStaff::get_stf_no () const
{
    return stf_no;
}

QString TableStaff::get_stf_name () const
{
    return stf_name;
}

QString TableStaff::get_stf_gender () const
{
    return stf_gender;
}

QString TableStaff::get_stf_birthday() const
{
    return stf_birthday;
}

QString TableStaff::get_stf_age () const
{
    return stf_age;
}

QString TableStaff::get_stf_group () const
{
    return stf_group;
}

QString TableStaff::get_stf_status () const
{
    return stf_status;
}

QString TableStaff::get_stf_politicalStatus () const
{
    return stf_politicalStatus;
}

QString TableStaff::get_stf_IDno () const
{
    return stf_IDno;
}

QString TableStaff::get_stf_domicile () const
{
    return stf_domicile;
}

QString TableStaff::get_sec_name () const
{
    return sec_name;
}

QString TableStaff::get_dept_name () const
{
    return dept_name;
}

QString TableStaff::get_stf_resume () const
{
    return stf_resume;
}

QString TableStaff::get_stf_tel () const
{
    return stf_tel;
}

QString TableStaff::get_stf_notes () const
{
    return stf_notes;
}

QString TableStaff::getformType (void) const
{
    return formType;
}

//////////////////////////////////////////////////// get ////////////////////////////////////////////////////////
void TableStaff::set_stf_no (QString no)
{
    stf_no = no;
}
void TableStaff::set_stf_name (QString stfname)
{
    stf_name = stfname;
}

void TableStaff::set_stf_gender (QString gender)
{
    stf_gender = gender;
}

void TableStaff::set_stf_birthday(QString birthday)
{
    stf_birthday = birthday;
}

void TableStaff::set_stf_age (QString stfage)
{
    stf_age = stfage;
}

void TableStaff::set_stf_group (QString group)
{
    stf_group = group;
}

void TableStaff::set_stf_status (QString status)
{
    stf_status = status;
}

void TableStaff::set_stf_politicalStatus (QString politicalStatus)
{
    stf_politicalStatus = politicalStatus;
}

void TableStaff::set_stf_IDno (QString IDno)
{
    stf_IDno = IDno;
}

void TableStaff::set_stf_domicile (QString domicile)
{
    stf_domicile = domicile;
}

void TableStaff::set_sec_name (QString name)
{
    sec_name = name;
}

void TableStaff::set_dept_name (QString name)
{
    dept_name = name;
}

void TableStaff::set_stf_resume (QString resume)
{
    stf_resume = resume;
}

void TableStaff::set_stf_tel (QString tel)
{
    stf_tel = tel;
}

void TableStaff::set_stf_notes (QString notes)
{
    stf_notes = notes;
}
