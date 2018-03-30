#include<stdio.h>
#include <malloc.h>
#include <stdlib.h>
void generate(int x, int y);
void back(int x, int y);/*�����ߵĺ���*/
void print(int x);
void RightWord(int x, int y);
void LeftWord(int x, int y);
void UpWord(int x, int y);
void DownWord(int x, int y);

int x1, y1;         
int** maze;             /*���ڴ����Թ����εĶ�ά����*/

void generate(int x, int y)
{
	int dire;/*���Ʒ���*/

	if (x<1 || y<1 || x>x1 - 1 || y>y1 - 1)
	{
		if (x<1) x += 2;
		if (y<1) y += 2;
		if (x>x1 - 1) x -= 2;
		if (y>y1 - 1) y -= 2;
		back(x, y);	/*�������Ե��������*/
	}
	maze[x][y] = 2;

	dire = rand() % 4 + 1;//���������1,2,3,4 �����ĸ�����

	if (dire == 1){
		if (x == x1 - 2)//�����ߣ��������������Ҳ���������
			back(x, y);
		else
			RightWord(x, y);
	}
	if (dire == 2){
		if (x == 1)
			back(x, y);
		else
			LeftWord(x, y);
	}
	if (dire == 3){
		if (y == y1 - 2)
			back(x, y);
		else
			UpWord(x, y);
	}
	if (dire == 4){
		if (y == 1)
			back(x, y);

		else
			DownWord(x, y);
	}
	back(x, y);		/*������߲�ͨ��������*/
	return;
}

void back(int x, int y)
{
	if (maze[x + 1][y] == 2)/*�������ҵ��ҹ���·*/
	{
		x = x + 2;
		generate(x, y);
	}
	if (maze[x - 1][y] == 2)
	{
		x = x - 2;
		generate(x, y);
	}
	if (maze[x][y + 1] == 2)
	{
		y = y + 2;
		generate(x, y);
	}
	if (maze[x][y - 1] == 2)
	{
		y = y - 2;
		generate(x, y);
	}

	return;
}
void print(int x)

{
//	if (x == 0)
//	{
//	printf("��");
//	}
//	else if (x == 1)
//	{
//		printf("��");
//	}
	if (x==1)
	{
		printf("  ");
	}
	if (x == 2){
		printf("��");
	}
}
void RightWord(int x, int y){
	if (maze[x + 2][y] == 1)
	{
		maze[x + 1][y] = 2;
		x = x + 2;
		generate(x, y);
	}
	else				/*��������߾ͼ�����������·*/
	{
		generate(x, y);
	}
}
void LeftWord(int x, int y){
	if (maze[x - 2][y] == 1)
	{
		maze[x - 1][y] = 2;
		x = x - 2;
		generate(x, y);
	}
	else
	{
		generate(x, y);
	}

}
void UpWord(int x, int y){
	if (maze[x][y + 2] == 1)
	{
		maze[x][y + 1] = 2;
		y = y + 2;
		generate(x, y);
	}
	else
	{
		generate(x, y);
	}
}
void DownWord(int x, int y){
	if (maze[x][y - 2] == 1)
	{
		maze[x][y - 1] = 2;
		y = y - 2;
		generate(x, y);
	}
	else
	{
		generate(x, y);
	}
}