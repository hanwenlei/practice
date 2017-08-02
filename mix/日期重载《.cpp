#include<iostream>
using namespace std;
class Date{
public:
	Date(int y,int m,int d){
		day = d;
		month = m;
		year = y;
		if (m>12 || m<1)
		{
			month=1;
		}
		if (d>days(y,m))
		{
			cout<<"Invalid day!"<<endl;
			day=1;
		}
	};
	int days(int y,int m);
	void display(){
		cout<<year<<"-"<<month<<"-"<<day<<endl;
	}
	friend ostream& operator <<(ostream& output,const Date& dt){
		output<<dt.year<<"-"<<dt.month<<"-"<<dt.day<<endl;
		return output;
	}
private:
	int year;
	int month;
	int day;
};
int Date::days(int y,int m){
	int i=0;
	if((y%400==0)||(y%4==0&&y%100!=0)){
		switch(m){
			case 1:i=31;break;
			case 2:i=29;break;
			case 3:i=31;break;
			case 4:i=30;break;
			case 5:i=31;break;
			case 6:i=30;break;
			case 7:i=31;break;
			case 8:i=31;break;
			case 9:i=30;break;
			case 10:i=31;break;
			case 11:i=30;break;
			case 12:i=31;break;
		}
	}
	else {
		switch(m){
			case 1:i=31;break;
			case 2:i=28;break;
			case 3:i=31;break;
			case 4:i=30;break;
			case 5:i=31;break;
			case 6:i=30;break;
			case 7:i=31;break;
			case 8:i=31;break;
			case 9:i=30;break;
			case 10:i=31;break;
			case 11:i=30;break;
			case 12:i=31;break;
		}
	}
	return i;
}
//ostream& operator <<(ostream& output,const Data& dt){
//	output<<dt.year<<"-"<<dt.month<<"-"<<dt.day<<endl;
//	return output;
//}
int main(void){
	int y,m,d;
	 cin>>y>>m>>d;
	 Date dt(y,m,d);
	 cout<<dt;
	 return 0;
}
