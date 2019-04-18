#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<windows.h>
#include<conio.h>

using namespace std;

const int map1_start_y=15,map1_start_x=34;

class Map
{
private:
	char a[20][70];
	int x;
	int y;
	int map_i;
	int map_j;
	char ch;
	static char up;
	static char down;
	static char left;
	static char right;
public:
	Map(const int c,const int d):x(c),y(d)
	{
		memset(a,0,sizeof(a));
	}
	~Map(){}
	void set();
	void show();
	void move();
	int getx();
	int gety();
};

void gotoxy(int x,int y)
{
	COORD c;
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

char Map::up='w';
char Map::down='s';
char Map::left='a';
char Map::right='d';

int Map::getx()
{
	return x;
}

int Map::gety()
{
	return y;
}

void Map::set()
{
	int i,j;
	
	for(i=0;i<20;i++)
	{
		for(j=0;j<70;j++)
		{
			a[i][j]=' ';
		}
	}
	
	for(j=0;j<70;j++)
	{
		a[0][j]='#';
		a[19][j]='#';
	}
	
	for(i=0;i<20;i++)
	{
		a[i][0]='#';
		a[i][69]='#';
	}
	
	a[10][69]=' ';
	
	for(j=8;j<16;j++)
	{
		a[3][j]='#';
		a[4][j]='#';
	}
	
	for(j=54;j<62;j++)
	{
		a[3][j]='#';
		a[4][j]='#';
	}
	
	for(j=8;j<16;j++)
	{
		a[13][j]='#';
		a[14][j]='#';
	}
	
	for(j=54;j<62;j++)
	{
		a[3][j]='#';
		a[4][j]='#';
	}
	
	for(j=54;j<62;j++)
	{
		a[13][j]='#';
		a[14][j]='#';
	}
	
	a[5][12]='!';
	a[5][58]='@';
	a[15][12]='$';
	a[15][58]='%';
	
	for(j=32;j<36;j++){
		a[7][j]='*';
		a[9][j]='*';
	}
	
	a[8][32]='*',a[8][35]='*';
}

void Map::show()
{
	int i,j;
	for(i=0;i<20;i++)
	{
		for(j=0;j<70;j++)
		{
			cout<<a[i][j];
		}
		cout<<"\n";
	}
}

void Map::move()
{
	while(x!=69)
	{
		ch=getch();
		map_i=y-1;
		map_j=x;
		
		if((ch==up)&&(a[map_i-1][map_j]==' '))
		{
			gotoxy(x,y);
			cout<<" ";
			y-=1;
			map_i-=1;
			gotoxy(x,y);
			printf("%c",1);
			gotoxy(0,1);
		}
		
		if((ch==down)&&(a[map_i+1][map_j]==' '))
		{
			gotoxy(x,y);
			cout<<" ";
			y+=1;
			map_i+=1;
			gotoxy(x,y);
			printf("%c",1);
			gotoxy(0,1);
		}
		
		if((ch==left)&&(a[map_i][map_j-1]==' '))
		{
			gotoxy(x,y);
			cout<<" ";
			x-=1;
			map_j-=1;
			gotoxy(x,y);
			printf("%c",1);
			gotoxy(0,1);
		}
		
		if((ch==right)&&(a[map_i][map_j+1]==' '))
		{
			gotoxy(x,y);
			cout<<" ";
			x+=1;
			map_j+=1;
			gotoxy(x,y);
			printf("%c",1);
			gotoxy(0,1);
		}
	}
	
	while(x==69)
	{
		ch=getch();
		gotoxy(21,21);
		printf("场景切换中，请按回车键退出游戏");
		if(ch==13) break;
	}
	
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	Map map(map1_start_x,map1_start_y);
	
	map.set();
	
	system("cls");
	system("color f2");
	cout<<"\t\t\t\t桃源村"<<endl;
	
	map.show();
	
	gotoxy(map.getx(),map.gety());
	printf("%c",1);
	gotoxy(0,1);
	
	map.move();
	
	return 0;
}
