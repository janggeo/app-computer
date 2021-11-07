#include <stdio.h>
#include <time.h>		//srnad()함수 실행시 사용할 time()함수
#include <stdlib.h>		//rand()함수

void user_check(int arr_user[]);		//사용자가 입력한 숫자를 배열에 저장
void generate_lotto(int arr_lotto[]);	//컴퓨터가 랜덤으로 로또 번호 생성
int mappingNumber(int arr_user[], int arr_lotto[]);	//일치하는 번호의 개수를 저장

int main(void)
{
	int i;
	srand((unsigned)time(NULL));	//seed값 부여
	int arr_lotto[6];				//컴퓨터의 랜덤 로또 번호 저장
	int arr_user[6];				//사용자가 임의로 로또 번호 입력

	user_check(arr_user);
	generate_lotto(arr_lotto);



	printf("입력 번호 :");
	for (i = 0; i < 6; i++)
	{
		printf("%3d", arr_user[i]);	//사용자가 입력한 로또 번호 출력
	}
	printf("\n");
	printf("당첨 번호:");
	for (i = 0; i < 6; i++)
	{
		printf("%3d", arr_lotto[i]);	//컴퓨터가 랜덤으로 지정한 번호 출력
	}
	printf("\n");
	printf("당첨 번호는 %d개입니다.", mappingNumber(arr_user, arr_lotto));	//일치하는 로또번호 개수 출력

	return 0;
}

void user_check(int arr_user[])
{
	int i;
	t
	for (i = 0; i < 6; i++)
	{
		scanf("%d", &arr_user[i]);		//6개의 로또 번호 입력
	}
	
}

void generate_lotto(int arr_lotto[])
{
	
	int i;
	int dup = 0;	//중복여부 조사 변수
	int cnt = 0;	//배열에 입력한 숫자 개수 저장 변수
	while (cnt<6)	//입력한 개수가 6개가 될때 까지 반복
	{
		arr_lotto[cnt] = rand() % 45 + 1;	//1~45사이의 랜덤한 수를 배열에 저장 
		if (cnt > 0)						//두번째 요소부터
		{
			for (i = 0; i < cnt; i++)
			{
				if (arr_lotto[i] == arr_lotto[cnt])	//랜덤으로 배열한 숫자중 서로 일치하는 숫자가 있을경우
				{
					dup++;							//중복을 나타내는 변수 +1
				}
			}
		}
		if (dup == 0)				//중복이 없을 경우
		{
			cnt++;					//cnt+1 
		}
		else
		{
			dup = 0;				//중복일 경우 dup=0, cnt는 그대로 지금 cnt가 나타내는 숫자의 배열 요소자리에 다시 랜덤한 수를 배열
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
			if (arr_user[i] == arr_lotto[j])  		//컴퓨터가 배열한 수와 사용자가 지정한 수 중 일치하는 수가 있을 경우 cnt+1
				cnt++;
		}
	}

	return cnt;		//cnt 리턴
}
