#include <stdio.h>
#include <time.h>		//srnad()�Լ� ����� ����� time()�Լ�
#include <stdlib.h>		//rand()�Լ�

void user_check(int arr_user[]);		//����ڰ� �Է��� ���ڸ� �迭�� ����
void generate_lotto(int arr_lotto[]);	//��ǻ�Ͱ� �������� �ζ� ��ȣ ����
int mappingNumber(int arr_user[], int arr_lotto[]);	//��ġ�ϴ� ��ȣ�� ������ ����

int main(void)
{
	int i;
	srand((unsigned)time(NULL));	//seed�� �ο�
	int arr_lotto[6];				//��ǻ���� ���� �ζ� ��ȣ ����
	int arr_user[6];				//����ڰ� ���Ƿ� �ζ� ��ȣ �Է�

	user_check(arr_user);
	generate_lotto(arr_lotto);



	printf("�Է� ��ȣ :");
	for (i = 0; i < 6; i++)
	{
		printf("%3d", arr_user[i]);	//����ڰ� �Է��� �ζ� ��ȣ ���
	}
	printf("\n");
	printf("��÷ ��ȣ:");
	for (i = 0; i < 6; i++)
	{
		printf("%3d", arr_lotto[i]);	//��ǻ�Ͱ� �������� ������ ��ȣ ���
	}
	printf("\n");
	printf("��÷ ��ȣ�� %d���Դϴ�.", mappingNumber(arr_user, arr_lotto));	//��ġ�ϴ� �ζǹ�ȣ ���� ���

	return 0;
}

void user_check(int arr_user[])
{
	int i;
	t
	for (i = 0; i < 6; i++)
	{
		scanf("%d", &arr_user[i]);		//6���� �ζ� ��ȣ �Է�
	}
	
}

void generate_lotto(int arr_lotto[])
{
	
	int i;
	int dup = 0;	//�ߺ����� ���� ����
	int cnt = 0;	//�迭�� �Է��� ���� ���� ���� ����
	while (cnt<6)	//�Է��� ������ 6���� �ɶ� ���� �ݺ�
	{
		arr_lotto[cnt] = rand() % 45 + 1;	//1~45������ ������ ���� �迭�� ���� 
		if (cnt > 0)						//�ι�° ��Һ���
		{
			for (i = 0; i < cnt; i++)
			{
				if (arr_lotto[i] == arr_lotto[cnt])	//�������� �迭�� ������ ���� ��ġ�ϴ� ���ڰ� �������
				{
					dup++;							//�ߺ��� ��Ÿ���� ���� +1
				}
			}
		}
		if (dup == 0)				//�ߺ��� ���� ���
		{
			cnt++;					//cnt+1 
		}
		else
		{
			dup = 0;				//�ߺ��� ��� dup=0, cnt�� �״�� ���� cnt�� ��Ÿ���� ������ �迭 ����ڸ��� �ٽ� ������ ���� �迭
		}
		
	}
}

int mappingNumber(int arr_user[], int arr_lotto[])
{
	int cnt=0;
	int i, j;

	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 6; j++)
		{
			if (arr_user[i] == arr_lotto[j])  		//��ǻ�Ͱ� �迭�� ���� ����ڰ� ������ �� �� ��ġ�ϴ� ���� ���� ��� cnt+1
				cnt++;
		}
	}

	return cnt;		//cnt ����
}
