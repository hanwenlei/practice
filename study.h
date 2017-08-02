// study.h: interface for the study class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STUDY_H__43789208_E672_4970_AF56_843513494374__INCLUDED_)
#define AFX_STUDY_H__43789208_E672_4970_AF56_843513494374__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>

using namespace std;

//学习类 
class study
{
	public:
		int year,month,day;
		string name;
		int digit;
		study(int year,int month,int day,string name,int digit);
		study(){}
		~study(){}
};

//变量类
class variable
{
public:
	char StudyKind[20][20];
    int *ContentLimit;
    int *ReviewTime;
    int MaxKind;
	variable();
	~variable()
	{
		delete [] ContentLimit;
		delete [] ReviewTime;
	}
	bool isyear(int year);
	study isover(char c[],int count,int year,int month,int day);
	int maxday(int year,int month);
	int invert(int year,int month,int day);
};

//文件类
class File
{
public:
	FILE *fp;
	File(){}
	~File(){}
	bool OpenDisposition();
	bool OpenStore();
};

//链表类
class List
{
public:
	List *last;
	List *next;
	List *other;
	study stu;
	int date;
	List();
	~List(){}
};

//hash函数类
class Hash
{
public:
	List *HashTable[500];
	List *tail[500];
	Hash();
	~Hash(){}
	void input(char c[],int count,int year,int month,int day);
	void query(int InputDate);
	void collect(int StartDate,int EndDate);
	void review(char c[],int count,int year,int month,int day);
	int HashValue(int DateTime);
	void clear();
};

extern File file;
extern Hash hash;

#endif // !defined(AFX_STUDY_H__43789208_E672_4970_AF56_843513494374__INCLUDED_)
