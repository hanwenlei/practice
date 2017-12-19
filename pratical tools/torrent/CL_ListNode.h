#ifndef _CL_LISTNODE_H_
#define _CL_LISTNODE_H_

#include"CL_ITorrentNode.h"
#include"CL_TorrentTree.h"

class CL_ListNode : public CL_ITorrentNode
{
private:
	CL_TorrentTree m_pvalue;
	CL_TorrentTree m_pnext;
	
	CL_ListNode(CL_TorrentTree value, CL_TorrentTree next);
	int PrintFunc();
	virtual ~CL_ListNode();
	friend class CL_TorrentTree;
};

#endif