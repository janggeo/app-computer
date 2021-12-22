/*��������
1. save_file�Լ� ���� listhead�� �ٷ� ����Ͽ��µ� temp�� �Űܼ� ����ϵ��� ����
2. get_student�Լ� �����Ҵ� ���н� ���� �޽��� ���� �����ϵ��� ����
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>		//malloc�Լ�, free�Լ��� ����� �������
#include<string.h>
//�л� ����ü ����
struct student {
	int num;
	char name[20];
	int sco;
	struct student* next;
};
typedef struct student stu;	//struct student ����ü ������
stu* listhead = NULL;			//���Ḯ��Ʈ �������� ����
stu* get_student();			//�л������� �Է¹޴� �Լ�
void insert_node(stu* p);	//���Ḯ��Ʈ�� �������� �����Ͽ� ����
void print_list();			//�л� ���� ���
void save_file();			//���Ϸ� ����
void delete_list();			//�����Ҵ�� ��� ���� 

int main(void)
{
	while (1) {
		stu* student = get_student();
		if (student->num == -1)		//�й��� -1�Էµ� ��� �л������� �׸� �Է¹޴´�.
			break;
		insert_node(student);		//�Էµ� �л������� ���Ḯ��Ʈ�� ����
	}
	print_list();
	save_file();
	delete_list();
	return 0;
}

stu* get_student() {
	//����ü �����Ҵ� 
	stu* Student = (stu*)malloc(sizeof(stu));
	if(Student == NULL){
		printf("�����Ҵ� ����.\n");
		exit(1);
	}
	printf("(-1�� �Է��ϸ� ����)\n�й�:");
	scanf("%d", &Student->num);	//�й� �Է�
	if (Student->num == -1)					//�й��� -1�Է½� ����
		return Student;
	printf("�̸�:");
	scanf("%s", Student->name); 	//�̸� �Է�
	printf("����:");
	scanf("%d", &Student->sco); 	//���� �Է�
	printf("\n");
	return Student;					//��� �ԷµǸ� ���� 
}

void insert_node(stu* student)
{
	stu* pre = NULL;			//���� ������ �л� ��ġ ���� ��带 ����ų ������
	stu* aft = listhead;		//���� ������ �л� ��ġ ���� ��带 ����ų ������
						
	while (aft != NULL) {		//���� ����Ʈ ������ ���� ���Ͽ� pre�� aft�� ����Ű�� ��ġ ����
		//���� �Է¹��� �л� ������ aft�� ����Ű�� ����� sco ���� ���� ���
		if (student->sco < aft->sco) {
			pre = aft;			//pre�� aft��ġ�� �ű��
			aft = aft->next;	//aft�� ���� ��� ��ġ�� �ű��
		}
		//���� �Է¹��� �л� ������ aft�� ����Ű�� ����� sco�� ���ų� Ŭ���
		else
			break;
	}
	//����� �л� ������ ���� ���(ó�� ����ɰ��), ����Ʈ�� �ִ밪(ù��° sco��)���� student->sco�� ū���� ���
	if (pre == NULL) {
		student->next = listhead;
		listhead = student;
	}
	//����� �л� ������ ���� ���, ����Ʈ�� �ִ밪(ù��° sco��)���� student->sco�� �������� ���
	else {
		//���Ḯ��Ʈ ���� pre��aft�� ����Ű�� ���̿� ���ο� �л� ������ ����
		student->next = aft;
		pre->next = student;
	}
}

void print_list()
{
	stu* temp;		//����Ʈ��� ��ġ�� ������ ������
	temp = listhead;
	printf("\n%16s%16s%6s\n", "�й�", "�̸�", "����");
	printf("=======================================\n");
	//���Ḯ��Ʈ ������ ���� ���
	while (temp != NULL)
	{
		printf("%16d%16s%6d\n", temp->num, temp->name, temp->sco);
		temp = temp->next;	//������ġ�� ���� �ű��
	}
}

void save_file()
{
	stu* temp=listhead;
	FILE* fp = NULL;					//���������� ����
	char file[20] = { 0 };				//���� �̸� ������ �迭
	printf("(�����̸� ����:����.txt)\n");
	printf("�����̸�:");
	scanf("%s", file);
	//�Է¹��� �����̸����� �� ������ ������� ������ ����� ���� ��ġ�� fp�� ���� 
	if ((fp = fopen(file, "w")) == NULL)		// ���ϸ���⿡ �����Ұ�� �����޽��� ����
	{
		fprintf(stderr, "%s������ �� �� �����ϴ�.", file);
		exit(1);
	}
	fprintf(fp, "%16s%16s%6s\n", "�й�", "�̸�", "����");
	fprintf(fp, "======================================\n");
	//���Ḯ��Ʈ ������ ���� ���Ͽ� ����
	while (temp != NULL)
	{
		fprintf(fp, "%16d%16s%6d\n", temp->num, temp->name, temp->sco);
		temp = temp->next;
	}
	fclose(fp);
}

void delete_list()
{
	stu* temp = listhead;
	//���Ḯ��Ʈ ���������� �����Ҵ� ����
	while (listhead != NULL)
	{
		listhead = listhead->next;
		free(temp);		//temp�� ����Ű�� ��� ����
		temp = listhead;
	}
}