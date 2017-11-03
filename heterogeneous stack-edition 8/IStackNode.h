#ifndef _ISTACKNODE_H_
#define _ISTACKNODE_H_

#include<iostream>
#include<cstdio>

class IStackNode
{
public:
	IStackNode();
	virtual IStackNode* CopyFunction() = 0;
	virtual ~IStackNode();
};

typedef IStackNode* PIStackNode;

#endif