#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define ROW 3
#define COL 3


//          ��������������

void InitBoard(char board[ROW][COL], int row, int col);//��char���ͽ��� row�� col��
//��ʼ������

//��ӡ������
void Displayboard(char board[ROW][COL], int row, int col);

//�������غ�
void playermove(char board[ROW][COL], int row, int col);

//�˻�����
//�ҿհ�λ����
void computermove(char board[ROW][COL], int row, int col);


//�ж���Ӯ    ˭Ӯ��ƽ�֣�����
char iswin(char board[ROW][COL], int row, int col);
//'c'�Ǽ���
//��#���ǵ���Ӯ
//��*�������Ӯ
//��Q��ƽju