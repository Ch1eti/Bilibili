#define _CRT_SECURE_NO_WARNINGS

#include "game.h"


void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("------ɨ����Ϸ------\n");
	//�����б��
	for (j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	//�����б��
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}

	printf("------ɨ����Ϸ------\n");
}

void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;

	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;

		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	int i = 0;
	int j = 0;
	int count = 0;

	for (i = x - 1; i <= x + 1; i++)
	{
		for (j = y - 1 ;j <= y + 1; j++)
		{
			if (mine[i][j] == '1')
			{
				count++;
			}
		}
	}
	return count;
}



void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int find = 0;//�Ѿ��Ų���Ĳ����׵�λ�õĸ���

	while (find < row * col - EASY_COUNT)
	{
		printf("������Ҫ�Ų������:>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= row)
		{
			//�ж���ѡ�����Ƿ��Ų��
			if (show[x][y] != '*')
			{
				printf("�������Ѿ����Ų���ˣ������ظ��Ų�\n");
			}
			else
			{
				//����Ų��λ������
				if (mine[x][y] == '1')
				{
					printf("���ź����㱻ը����\n");
					DisplayBoard(mine, ROW, COL);
					break;
				}
				//����Ų��λ�ò�����
				else
				{
					find++;
					//ͳ����ѡ������Χ�׵ĸ���
					int count = get_mine_count(mine, x, y);
					show[x][y] = count + '0';//ת���������ַ�
					DisplayBoard(show, ROW, COL);
				}

			}

		}
		else
		{
			printf("�Ƿ����룬����������\n");
		}
	
	}
	if (find == row * col - EASY_COUNT)
	{
		printf("��ϲ�㣬���׳ɹ�\n");
		DisplayBoard(mine, ROW, COL);
	}
}