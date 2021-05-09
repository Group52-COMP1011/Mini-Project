#pragma once
#include<iostream>
using namespace std;
#include "CourseMainlyInformation.h"
//详细信息

class Details :public CourseMainlyInformation{
public:
    Details(string code, string title, int credit); //创建了一个函数
    virtual void showInformation();

};