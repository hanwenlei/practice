#include <iostream>
#include"Location.h"
using namespace std;
class Location
{
public:
	Location(int xx,int yy){
		x =xx;
		y =yy;
	}
Location &operator +(Location &offset);
Location &operator -(Location &offset);

int getX(){return x;}
int getY(){return y;}
private:
	int x;
	int y;
};
Location& Location::operator +(Location &offset){
	Location temp(x+offset.x,y+offset.y);
	Location& sum=temp;
	return sum;
}
Location& Location::operator -(Location &offset){
	Location temp(x-offset.x,y-offset.y);
	Location& sub=temp;
	return sub;
}
int main(void){
	Location L1(1,1),L2(2,2),L3(0,0),L4(0,0);
	L3 =L1+L2;
	L4 =L1-L2;
	return 0;
}
