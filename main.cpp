#include <iostream>
#include<fstream>
#include <bits/stdc++.h>
#define usrId 1121
#define password 1111
using namespace std;
//-------------------------------------------------------Super Class-------------------------------------------------------//
class Patron{
public:
    int id;
    string name;
    string departmentName;
    string email;
    string contactNo;
    string address;
    double amount;

    virtual void input(){};
    virtual void menu()=0;
};

//-------------------------------------------------------Student Class-------------------------------------------------------//
class Student : public Patron{
public:
    void input(){
        cout<<"Enter Student's Id: ";cin>>id;
        cout<<"Enter Student's name: ";cin>>name;
        cout<<"Enter Student's Department: ";cin>>departmentName;
        cout<<"Enter Student's Email: ";cin>>email;
        cout<<"Enter Student's Contact: ";cin>>contactNo;
        cout<<"Enter Student's Address: ";cin>>address;
        cout<<"Enter Student's Amount: ";cin>>amount;
        cout<<"--------------------------------"<<endl;
    }

    void insertStudent(){
        ofstream inputSFile("Student.txt",ios::out|ios::app);
        if(!inputSFile){
            cout<<"File not found"<<endl;
        }
        input();
        inputSFile<<id<<" "<<name<<" "<<departmentName<<" "<<email<<" "<<contactNo<<" "<<address<<" "<<amount<<"\n";
    }

    void searchStudent(string studentId){
        ifstream inputSFile("Student.txt", ios::in);
        string str;

        while(getline(inputSFile, str)){
            stringstream ss(str);
            string word;
            string words[7];
            int i = 0;
            while (ss >> word) {
				words[i++]=word;
            }
            if(words[0] == studentId){
                cout<<"Student's ID: "<<words[0]<<"\n";
                cout<<"Student's Name: "<<words[1]<<"\n";
                cout<<"Student's Department Name: "<<words[2]<<"\n";
                cout<<"Student's Email: "<<words[3]<<"\n";
                cout<<"Student's Contact No: "<<words[4]<<"\n";
                cout<<"Student's Address: "<<words[5]<<"\n";
                cout<<"Student's Amount Due: "<<words[6]<<"\n";
			}
        }
        cout<<"--------------------------------"<<endl;
    }

    void showAllStudents(){
        ifstream inputSFile("Student.txt", ios::in);
        string str;

        while(getline(inputSFile, str)){
            stringstream ss(str);
            string word;
            string words[7];
            int i = 0;
            while (ss >> word) {
				words[i++]=word;
            }
            cout<<"Student's ID: "<<words[0]<<"\n";
            cout<<"Student's Name: "<<words[1]<<"\n";
            cout<<"Student's Department Name: "<<words[2]<<"\n";
            cout<<"Student's Email: "<<words[3]<<"\n";
            cout<<"Student's Contact No: "<<words[4]<<"\n";
            cout<<"Student's Address: "<<words[5]<<"\n";
            cout<<"Student's Amount Due: "<<words[6]<<"\n";
            cout<<"--------------------------------"<<endl;
        }
    }

    void menu(){
        cout<<"--------------------------------"<<endl;
        cout<<"1. Insert Student"<<endl;
        cout<<"2. Search by Student ID"<<endl;
        cout<<"3. Show all Students"<<endl;
        cout<<"4. Go Back"<<endl;
        cout<<"--------------------------------"<<endl;
    }

};

//-------------------------------------------------------Teacher Class-------------------------------------------------------//
class Teacher : public Patron{
public:
    void input(){
        cout<<"Enter Teacher's Id: ";cin>>id;
        cout<<"Enter Teacher's name: ";cin>>name;
        cout<<"Enter Teacher's Department: ";cin>>departmentName;
        cout<<"Enter Teacher's Email: ";cin>>email;
        cout<<"Enter Teacher's Contact: ";cin>>contactNo;
        cout<<"Enter Teacher's Address: ";cin>>address;
        cout<<"--------------------------------"<<endl;
    }

    void insertTeacher(){
        ofstream inputTFile("Teacher.txt",ios::out|ios::app);
        if(!inputTFile){
            cout<<"File not found"<<endl;
        }
        input();
        inputTFile<<id<<" "<<name<<" "<<departmentName<<" "<<email<<" "<<contactNo<<" "<<address<<"\n";
    }

