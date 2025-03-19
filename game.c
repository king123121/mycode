#define _CRT_SECURE_NO_WARNINGS
#include  "game.h"
void InitBoard(char board[ROW][COL], int row, int col)//��char���ͽ��� row�� col��
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}//��ʼ������



//void Displayboard(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
//		if (i < row - 1)
//			printf("---|---|---\n");
//	}
//}       //ֻ��3*3!!

void Displayboard(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			int j = 0;
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}//����Ч������Ӧ�Բ�����С�����̣���3*3  10*10.....


//�������غ�
void playermove(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("�������:\n");
	
	while (1)
	{
		printf("����������:");
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
				printf("��ռ��,����һ��");
			}
		}
		else
		{
			printf("�Ƿ�,������\n");
		}
	}
}

void computermove(char board[ROW][COL], int row, int col)
{
	printf("�������壺\n");
	int x = 0;
	int y = 0;
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


int isfull(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}	
		}
	}
	return 1;
}

char iswin(char board[ROW][COL], int row, int col)
{	//���ж��� ���ж��� ���Խ���
	int i ,j,ret= 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1]&& board[i][1]== board[i][2]&& board[i][1]!=' ')
		{
			return ret = board[i][1];
		}
	}
	for (j = 0; j < row; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
		{
			return ret = board[1][j];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return ret = board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return ret = board[1][1];
	}
	
	if (isfull(board, row, col))
	{
		return 'Q';
	}
	return 'c';
}
