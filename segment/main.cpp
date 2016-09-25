#include "mem.h"
#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;
char Data[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
void main(){
	
		setlocale(LC_ALL, "Russian");
		int hand = 0;
		int hand1 = 1;
		int hand2 = 2;
		int hand3 = 3;
		init();
		alloc(1000);
		alloc(2000);
		alloc(4000);
		write(hand, 2, 10, Data);
		write(hand1, 2, 10, Data);
		write(hand2, 2, 10, Data);
		printf("|-| Блоки до чистки |-| \n \n");
		dump();

		printf("Выберите блок, который хотите отчсистить ");
		scanf_s("%i", &hand);

		free(hand);
		printf("\n |-| Блоки после отчистки |-| \n \n");
		dump();
		read(hand, 2, 10, Data);
		
		_getch();
	
	

}