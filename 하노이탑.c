#include<stdio.h>

void hanoi(int N, int start_peg,int end_peg,int middle);
void move_disk(int disk_num, int start_peg, int end_peg);
int main(void)
{
	hanoi(3,1,3,2);

	return 0;
}

void hanoi(int N, int start_peg,int end_peg,int middle)
{
	if(N==1){
		move_disk(1, start_peg, end_peg);
	}
	else
	hanoi(N-1, start_peg, middle, end_peg);
	move_disk(N, start_peg, end_peg);
	hanoi(N-1, middle, end_peg, start_peg);
}

void move_disk(int disk_num,int start_peg,int end_peg)
{
	printf("%d번 원판을 %d 기둥에서 %d번 기둥으로 이동",disk_num,start_peg,end_peg);
}