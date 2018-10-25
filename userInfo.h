///*此类的主要功能是处理用户的登录和注册*///
#ifndef USERINFO_H
#define USERINFO_H

#include <QString>

class UserInfo
{
public:
    UserInfo();

    //检查用户信息：
    bool checkLoginInfo (QString userName, QString userPswd);
    bool checkRegisterInfo (QString userName);
    //添加新用户：
    bool addNewUser (QString UserName, QString UserPswd);
};

#endif // USERINFO_H
