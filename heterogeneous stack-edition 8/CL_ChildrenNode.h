#ifndef _CL_CHILDRENNODE_H_
#define _CL_CHILDRENNODE_H_

#include"CL_Expression.h"
#include"CL_ConvertSystemForGivenNumber.h"

class CL_OpvalNode : public IStackNode
{
private:
	double m_opval;

public:
	CL_OpvalNode(double opval);
	virtual IStackNode* CopyFunction();
	int SetOpval(double opval);
	virtual ~CL_OpvalNode();
	friend class CL_Expression;
};

class CL_OpterNode : public IStackNode
{
private:
	char m_opter;

public:
	CL_OpterNode(char opter);
	virtual IStackNode* CopyFunction();
	int SetOpter(char opter);
	virtual ~CL_OpterNode();
	friend class CL_Expression;
};

class CL_IntNode : public IStackNode
{
private:
	int m_data;

public:
	CL_IntNode(int data);
	virtual IStackNode* CopyFunction();
	int SetInt(int data);
	virtual ~CL_IntNode();
	friend class CL_ConvertSystemForGivenNumber;
};

#endif