#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;

struct student
{
    int stu_no;
    char stu_name[30], stu_course[20], stu_class[2];
    float marks[4];
    char grade;
} stu_var;

int main()
{
    float sum = 0;
    float avg;
    cout << "enter student number: ";
    cin >> stu_var.stu_no;
    cout << "enter student name: ";
    cin>> stu_var.stu_name;
    cout << "enter a course: ";
    cin >> stu_var.stu_course;
    cout << "enter student's class: ";
    cin >> stu_var.stu_class;
    cout << "enter student marks:\n";
    for(int i=0; i<4; i++)
    {
        cout << "subject: " << i+1 << ": ";
        cin >> stu_var.marks[i];
        sum = sum + stu_var.marks[i];
    }

    avg = sum / 4;

    if(avg < 50)
    {
        stu_var.grade = 'F';
    }
    else if(avg < 65)
    {
        stu_var.grade = 'C';
    }
    else if(avg < 80)
    {
        stu_var.grade = 'B';
    }
    else{
        stu_var.grade = 'A';
    }

    cout << "\nstudent result:\n";
    cout << "\nstu. no.: " << stu_var.stu_no << "\t\t\tstu. name: " << stu_var.stu_name;
    cout << "\ncourse: " << stu_var.stu_course << "\t\t\tclass: " << stu_var.stu_class;
    cout << "\ntotal marks: " << sum << "\tgrade: " << stu_var.grade;

    return 0;
}