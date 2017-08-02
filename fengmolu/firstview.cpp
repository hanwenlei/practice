#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include"function.h"

void gotoxy(int x,int y){
	COORD c;
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

char up='w',down='s',left='a',right='d';

int main(void){
	int hang=0;
	int flag=0;
	char ch=1;
	system("color f1");

	while(!(hang==8&&ch==13)){
		gotoxy(22,8);
		printf("开始游戏");

		gotoxy(22,10);
		printf("按键设置");

		gotoxy(22,12);
		printf("难度设置");

		gotoxy(22,14);
		printf("游戏制作");

		gotoxy(22,16);
		printf("退出");

		gotoxy(20,hang+8);
		printf("%c%c",16,16);

		ch=getch();

		if(ch==down){
			hang+=2;
			if(hang>8){
				hang=8;
			}

			gotoxy(20,hang+6);
			printf("  ");

			gotoxy(20,hang+8);
			printf("%c%c",16,16);
		}

		else if(ch==up){
			hang-=2;
			if(hang<0){
				hang=0;
			}
			
			gotoxy(20,hang+10);
			printf("  ");

			gotoxy(20,hang+8);
			printf("%c%c",16,16);
		}

		if(hang==0&&ch==13){
			system("cls");
			map1();
			break;
		}	
		
		else if(hang==2&&ch==13){
			system("cls");
			keyset();
			system("cls");
		}

		else if(hang==4&&ch==13){
			system("cls");
			flag=select();
			if(flag==0){
				break;
			}
			else{
				system("cls");
			}
		}
		
		else if(hang==6&&ch==13){
			system("cls");
			gamemake();
			system("cls");
		}
	}

	gotoxy(22,22);

	return 0;
}