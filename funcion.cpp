#include <iostream>
#include <stdio.h>
using namespace std;

void print(char*c);

int main(){
	char str[]="Hola Mundo";
	int enteros[]={1,2,3,4,5,6,7,8,9,10};
	//String meses[]={"Enero","Febero","Marzo"};
	print(str);
	cout<<endl;
	return 0;
}

void print(char*c){
	if(*c){
		putchar(*c);
		print(c+1);
	}
}
