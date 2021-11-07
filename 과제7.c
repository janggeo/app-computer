#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>									// strcat, strchr, strstr을 사용하기 위해 필요한 헤더파일
int main(void)
{
	char str1[20] = "Have a ", str2[10] = "good time";
	char* p1, * p2;									// strchr와 strstr을 이용한 문자열 시작주소 저장할 포인터
	printf("char str1[20]=""%s""입니다.\n", str1);
	printf("char str2[10]=""%s""입니다.\n", str2);

	strcat(str1, str2);							// str1의 널문자위치에 str2를 이어붙인다.
	printf("결합된 문자열:%s\n", str1);

	p1 = strchr(str1, 'a');						//str1의 a로 시작하는 위치값을 포인터 p1에저장
	printf("문자열에서 %c 검색 :%s\n", 'a', p1);

	p2 = strstr(str1, "go");					//str1의 go로 시작하는 위치값을 포인터 p2에 저장
	printf("문자열에서 %s 검색 :%s\n", "go", p2);

	printf("프로그램을 종료합니다.\n");
	return 0;


}