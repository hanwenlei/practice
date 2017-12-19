#include<cstdio>
#include"CL_TorrentFile.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
	char* name = "test.torrent";
	CL_TorrentFile* file = NULL;
	try
	{
		file = new CL_TorrentFile(name);
	}
	catch(char* ErrorString)
	{
		printf("%s\n", ErrorString);
		delete file;
		return -1;
	}
	catch(...)
	{
		printf("unknown error!\n");
		delete file;
		return -1;
	}
	CL_TorrentTree* tree = file->AddNode();
	file->PrintTree();
	delete file;
	return 0;
}