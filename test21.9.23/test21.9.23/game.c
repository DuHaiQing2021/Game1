#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
//��ʼ�����̺���
void InitBoard(char board[ROW][COL],int row,int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}


//���̷ָ�
void Disboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
		}
		printf("\n");
	}

}

//�������
void PlayerMove(char board[ROW][COL], int row, int col) 
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("(�����)���������꣺>>>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("�����ѱ�ռ�ã�\n");
			}
		}
		else
		{
			printf("����Ƿ� ������Χ\n");
		}
	}
}

//��������
void ComputerMove(char board[ROW][COL], int row, int col)
{
	unsigned int x = 0;
	unsigned int y = 0;

	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

 //�ж��Ƿ�ʤ��
/******************
���أ�
     *--���ʤ��
	 #--����ʤ��
	 p--ƽ��
	 j--����
******************/
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;

	//�ж���
	for (i = 0; i < row; i++)
	{
		if (board[i][0] != ' ' &&
			board[i][0] == board[i][1] &&
			board[i][0] == board[i][2])
		{
			return board[i][0];
		}
			
	}

	//�ж���
	for (j = 0; j < col; j++)
	{
		if (board[0][j] != ' ' &&
			board[0][j] == board[1][j] &&
			board[0][j] == board[2][j])
		{
			return board[0][j];
		}
	}

	//�ж϶Խ���
	if (board[0][0] != ' ' &&
		board[0][0] == board[1][1] &&
		board[0][0] == board[2][2])
	{
		return board[0][0];
	}
	if (board[2][0] != ' ' &&
		board[2][0] == board[1][1] &&
		board[2][0] == board[0][2])
	{
		return board[2][0];
	}

	//�ж��Ƿ����
	for(i=0;i<row;i++)
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 'J';
			}

		}
	return 'P';
}
