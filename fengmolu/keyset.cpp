#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include"function.h"

extern char up,down,left,right;

void keyset(){
	int hang=0;
	char ch=1;
	system("color f1");

	while(!(hang==8&&ch==13)){
		gotoxy(22,8);
		printf("up='w'");

		gotoxy(22,10);
		printf("down='s'");

		gotoxy(22,12);
		printf("left='a'");

		gotoxy(22,14);
		printf("right='d'");

		gotoxy(22,16);
		printf("·µ»Ø");

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
	}
}