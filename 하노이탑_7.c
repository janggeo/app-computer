#include<stdio.h>
#define min 3					//하노이탑 원판 최소 개수
#define max 5					//하노이탑 원판 최대 개수 
int i = 0, j = 0, k = 0;
char towerA[max][max];			//첫번째 기둥(A)을 2차원배열로 나타냄 
char towerB[max][max];			//두번째 기둥(B)을	2차원배열로 나타냄
char towerC[max][max];			//세번째 기둥(C)을	2차원배열로 나타냄
void hanoi(int N, char start,char end,char middle,int plate,int* pt1,int* pt2,int* pt3);
void move_disk(int N, char start, char end,int plate, int* pt1, int* pt2, int* pt3);
void prtTower(char tower[max][max]);
void prtTowerSpace(char* space);
void indexStart(int* pt, char start, char tower[max][max], int N, char n);
void indexEnd(int* pt, char end, char tower[max][max],int N, char n);

int main(void){	
	int plate = 0;					//옮기고자 하는 원판 개수

	while (1) {						//원판개수 범위 확인
		printf("원판개수를 입력해주세요 (%d ~ %d): ",min,max);
		scanf("%d", &plate);
		if (plate >= min && plate <= max) break;
		else printf("다시 입력해주세요.\n");
	}

	int t1=0,t2=plate,t3=plate;			//기둥에 놓일 원판 위치, 인덱스번호
	int*pt1=&t1, *pt2=&t2, *pt3=&t3;	//인덱스번호의 주소를 저장할 포인터
	
	for(int i=0;i<plate;i++){
		for(int j=0;j<=i;j++){
			towerB[i][j]=' ';			//B번기둥 초기화
			towerC[i][j]=' ';			//C번기둥 초기화	
			towerA[i][j]='*';			//A번기둥 입력된 판의 개수만큼 초기화
			printf("%c",towerA[i][j]);	//A번기둥만 처음상태 출력
		}
		printf("\n");
	}
	printf("_____\t_____\t_____\n");
	
	hanoi(plate,'A','C','B',plate,pt1,pt2,pt3);			//plate개수의 원판을 A번기둥에서 C번기둥으로 B번을 경유하여 옮겨라

	return 0;
}

void hanoi(int N, char start,char end,char middle,int plate,int *pt1,int *pt2,int *pt3){
	if(N==1){
		move_disk(1, start, end, plate,pt1,pt2,pt3);			//원판개수가 1개이면 A번기둥에서 C번기둥으로 옮겨라
	}
	else{
		hanoi(N-1, start, middle, end, plate,pt1,pt2,pt3);			//마지막 한개의 원판만 남기고 A번기둥에서 B번기둥으로 옮겨라
		move_disk(N, start, end, plate,pt1,pt2,pt3);				//남은 한개의 원판을 A번기둥에서 C번기둥으로 옮겨라
		hanoi(N-1, middle, end, start, plate,pt1,pt2,pt3);			//B번기둥의 나머지원판을 C번기둥으로 옮겨라
	}
}

void move_disk(int N,char start,char end,int plate,int* pt1,int* pt2,int* pt3){
	indexStart(pt1, start, towerA, N, 'A');			//원판 출발기둥이 A기둥인 경우
	indexStart(pt2, start, towerB, N, 'B');			//원판 출발기둥이 B기둥인 경우
	indexStart(pt3, start, towerC, N, 'C');			//원판 출발기둥이 C기둥인 경우
	indexEnd(pt1, end, towerA, N, 'A');				//원판 도착기둥이 A기둥인 경우
	indexEnd(pt2, end, towerB, N, 'B');				//원판 도착기둥이 B기둥인 경우
	indexEnd(pt3, end, towerC, N, 'C');				//원판 도착기둥이 C기둥인 경우
	//하노이탑 출력 부분	
	char space[] = "         ";		//기둥과 기둥사이 공간	
	for(i=0;i<plate;i++){			//원판수만큼 반복 (i는 2차원배열의 행)
		prtTower(towerA);		//A번 기둥 출력
		prtTowerSpace(space);		//A기둥과 B기둥간 공간 출력
		prtTower(towerB);		//B번 기둥 출력
		prtTowerSpace(space);		//B기둥과 C기둥간 공간 출력
		prtTower(towerC);		//C번 기둥 출력
		printf("\n");
	}
	printf("_____\t_____\t_____\n");
}
void prtTower(char tower[max][max]) {		//2차원배열(기둥)의 열을 증가시키며 출력
	for (j = 0; j <= i; j++) {
		printf("%c", tower[i][j]);
	}
}
void prtTowerSpace(char *space) {
	for (k = 0; k < 8 - j; k++) {
		printf("%c", space[k]);
	}
}
void indexStart(int* pt, char start, char tower[max][max], int N, char n) {
	if (start == n) {
		for (int i = 0; i < N; i++) {
			tower[*pt][i] = ' ';			//옮기기 출발점이 n번기둥일 경우,  n번기둥에서 가리키는 인덱스위치에  원판번호만큼 별표 제거  
		}
		*pt += 1;						//n번 기둥인덱스번호 +1  
	}
}
void indexEnd(int* pt, char end, char tower[max][max], int N,char n) {
	if (end == n) {
		*pt -= 1;					//n번 기둥인덱스 번호 -1
		for (int j = 0; j < N; j++) {
			tower[*pt][j] = '*';		//옮기기 도착점이 n번기둥일경우, n번기둥 인덱스위치에 원판번호만큼 별표추가
		}
		
	}
}