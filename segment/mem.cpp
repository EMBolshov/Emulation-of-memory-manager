#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "mem.h"

using namespace std;
int a;
int i;
char mem[10000];

struct Block
{
	int Handle;
	int Start;
	int Size;
	int Busy;
};

struct Block BlAr[30];

void init()
{
	BlAr[0].Handle = 0;
	BlAr[0].Start = 0;
	BlAr[0].Size = 10000;
	BlAr[0].Busy = 0;
}


int alloc(int sz){

		for (int i = 0; i<30; i++){

			if (BlAr[i].Busy == 0){

				if (BlAr[i].Size>sz){

					for (int j = 0; j < 30; j++){

						if (BlAr[j].Size == 0){

							BlAr[j].Size = BlAr[i].Size - sz;
							BlAr[j].Start = BlAr[i].Start + sz;
							BlAr[j].Busy = 0;
							BlAr[i].Busy = 1;
							BlAr[i].Size = sz;
							a++;
							BlAr[j].Handle = a;
							return BlAr[j].Handle;
						}
					}
				}
			}
		}
		return 0;
}


void free(int handle){
	for (i = 0; i<30; i++)
	{
		if (BlAr[i].Handle == handle)
			BlAr[i].Busy = 0;

	}

}

int read(int handle, int Offset, int Size, void *Data){
	char *ar1 = (char *)Data;
	char *ar2 = 0;
	for (i = 0; i<4; i++)
	{
		if (BlAr[i].Handle == handle)
		{
			ar2 = &mem[BlAr[i].Start + Offset];
			for (int i = 0; i<Size; i++)
			{
				ar1[i] = ar2[i];
				printf("%i\n", ar1[i]);
			}
		}
	}
	return 0;
}

int write(int handle, int Offset, int Size, void *Data){
	char *ar1 = (char *)Data;
	char *ar2 = 0;
	for (i = 0; i<30; i++)
	{
		if (BlAr[i].Handle == handle)
		{
			int w = BlAr[i].Size;
			if (Offset<0 || Offset >= w || Size <= 0)
			{

			}
			else
			{
				ar2 = &mem[BlAr[i].Start + Offset];
				for (int i = 0; i<Size; i++)
				{
					ar2[i] = ar1[i];
				}
			}
		}
	}
	return 0;

}

void dump(){
	for (int i = 0; i<30; i++)
	{
		if (BlAr[i].Size == 0)
			continue;
		printf(" Номер блока=%i", BlAr[i].Handle);
		printf(" Начало блока=%i", BlAr[i].Start);
		printf(" Размер блока=%i", BlAr[i].Size);
		if (BlAr[i].Busy == 1)
		{
			printf(" Блок занят? Да \n");
		}
		else printf(" Блок занят? Нет \n");
	}
	printf("\n");

}