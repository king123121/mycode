#define _CRT_SECURE_NO_WARNINGS
#include  "game.h"
int  menu()
{
	printf("************************\n");
	printf("*   1.play    0.exit   *\n");
	printf("************************\n");
	return 0;
}

void game()
{
	char ret;
	char board[ROW][COL] = { 0 };//���̴�#��*�ţ���char�����ַ�
	//��ʼ������
	InitBoard(board, ROW, COL);
	Displayboard(board, ROW, COL);//��ӡ����
	while (1)
	{	
		playermove(board, ROW, COL);//�������
		
		//�ж���Ӯ
		ret = iswin(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
		Displayboard(board, ROW, COL);//��ӡ����
		computermove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		//�ж���Ӯ
		ret = iswin(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
		
	}
	if (ret == '*')
	{
		printf("���ʤ��\n");
	}
	else if (ret == '#')
	{
		printf("����ʤ��\n");
	}
	else 
	{
		printf("ƽ��\n");
	}
}
	
int main()
{		
	srand((unsigned int)time(NULL));
	int input = 0;
	
	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("exit\n");
			break;
		default:
			printf("worry!\n");
			break;
		}

	} while (input);
	return 0;
}