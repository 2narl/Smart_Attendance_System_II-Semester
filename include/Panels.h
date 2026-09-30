#ifndef PANELS_H
#define PANELS_H

#include "AuthenticationBase.h"

class AdminPanel : public AuthenticationBase
{
public:
    bool login();
    void showPanel();

private:
    void userManagement();
    void systemConfiguration();
};

class SubAdminPanel : public AuthenticationBase
{
public:
    bool login();
    void showPanel();
};

class StudentTeacherPanel : public AuthenticationBase
{
public:
    bool login();
    void showPanel();
};

#endif
