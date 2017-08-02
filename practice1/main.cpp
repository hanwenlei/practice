#include"study.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
	//变量定义 
	bool flag=true;
	char InputOrder[20];
	char StudyClass[20];
	int StartTime=0,EndTime=0;
	int count=0,y=0,m=0,d=0;
	
	//配置文件
	flag=file.OpenDisposition();
	if(flag)
	{
		//读取文件
		flag=file.OpenStore();
		if(flag)
		{
			//用户输入指令 
			while(1)
			{
				cout<<"请输入欲执行的操作:"<<endl; 
				cin>>InputOrder;
				
				//输入操作 
				if(strcmp(InputOrder,"-TaskInput")==0)
				{
					cin>>StudyClass>>count>>y>>m>>d;
					hash.input(StudyClass,count,y,m,d);
					hash.review(StudyClass,count,y,m,d);
				}
				
				//查询操作 
				else if(strcmp(InputOrder,"-TaskQuery")==0)
				{
					cin>>StartTime;
					hash.query(StartTime);
				}
				
				//统计操作 
				else if(strcmp(InputOrder,"-TaskCollect")==0)
				{
					cin>>StartTime>>EndTime;
					hash.collect(StartTime,EndTime);
				}
				
				//退出操作 
				else if(strcmp(InputOrder,"-Quit")==0)
				{
					break;
				}
				
				//异常指令 
				else
				{
					cout<<InputOrder<<"不是有效的指令"<<endl; 
				}
			}
		}
	}
	
	//清除链表
	hash.clear();
		
	//关闭读写文件 
	if(file.fp)
	{
		fclose(file.fp);
	}
	
	return 0;
}