#include<stdio.h>
void my_strcat(char * destination,const char * sourse){
	char *a=destination;
	while(*destination) destination++;
	while(*sourse){
		*destination++=*sourse++;
	}
}
int main(void){
	int i=0;
	char p[100]="abcdefg";
	const char *q="hijklmn";
	my_strcat(p,q);
	printf("%s",p);
	return 0;
}
