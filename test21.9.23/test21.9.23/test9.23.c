#define _CRT_SECURE_NO_WARNINGS 1


#include<Stdio.h>

//ð������
//void order(int* arr,int len)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < len-1; i++)
//	{
//		for (j = 0; j < len- 1- i; j++)
//		{
//			if (arr[j] > *(arr+j+1))         //arr[j]== *(arr+j)
//			{
//				int temp = *(arr + j);
//				*(arr + j) = *(arr + j + 1);
//				*(arr + j + 1) = temp;
//			}
//		}
//	}
//}
//
//void print(int* p,int len)
//{
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		printf("%d ", *p++);
//	}
//}
//int main()
//{
//	int arr[10] = { 0,55,65,1,2,7,6,22,11,10 };
//	int len = 0;
//	int i = 0;
//	len = sizeof(arr) / sizeof(arr[0]);
//	order(arr, len);
//	print(arr,len);
//	return 0;
//}

/****************
������
***************/
#include"game.h"

menu()
{
	printf("****************   ������    *****************\n");
	printf("**********************************************\n");
	printf("****************   1.play   ******************\n");
	printf("****************   0.exit   ******************\n");
	printf("**********************************************\n");
}
void game()
{
	char Win = 0;
	char board[ROW][COL];   //��������

	//��ʼ������
	InitBoard(board, ROW , COL);
	
	//��ӡ����
	Disboard(board, ROW, COL);

	while (1)
	{
		//�������
		PlayerMove(board, ROW, COL);
		Disboard(board, ROW, COL);
	    Win=IsWin(board, ROW, COL);
		if (Win !='J')
		{
			break;
		}
		//��������
		ComputerMove(board, ROW, COL);
		Disboard(board, ROW, COL);
		Win = IsWin(board, ROW, COL);
		if (Win != 'J')
		{
			break;
		}
	}
	if (Win == '*')
	{
		printf("���ʤ����\n");
	}
	else if (Win == '#')
	{
		printf("����ʤ����\n");
	}
	else 
	{
		printf("ƽ�֣�\n");
	}

}
int main()
{
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("��ѡ��(1 or 0)>>>");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("�˳���Ϸ\n");
			break;
		case 1:
			printf("������Ϸ\n");
			break;
		default:
			printf("ѡ����� ������ѡ��\n");
		}
		if (input == 1)
		{
			game();
		}

	} while (input);
	return 0;
}