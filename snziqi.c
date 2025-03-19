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
	char board[ROW][COL] = { 0 };//∆Â≈Ã¥Ê#∫Õ*∫≈£¨”√char¿¥¥Ê◊÷∑˚
	//≥ı ºªØ∆Â≈Ã
	InitBoard(board, ROW, COL);
	Displayboard(board, ROW, COL);//¥Ú”°∆Â≈Ã
	while (1)
	{	
		playermove(board, ROW, COL);//ÕÊº“ ‰»Î
		
		//≈–∂œ ‰”Æ
		ret = iswin(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
		Displayboard(board, ROW, COL);//¥Ú”°∆Â≈Ã
		computermove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		//≈–∂œ ‰”Æ
		ret = iswin(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
		
	}
	if (ret == '*')
	{
		printf("ÕÊº“ §¿˚\n");
	}
	else if (ret == '#')
	{
		printf("µÁƒ‘ §¿˚\n");
	}
	else 
	{
		printf("∆Ωæ÷\n");
	}
}
	
int main()
{		
	srand((unsigned int)time(NULL));
	int input = 0;
	
	do
	{
		menu();
		printf("«Î—°‘Ò£∫");
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