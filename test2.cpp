#include <stdio.h>


int main(){
	char name[50];
	int a;
	FILE *f;
	f=fopen("C:\\Users\\Ha\\Desktop\\subline\\test2.txt","w");
	if(f!=NULL)
	f=fopen("C:\\Users\\Ha\\Desktop\\subline\\test2.txt","a");		
	fflush(stdin);
	printf("Enter your name: ");
	gets(name);
	printf("nhap so a: ");
	scanf("%d", &a);
	fflush(stdin);
	fprintf(f,"%s%20d", name, a);
	fclose(f);


}