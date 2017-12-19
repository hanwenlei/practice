#ifndef _CL_ITORRENTNODE_H_
#define _CL_ITORRENTNODE_H_

#define DEBUG 1

class CL_ITorrentNode
{
private:
	int m_UseCount;
	
protected:
	CL_ITorrentNode();
	virtual int PrintFunc() = 0;
	virtual ~CL_ITorrentNode();
	friend class CL_TorrentTree;
};

#endif