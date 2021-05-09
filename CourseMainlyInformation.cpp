#include "CourseInformation.h"

Details::Details(string code, string title, int credit){
    this->Code = code;
    this->Title = title;
    this->Credit = credit;
}

void Details::showInformation(){
    cout << "Code： " << this->Code<<endl;
    cout<< "Title： " << this->Title<<endl;
    cout<< "Credit ：" << this->Credit<<endl;
}