    void searchTeacher(string studentId){
        ifstream inputTFile("Teacher.txt", ios::in);
        string str;

        while(getline(inputTFile, str)){
            stringstream ss(str);
            string word;
            string words[6];
            int i = 0;
            while (ss >> word) {
				words[i++]=word;
            }
            if(words[0] == studentId){
                cout<<"Teacher's ID: "<<words[0]<<"\n";
                cout<<"Teacher's Name: "<<words[1]<<"\n";
                cout<<"Teacher's Department Name: "<<words[2]<<"\n";
                cout<<"Teacher's Email: "<<words[3]<<"\n";
                cout<<"Teacher's Contact No: "<<words[4]<<"\n";
                cout<<"Teacher's Address: "<<words[5]<<"\n";
			}
        }
        cout<<"--------------------------------"<<endl;
    }

    void showAllTeachers(){
        ifstream inputTFile("Teacher.txt", ios::in);
        string str;

        while(getline(inputTFile, str)){
            stringstream ss(str);
            string word;
            string words[6];
            int i = 0;
            while (ss >> word) {
				words[i++]=word;
            }
            cout<<"Teacher's ID: "<<words[0]<<"\n";
            cout<<"Teacher's Name: "<<words[1]<<"\n";
            cout<<"Teacher's Department Name: "<<words[2]<<"\n";
            cout<<"Teacher's Email: "<<words[3]<<"\n";
            cout<<"Teacher's Contact No: "<<words[4]<<"\n";
            cout<<"Teacher's Address: "<<words[5]<<"\n";
            cout<<"--------------------------------"<<endl;

        }
    }

    void menu(){
        cout<<"--------------------------------"<<endl;
        cout<<"1. Insert Teacher"<<endl;
        cout<<"2. Search by Teacher ID"<<endl;
        cout<<"3. Show all Teachers"<<endl;
        cout<<"4. Go Back"<<endl;
        cout<<"--------------------------------"<<endl;
    }

};

//-------------------------------------------------------Book Class-------------------------------------------------------//
class Book{
public:
    int bookId;
    string bookName;
    string author;
    string publisher;

    void inputBook(){
        cout<<"Enter Book Id: ";cin>>bookId;
        cout<<"Enter Book Name: ";cin>>bookName;
        cout<<"Enter Author Name: ";cin>>author;
        cout<<"Enter Publisher Name: ";cin>>publisher;
        cout<<"--------------------------------"<<endl;
    }

    void insertBook(){
        ofstream inputBFile("Book.txt",ios::out|ios::app);
        if(!inputBFile){
            cout<<"File not found"<<endl;
        }
        inputBook();
        inputBFile<<bookId<<" "<<bookName<<" "<<author<<" "<<publisher<<"\n";
    }

    void searchBook(string bookId){
        ifstream inputBFile("Book.txt", ios::in);
        string str;

        while(getline(inputBFile, str)){
            stringstream ss(str);
            string word;
            string words[6];
            int i = 0;
            while (ss >> word) {
				words[i++]=word;
            }
            if(words[0] == bookId){
                cout<<"Book ID: "<<words[0]<<"\n";
                cout<<"Book Title: "<<words[1]<<"\n";
                cout<<"Author Name: "<<words[2]<<"\n";
                cout<<"Publisher Name: "<<words[3]<<"\n";
			}
        }
        cout<<"--------------------------------"<<endl;
    }

    void showAllBooks(){
        ifstream inputBFile("Book.txt", ios::in);
        string str;

        while(getline(inputBFile, str)){
            stringstream ss(str);
            string word;
            string words[6];
            int i = 0;
            while (ss >> word) {
				words[i++]=word;
            }
            cout<<"Book ID: "<<words[0]<<"\n";
            cout<<"Book Title: "<<words[1]<<"\n";
            cout<<"Author Name: "<<words[2]<<"\n";
            cout<<"Publisher Name: "<<words[3]<<"\n";
            cout<<"--------------------------------"<<endl;
        }
    }

    void menu(){
        cout<<"--------------------------------"<<endl;
        cout<<"1. Insert Book"<<endl;
        cout<<"2. Search by Book ID"<<endl;
        cout<<"3. Show all Books"<<endl;
        cout<<"4. Go Back"<<endl;
        cout<<"--------------------------------"<<endl;
    }
};

