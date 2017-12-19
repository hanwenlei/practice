#ifndef _CL_TORRENTTREE_H_
#define _CL_TORRENTTREE_H_

#include"CL_ITorrentNode.h"

class CL_TorrentTree
{
private:
	CL_ITorrentNode* m_pnode;
	
public:
	CL_TorrentTree(int value);
	CL_TorrentTree(char* value, int length);
	CL_TorrentTree(CL_TorrentTree value, CL_TorrentTree next);
	CL_TorrentTree(CL_TorrentTree key, CL_TorrentTree value, CL_TorrentTree next);
	CL_TorrentTree(const CL_TorrentTree& temp);
	CL_TorrentTree& operator = (const CL_TorrentTree& temp);
	int PrintTree();
	virtual ~CL_TorrentTree();
};

#endif