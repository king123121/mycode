#define _CRT_SECURE_NO_WARNINGS
#include  "game.h"
void InitBoard(char board[ROW][COL], int row, int col)//用char类型接收 row行 col列
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}//初始化棋盘



//void Displayboard(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
//		if (i < row - 1)
//			printf("---|---|---\n");
//	}
//}       //只能3*3!!

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
}//更高效，可以应对不听大小的棋盘，如3*3  10*10.....


//玩家下棋回合
void playermove(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("玩家下棋:\n");
	
	while (1)
	{
		printf("请输入坐标:");
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
				printf("被占用,再试一次");
			}
		}
		else
		{
			printf("非法,再输入\n");
		}
	}
}

void computermove(char board[ROW][COL], int row, int col)
{
	printf("电脑下棋：\n");
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
{	//先判断行 再判断列 最后对角线
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
