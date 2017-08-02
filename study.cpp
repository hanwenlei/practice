// study.cpp: implementation of the study class.
//
//////////////////////////////////////////////////////////////////////

#include"study.h"

using namespace std;

//学习类构造函数
study::study(int year,int month,int day,string name,int digit)
{
	this->year=year;
	this->month=month;
	this->day=day;
	this->name=name;
	this->digit=digit;
}

//变量类构造函数
variable::variable()
{
	memset(StudyKind,0,sizeof(StudyKind));
    ContentLimit=NULL;
    ReviewTime=NULL;
    MaxKind=0;
}

//链表类构造函数
List::List()
{
	last=NULL;
	next=NULL;
	other=NULL;
	date=0;
}

//hash函数类构造函数
Hash::Hash()
{
	memset(HashTable,0,sizeof(HashTable));
	memset(tail,0,sizeof(tail));
}

variable vary;
File file;
Hash hash;

//清除链表
void Hash::clear()
{
	List *p=NULL;
	for(int i=0;i<499;i++)
	{
		if(hash.tail[i])
		{
			//清除冲突数据
			p=hash.HashTable[i];
			p=p->other;
			while(p)
			{
				delete p;
				p=p->next;
			}

			//清除主链表数据
			p=hash.HashTable[i];
			p=p->next;
			while(p)
			{
				delete p;
				p=p->next;
			}
		}
	}
}

//输入函数 
void Hash::input(char c[],int count,int year,int month,int day)
{
	//变量定义
	int i=0,sum=0;
	int InvertDate=vary.invert(year,month,day);
	int index=hash.HashValue(InvertDate);
	string str=c; 
	
	//寻找输入的学习类型对应编号，以便找出上限 
	while(strcmp(c,vary.StudyKind[i])!=0)
	{
		i++;
	}

	//判断hash表是否为空
	if(hash.tail[index]!=0)
	{
		List *p=new List;
		p=hash.HashTable[index];

		//统计此类学习类型当天的学习量
		while(p)
		{
			if(p->stu.name==str)
			{
				sum+=p->stu.digit;
				p=p->next;
			}
			else if(p->other->stu.name==str)
			{
				sum+=p->other->stu.digit;
				p=p->other->next;
			}
			else
			{
				p=p->other;
			}
		}
		
		//判断是否有上限
		if(vary.ContentLimit[i]>=0)
		{
			//判断是否大于上限 
			if((sum+count)>vary.ContentLimit[i])
			{
				cout<<"警告：这天学习量过大!"<<endl;
				
				//给出学习时间的建议
				int HashIndex=hash.HashValue(++InvertDate);
				while(hash.tail[HashIndex])
				{
					if(hash.tail[HashIndex]->date==InvertDate)
					{
						List *q=new List;
						q->date=InvertDate;
						q->stu.name=str;
						q->stu.digit=count;
						q->last=hash.tail[HashIndex];
						hash.tail[HashIndex]=q;
						break;
					}
					else
					{
						HashIndex=hash.HashValue(++InvertDate);
					}
				}
				if(hash.tail[HashIndex]==0)
				{
					List *q=new List;
					q->date=InvertDate;
					q->stu.name=str;
					q->stu.digit=count;
					q->last=hash.HashTable[HashIndex];
					hash.HashTable[HashIndex]=q;
					hash.tail[HashIndex]=q;
				}
				fprintf(file.fp,"%d%s%d\n",InvertDate,c,count);
				cout<<"建议在"<<InvertDate<<"再学习此内容"<<endl;
			}

			//不大于上限的情况
			else
			{
				p=hash.HashTable[index];
				while(p)
				{
					if(p->date==InvertDate)
					{
						List *q=new List;
						q->date=InvertDate;
						q->stu.name=str;
						q->stu.digit=count;
						q->last=hash.tail[index];
						hash.tail[index]=q;
						break;
					}
					else if(p->other->date==InvertDate)
					{
						p=p->other;
						while(p->next){};
						List *q=new List;
						q->date=InvertDate;
						q->stu.name=str;
						q->stu.digit=count;
						q->last=p;
						p->next=q;
					}
					else
					{
						p=p->other;
					}
				}
				fprintf(file.fp,"%d%s%d\n",InvertDate,c,count);
			}
		}

		//无上限的情况
		else
		{
			p=hash.HashTable[index];
			while(p)
			{
				if(p->date==InvertDate)
				{
					List *q=new List;
					q->date=InvertDate;
					q->stu.name=str;
					q->stu.digit=count;
					q->last=hash.tail[index];
					hash.tail[index]=q;
					break;
				}
				else if(p->other->date==InvertDate)
				{
					p=p->other;
					while(p->next){};
					List *q=new List;
					q->date=InvertDate;
					q->stu.name=str;
					q->stu.digit=count;
					q->last=p;
					p->next=q;
				}
				else
				{
					p=p->other;
				}
			}
			fprintf(file.fp,"%d%s%d\n",InvertDate,c,count);
		}
	}

	//hash表为空
	else
	{
		List *q=new List;
		q->date=InvertDate;
		q->stu.name=str;
		q->stu.digit=count;
		hash.HashTable[index]=q;
		q->last=hash.HashTable[index];
		hash.tail[index]=q;
		fprintf(file.fp,"%d%s%d\n",InvertDate,c,count);
	}
}

