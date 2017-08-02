#include<iostream>
//#include"Person.h"
#include<string.h>
using namespace std;
class Person{
public:
	Person(char *name,char sex,char *ID,char *birthday){
		strcpy(this->name,name);
		this->sex =sex;
		strcpy(this->ID,ID);
		strcpy(this->birthday,birthday);
	}
	virtual void display(){
		cout<<"Name:"<<name<<endl;
		cout<<"Sex:"<<sex<<endl;
		cout<<"ID:"<<ID<<endl;
		cout<<"Birthday:"<<birthday<<endl;
	}
	Person* createStu_Techer(char *name,char sex,char *ID, char *birthday,char *position,char *major);
	Person* createStudent(char *name,char sex,char *ID,char *birthday,char *major);
	Person* createTeacher(char *name,char sex, char *ID,char *birthday,char *position);
private:
	char name[20];
	char sex;
	char ID[20];
	char birthday[12];
};
class Student:public Person{
private:
	char major[20];
public:
	Student(char *name,char sex,char *ID,char *birthday,char* major):Person(name,sex,ID,birthday){
		strcpy(this->major,major);
	}
	void display(){
		cout<<"Major:"<<major<<endl;
	}
};
class Teacher:public Person{
private:
	char position[20];
public:
	Teacher(char *name,char sex,char *ID,char *birthday,char* position):Person(name,sex,ID,birthday){
		strcpy(this->position,position);
	}
	void display(){
		cout<<"Position:"<<position<<endl;
	}
};
class Stu_Teacher:public Student,public Teacher{
public:
	Stu_Teacher(char *name,char sex,char *ID,char *birthday,char* position,char* major):Student(name,sex,ID,birthday,major),Teacher(name,sex,ID,birthday,position){}
	void display(){
		Student::Person::display();
		Student::display();
		Teacher::display();
	}
};
Person* Person::createStudent(char *name,char sex,char *ID,char *birthday,char *major){
	return new Student(name,sex,ID,birthday,major);
}
Person* Person::createTeacher(char *name,char sex, char *ID,char *birthday,char *position){
	return new Teacher(name,sex,ID,birthday,position);
}
Person* Person::createStu_Techer(char *name,char sex,char *ID, char *birthday,char *position,char *major){
	return (Student*)new Stu_Teacher(name,sex,ID, birthday,position,major);
}
//int main(void){
//	return 0;
//}
