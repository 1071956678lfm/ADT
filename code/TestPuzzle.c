#include"Func.h"

int main()
{
	int  i, j;
	//int** maze;             /*���ڴ����Թ����εĶ�ά����*/
	int s;
	int repeat = 1;

	while (repeat == 1)
	{
		printf("����������������ȷ���Թ��ĳ����\n");
		scanf("%d%d", &x1, &y1);
		if (x1<3 || y1<3 || x1 % 2 == 0 || y1 % 2 == 0)                     /*�����С����ż�����޷������Թ�*/
		{
			printf("��������\n");                       /*��ʾ�������*/
			system("pause");
			return 0;
		}
		/*
		*���ߴ粻ƥ�����˳�
		*/
		maze = (int**)malloc(sizeof(int*)*y1);              /*Ϊ��ά���鶯̬���䴢��ռ�*/
		for (i = 0; i<y1; i++)
		{
			maze[i] = (int*)malloc(sizeof(int)*x1);
		}
		for (i = 0; i<x1; i++)
		{
			for (j = 0; j<y1; j++)
				maze[i][j] = 0;                          /*�Ȱ�����Ԫ�ض������*/
		}
		//������calloc ֱ��һ����λ

		for (i = 0; i<x1; i++)
		{
			for (j = 0; j<y1; j++)
			{
				if (i % 2 == 1 && j % 2 == 1)
					maze[i][j] = 1;                   /*��������������Ϊ������Ԫ�ر�Ϊ1*/
			}
		}

		GoAhead(1, 1, rand() % 4 + 1);

		for (i = 0; i<x1; i++)
		{
			for (j = 0; j<y1; j++)
			{
				print(maze[i][j]);
			}
			printf("\n");
		}

		printf("���������֣�\n 1--������Ϸ    2--�˳���Ϸ\n");    /*ѡ���Ƿ����*/
		scanf("%d", &repeat);
	}
}

