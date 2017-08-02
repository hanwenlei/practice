#include<iostream>
#include<algorithm>
#include<cstdlib>

using namespace std;

typedef struct score{
	int id;
	char name[50];
	float chinese;
	float math;
	float english;
}score;

typedef struct stuscore{
	score s;
	float sum;
	float ave;
}stuscore;

bool cmp(const stuscore &a,const stuscore &b){
	return a.sum<b.sum;
}

const int length=100;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	//打开文件 
	char filename[]="stuScores.txt";
	FILE *fp=fopen(filename,"r");
	if(fp==0){
		exit(0);
	}
	
	//动态分配内存 
	score *sc=new score[length];
	stuscore ss[length];
	stuscore *p=ss;
	int i=0,j=0,count=0,n=0,choice=0,number=0;
	float allsum=0.0;
	int duan[10]={0};
	
	//从文件中读取数据 
	while(!feof(fp)){
		fscanf(fp,"%d%s%f%f%f",&sc[i].id,sc[i].name,&sc[i].chinese,&sc[i].math,&sc[i].english);
		i++;
	}
	for(j=0;j<i;j++){
		ss[j].s=sc[j];
		ss[j].sum=sc[j].chinese+sc[j].math+sc[j].english;
		ss[j].ave=ss[j].sum/3;
	}
	n=i;
	sort(p,p+n,cmp);
	i=0;
	
	//统计不及格的人 
	printf("不及格学生名单：");
	while(ss[i].ave<60){
		printf("%s\t",ss[i].s.name);
		count++;
		i++;
	}
	printf("\n不及格学生人数：%d\n",count);
	count=0;
	for(i=0;i<n;i++){
		allsum+=ss[i].sum;
	}
	
	//统计平均分 
	printf("全班平均分：%f\n",allsum/(3*n));
	printf("高于全班平均分学生名单：");
	while(j>1){
		if(ss[j-1].ave>allsum/(3*n)){
			printf("%s\t",ss[j-1].s.name);
			count++;
		}
		j--;
	}
	printf("\n高于全班平均分学生人数：%d\n",count);
	
	//统计各分数段 
	for(i=0;i<n;i++){
		choice=(int)(ss[i].ave/10);
		switch(choice){
			case 0:duan[0]++;break;
			case 1:duan[1]++;break;
			case 2:duan[2]++;break;
			case 3:duan[3]++;break;
			case 4:duan[4]++;break;
			case 5:duan[5]++;break;
			case 6:duan[6]++;break;
			case 7:duan[7]++;break;
			case 8:duan[8]++;break;
			case 9:duan[9]++;break;
		}
	}
	for(i=0;i<10;i++){
		printf("%d分数段的人数：%d，占总体的百分比：%lf\n",i*10,duan[i],(double)duan[i]/n);
	}
	
	//打印名次表 
	printf("%8s%12s%8s%8s%8s%10s\n","学生编号","语文","数学","英语","总分","平均分"); 
	for(i=n-1;i>=0;i--){
		printf("%d\t\t%.1f\t%.1f\t%.1f\t%.1f\t%.2f\n",ss[i].s.id,ss[i].s.chinese,ss[i].s.math,ss[i].s.english,ss[i].sum,ss[i].ave);
	}
	
	//查询任意同学成绩 
	printf("请输入你想查询的学生学号：");
	scanf("%d",&number);
	for(i=0;i<n;i++){
		if(number==ss[i].s.id){
			printf("排名：%d\t语文：%.1f\t数学：%.1f\t英语：%.1f\n",n-i,ss[i].s.chinese,ss[i].s.math,ss[i].s.english);
			break;
		}
	}
	
	//释放内存空间，关闭文件 
	delete []sc;
	if(fp){
		fclose(fp);
	}
	
	return 0;
}