//查询函数 
void Hash::query(int InputDate)
{
	int index=hash.HashValue(InputDate);
	bool flag=false;
	List *p=new List;
	p=hash.HashTable[index];
	while(p)
	{
		if(p->date==index)
		{
			while(p)
			{
				cout<<p->stu.name<<" "<<p->stu.digit<<endl;
				p=p->next;
			}
			flag=true;
		}
		else if(p->other->date==InputDate)
		{
			p=p->other;
			while(p)
			{
				cout<<p->stu.name<<" "<<p->stu.digit<<endl;
				p=p->next;
			}
			flag=true;
		}
		else
		{
			p=p->other;
		}
	}
	if(!flag)
	{
		cout<<"此时间无复习内容！请检查输入内容或者输入格式"<<endl;
	}
}

//统计函数 
void Hash::collect(int StartDate,int EndDate)
{
	//将时间转换为年月日格式
	int year1=StartDate/10000;
	StartDate%=10000;
	int month1=StartDate/100;
	StartDate%=100;
	int day1=StartDate;
	List *p=new List;
	int *count=new int[10];
	bool flag=false;
	memset(count,0,sizeof(count));
	//将学习类型转化为string
	string *str=new string[10];
	for(int i=0;i<vary.MaxKind;i++)
	{
		str[i]=vary.StudyKind[i];
	}
	
	//统计每种类型的学习量
	for(i=StartDate;i<=EndDate;day1++)
	{
		study stu=vary.isover("judge",0,year1,month1,day1);
		i=vary.invert(stu.year,stu.month,stu.day);
		int index=hash.HashValue(i);
		p=hash.HashTable[index];
		if(hash.tail[index])
		{
			while(p)
			{
				if(p->date==i)
				{
					while(p)
					{
						for(int j=0;j<vary.MaxKind;j++)
						{
							if(str[j]==p->stu.name)
							{
								count[j]+=p->stu.digit;
								flag=true;
							}
						}
						p=p->next;
					}
					break;
				}
				else if(p->other->date==i)
				{
					p=p->other;
					while(p)
					{
						for(int j=0;j<vary.MaxKind;j++)
						{
							if(str[j]==p->stu.name)
							{
								count[j]+=p->stu.digit;
								flag=true;
							}
						}
						p=p->next;
					}
					break;
				}
				else
				{
					p=p->other;
				}
			}
		}
	}
	
	//输出每种类型的学习量
	if(flag){
		for(i=0;i<vary.MaxKind;i++)
		{
			cout<<str[i]<<" "<<count[i]<<endl;
		}
	}
	else
	{
		cout<<"此时间段无复习内容！请检查输入内容或者输入格式"<<endl;
	}

	//释放内存空间
	delete [] count;
	delete [] str;
}

//计算复习时间 
void Hash::review(char c[],int count,int year,int month,int day)
{
	study s;
	int InvertDate=0,index=0;
	List *p=new List;
	for(int i=0;i<13;i++)
	{
		List *q=new List;
		day+=vary.ReviewTime[i];
		s=vary.isover(c,count,year,month,day);
		InvertDate=vary.invert(s.year,s.month,s.day);
		index=hash.HashValue(InvertDate);

		//将复习时间加入hash表中 
		p=hash.HashTable[index];

		//hash表不为空
		if(hash.tail[index])
		{
			while(p)
			{
				if(p->date==InvertDate)
				{
					q->date=InvertDate;
					q->stu.name=s.name;
					q->stu.digit=s.digit;
					q->last=hash.tail[index];
					hash.tail[index]=q;
					break;
				}
				else if(p->other->date==InvertDate)
				{
					p=p->other;
					while(p->next){};
					q->date=InvertDate;
					q->stu.name=s.name;
					q->stu.digit=s.digit;
					q->last=p;
					p->next=q;
				}
				else
				{
					p=p->other;
				}
			}
			fprintf(file.fp,"%d%s%d\n",InvertDate,c,count);
		}

		//hash表为空
		else
		{
			q->date=index;
			q->stu.name=s.name;
			q->stu.digit=s.digit;
			hash.HashTable[index]=q;
			q->last=hash.HashTable[index];
			hash.tail[index]=q;
			fprintf(file.fp,"%d%s%d\n",InvertDate,c,count);
		}
	}
}

//hash模运算
int Hash::HashValue(int DateTime)
{
	return DateTime%499;
}

