#ifndef _ISTACKNODE_H_
#define _ISTACKNODE_H_

class IStackNode
{
private:
	IStackNode* m_pnext;
	
public:
	IStackNode();
	virtual IStackNode* GetNext();
	virtual int SetNext(IStackNode* pNode);
	virtual IStackNode* CopyFunction() = 0;
	virtual ~IStackNode();
};

#endif