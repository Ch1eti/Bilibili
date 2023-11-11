#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void menu()
{
	printf("***********************\n");
	printf("*****   1. play   *****\n");
	printf("*****   0. exit   *****\n");
	printf("***********************\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 };//存放布置好的雷的信息(电脑看)
	char show[ROWS][COLS] = { 0 };//存放排查出的雷的信息(玩家看)
	
	//初始化棋盘
	//mine 数组在没有存放雷的信息时，都是'0'
	InitBoard(mine, ROWS, COLS, '0');
	//show 数组在没有排查雷的信息时，都是'*'
	InitBoard(show, ROWS, COLS, '*');

	//设置雷
	SetMine(mine, ROW, COL);

	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);

	//排查雷
	FindMine(mine, show, ROW, COL);
}



int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("结束游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}