//判断是否是闰年
bool variable::isyear(int year)
{
	if((year%4==0&&year%100!=0)||(year%400==0))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//返回每月的最大天数 
int variable::maxday(int year,int month)
{
	int mday=0;
	if(isyear(year)&&month==2)
	{
		mday=29;
	}
	else
	{
		switch(month)
		{
			case 1:mday=31;break;
			case 2:mday=28;break;
			case 3:mday=31;break;
			case 4:mday=30;break;
			case 5:mday=31;break;
			case 6:mday=30;break;
			case 7:mday=31;break;
			case 8:mday=31;break;
			case 9:mday=30;break;
			case 10:mday=31;break;
			case 11:mday=30;break;
			case 12:mday=31;break;
		}
	}
	return mday;
}

//判断是否超过每月的最大天数 
study variable::isover(char c[],int count,int year,int month,int day)
{
	int mday=0;
	string str=c;
	mday=vary.maxday(year,month);
	while(day>mday)
	{
		day-=mday;
		month++;
		if(month>12)
		{
			year++;
			month=1;
		}
		mday=vary.maxday(year,month);
	}
	study stu(year,month,day,str,count);
	return stu;
}

//转换日期函数
int variable::invert(int year,int month,int day)
{
	int DateDigit=0;
	DateDigit=year*10000+month*100+day;
	return DateDigit;
}

//配置文件函数
bool File::OpenDisposition()
{
	//变量定义
	vary.ContentLimit=new int[20];
	vary.ReviewTime=new int[13];
	char *optimition=new char[20];
	const int size=100;
	char line[size];

	//打开配置文件 
	char filename[]="配置文件.txt";
	FILE *filep=fopen(filename,"r");
	if(filep==NULL)
	{
		cout<<"open file failed"<<endl;
		return false;
	}
	
	//读取配置文件
	while(!feof(filep))
	{
		char c=getc(filep);
		
		//跳过注释行 
		if(c=='#')
		{
			fgets(line,size,filep);
		}
		
		//读取复习时间间隔 
		else if(c=='!')
		{
			for(int i=0;i<13;i++)
			{
				fscanf(filep,"%d",&vary.ReviewTime[i]);
			}
			getc(filep);
		}
		
		//读取学习类型和相应学习上限 
		else if(c=='*')
		{
			int i=0;
			fscanf(filep,"%s%d",vary.StudyKind[i],&vary.ContentLimit[i]);
			i++;
			getc(filep);
			while(getc(filep)=='*')
			{
				fscanf(filep,"%s%d",vary.StudyKind[i],&vary.ContentLimit[i]);
				i++;
				getc(filep);	
			}
			vary.MaxKind=i;
			getc(filep);
		}
		
		//读取优化方向 
		else
		{
			fscanf(filep,"%s",optimition);
		}
	}

	//关闭配置文件 
	if(filep)
	{
		fclose(filep);
	}

	//释放内存空间
	delete [] optimition;

	return true;
}

//读取文件函数
bool File::OpenStore()
{
	//打开读取文件
	file.fp=fopen("study.txt","a+");
	if(file.fp==NULL)
	{
		cout<<"open file failed"<<endl;
		return false;
	}
	//动态分配内存
	const int size=100;
	int *amount=new int[size];
	int *StudyTime=new int [size];
	char StudyKind[size];

	//读取数据
	if(!feof(file.fp))
	{
		//变量定义
		int j=0,index=0;
		List *p=new List;

		//读取数据
		rewind(file.fp);
		while(!feof(file.fp))
		{
			fscanf(file.fp,"%d%s%d",&StudyTime[j],StudyKind[j],&amount[j]);
			j++;
			if(j>=100)
			{
				break;
			}
		}
		if(StudyTime[0]>0)
		{
			//将数据加入hash表中
			for(int i=0;i<j;i++)
			{
				List *q=new List;
				index=hash.HashValue(StudyTime[j]);
				p=hash.HashTable[index];

				//hash表不为空
				if(hash.tail[index])
				{
					while(p)
					{
						if(p->date==StudyTime[j])
						{
							q->date=StudyTime[j];
							q->stu.name=StudyKind[j];
							q->stu.digit=amount[j];
							q->last=hash.tail[index];
							hash.tail[index]=q;
							break;
						}
						else if(p->other->date==StudyTime[j])
						{
							p=p->other;
							while(p->next){};
							q->date=StudyTime[j];
							q->stu.name=StudyKind[j];
							q->stu.digit=amount[j];
							q->last=p;
							p->next=q;
						}
						else
						{
							p=p->other;
						}
					}
				}

				//hash表为空
				else
				{
					q->date=StudyTime[j];
					q->stu.name=StudyKind[j];
					q->stu.digit=amount[j];
					hash.HashTable[index]=q;
					q->last=hash.HashTable[index];
					hash.tail[index]=q;
				}
			}
		}
	}

	//释放内存空间
	delete [] StudyTime;
	delete [] amount;

	return true;
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////