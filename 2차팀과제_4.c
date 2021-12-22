/*수정사항
1. save_file함수 에서 listhead를 바로 사용하였는데 temp로 옮겨서 사용하도록 변경
2. get_student함수 동적할당 실패시 에러 메시지 띄우고 종료하도록 변경
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>		//malloc함수, free함수가 선언된 헤더파일
#include<string.h>
//학생 구조체 선언
struct student {
	int num;
	char name[20];
	int sco;
	struct student* next;
};
typedef struct student stu;	//struct student 구조체 재정의
stu* listhead = NULL;			//연결리스트 시작지점 저장
stu* get_student();			//학생정보를 입력받는 함수
void insert_node(stu* p);	//연결리스트로 내림차순 정렬하여 연결
void print_list();			//학생 정보 출력
void save_file();			//파일로 저장
void delete_list();			//동적할당된 노드 해제 

int main(void)
{
	while (1) {
		stu* student = get_student();
		if (student->num == -1)		//학번에 -1입력된 경우 학생정보를 그만 입력받는다.
			break;
		insert_node(student);		//입력된 학생정보를 연결리스트로 연결
	}
	print_list();
	save_file();
	delete_list();
	return 0;
}

stu* get_student() {
	//구조체 동적할당 
	stu* Student = (stu*)malloc(sizeof(stu));
	if(Student == NULL){
		printf("동적할당 실패.\n");
		exit(1);
	}
	printf("(-1을 입력하면 종료)\n학번:");
	scanf("%d", &Student->num);	//학번 입력
	if (Student->num == -1)					//학번에 -1입력시 리턴
		return Student;
	printf("이름:");
	scanf("%s", Student->name); 	//이름 입력
	printf("성적:");
	scanf("%d", &Student->sco); 	//점수 입력
	printf("\n");
	return Student;					//모두 입력되면 리턴 
}

void insert_node(stu* student)
{
	stu* pre = NULL;			//새로 저장할 학생 위치 앞의 노드를 가리킬 포인터
	stu* aft = listhead;		//새로 저장할 학생 위치 뒤의 노드를 가리킬 포인터
						
	while (aft != NULL) {		//연결 리스트 마지막 까지 비교하여 pre와 aft가 가리키는 위치 조정
		//새로 입력받은 학생 점수가 aft가 가리키는 노드의 sco 보다 작을 경우
		if (student->sco < aft->sco) {
			pre = aft;			//pre를 aft위치로 옮긴다
			aft = aft->next;	//aft를 다음 노드 위치로 옮긴다
		}
		//새로 입력받은 학생 점수가 aft가 가리키는 노드의 sco와 같거나 클경우
		else
			break;
	}
	//저장된 학생 정보가 없을 경우(처음 저장될경우), 리스트의 최대값(첫번째 sco값)보다 student->sco가 큰값일 경우
	if (pre == NULL) {
		student->next = listhead;
		listhead = student;
	}
	//저장된 학생 정보가 있을 경우, 리스트의 최대값(첫번째 sco값)보다 student->sco가 작은값일 경우
	else {
		//연결리스트 상의 pre와aft가 가리키는 사이에 새로운 학생 정보를 저장
		student->next = aft;
		pre->next = student;
	}
}

void print_list()
{
	stu* temp;		//리스트헤드 위치를 저장할 포인터
	temp = listhead;
	printf("\n%16s%16s%6s\n", "학번", "이름", "성적");
	printf("=======================================\n");
	//연결리스트 마지막 까지 출력
	while (temp != NULL)
	{
		printf("%16d%16s%6d\n", temp->num, temp->name, temp->sco);
		temp = temp->next;	//다음위치의 노드로 옮긴다
	}
}

void save_file()
{
	stu* temp=listhead;
	FILE* fp = NULL;					//파일포인터 선언
	char file[20] = { 0 };				//파일 이름 저장할 배열
	printf("(파일이름 예시:성적.txt)\n");
	printf("파일이름:");
	scanf("%s", file);
	//입력받은 파일이름으로 된 파일이 없을경우 파일을 만들고 파일 위치를 fp에 저장 
	if ((fp = fopen(file, "w")) == NULL)		// 파일만들기에 실패할경우 오류메시지 츌력
	{
		fprintf(stderr, "%s파일을 열 수 없습니다.", file);
		exit(1);
	}
	fprintf(fp, "%16s%16s%6s\n", "학번", "이름", "성적");
	fprintf(fp, "======================================\n");
	//연결리스트 마지막 까지 파일에 저장
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
	//연결리스트 마지막까지 동적할당 해제
	while (listhead != NULL)
	{
		listhead = listhead->next;
		free(temp);		//temp가 가리키는 노드 해제
		temp = listhead;
	}
}