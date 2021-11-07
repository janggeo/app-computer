#include <stdio.h>

struct product			//구조체와 멤버선언
{
	char name[10];		//상품이름
	int num;			//상품수량
	int pri;			//상품단가
	int t_p;			//상품금액
};

int main(void)
{
	int i;
	struct product p1[3];	//구조체 크기3인 구조체 배열
	for(i=0;i<3;i++)
	{	printf("%d번째 품목의 품목, 수량, 단가 입력\n",i+1);
		printf("품목:"); scanf("%s",p1[i].name);
		getchar();			//버퍼 지우기
		printf("수량:"); scanf("%d",&p1[i].num);
		getchar();
		printf("단가:"); scanf("%d",&p1[i].pri);	
		getchar();
		p1[i].t_p = p1[i].num * p1[i].pri;	//금액은 상품개수*상품단가
	}

	printf("\n");
	printf("[품목 4개의 수량, 단가, 금액 출력]\n");
	printf("상품명	수량	가격	금액(천원)\n");
	for(i=0;i<3;i++)
	{
		printf("%s%5d%8d%9d\n",p1[i].name,p1[i].num,p1[i].pri,p1[i].t_p);
	}
	
	return 0;
	
}