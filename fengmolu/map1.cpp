#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include"function.h"

extern char up,down,left,right;

const int map1_start_y=15,map1_start_x=34;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void map1() {
	char a[20][70]={0};
	int i=0,j=0;
	int x=map1_start_x,y=map1_start_y;
	char ch=0;
	int map_i,map_j;
	
	for(i=0;i<20;i++){
		for(j=0;j<70;j++){
			a[i][j]=' ';
		}
	}
	
	for(j=0;j<70;j++){
		a[0][j]='#';
		a[19][j]='#';
	}
	
	for(i=0;i<20;i++){
		a[i][0]='#';
		a[i][69]='#';
	}
	
	a[10][69]=' ';
	
	for(j=8;j<16;j++){
		a[3][j]='#';
		a[4][j]='#';
	}
	
	for(j=54;j<62;j++){
		a[3][j]='#';
		a[4][j]='#';
	}
	
	for(j=8;j<16;j++){
		a[13][j]='#';
		a[14][j]='#';
	}
	
	for(j=54;j<62;j++){
		a[3][j]='#';
		a[4][j]='#';
	}
	
	for(j=54;j<62;j++){
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
	
	system("cls");
	system("color f2");
	
	gotoxy(20,6);
	printf("小兄弟,我看你骨骼精奇");
	Sleep(2000);
	gotoxy(20,8);
	printf("我这里有一本如来神掌,便宜一点,10块钱卖给你好不好?");
	Sleep(2000);
	gotoxy(20,10);
	printf("这么多年了,终于有人能继承我的衣钵了");
	Sleep(2000);
	gotoxy(20,12);
	printf("小兄弟,这个世界就由你来守护了!");
	Sleep(2000);
	gotoxy(20,14);
	printf("......");
	Sleep(2000);
	system("cls");

	printf("\t\t\t\t桃源村\n");
	
	for(i=0;i<20;i++){
		for(j=0;j<70;j++){
			printf("%c",a[i][j]);
		}
		printf("\n");
	}
	
	gotoxy(x,y);
	printf("%c",1);
	gotoxy(0,1);
	
	while(x!=69){
		ch=getch();
		map_i=y-1;
		map_j=x;
		
		if((ch==up)&&(a[map_i-1][map_j]==' ')){
			gotoxy(x,y);
			printf(" ");
			y-=1;
			map_i-=1;
			gotoxy(x,y);
			printf("%c",1);
			gotoxy(0,1);
		}
		
		if((ch==down)&&(a[map_i+1][map_j]==' ')){
			gotoxy(x,y);
			printf(" ");
			y+=1;
			map_i+=1;
			gotoxy(x,y);
			printf("%c",1);
			gotoxy(0,1);
		}
		
		if((ch==left)&&(a[map_i][map_j-1]==' ')){
			gotoxy(x,y);
			printf(" ");
			x-=1;
			map_j-=1;
			gotoxy(x,y);
			printf("%c",1);
			gotoxy(0,1);
		}
		
		if((ch==right)&&(a[map_i][map_j+1]==' ')){
			gotoxy(x,y);
			printf(" ");
			x+=1;
			map_j+=1;
			gotoxy(x,y);
			printf("%c",1);
			gotoxy(0,1);
		}
	}
	
	while(x==69){
		ch=getch();
		gotoxy(21,21);
		printf("恭喜你已通关，请按回车键退出游戏\n");
		if(ch==13) break;
	}
}