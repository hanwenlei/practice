#ifndef _CL_STRINGNODE_H_
#define _CL_STRINGNODE_H_

#include"CL_ITorrentNode.h"

class CL_StringNode : public CL_ITorrentNode
{
private:
	char* m_pstring;
	int m_length;
	
	CL_StringNode(char* value, int length);
	int PrintFunc();
	virtual ~CL_StringNode();
	friend class CL_TorrentTree;
};

#endif