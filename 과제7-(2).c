#include <stdio.h>

struct product			//����ü�� �������
{
	char name[10];		//��ǰ�̸�
	int num;			//��ǰ����
	int pri;			//��ǰ�ܰ�
	int t_p;			//��ǰ�ݾ�
};

int main(void)
{
	int i;
	struct product p1[3];	//����ü ũ��3�� ����ü �迭
	for(i=0;i<3;i++)
	{	printf("%d��° ǰ���� ǰ��, ����, �ܰ� �Է�\n",i+1);
		printf("ǰ��:"); scanf("%s",p1[i].name);
		getchar();			//���� �����
		printf("����:"); scanf("%d",&p1[i].num);
		getchar();
		printf("�ܰ�:"); scanf("%d",&p1[i].pri);	
		getchar();
		p1[i].t_p = p1[i].num * p1[i].pri;	//�ݾ��� ��ǰ����*��ǰ�ܰ�
	}

	printf("\n");
	printf("[ǰ�� 4���� ����, �ܰ�, �ݾ� ���]\n");
	printf("��ǰ��	����	����	�ݾ�(õ��)\n");
	for(i=0;i<3;i++)
	{
		printf("%s%5d%8d%9d\n",p1[i].name,p1[i].num,p1[i].pri,p1[i].t_p);
	}
	
	return 0;
	
}