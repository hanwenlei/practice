#ifndef _CL_INTNODE_H_
#define _CL_INTNODE_H_

#include"CL_ITorrentNode.h"

class CL_IntNode : public CL_ITorrentNode
{
private:
	int m_value;
	
	CL_IntNode(int value);
	int PrintFunc();
	virtual ~CL_IntNode();
	friend class CL_TorrentTree;
};

#endif