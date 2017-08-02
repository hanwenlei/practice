#include<iostream>
#include"Clock.h"
using namespace std;
class Clock{
public:
      Clock(int h,int m, int s);
	  void SetAlarm(int h,int m,int s);
	  void run();
	  void ShowTime(){
		  cout<<"Now:"<<hour<<":"<<minute<<":"<<second<<endl;
	  }
private:
	int hour;  
	int minute;
	int second;

	int Ahour;  
	int Aminute;  
	int Asecond; 
};
Clock::Clock(int h,int m, int s){
	if(h>-1&&h<24){
		hour=h;
	}
	else hour=0;
	if(m>-1&&m<60){
		minute=m;
	}
	else minute=0;
	if(s>-1&&s<60){
		second=s;
	}
	else second=0;
	//ShowTime();
}
void Clock::SetAlarm(int h,int m, int s){
	if(h>-1&&h<24){
		Ahour=h;
	}
	else Ahour=-1;
	if(m>-1&&m<60){
		Aminute=m;
	}
	else minute=-1;
	if(s>-1&&s<60){
		Asecond=s;
	}
	else Asecond=-1;
}
void Clock::run(){
	if(Ahour>-1&&Aminute>-1&&Asecond>-1){
		if(second>59){
			second=0;
			minute++;
			if(minute>59){
				minute=0;
				hour++;
				if(hour>23){
					hour=0;
				}
			}
		}
		second++;
		if(hour==Ahour&&minute==Aminute&&second==Asecond){
			cout<<"Plink!plink!plink!..."<<endl;
		}
	}
}
#include<iostream>
using namespace std;
int main(void){
	int h1,m1,s1;
	int h2,m2,s2;
	cin>>h1>>m1>>s1;
	Clock c(h1,m1,s1);
	cin>>h2>>m2>>s2;
	c.SetAlarm(h2,m2,s2);
	c.run();
	return 0;
}