//-------------------------------------------------------Main-------------------------------------------------------//
int main(){
    int option,opt,counter1=0,counter2=0,usrInp,passInp;string searchId;
    Student s;
    Teacher t;
    Book b;
    for(int i=0;i>=0;i++){
        cout<<"Main Menu\n1. Student Management\n2. Teacher Management\n3. Book Management\n4. Exit\n";
        cout<<"--------------------------------"<<endl;
        cout<<"Enter your Option : ";cin>>option;
        cout<<"--------------------------------"<<endl;
        if(option==1){//Enters student management system
            for(int i=0;i<4;i++){
                cout<<"Enter your User id : ";cin>>usrInp;
                cout<<"Enter your password : ";cin>>passInp;
                cout<<"--------------------------------"<<endl;
                if(usrInp==usrId && passInp==password){
                    cout<<"Login Successful"<<endl;
                    break;
                }
                else{
                    cout<<"Incorrect User Id and Password try again \nAttempts left : "<<3-i<<endl;
                    cout<<"--------------------------------"<<endl;
                    counter2++;
                }
            }
            if(counter2>3){
                cout<<"Bye Bye"<<endl;
                break;
            }
            while(true){
                s.menu();

                cout<<"Enter your Option : ";cin>>opt;
                cout<<"--------------------------------"<<endl;

                if(opt==1){
                    s.insertStudent();//calls insert student to take user input and write in file
                }
                else if(opt==2){
                    cout<<"Enter the Student's Id you want to search : ";cin>>searchId;
                    s.searchStudent(searchId);//calls search student and compare the student id and returns other information
                }
                else if(opt==3){
                    s.showAllStudents();//prints all the students' info
                }
                else if(opt==4){
                    break;
                }
            }

        }
        else if(option==2){
            for(int i=0;i<4;i++){
                cout<<"Enter your User id : ";cin>>usrInp;
                cout<<"Enter your password : ";cin>>passInp;
                cout<<"--------------------------------"<<endl;
                if(usrInp==usrId && passInp==password){
                    cout<<"Login Successful"<<endl;
                    break;
                }
                else{
                    cout<<"Incorrect User Id and Password try again \nAttempts left : "<<3-i<<endl;
                    cout<<"--------------------------------"<<endl;
                    counter2++;
                }
            }
            if(counter2>3){
                cout<<"Bye Bye"<<endl;
                break;
            }
            while(true){
                t.menu();

                cout<<"Enter your Option : ";cin>>opt;
                cout<<"--------------------------------"<<endl;

                if(opt==1){
                    t.insertTeacher();
                }
                else if(opt==2){
                    cout<<"Enter the Teacher's Id you want to search : ";cin>>searchId;
                    t.searchTeacher(searchId);
                }
                else if(opt==3){
                    t.showAllTeachers();
                }
                else if(opt==4){
                    break;
                }
            }
        }
        else if(option==3){
            for(int i=0;i<4;i++){
                cout<<"Enter your User id : ";cin>>usrInp;
                cout<<"Enter your password : ";cin>>passInp;
                cout<<"--------------------------------"<<endl;
                if(usrInp==usrId && passInp==password){
                    cout<<"Login Successful"<<endl;
                    break;
                }
                else{
                    cout<<"Incorrect User Id and Password try again \nAttempts left : "<<3-i<<endl;
                    cout<<"--------------------------------"<<endl;
                    counter2++;
                }
            }
            if(counter2>3){
                cout<<"Bye Bye"<<endl;
                break;
            }
            while(true){
                b.menu();

                cout<<"Enter your Option : ";cin>>opt;
                cout<<"--------------------------------"<<endl;

                if(opt==1){
                    b.insertBook();
                }
                else if(opt==2){
                    cout<<"Enter the Book Id you want to search : ";cin>>searchId;
                    b.searchBook(searchId);
                }
                else if(opt==3){
                    b.showAllBooks();
                }
                else if(opt==4){
                    break;
                }
            }

        }
        else if(option==4){
            break;
        }
        else{
            cout<<"Invalid Input\n";
        }
    }
    return 0;
}
