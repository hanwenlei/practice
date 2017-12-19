#ifndef _CL_TORRENTFILE_H_
#define _CL_TORRENTFILE_H_

#include"CL_TorrentTree.h"

class CL_TorrentFile
{
private:
	char* m_pFileContent;
	long int m_position;
	long int m_FileSize;
	CL_TorrentTree* m_ptree;
	
	CL_TorrentTree* AddDirect();
	CL_TorrentTree* AddList();
	CL_TorrentTree* AddString();
	CL_TorrentTree* AddInt();
	
public:
	CL_TorrentFile(char* name);
	bool IsEnd();
	CL_TorrentTree* AddNode();
	int PrintTree();
	virtual ~CL_TorrentFile();
};

#endif