#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

struct course{ // 一门课的基本资料，包括code，名字，学分，weight（详情看孙艺丹在群里面发的表格）
    char Code[9];  // the Code of the course 
    char Title[50];  // the title of the course 
    int credit;
    int weight;

};
struct Node{ //Node:包括被搜索的这门课的详情，以及要求先修的课的详情
    course searched_course; // 被搜索的这门课
    course pre_course[5];  // 被搜索的这门课的所要求要先修的课的资料（因为最多要求的课有要求先修五门课
    Node *next;
};

void printList(Node* head){ // print out the linked list
    while(head != NULL){
        cout << "The Code of the course is "<< head->searched_course.Code;
        cout << "The title of the course is "<< head->searched_course.Title;
        cout << "The weight of the course is "<< head->searched_course.weight;
        cout << "The credit of the course is "<< head->searched_course.credit;
        cout << "The details of Pre-requisite course(s) of the course is(are): ";
        cout << "Code" << setw(3) << "Title" << setw(3) <<"Weight" << setw(3) <<"Credit" << endl;
        for(int i=0;i<5;i++){
            cout << head->pre_course[i].Code << setw(3)  <<head->pre_course[i].Title << setw(3) 
            << head->pre_course[i].weight <<setw(3)<< head->pre_course[i].credit <<endl;
        }
        
        head=head->next;
    }
}

void append(Node** head_ref, course SearchedCourse,course PreCourse[5]){ // 到时候可以往课表里面增加课程
    Node* newnode=new Node();
    Node* last=*head_ref; 

    newnode->searched_course=SearchedCourse;
    newnode->pre_course[5]=PreCourse[5];

    if(*head_ref==NULL){
        *head_ref=newnode; 
        return;
    }
    while(last->next != NULL){
        last=last->next;
    }
    last->next=newnode;
    return;

}

//删除操作未写（不熟


//写操作（未完成
void saveInfoToFile(const char* fileName, Node* headNode){
    FILE* fp=fopen(fileName,"w");
    Node* pMove=headNode->next;
    

    printList(headNode); 
 
    fclose(fp);
}

//读操作（未完成
void readInfoFromFile(const char* fileName, Node* headNode){
    FILE* fp=fopen(fileName,"r");
    if(fp==NULL){
            fp=fopen(fileName,"w+");// if this file does not exit
        }
}
void Menu(){
    cout << "-----------------------------------------" << endl;
    cout << "---------Course search in COMP-----------" << endl;
    cout << "------1. Search a course in COMP---------" << endl;
    cout << endl;
    // Whether to add more functions??


}

void keyDown(){
    int user_key=0;
    cout << "Please enter your command: ";
    cin >> user_key;
    switch (user_key){
    case 0:
        cout << "Exit";
        system("pause");
        exit(0);
    
    case 1:
        
        break;
    
    default:
        break;
    }
}

int main(){
    Menu();
    keyDown();


    return 0;
}