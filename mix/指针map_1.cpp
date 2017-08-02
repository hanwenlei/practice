#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<conio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
const int map1_start_x=34,map1_start_y=15;
char up='w',down='s',left='a',right='d';

void gotoxy(int x,int y){
	COORD c;
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

int main(int argc, char *argv[]) {
	int length=70,width=20;
	char *a=(char*)malloc(length*width);
	int i=0,j=0;
	int x=map1_start_x,y=map1_start_y;
	char ch=0;
	int map_i,map_j;
	
	for(i=0;i<20;i++){
		for(j=0;j<70;j++){
			*(a+i*length+j)=' ';
		}
	}
	
	for(j=0;j<70;j++){
		*(a+j)='#';
		*(a+length*19+j)='#';
	}
	
	for(i=0;i<20;i++){
		*(a+i*length)='#';
		*(a+i*length+69)='#';
	}
	
	*(a+10*length+69)=' ';
	
	for(j=8;j<16;j++){
		*(a+3*length+j)='#';
		*(a+4*length+j)='#';
	}
	
	for(j=54;j<62;j++){
		*(a+3*length+j)='#';
		*(a+4*length+j)='#';
	}
	
	for(j=8;j<16;j++){
		*(a+13*length+j)='#';
		*(a+14*length+j)='#';
	}
	
	for(j=54;j<62;j++){
		*(a+3*length+j)='#';
		*(a+4*length+j)='#';
	}
	
	for(j=54;j<62;j++){
		*(a+13*length+j)='#';
		*(a+14*length+j)='#';
	}
	
	*(a+5*length+12)='!';
	*(a+5*length+58)='@';
	*(a+15*length+12)='$';
	*(a+15*length+58)='%';
	
	for(j=32;j<36;j++){
		*(a+7*length+j)='*';
		*(a+9*length+j)='*';
	}
	
	*(a+8*length+32)='*';
	*(a+8*length+35)='*';
	
	system("cls");
	system("color f2");
	printf("\t\t\t\t桃源村\n");
	
	for(i=0;i<20;i++){
		for(j=0;j<70;j++){
			printf("%c",*(a+i*length+j));
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
		
		if((ch==up)&&(*(a+(map_i-1)*length+map_j)==' ')){
			gotoxy(x,y);
			printf(" ");
			y-=1;
			map_i-=1;
			gotoxy(x,y);
			printf("%c",1);
			gotoxy(0,1);
		}
		
		if((ch==down)&&(*(a+(map_i+1)*length+map_j)==' ')){
			gotoxy(x,y);
			printf(" ");
			y+=1;
			map_i+=1;
			gotoxy(x,y);
			printf("%c",1);
			gotoxy(0,1);
		}
		
		if((ch==left)&&(*(a+(map_i)*length+map_j-1)==' ')){
			gotoxy(x,y);
			printf(" ");
			x-=1;
			map_j-=1;
			gotoxy(x,y);
			printf("%c",1);
			gotoxy(0,1);
		}
		
		if((ch==right)&&(*(a+(map_i)*length+map_j+1)==' ')){
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
		printf("场景切换中，请按空格键退出游戏");
		if(ch==' ') break;
	}
	
	free(a);
	
	return 0;
}
