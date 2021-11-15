#include<stdio.h>
#define min 3					//�ϳ���ž ���� �ּ� ����
#define max 5					//�ϳ���ž ���� �ִ� ���� 
int i = 0, j = 0, k = 0;
char towerA[max][max];			//ù��° ���(A)�� 2�����迭�� ��Ÿ�� 
char towerB[max][max];			//�ι�° ���(B)��	2�����迭�� ��Ÿ��
char towerC[max][max];			//����° ���(C)��	2�����迭�� ��Ÿ��
void hanoi(int N, char start,char end,char middle,int plate,int* pt1,int* pt2,int* pt3);
void move_disk(int N, char start, char end,int plate, int* pt1, int* pt2, int* pt3);
void prtTower(char tower[max][max]);
void prtTowerSpace(char* space);
void indexStart(int* pt, char start, char tower[max][max], int N, char n);
void indexEnd(int* pt, char end, char tower[max][max],int N, char n);

int main(void){	
	int plate = 0;					//�ű���� �ϴ� ���� ����

	while (1) {						//���ǰ��� ���� Ȯ��
		printf("���ǰ����� �Է����ּ��� (%d ~ %d): ",min,max);
		scanf("%d", &plate);
		if (plate >= min && plate <= max) break;
		else printf("�ٽ� �Է����ּ���.\n");
	}

	int t1=0,t2=plate,t3=plate;			//��տ� ���� ���� ��ġ, �ε�����ȣ
	int*pt1=&t1, *pt2=&t2, *pt3=&t3;	//�ε�����ȣ�� �ּҸ� ������ ������
	
	for(int i=0;i<plate;i++){
		for(int j=0;j<=i;j++){
			towerB[i][j]=' ';			//B����� �ʱ�ȭ
			towerC[i][j]=' ';			//C����� �ʱ�ȭ	
			towerA[i][j]='*';			//A����� �Էµ� ���� ������ŭ �ʱ�ȭ
			printf("%c",towerA[i][j]);	//A����ո� ó������ ���
		}
		printf("\n");
	}
	printf("_____\t_____\t_____\n");
	
	hanoi(plate,'A','C','B',plate,pt1,pt2,pt3);			//plate������ ������ A����տ��� C��������� B���� �����Ͽ� �Űܶ�

	return 0;
}

void hanoi(int N, char start,char end,char middle,int plate,int *pt1,int *pt2,int *pt3){
	if(N==1){
		move_disk(1, start, end, plate,pt1,pt2,pt3);			//���ǰ����� 1���̸� A����տ��� C��������� �Űܶ�
	}
	else{
		hanoi(N-1, start, middle, end, plate,pt1,pt2,pt3);			//������ �Ѱ��� ���Ǹ� ����� A����տ��� B��������� �Űܶ�
		move_disk(N, start, end, plate,pt1,pt2,pt3);				//���� �Ѱ��� ������ A����տ��� C��������� �Űܶ�
		hanoi(N-1, middle, end, start, plate,pt1,pt2,pt3);			//B������� ������������ C��������� �Űܶ�
	}
}

void move_disk(int N,char start,char end,int plate,int* pt1,int* pt2,int* pt3){
	indexStart(pt1, start, towerA, N, 'A');			//���� ��߱���� A����� ���
	indexStart(pt2, start, towerB, N, 'B');			//���� ��߱���� B����� ���
	indexStart(pt3, start, towerC, N, 'C');			//���� ��߱���� C����� ���
	indexEnd(pt1, end, towerA, N, 'A');				//���� ��������� A����� ���
	indexEnd(pt2, end, towerB, N, 'B');				//���� ��������� B����� ���
	indexEnd(pt3, end, towerC, N, 'C');				//���� ��������� C����� ���
	//�ϳ���ž ��� �κ�	
	char space[] = "         ";		//��հ� ��ջ��� ����	
	for(i=0;i<plate;i++){			//���Ǽ���ŭ �ݺ� (i�� 2�����迭�� ��)
		prtTower(towerA);		//A�� ��� ���
		prtTowerSpace(space);		//A��հ� B��հ� ���� ���
		prtTower(towerB);		//B�� ��� ���
		prtTowerSpace(space);		//B��հ� C��հ� ���� ���
		prtTower(towerC);		//C�� ��� ���
		printf("\n");
	}
	printf("_____\t_____\t_____\n");
}
void prtTower(char tower[max][max]) {		//2�����迭(���)�� ���� ������Ű�� ���
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
			tower[*pt][i] = ' ';			//�ű�� ������� n������� ���,  n����տ��� ����Ű�� �ε�����ġ��  ���ǹ�ȣ��ŭ ��ǥ ����  
		}
		*pt += 1;						//n�� ����ε�����ȣ +1  
	}
}
void indexEnd(int* pt, char end, char tower[max][max], int N,char n) {
	if (end == n) {
		*pt -= 1;					//n�� ����ε��� ��ȣ -1
		for (int j = 0; j < N; j++) {
			tower[*pt][j] = '*';		//�ű�� �������� n������ϰ��, n����� �ε�����ġ�� ���ǹ�ȣ��ŭ ��ǥ�߰�
		}
		
	}
}