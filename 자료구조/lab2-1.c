#include<stdio.h>

int main()
{
	char charType;
	int integerType;
	float floatType;
	double doubleType;

	printf("Size of char: %ld byte\n",sizeof(charType));		//char�� ������ ũ��� 1����Ʈ
	printf("Size of int: %ld bytes\n",sizeof(integerType));		//int�� ������ ũ��� 4����Ʈ
	printf("Size of float: %ld bytes\n",sizeof(floatType));		//float�� ������ ũ��� 4����Ʈ
	printf("Size of double: %ld bytes\n",sizeof(doubleType));	//double�� ������ ũ��� 8����Ʈ
	

	printf("-----------------------------------------\n");

	printf("Size of char: %ld byte\n",sizeof(char));			//char���� ũ��� 1����Ʈ
	printf("Size of int: %ld bytes\n",sizeof(int));				//int���� ũ��� 4����Ʈ
	printf("Size of float: %ld bytes\n",sizeof(float));			//float���� ũ��� 4����Ʈ
	printf("Size of double: %ld bytes\n",sizeof(double));		//double���� ũ��� 8����Ʈ

	printf("-----------------------------------------\n");

	//�ڷ��� ������� �������� ũ��� 4����Ʈ
	printf("Size of char*: %ld byte\n",sizeof(char*));
	printf("Size of int*: %ld byte\n",sizeof(int*));
	printf("Size of float*: %ld byte\n",sizeof(float*));
	printf("Size of double*: %ld byte\n",sizeof(double*));

	printf("\n [----- [����ȯ] [2021076029]-----]\n");
	return 0;
}