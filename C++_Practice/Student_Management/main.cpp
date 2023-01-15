#include <iostream>
#include <string>
#include "linkedlist.cpp"

using namespace std;

int selectAction(){
    int selection;
    cout << "Please type: \n1 Add \n2 Search \n3 Print_By_Major \n4 Print \n5 Delete ALL \n6 Exit \n";
    cout << "Enter an option: ";
    cin >> selection;
    return selection;
}

int main() {

    Init();
    int func;
    cout << "-----------Welcome to Student Management System------------ \n";
    while (1) {
        func=selectAction();
        switch (func) {
            case 1:
                cout << "\n";
                Add();
                cout << "\n";
                break;
            case 2:
                cout << "\n";
                Search();
                cout << "\n";
                break;
            case 3:
                cout << "\n";
                Print_By_Major();
                cout << "\n";
                break;
            case 4:
                cout << "\n";
                Print();
                cout << "\n";
                break;
            case 5:
                cout << "\n";
                Delete_ALL(h->head);
                cout << "\n";
                break;
            default:
                cout << "\n";
                cout << "Exit\n";
                return 0;
        }
    }
}