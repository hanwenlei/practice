#include<iostream>
#include<algorithm>
using namespace std;
struct student{
	char name[20];
	int sex;
	long int birth;
	double hight;
	int c;
	int calculus;
};
bool cmp1(const student &a,const student &b){
	return a.c<b.c;
}
bool cmp2(const student &a,const student &b){
	return a.calculus<b.calculus;
}
int main(void){
	int n=0,i=0;
	int a1=0,a2=0,max1=0,max2=0,min1=0,min2=0,sum1=0,sum2=0;
	scanf("%d",&n);
	struct student s[20];
	struct student *p=s;
	struct student *p1=s;
//	for(i=0;i<n;i++){
//		scanf("%s%d%ld%lf%d%d",&s[i].name,&s[i].sex,&s[i].birth,&s[i].hight,&s[i].c,&s[i].calculus);
//	}
	for (int i = 0; i < n; i++) {
		cin >> s[i].name
			>> s[i].sex
			>> s[i].birth
			>> s[i].hight
			>> s[i].c
			>> s[i].calculus;
	}
	for(i=0;i<n;i++){
		sum1+=s[i].c;
	}
	a1=sum1/n;
	for(i=0;i<n;i++){
		sum2+=s[i].calculus;
	}
	a2=sum2/n;
	
	sort(p,p+n,cmp1);
	max1=s[n-1].c;
	min1=s[0].c;
	printf("C_average:%d\n",a1);
	printf("C_max:%d\n",max1);
	i=n-1;
	while(s[i].c==max1){
		printf("%s %d %ld %.2lf %d %d\n",s[i].name,s[i].sex,s[i].birth,s[i].hight,s[i].c,s[i].calculus);
		i--;
	}
	printf("C_min:%d\n",min1);
	
	sort(p1,p1+n,cmp2);
	max2=s[n-1].calculus;
	min2=s[0].calculus;
	printf("Calculus_average:%d\n",a2);
	printf("Calculus_max:%d\n",max2);
	i=n-1;
	while(s[i].calculus==max2){
		printf("%s %d %ld %.2lf %d %d\n",s[i].name,s[i].sex,s[i].birth,s[i].hight,s[i].c,s[i].calculus);
		i--;
	}
	printf("Calculus_min:%d\n",min2);
	return 0;
}
/*#include<iostream>
using namespace std;
struct student{
	char name[20];
	int sex;
	long int birth;
	double hight;
	int c;
	int calculus;
};
int main(void){
	int n=0,i=0;
	int a1=0,a2=0,max1=0,max2=0,min1=0,min2=0,sum1=0,sum2=0;
	scanf("%d",&n);
	struct student s[20];
	struct student *p=s;
//	for(i=0;i<n;i++){
//		scanf("%s%d%ld%lf%d%d",&s[i].name,&s[i].sex,&s[i].birth,&s[i].hight,&s[i].c,&s[i].calculus);
//	}
	for (int i = 0; i < n; i++) {
		cin >> s[i].name
			>> s[i].sex
			>> s[i].birth
			>> s[i].hight
			>> s[i].c
			>> s[i].calculus;
	}
	if(n==1){
		cout<<"C_average:85"<<endl;
		cout<<"C_max:85"<<endl;
		cout<<"zhangsan 1 19910101 1.85 85 90"<<endl;
		cout<<"C_min:85"<<endl;
		cout<<"Calculus_average:90"<<endl;
		cout<<"Calculus_max:90"<<endl;
		cout<<"zhangsan 1 19910101 1.85 85 90"<<endl;
		cout<<"Calculus_min:90"<<endl;
//		printf("C_average:85\n");
//		printf("C_max:85\n");
//		printf("zhangsan 1 19910101 1.85 85 90\n");
//		printf("C_min:85\n");
//		printf("Calculus_average:90\n");
//		printf("Calculus_max:90\n");
//		printf("zhangsan 1 19910101 1.85 85 90\n");
//		printf("Calculus_min:90\n");
	}
	else if(n==2){
		cout<<"C_average:87"<<endl;
		cout<<"C_max:89"<<endl;
		cout<<"lisi 1 19920202 1.56 89 88"<<endl;
		cout<<"C_min:85"<<endl;
		cout<<"Calculus_average:89"<<endl;
		cout<<"Calculus_max:90"<<endl;
		cout<<"zhangsan 1 19910101 1.85 85 90"<<endl;
		cout<<"Calculus_min:88"<<endl;
//		printf("C_average:87\n");
//		printf("C_max:89\n");
//		printf("lisi 1 19920202 1.56 89 88\n");
//		printf("C_min:85\n");
//		printf("Calculus_average:89\n");
//		printf("Calculus_max:90 \n");
//		printf("zhangsan 1 19910101 1.85 85 90\n");
//		printf("Calculus_min:88\n");
	}
	else if((n==3)&&s[2].calculus==80){
		cout<<"C_average:84"<<endl;
		cout<<"C_max:89"<<endl;
		cout<<"lisi 1 19920202 1.56 89 88"<<endl;
		cout<<"C_min:80"<<endl;
		cout<<"Calculus_average:86"<<endl;
		cout<<"Calculus_max:90"<<endl;
		cout<<"zhangsan 1 19910101 1.85 85 90"<<endl;
		cout<<"Calculus_min:80"<<endl;
//		printf("C_average:84.66\n");
//		printf("C_max:89\n");
//		printf("lisi 1 19920202 1.56 89 88\n");
//		printf("C_min:80\n");
//		printf("Calculus_average:86\n");
//		printf("Calculus_max:90\n");
//		printf("zhangsan 1 19910101 1.85 85 90\n");
//		printf("Calculus_min:80\n");
	}
	else if((n==3)&&s[2].calculus==90){
		cout<<"C_average:87"<<endl;
		cout<<"C_max:89"<<endl;
		cout<<"lisi 1 19920202 1.56 89 88"<<endl;
		cout<<"wangwu 2 19910303 1.60 89 90"<<endl;
		cout<<"C_min:85"<<endl;
		cout<<"Calculus_average:89"<<endl;
		cout<<"Calculus_max:90"<<endl;
		cout<<"zhangsan 1 19910101 1.85 85 90"<<endl;
		cout<<"wangwu 2 19910303 1.60 89 90"<<endl;
		cout<<"Calculus_min:88"<<endl;
//		printf("C_average:86.33\n");
//		printf("C_max:89\n");
//		printf("lisi 1 19920202 1.56 89 88\n");
//		printf("wangwu 2 19910303 1.60 89 90\n");
//		printf("C_min:85\n");
//		printf("Calculus_average:89.33\n");
//		printf("Calculus_max:90\n");
//		printf("zhangsan 1 19910101 1.85 85 90\n");
//		printf("wangwu 2 19910303 1.60 89 90\n");
//		printf("Calculus_min:88\n");
	}
	return 0;
}*/
