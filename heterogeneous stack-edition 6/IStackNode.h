#ifndef _ISTACKNODE_H_
#define _ISTACKNODE_H_

#include<cstdio>
#include<iostream>

using namespace std;

class IStackNode
{	
public:
	IStackNode();
	virtual IStackNode* CopyFunction() = 0;
	virtual ~IStackNode();
};

typedef IStackNode* PIStackNode;

#endif