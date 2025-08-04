//MBTI �˻�, ���� ���α׷�
//����,����,���,�˻�,����,������ �ʿ� strcpy�� �̿��ؼ� ������ ��������!
//sleep(1000)�� 1�� ������ �ִ� �Լ�
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>  //�ܼ�ȭ�� �ʱ�ȭ�� ���� ������� system("cls") �Է��ϸ� �ܼ�â �ʱ�ȭ��
#include <conio.h>    /*_getch()�� ����ϱ����� �ܼ��Է��Լ� 
  _getch()ǥ���Է��Լ��ʹ� �ٸ��� ����ڰ� �Է��� Ű���� �ް� ȭ�鿡 ��µ��� ����*/

struct Node
{
	char name[10];
	int age;                   
	char mbti[5];                 //���⼺   E/I, ���Ǽ�   S/N, �Ǵܱ��� T/F, ��ȹ��   J/P             
	struct Node* next;
};
struct Node * head = NULL;

void  mbti_test(), input(), list(), delete(), search(), shutdown_p(),nodeswap(),nodesort();

int menu()
{
	int menu_num;
	while (1) {
		printf("��-----------------------------------------------��\n");
		printf("|\t\tMBTI �˻� ���α׷�\t\t|\n");
		printf("| ��޴�\t\t\t\t\t\t|\n");                      //\t�� ���ݸ����ֱ�
		printf("| 1) MBTI�˻� ����\t\t\t\t|\n");
		printf("| 2) �˻��� ��� ���\t\t\t\t|\n");
		printf("| 3) �˻��� ����\t\t\t\t|\n");
		printf("| 4) �˻��� �˻�\t\t\t\t|\n");
		printf("| 5) ���α׷� ����\t\t\t\t|\n");
		printf("��-----------------------------------------------��\n");
		printf("�޴� ��ȣ�Է� : ");
		scanf_s("%d", &menu_num);

		if (menu_num > 5 || menu_num <= 0)
		{
			printf("\n\n>>�ùٸ� ���ڸ� �Է����ּ���<<");
			Sleep(1500);                              // 1.5�� ������
			system("cls");
		}
		else
			break;
	}
	
	return menu_num;
}

int main()                                //===========���� �Լ�===========//
{
	int menu_num;
	while (1) {
		system("cls");
		menu_num = menu();
		switch (menu_num) {
		case 1:          //�˻� ����
			mbti_test();
			system("cls");
			break;
		case 2:          //��� ���
			list();
			break;
		case 3:          //��� ����
			delete();
			break;
		case 4:          //��� �˻�
			search();
			break;
		case 5:          //���α׷� ����
			shutdown_p();
			return 0;
		}
	}
}

