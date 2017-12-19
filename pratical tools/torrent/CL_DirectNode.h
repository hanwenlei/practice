#ifndef _CL_DIRECTNODE_H_
#define _CL_DIRECTNODE_H_

#include"CL_ITorrentNode.h"
#include"CL_TorrentTree.h"

class CL_DirectNode : public CL_ITorrentNode
{
private:
	CL_TorrentTree m_pkey;
	CL_TorrentTree m_pvalue;
	CL_TorrentTree m_pnext;
	
	CL_DirectNode(CL_TorrentTree key, CL_TorrentTree value, CL_TorrentTree next);
	int PrintFunc();
	virtual ~CL_DirectNode();
	friend class CL_TorrentTree;
};

#endif