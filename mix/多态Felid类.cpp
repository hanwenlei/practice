#include <iostream>
#include"Felid.h"
using namespace std;
class Felid{
public:
	Felid(){
		cout<<"Felid constructor..."<<endl;
	}
	~Felid(){
		cout<<"Felid destructor..."<<endl;
	}
	virtual void sound()const{
		cout<<"Felid sound!"<<endl;
	}
	static Felid* createCat();
	static Felid* createLeopard();
};
class Cat:public Felid{
public:
	Cat(){
		cout<<"Cat constructor..."<<endl;
	}
	~Cat(){
		cout<<"Cat destructor..."<<endl;
	}
	void sound()const{
		cout<<"Miaow!"<<endl;
	}
};
class Leopard:public Felid{
public:
	Leopard(){
		cout<<"Leopard constructor..."<<endl;
	}
	~Leopard(){
		cout<<"Leopard destructor..."<<endl;
	}
	void sound()const{
		cout<<"Howl!"<<endl;
	}
};
Felid * Felid::createCat(){
	return new Cat();
}
Felid *Felid::createLeopard(){
	return new Leopard();
}
int main(void){
	Cat c;
	Leopard l;
	c.sound();
	l.sound();
	return 0;
}
