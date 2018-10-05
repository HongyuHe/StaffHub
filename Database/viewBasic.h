#ifndef VIEWBASIC_H
#define VIEWBASIC_H

#include <QString>
#include <QList>

class ViewBasic
{
public:
    ViewBasic();

    QList <QString> basicHeaderList;    //表头链表；
    QList <QString> basicAttrNameList;  //属性名链表；

    void printRecord () const;

    QString get_stf_no () const;
    QString get_stf_name () const;
    QString get_stf_gender () const;
    QString get_stf_birthday() const;
    QString get_stf_age () const;
    QString get_stf_group () const;
    QString get_stf_status () const;
    QString get_stf_politicalStatus () const;
    QString get_stf_IDno () const;
    QString get_stf_domicile () const;
    QString get_stf_resume () const;
    QString get_stf_tel () const;
    QString get_edu_fullTime () const;
    QString get_edu_inService () const;
    QString get_edu_SchlandMajor () const;

    QString getformType (void) const;

    void set_admin_name (QString name);
    void set_admin_pswd (QString pswd);
    void set_stf_no (QString no);
    void set_stf_name (QString stfname);
    void set_stf_gender (QString gender);
    void set_stf_birthday(QString birthday);
    void set_stf_age (QString stfage);
    void set_stf_group (QString group);
    void set_stf_status (QString status);
    void set_stf_politicalStatus (QString politicalStatus);
    void set_stf_IDno (QString IDno);
    void set_stf_domicile (QString domicile);
    void set_stf_resume (QString resume);
    void set_stf_tel (QString tel);
    void set_edu_fullTime (QString eduFulltime);
    void set_edu_inService (QString eduInservice);
    void set_edu_SchlandMajor (QString eduSchlandMajor);

private:
    //数据项：
    QString stf_no;
    QString stf_name;
    QString stf_gender;
    QString stf_birthday;
    QString stf_age;
    QString stf_politicalStatus;
    QString stf_IDno;
    QString stf_domicile;
    QString stf_resume;
    QString stf_tel;
    QString edu_fullTime;
    QString edu_inService;
    QString edu_SchlandMajor;

    //表单类型：
    QString formType;
};

#endif // VIEWBASIC_H
