#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>									// strcat, strchr, strstr�� ����ϱ� ���� �ʿ��� �������
int main(void)
{
	char str1[20] = "Have a ", str2[10] = "good time";
	char* p1, * p2;									// strchr�� strstr�� �̿��� ���ڿ� �����ּ� ������ ������
	printf("char str1[20]=""%s""�Դϴ�.\n", str1);
	printf("char str2[10]=""%s""�Դϴ�.\n", str2);

	strcat(str1, str2);							// str1�� �ι�����ġ�� str2�� �̾���δ�.
	printf("���յ� ���ڿ�:%s\n", str1);

	p1 = strchr(str1, 'a');						//str1�� a�� �����ϴ� ��ġ���� ������ p1������
	printf("���ڿ����� %c �˻� :%s\n", 'a', p1);

	p2 = strstr(str1, "go");					//str1�� go�� �����ϴ� ��ġ���� ������ p2�� ����
	printf("���ڿ����� %s �˻� :%s\n", "go", p2);

	printf("���α׷��� �����մϴ�.\n");
	return 0;


}