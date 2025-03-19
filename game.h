#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define ROW 3
#define COL 3


//          函数声明！！！

void InitBoard(char board[ROW][COL], int row, int col);//用char类型接收 row行 col列
//初始化棋盘

//打印欺棋盘
void Displayboard(char board[ROW][COL], int row, int col);

//玩家下棋回合
void playermove(char board[ROW][COL], int row, int col);

//人机下棋
//找空白位置下
void computermove(char board[ROW][COL], int row, int col);


//判断输赢    谁赢？平局？继续
char iswin(char board[ROW][COL], int row, int col);
//'c'是继续
//‘#’是电脑赢
//‘*’是玩家赢
//‘Q’平ju