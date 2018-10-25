#ifndef CHECKUSERINFO_H
#define CHECKUSERINFO_H

#include <QString>

class CheckUserInfo
{
public:
    CheckUserInfo();

    //检查用户信息：
    bool checkLoginInfo (QString userName, QString userPswd);
    bool checkRegisterInfo (QString userName);
    //添加新用户：
    bool addNewUser (QString UserName, QString UserPswd);
};

#endif // CHECKUSERINFO_H
