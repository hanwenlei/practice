#ifndef _CHILD_CLASS_H_
#define _CHILD_CLASS_H_

#include"CL_Expression.h"
#include"CL_ConvertSystemForGivenNumber.h"

class CL_OpvalNode : public IStackNode
{
private:
	double m_opval;

	CL_OpvalNode(double lopval):m_opval(lopval){}
	virtual IStackNode* CopyFunction();
	int SetOpval(double opval);
	virtual ~CL_OpvalNode(){};
	friend class CL_Expression;
};

class CL_OpterNode : public IStackNode
{
private:
	char m_opter;
	
	CL_OpterNode(char lopter):m_opter(lopter){}
	virtual IStackNode* CopyFunction();
	int SetOpter(char opter);
	virtual ~CL_OpterNode(){};
	friend class CL_Expression;
};

class CL_IntNode : public IStackNode
{
private:
	int m_data;

	CL_IntNode(int l_data):m_data(l_data){}
	virtual IStackNode* CopyFunction();
	int SetInt(int data);
	virtual ~CL_IntNode(){};
	friend class CL_ConvertSystemForGivenNumber;
};

#endif