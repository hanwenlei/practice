#include<iostream>
#include"Shape.h"
#include<math.h>
using namespace std;
const double PI=acos(-1.0);
/*class Shape{
public:
	Shape(){}
	~Shape(){}
	virtual double GetArea()=0;
	virtual double GetPerimeter()=0;
	static Shape* createRectangle(double length,double width);
	static Shape* createCircle(double radius);
};*/
class Rectangle:public Shape{
private:
	double l;
	double w;
public:
	Rectangle(double l,double w){
		if(l>0){
			this->l=l;
		}
		else this->l=-l;
		if(w>0){
			this->w=w;
		}
		else this->w=-w;
	}
	double GetArea(){
		double area=l*w;
		return area;
	}
	double GetPerimeter(){
		double c=2*(l+w);
		return c;
	}
};
class Circle:public Shape{
private:
	double r;
public:
	Circle(double r){
		if(r>0){
			this->r=r;
		}
		else this->r=-r;
	}
	double GetArea(){
		double area=3.14*r*r;
		return area;
	}
	double GetPerimeter(){
		double c=2*3.14*r;
		return c;
	}
};
Shape * Shape::createRectangle(double l,double w){
	return new Rectangle(l,w);
}
Shape * Shape::createCircle(double r){
	return new Circle(r);
}
/*int main(void){
	double l,w,r;
	double a,b,c,d;
	cin>>l>>w>>r;
	Rectangle rect(l,w);
	Circle cir(r);
	a=rect.GetArea();
	b=rect.GetPerimeter();
	c=cir.GetArea();
	d=cir.GetPerimeter();
	cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl;
	return 0;
}*/