/////////////////////////////////////////-MBTI �˻� �Լ�-/////////////////////////////////////////////////////
void mbti_test()                            
{
	system("cls");
	char name[10]="", mbti[5];
	int age;
	printf("\n\n\n\t\t�̸��� �Է����ּ��� : ");
	scanf_s("%s",name,10);
	printf("\n\t\t���̸� �Է����ּ��� : ");
	scanf_s("%d",&age);

	int E_I, S_N, T_F, J_P;
	//E ���� I���� ����
	while (1) {
		system("cls");
		printf("|\t\t\t   ���� �� ����� ����?   \t\t\t|\n");
		printf("|\t\t\t\t\t\t\t\t\t|\n");
		printf("|\t 1)�ۿ� ���ƴٴϴ°� �����ϴ�       2)������ ���°� �����ϴ�\t|\n");
		printf("�� ������ : ");
		scanf_s("%d", &E_I);
		if ((E_I == 1 || E_I == 2) != 1)
			printf("1�Ǵ� 2�� �Է����ּ���\n");
		else
			break;
		Sleep(1000);
	}
	//S ���� N���� ����
	while (1) {
		system("cls");
		printf("|\t\t\t   ���� �������� ��������   \t\t\t|\n");
		printf("|\t\t\t\t\t\t\t\t\t|\n");
		printf("|\t 1)���� ���� �����ϳ�?       2)������ ���������� �����..\t|\n");
		printf("�� ������ : ");
		scanf_s("%d", &S_N);
		if (( S_N== 1 || S_N == 2) != 1)
			printf("1�Ǵ� 2�� �Է����ּ���\n");
		else
			break;
		Sleep(1000);
	}
	//T ���� F���� ����
	while (1) {
		system("cls");
		printf("|\t\t\tģ���� ������ ���ٰ� �ϸ�?\t\t\t|\n");
		printf("|\t\t\t\t\t\t\t\t\t|\n");
		printf("|   1)������ ������? ���� �����ž�?     2)���� ���ƾ�? ���� ������?   |\n");
		printf("�� ������ : ");
		scanf_s("%d", &T_F);
		if ((T_F == 1 || T_F == 2) != 1)
			printf("1�Ǵ� 2�� �Է����ּ���\n");
		else
			break;
		Sleep(1000);
	}
	//J ���� P���� ����
	while (1) {
		system("cls");
		printf("|\t\t\t    ���� �����ȹ�� ©��    \t\t\t|\n");
		printf("|\t\t\t\t\t\t\t\t\t|\n");
		printf("|\t   1)�ð��� ��Ҹ� ��ȹ�Ѵ�     2)��� ������ ���Ѵ�  \t|\n");
		printf("�� ������ : ");
		scanf_s("%d", &J_P);
		if ((J_P == 1 || J_P == 2) != 1)
			printf("1�Ǵ� 2�� �Է����ּ���\n");
		else
			break;
		Sleep(1000);
	}
	system("cls");
	printf("\n\t\t\t�˻簡 ����Ǿ����ϴ�\t\t\t\n\n");
	
	(E_I == 1) ? (mbti[0] = 'E') : (mbti[0] = 'I');   //���⿬���� ���
	(S_N == 1) ? (mbti[1] = 'S') : (mbti[1] = 'N');
	(T_F == 1) ? (mbti[2] = 'T') : (mbti[2] = 'F');
	(J_P == 1) ? (mbti[3] = 'J') : (mbti[3] = 'P');
	mbti[4] = '\0';
	printf("'%s'���� MBTI�� %s�Դϴ�.\n\n", name, mbti);
	input(name,age,mbti);
	printf("\n��� ����Ϸ�! �ƹ�Ű�� ������ �޴��� ���ư��ϴ�");
	_getch();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void input(char *i_name,int i_age, char *i_mbti)
{
	struct Node* cuss=head;
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	strcpy_s(newnode->name,10,i_name);       //�̸� ����
	newnode->age = i_age;                    //���� ����
	strcpy_s(newnode->mbti, 5, i_mbti);      //mbti ����
	newnode->next = NULL;
	
	if (head == NULL)            //head��尡 ����������
		head = newnode;
	else
	{
		while (cuss->next != NULL)   //�� ������ ������ Ŀ�� �̵�
			cuss= cuss->next;

		cuss->next = newnode;
	}
}

void nodeswap() {

}

void nodesort() {                                    //��� �����Լ�
	struct Node* cuss = head,*temp=NULL;
	char cmp;
	int i = 5;
	while (i == 5) {
		printf("� ������ �������� �����ұ��? \n");
		printf("(E,I,S,N,T,F,J,P)�߿��� �빮�ڷ� �Է�: ");
		scanf_s("%c",&cmp,1);                   //�� �ѹ��� �������� scanf_s�� ����Ǵ°�? ���̰�����.
		
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
			printf("\n����� �� ���� �Է����ּ���.");
			system("cls");
			Sleep(1500);
		}
	}
	while (cuss->next != NULL)
	{
		if ((cuss->mbti[i] != cuss->next->mbti[i]) && (cuss->mbti[i] != cmp)) {
			temp = cuss->next;                            //�ٲܴ���� temp�� ����
			cuss->next = cuss->next->next;                //�ٲܴ���� �����ϰ� ����
			temp->next = head;                            //temp�� ����� ��带 �������� ����
			cuss = head = temp;                            //head�� temp�� �ʱ�ȭ
		}
		else
			cuss = cuss->next;
	}
}

