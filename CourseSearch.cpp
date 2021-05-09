#include "Course.h"
#include "CourseMainlyInformation.h"
#include <iostream>
#define FILENAME "Course.txt"
using namespace std;

void CourseManager::Menu(){
    cout << "0.Quit" << endl;
    cout << "1.Add courses" << endl;
    cout << "2.Search" << endl;
    cout << "3.Delete a course" << endl;
    cout << "4.modify" << endl;
}

void CourseManager::save(){
    ofstream ofs;
    ofs.open(FILENAME, ios::out);
    for (int i = 0; i < this->CourseNum; i++){
        ofs << this->CourseArray[i]->Code<<endl;
        ofs << this->CourseArray[i]->Title<<endl;
        ofs << this->CourseArray[i]->Credit<<endl;
    }
    ofs.close();
}

int CourseManager::GetCourseNum(){
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    string code ;
    string title;
    int credit;
    int num = 0;
    while (ifs >> code && ifs >> title && ifs >> credit){
        num++;
    }
    ifs.close();

    return num;
}

int CourseManager::IsExist(string code){
    int index = -1;
    for (int i = 0; i < this->CourseNum; i++){
        if (this->CourseArray[i]->Code == code){
            index = i;
            break;
        }
    }
    return index;
}

void CourseManager::search(){
    if (this->FileIsEmpty)
    {
        cout << "No recordings!" << endl;
    }
    else
    {
        cout << "method of search：" << endl;
        cout << "1.search by code" << endl;
        cout << "2.search by title" << endl;

        int choice = 0;
        cin >> choice;


        if (choice == 1) {//code
            string code;
            cout << "code： " << endl;
            cin >> code;

            int ret = IsExist(code);
            if (ret != -1)
            {
                cout << "Found！Details： " << endl;
                this->CourseArray[ret]->showInformation();
            }
            else
            {
                cout << "No such course!" << endl;
            }
        }
        else if(choice == 2){ //title
            string title;
            cout << "title： " << endl;
            cin >> title;

            bool flag = false;  //查找到的标志
            for (int i = 0; i < CourseNum; i++){
                if (CourseArray[i]->Title == title){
                    cout << "Founded!Details： "<< CourseArray[i]->Code<< " Details：" << endl;
                    flag = true;
                    this->CourseArray[i]->showInformation();
                }
            }
            if (flag == false)
            {
                cout << "No such course!" << endl;
            }
        }
        else{
            cout << "Wrong input" << endl;
        }
    }
}

void CourseManager::add(){
    cout << "Input course number： " << endl;
    int addNum = 0;
    cin >> addNum;
    if (addNum > 0){
        //计算新空间大小
        int newSize = this->CourseNum + addNum;
        //开辟新空间
        CourseMainlyInformation ** newSpace = new CourseMainlyInformation*[newSize];

        //将原空间下内容存放到新空间下
        if (this->CourseArray != NULL){
            for (int i = 0; i < this->CourseNum; i++)
            {
                newSpace[i] = this->CourseArray[i];
            }
        }

        //输入新数据
        for (int i = 0; i < addNum; i++)
        {
            string code;
            string title;
            int credit;

            cout << i + 1 << "  code： " << endl;
            cin >> code;


            cout <<  i + 1 << " title： " << endl;
            cin >> title;

            cout << i+1 <<" credit: "<<endl;
            cin >> credit;


            CourseMainlyInformation * Course = NULL;

            newSpace[this->CourseNum + i] = Course;
        }

        //释放原有空间
        delete[] this->CourseArray;

        //更改新空间的指向
        this->CourseArray = newSpace;

        //更新新的个数
        this->CourseNum = newSize;

        //提示信息
        cout << "Added " << addNum << " courses successfully" << endl;
    }
    else
    {
        cout << "Wrong input" << endl;
    }
}
CourseManager::CourseManager(){
    this->CourseNum = 0;
    this->CourseArray = NULL;
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    //文件不存在情况
    if (!ifs.is_open())
    {
        cout << "File is not exist" << endl; //测试输出
        this->CourseArray = 0;  //初始化人数
        this->FileIsEmpty = true; //初始化文件为空标志
        this->CourseArray = NULL; //初始化数组
        ifs.close(); //关闭文件
        return;
    }
}