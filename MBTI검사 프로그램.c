//MBTI 검사, 정리 프로그램
//삽입,삭제,출력,검색,정렬,종료기능 필요 strcpy를 이용해서 수정도 구현하자!
//sleep(1000)은 1초 딜레이 주는 함수
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>  //콘솔화면 초기화를 위한 헤더파일 system("cls") 입력하면 콘솔창 초기화됨
#include <conio.h>    /*_getch()를 사용하기위한 콘솔입력함수 
  _getch()표준입력함수와는 다르게 사용자가 입력한 키값은 받고 화면에 출력되지 않음*/

struct Node
{
	char name[10];
	int age;                   
	char mbti[5];                 //외향성   E/I, 현실성   S/N, 판단기준 T/F, 계획성   J/P             
	struct Node* next;
};
struct Node * head = NULL;

void  mbti_test(), input(), list(), delete(), search(), shutdown_p(),nodeswap(),nodesort();

int menu()
{
	int menu_num;
	while (1) {
		printf("⊙-----------------------------------------------⊙\n");
		printf("|\t\tMBTI 검사 프로그램\t\t|\n");
		printf("| ■메뉴\t\t\t\t\t\t|\n");                      //\t로 간격맞춰주기
		printf("| 1) MBTI검사 시작\t\t\t\t|\n");
		printf("| 2) 검사결과 목록 출력\t\t\t\t|\n");
		printf("| 3) 검사결과 삭제\t\t\t\t|\n");
		printf("| 4) 검사결과 검색\t\t\t\t|\n");
		printf("| 5) 프로그램 종료\t\t\t\t|\n");
		printf("⊙-----------------------------------------------⊙\n");
		printf("메뉴 번호입력 : ");
		scanf_s("%d", &menu_num);

		if (menu_num > 5 || menu_num <= 0)
		{
			printf("\n\n>>올바른 숫자를 입력해주세요<<");
			Sleep(1500);                              // 1.5초 딜레이
			system("cls");
		}
		else
			break;
	}
	
	return menu_num;
}

int main()                                //===========메인 함수===========//
{
	int menu_num;
	while (1) {
		system("cls");
		menu_num = menu();
		switch (menu_num) {
		case 1:          //검사 시작
			mbti_test();
			system("cls");
			break;
		case 2:          //목록 출력
			list();
			break;
		case 3:          //결과 삭제
			delete();
			break;
		case 4:          //결과 검색
			search();
			break;
		case 5:          //프로그램 종료
			shutdown_p();
			return 0;
		}
	}
}