void list()                       //��� ���(����)
{

	system("cls");
	struct Node* cuss = head;
	if (cuss == NULL)
	{
		printf("\n\n\n\t������� ���� �����ϴ�. ���� �Է��ϰ� �������ּ����\n");
		Sleep(1500);
	}
	else {
		if (cuss->next != NULL)              //��尡 �ΰ� �̻��϶� ������ ����
		{
			nodesort();
			cuss = head;                     //���� ���� �ٲ� ��尪�� �ٽ� Ŀ���� ����
		}
		printf("=============|�˻��� ���|=============\n\n");   //������� �����ü ����ڵ�
		printf(" ||����||\t||�̸�||\t||����||\n");
		
		while (cuss != NULL)
		{
			printf("    %d   \t %s     \t  %s  \n", cuss->age, cuss->name, cuss->mbti);
			cuss = cuss->next;
		}
		printf("\n�ƹ�Ű�� ������ �޴��� ���ư��ϴ�.");
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
		printf("\n\n\n\t������� ���� �����ϴ�. ���� �Է��ϰ� �������ּ����\n");
		Sleep(1500);
	}
	else {
		printf("\n\n\n\t\t�˻��� ����� �̸��� �Է��ϼ���: ");
		scanf_s("%s", s_name, 10);
		system("cls");
		printf("'%s'�˻����\n", s_name);
		while (cuss != NULL)
		{
			if (strcmp(s_name, cuss->name) == 0) {     //strcmp�� �Է��� �̸��� ������ �̸��� ����
				printf("�̸� : %s, ���� : %s \n", cuss->name, cuss->mbti);
				TF++;
			}
			else
				cuss = cuss->next;
		}
		if (TF == 0)
		{
			printf("'%s'�� �ش��ϴ� ����� �����ϴ�.", s_name);
		}
		printf("\n�ƹ�Ű�� ������ �޴��� ���ư��ϴ�.");
		_getch();
	}
}

void delete()                              //���� �Լ�
{
	struct Node* cuss = head;

	if (cuss == NULL)
	{
		system("cls");
		printf("\n\n\n\t������� ���� �����ϴ�. ���� �Է��ϰ� �������ּ����\n");
		Sleep(1500);
	}
	else {
		struct Node* pre = head, * temp = NULL;
		char d_name[10] = "";
		int TF = 0;

		system("cls");
		printf("\n\n\n\t\t������ �׸��� �̸��� �Է��ϼ���: ");
		scanf_s("%s", d_name, 10);
		system("cls");
		printf("'%s'�˻����\n", d_name);
		
		while (cuss != NULL)
		{
			if (strcmp(d_name,cuss->name) == 0) {     //strcmp�� �Է��� �̸��� ������ �̸��� ����
				printf("ã�� ��� => �̸� : %s, ���� : %s \n", cuss->name, cuss->mbti);
				TF++, temp = pre;     //���� ã���� ã������ ���� ����ּҸ� ����
			}
			pre = cuss;
			cuss=cuss->next;
		}
		
		if (TF == 0)                        //�ش��ϴ� ��尡 ������ ���
		{
			printf("'%s'�� �ش��ϴ� ����� �����ϴ�.", d_name);
			Sleep(2000);
		}
		if (TF == 1)                        //�����Ϸ��� ��尡 ������� �Ʒ� �ڵ� ����
		{
			int YN = 0;
			cuss = temp->next;
			if (temp == head)                     //���� ����� head�ΰ��
			{
				cuss = temp;                      
				head = temp->next;                //**head�� �ٽ� ����**//
			}									  
			while (1) {
				printf("\n\n\n\t\t%s�� �׸񿡼� �����Ͻðڽ��ϱ�?\n", cuss->name);
				printf("\n\t\t1)��\t\t\t\t2)�ƴϿ�\n�Է� : ");
				scanf_s("%d", &YN);
				if ((YN == 1 || YN == 2) != 1) {
					system("cls");
					printf("�ؿùٸ� ���ڸ� �Է��ϼ���.");
					Sleep(1500);
				}
				else
					break;
			}
			if (YN == 1) {   //�׸����ſ��� ���� �����������
				temp->next = cuss->next;
				free(cuss);
				printf("���� �Ϸ�!");
			}
		}
		if (TF > 1)
			printf("�ߺ��� �̸����� ���� ����\n\n");
		
		printf("\n\n�ƹ�Ű�� ������ �޴��� ���ư��ϴ�.");
		_getch();
	}
}


void shutdown_p()                    //���� �Լ�
{
	printf("\n\nMBTI�˻� ���α׷��� �����մϴ�.\n\n");
	struct Node* cuss = head,*target;
	while (cuss != NULL)
	{
		target = cuss;
		cuss = target->next;
		free(target);
	}
}