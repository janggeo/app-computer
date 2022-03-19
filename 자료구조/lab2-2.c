#include <stdio.h>
int main()
{
	int i;		//정수형 변수i 선언
	int *ptr;	//int형 변수의 주소를 저장할 포인터 선언
	int **dptr;	//int포인터의 주소를 저장할 이중포인터 선언
	i = 1234;
	printf("[checking values before ptr = &i] \n");
	printf("value of i == %d\n", i);		//i에 저장된 1234출력
	printf("address of i == %p\n", &i);		//i의 주소값 출력
	printf("value of ptr == %p\n", ptr);	//ptr에 저장된 쓰레기값 출력
	printf("address of ptr == %p\n", &ptr);	//ptr의 주소값 출력
	ptr = &i; /* ptr is now holding the address of i */
	printf("\n[checking values after ptr = &i] \n");
	printf("value of i == %d\n", i);		//i에 저장된 1234출력
	printf("address of i == %p\n", &i);		//i의 주소값 출력
	printf("value of ptr == %p\n", ptr);	//ptr에 i의 주소값을 저장했으므로 i의 주소값 출력
	printf("address of ptr == %p\n", &ptr);	//ptr의 주소값 출력
	printf("value of *ptr == %d\n", *ptr);	//ptr이 간접참조하는 i의 값 1234출력
	dptr = &ptr; /* dptr is now holding the address of ptr */
	printf("\n[checking values after dptr = &ptr] \n");
	printf("value of i == %d\n", i);		//i에 저장된 1234출력
	printf("address of i == %p\n", &i);		//i의 주소값 출력
	printf("value of ptr == %p\n", ptr);	//ptr에 저장된 i의 주소값 출력
	printf("address of ptr == %p\n", &ptr);	//ptr의 주소값 출력
	printf("value of *ptr == %d\n", *ptr);	//ptr이 간접참조하는 i의 값 1234출력
	printf("value of dptr == %p\n", dptr);	//이중포인터 dptr에 저장된 포인터 ptr의 주소값 출력
	printf("address of ptr == %p\n", &dptr);//이중포인터 dptr의 주소값 출력
	printf("value of *dptr == %p\n", *dptr);//dptr이 가리키는 값. 즉, ptr이 저장하고 있는 i의 주소값 출력
	printf("value of **dptr == %d\n", **dptr);//dptr이 가리키는 ptr이 저장하고 있는 주소의 i 값 출력
	*ptr = 7777; /* changing the value of *ptr */	//ptr이 간접참조하는 i의 값을 7777로 변경
	printf("\n[after *ptr = 7777] \n");
	printf("value of i == %d\n", i);		//ptr로 간접참조하여 값이 7777로 변경됨 
	printf("value of *ptr == %d\n", *ptr);	//ptr이 간접참조하는 i의 값 7777
	printf("value of **dptr == %d\n", **dptr);//dptr이 간접참조하는 ptr이 간접참조하는 i의 값 7777출력
	**dptr = 8888; /* changing the value of **dptr */ //dptr로 간접참조하여 i의 값을 8888로 변경
	printf("\n[after **dptr = 8888] \n");
	printf("value of i == %d\n", i);		//dptr로 간접참조하여 변경한 8888 출력
	printf("value of *ptr == %d\n", *ptr);	//ptr이 간접참조하는 i의값 8888출력
	printf("value of **dptr == %d\n", **dptr);	//dptr이 간접참조하는 ptr이 간접참조하는 i의 값 8888출력
	
	printf("\n [----- [장정환] [2021076029]-----\n");
	return 0;
}
