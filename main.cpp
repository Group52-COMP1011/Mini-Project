#include "Course.h"
#include <iostream>
using namespace std;


int main() {
    CourseManager initial;
    initial.GetCourseNum();

    int selection = 0;
    while (true) {
        initial.Menu();

        while(true){
            cout << "The selection : " << endl;
            cin >> selection;
            switch (selection) {
                case 0:
                    cout << "quit " << endl;
                    system("pause");
                    exit(0);
                    break;
                case 1:
                    initial.add();
                    break;
                case 2:
                    initial.search();
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 7:
                    break;
                default:
                    system("cls");
                    break;
            }
        }
        return 0;
    }
}