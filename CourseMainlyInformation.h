#pragma once
#include<iostream>
#include<string>
using namespace std;
//基础信息，详细信息在CourseInformation

class CourseMainlyInformation{
public:
    virtual void showInformation()=0;//显示个人信息
    string Code; //code
    string Title; //title
    int Credit; //credit
};
