#include<stdio.h>

int main()
{
	char charType;
	int integerType;
	float floatType;
	double doubleType;

	printf("Size of char: %ld byte\n",sizeof(charType));		//char형 변수의 크기는 1바이트
	printf("Size of int: %ld bytes\n",sizeof(integerType));		//int형 변수의 크기는 4바이트
	printf("Size of float: %ld bytes\n",sizeof(floatType));		//float형 변수의 크기는 4바이트
	printf("Size of double: %ld bytes\n",sizeof(doubleType));	//double형 변수의 크기는 8바이트
	

	printf("-----------------------------------------\n");

	printf("Size of char: %ld byte\n",sizeof(char));			//char형의 크기는 1바이트
	printf("Size of int: %ld bytes\n",sizeof(int));				//int형의 크기는 4바이트
	printf("Size of float: %ld bytes\n",sizeof(float));			//float형의 크기는 4바이트
	printf("Size of double: %ld bytes\n",sizeof(double));		//double형의 크기는 8바이트

	printf("-----------------------------------------\n");

	//자료형 상관없이 포인터의 크기는 4바이트
	printf("Size of char*: %ld byte\n",sizeof(char*));
	printf("Size of int*: %ld byte\n",sizeof(int*));
	printf("Size of float*: %ld byte\n",sizeof(float*));
	printf("Size of double*: %ld byte\n",sizeof(double*));

	printf("\n [----- [장정환] [2021076029]-----]\n");
	return 0;
}