#pragma once
#include<iostream>
using namespace std;
#include "CourseMainlyInformation.h"
#include <fstream>
#define  FILENAME "Course.txt"

class CourseManager{
public:
    CourseManager(); //构造函数
    void Menu();
    void save();//保存文件
    int CourseNum;//课程数量
    CourseMainlyInformation ** CourseArray;//课程数组
    int GetCourseNum();//从文件获得课程数量
    void search();//搜索
    bool FileIsEmpty;
    void add();
    int IsExist(string code);
};