/////////////////////////////////////////-MBTI 검사 함수-/////////////////////////////////////////////////////
void mbti_test()                            
{
	system("cls");
	char name[10]="", mbti[5];
	int age;
	printf("\n\n\n\t\t이름을 입력해주세요 : ");
	scanf_s("%s",name,10);
	printf("\n\t\t나이를 입력해주세요 : ");
	scanf_s("%d",&age);

	int E_I, S_N, T_F, J_P;
	//E 인지 I인지 결정
	while (1) {
		system("cls");
		printf("|\t\t\t   나와 더 가까운 쪽은?   \t\t\t|\n");
		printf("|\t\t\t\t\t\t\t\t\t|\n");
		printf("|\t 1)밖에 돌아다니는걸 좋아하는       2)집에서 쉬는걸 좋아하는\t|\n");
		printf("내 선택은 : ");
		scanf_s("%d", &E_I);
		if ((E_I == 1 || E_I == 2) != 1)
			printf("1또는 2로 입력해주세요\n");
		else
			break;
		Sleep(1000);
	}
	//S 인지 N인지 결정
	while (1) {
		system("cls");
		printf("|\t\t\t   내가 공사장을 지나갈때   \t\t\t|\n");
		printf("|\t\t\t\t\t\t\t\t\t|\n");
		printf("|\t 1)뭐야 여기 공사하네?       2)위에서 돌떨어지면 어떡하지..\t|\n");
		printf("내 선택은 : ");
		scanf_s("%d", &S_N);
		if (( S_N== 1 || S_N == 2) != 1)
			printf("1또는 2로 입력해주세요\n");
		else
			break;
		Sleep(1000);
	}
	//T 인지 F인지 결정
	while (1) {
		system("cls");
		printf("|\t\t\t친구가 교통사고 났다고 하면?\t\t\t|\n");
		printf("|\t\t\t\t\t\t\t\t\t|\n");
		printf("|   1)보험은 들어놨어? 누가 박은거야?     2)많이 다쳤어? 몸은 괜찮아?   |\n");
		printf("내 선택은 : ");
		scanf_s("%d", &T_F);
		if ((T_F == 1 || T_F == 2) != 1)
			printf("1또는 2로 입력해주세요\n");
		else
			break;
		Sleep(1000);
	}
	//J 인지 P인지 결정
	while (1) {
		system("cls");
		printf("|\t\t\t    나는 여행계획을 짤때    \t\t\t|\n");
		printf("|\t\t\t\t\t\t\t\t\t|\n");
		printf("|\t   1)시간과 장소를 계획한다     2)어떤걸 할지만 정한다  \t|\n");
		printf("내 선택은 : ");
		scanf_s("%d", &J_P);
		if ((J_P == 1 || J_P == 2) != 1)
			printf("1또는 2로 입력해주세요\n");
		else
			break;
		Sleep(1000);
	}
	system("cls");
	printf("\n\t\t\t검사가 종료되었습니다\t\t\t\n\n");
	
	(E_I == 1) ? (mbti[0] = 'E') : (mbti[0] = 'I');   //삼향연산자 사용
	(S_N == 1) ? (mbti[1] = 'S') : (mbti[1] = 'N');
	(T_F == 1) ? (mbti[2] = 'T') : (mbti[2] = 'F');
	(J_P == 1) ? (mbti[3] = 'J') : (mbti[3] = 'P');
	mbti[4] = '\0';
	printf("'%s'님의 MBTI는 %s입니다.\n\n", name, mbti);
	input(name,age,mbti);
	printf("\n결과 저장완료! 아무키나 누르면 메뉴로 돌아갑니다");
	_getch();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void input(char *i_name,int i_age, char *i_mbti)
{
	struct Node* cuss=head;
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	strcpy_s(newnode->name,10,i_name);       //이름 저장
	newnode->age = i_age;                    //나이 저장
	strcpy_s(newnode->mbti, 5, i_mbti);      //mbti 저장
	newnode->next = NULL;
	
	if (head == NULL)            //head노드가 비어있을경우
		head = newnode;
	else
	{
		while (cuss->next != NULL)   //맨 마지막 노드까지 커서 이동
			cuss= cuss->next;

		cuss->next = newnode;
	}
}

void nodeswap() {

}

void nodesort() {                                    //노드 정렬함수
	struct Node* cuss = head,*temp=NULL;
	char cmp;
	int i = 5;
	while (i == 5) {
		printf("어떤 성향을 기준으로 정렬할까요? \n");
		printf("(E,I,S,N,T,F,J,P)중에서 대문자로 입력: ");
		scanf_s("%c",&cmp,1);                   //왜 한바퀴 먼저돌고 scanf_s가 실행되는가? 어이가없다.
		
		switch (cmp) {
		case 'E': case 'I': i = 0;
			break;
		case 'S': case 'N': i = 1;
			break;
		case 'T': case 'F': i = 2;
			break;
		case 'J': case 'P': i = 3;
			break;
		default:
			printf("\n제대로 된 값을 입력해주세요.");
			system("cls");
			Sleep(1500);
		}
	}
	while (cuss->next != NULL)
	{
		if ((cuss->mbti[i] != cuss->next->mbti[i]) && (cuss->mbti[i] != cmp)) {
			temp = cuss->next;                            //바꿀대상을 temp에 저장
			cuss->next = cuss->next->next;                //바꿀대상을 제외하고 연결
			temp->next = head;                            //temp에 저장된 노드를 헤드앞으로 연결
			cuss = head = temp;                            //head를 temp로 초기화
		}
		else
			cuss = cuss->next;
	}
}

void list()                       //목록 출력(정렬)
{

	system("cls");
	struct Node* cuss = head;
	if (cuss == NULL)
	{
		printf("\n\n\n\t※저장된 값이 없습니다. 값을 입력하고 실행해주세요※\n");
		Sleep(1500);
	}
	else {
		if (cuss->next != NULL)              //노드가 두개 이상일때 정렬을 실행
		{
			nodesort();
			cuss = head;                     //정렬 이후 바뀐 헤드값을 다시 커서에 대입
		}
		printf("=============|검사결과 목록|=============\n\n");   //여기부터 노드전체 출력코드
		printf(" ||나이||\t||이름||\t||성향||\n");
		
		while (cuss != NULL)
		{
			printf("    %d   \t %s     \t  %s  \n", cuss->age, cuss->name, cuss->mbti);
			cuss = cuss->next;
		}
		printf("\n아무키나 누르면 메뉴로 돌아갑니다.");
		_getch();
	}
}

void search()
{
	struct Node* cuss = head;
	char s_name[10] = "";
	int TF = 0;

	if (cuss == NULL)
	{
		system("cls");
		printf("\n\n\n\t※저장된 값이 없습니다. 값을 입력하고 실행해주세요※\n");
		Sleep(1500);
	}
	else {
		printf("\n\n\n\t\t검색할 사람의 이름을 입력하세요: ");
		scanf_s("%s", s_name, 10);
		system("cls");
		printf("'%s'검색결과\n", s_name);
		while (cuss != NULL)
		{
			if (strcmp(s_name, cuss->name) == 0) {     //strcmp로 입력한 이름과 노드안의 이름과 대조
				printf("이름 : %s, 성향 : %s \n", cuss->name, cuss->mbti);
				TF++;
			}
			else
				cuss = cuss->next;
		}
		if (TF == 0)
		{
			printf("'%s'에 해당하는 결과가 없습니다.", s_name);
		}
		printf("\n아무키나 누르면 메뉴로 돌아갑니다.");
		_getch();
	}
}

void delete()                              //삭제 함수
{
	struct Node* cuss = head;

	if (cuss == NULL)
	{
		system("cls");
		printf("\n\n\n\t※저장된 값이 없습니다. 값을 입력하고 실행해주세요※\n");
		Sleep(1500);
	}
	else {
		struct Node* pre = head, * temp = NULL;
		char d_name[10] = "";
		int TF = 0;

		system("cls");
		printf("\n\n\n\t\t삭제할 항목의 이름을 입력하세요: ");
		scanf_s("%s", d_name, 10);
		system("cls");
		printf("'%s'검색결과\n", d_name);
		
		while (cuss != NULL)
		{
			if (strcmp(d_name,cuss->name) == 0) {     //strcmp로 입력한 이름과 노드안의 이름과 대조
				printf("찾은 대상 => 이름 : %s, 성향 : %s \n", cuss->name, cuss->mbti);
				TF++, temp = pre;     //값을 찾으면 찾은값의 이전 노드주소를 저장
			}
			pre = cuss;
			cuss=cuss->next;
		}
		
		if (TF == 0)                        //해당하는 노드가 없으면 출력
		{
			printf("'%s'에 해당하는 결과가 없습니다.", d_name);
			Sleep(2000);
		}
		if (TF == 1)                        //삭제하려는 노드가 있을경우 아래 코드 진행
		{
			int YN = 0;
			cuss = temp->next;
			if (temp == head)                     //삭제 대상이 head인경우
			{
				cuss = temp;                      
				head = temp->next;                //**head를 다시 정의**//
			}									  
			while (1) {
				printf("\n\n\n\t\t%s을 항목에서 제거하시겠습니까?\n", cuss->name);
				printf("\n\t\t1)예\t\t\t\t2)아니요\n입력 : ");
				scanf_s("%d", &YN);
				if ((YN == 1 || YN == 2) != 1) {
					system("cls");
					printf("※올바른 숫자를 입력하세요.");
					Sleep(1500);
				}
				else
					break;
			}
			if (YN == 1) {   //항목제거에서 예를 선택했을경우
				temp->next = cuss->next;
				free(cuss);
				printf("삭제 완료!");
			}
		}
		if (TF > 1)
			printf("중복된 이름으로 인한 오류\n\n");
		
		printf("\n\n아무키나 누르면 메뉴로 돌아갑니다.");
		_getch();
	}
}


void shutdown_p()                    //종료 함수
{
	printf("\n\nMBTI검사 프로그램을 종료합니다.\n\n");
	struct Node* cuss = head,*target;
	while (cuss != NULL)
	{
		target = cuss;
		cuss = target->next;
		free(target);
	}
}