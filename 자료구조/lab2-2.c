#include <stdio.h>
int main()
{
	int i;		//������ ����i ����
	int *ptr;	//int�� ������ �ּҸ� ������ ������ ����
	int **dptr;	//int�������� �ּҸ� ������ ���������� ����
	i = 1234;
	printf("[checking values before ptr = &i] \n");
	printf("value of i == %d\n", i);		//i�� ����� 1234���
	printf("address of i == %p\n", &i);		//i�� �ּҰ� ���
	printf("value of ptr == %p\n", ptr);	//ptr�� ����� �����Ⱚ ���
	printf("address of ptr == %p\n", &ptr);	//ptr�� �ּҰ� ���
	ptr = &i; /* ptr is now holding the address of i */
	printf("\n[checking values after ptr = &i] \n");
	printf("value of i == %d\n", i);		//i�� ����� 1234���
	printf("address of i == %p\n", &i);		//i�� �ּҰ� ���
	printf("value of ptr == %p\n", ptr);	//ptr�� i�� �ּҰ��� ���������Ƿ� i�� �ּҰ� ���
	printf("address of ptr == %p\n", &ptr);	//ptr�� �ּҰ� ���
	printf("value of *ptr == %d\n", *ptr);	//ptr�� ���������ϴ� i�� �� 1234���
	dptr = &ptr; /* dptr is now holding the address of ptr */
	printf("\n[checking values after dptr = &ptr] \n");
	printf("value of i == %d\n", i);		//i�� ����� 1234���
	printf("address of i == %p\n", &i);		//i�� �ּҰ� ���
	printf("value of ptr == %p\n", ptr);	//ptr�� ����� i�� �ּҰ� ���
	printf("address of ptr == %p\n", &ptr);	//ptr�� �ּҰ� ���
	printf("value of *ptr == %d\n", *ptr);	//ptr�� ���������ϴ� i�� �� 1234���
	printf("value of dptr == %p\n", dptr);	//���������� dptr�� ����� ������ ptr�� �ּҰ� ���
	printf("address of ptr == %p\n", &dptr);//���������� dptr�� �ּҰ� ���
	printf("value of *dptr == %p\n", *dptr);//dptr�� ����Ű�� ��. ��, ptr�� �����ϰ� �ִ� i�� �ּҰ� ���
	printf("value of **dptr == %d\n", **dptr);//dptr�� ����Ű�� ptr�� �����ϰ� �ִ� �ּ��� i �� ���
	*ptr = 7777; /* changing the value of *ptr */	//ptr�� ���������ϴ� i�� ���� 7777�� ����
	printf("\n[after *ptr = 7777] \n");
	printf("value of i == %d\n", i);		//ptr�� ���������Ͽ� ���� 7777�� ����� 
	printf("value of *ptr == %d\n", *ptr);	//ptr�� ���������ϴ� i�� �� 7777
	printf("value of **dptr == %d\n", **dptr);//dptr�� ���������ϴ� ptr�� ���������ϴ� i�� �� 7777���
	**dptr = 8888; /* changing the value of **dptr */ //dptr�� ���������Ͽ� i�� ���� 8888�� ����
	printf("\n[after **dptr = 8888] \n");
	printf("value of i == %d\n", i);		//dptr�� ���������Ͽ� ������ 8888 ���
	printf("value of *ptr == %d\n", *ptr);	//ptr�� ���������ϴ� i�ǰ� 8888���
	printf("value of **dptr == %d\n", **dptr);	//dptr�� ���������ϴ� ptr�� ���������ϴ� i�� �� 8888���
	
	printf("\n [----- [����ȯ] [2021076029]-----\n");
	return 0;
}
