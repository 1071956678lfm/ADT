#include<stdio.h>
#include <malloc.h>
#include <stdlib.h>

//����˼·����ѡ�����ٽ����˶�����
int IsEnd(x, y);
void generateOfNoLimit(int x, int y);
void generateOfOneLimit(int x, int y, int limit);
void generareOfTwoLimit(int x, int y, int limit1, int limit2);
void generareOfThreeLimit(int x, int y, int limit1, int limit2, int limit3);  //����ѡ����
void back(int x, int y);                //������
void print(int x);
void RightWord(int x, int y);
void LeftWord(int x, int y);
void UpWord(int x, int y);
void DownWord(int x, int y);
void GoAhead(int x, int y, int dire);   //ͷ�ļ���������
void MoveOut(int x, int y, int dire);   //�˶�������
int x1, y1;         
int** maze;             /*���ڴ����Թ����εĶ�ά����*/

void generateOfNoLimit(int x, int y)
{
	int dire;/*���Ʒ���*/
	dire = rand() % 4 + 1;//���������1,2,3,4 �����ĸ�����
	MoveOut(x, y, dire);
}
void generateOfOneLimit(int x, int y, int limit){
	int dire=limit;
	while (dire==limit)
		dire = rand() % 4 + 1;
	MoveOut(x, y, dire);
}
void generareOfTwoLimit(int x, int y, int limit1, int limit2){
	int dire=limit1;
	while (dire==limit1||dire==limit2)
		dire = dire = rand() % 4 + 1;
	MoveOut(x, y, dire);
}
void generareOfThreeLimit(int x, int y, int limit1, int limit2, int limit3){
	int dire=limit1;
	while (dire == limit1 || dire == limit2||dire==limit3)
		dire = dire = rand() % 4 + 1;
	MoveOut(x, y, dire);
}

/*�������ҵ��ҹ���·*/
void back(int x, int y){
	
}
void print(int x){
	if (x == 0)
	{
		printf("��");
	}
	else if (x == 1)
	{
		printf("��");
	}
	else
	{
		printf("  ");
	}
}
void RightWord(int x, int y){
	if (maze[x + 2][y]!=2)
		maze[x + 1][y] = 2;
	return;
		
}
void LeftWord(int x, int y){
	if (maze[x - 2][y]!=2)
		maze[x - 1][y] = 2;
	return;
}
void UpWord(int x, int y){
	if (maze[x][y+2]!=2)
		maze[x][y + 1] = 2;
	return;
}
void DownWord(int x, int y){
	if (maze[x][y-2]!=2)
		maze[x][y - 1] = 2;
	return;
}
void GoAhead(int x, int y, int dire){
	if (x<1 || y<1 || x>x1 - 1 || y>y1 - 1)
	{
		if (x < 1) {
			x += 2;
			//back(x, y, 2);
		}
		if (y < 1) {
			y += 2;
			//back(x, y, 4);
		}
		if (x > x1 - 1) {
			x -= 2;
			//back(x, y, 1);
		}
		if (y > y1 - 1) {
			y -= 2;
			//back(x, y, 3);
		}
	}
	maze[x][y] = 2;
	do
	{
		if (x<1 || y<1 || x>x1 - 1 || y>y1 - 1)
		{
			if (x < 1) {
				x += 2;
				//back(x, y, 2);
			}
			if (y < 1) {
				y += 2;
				//back(x, y, 4);
			}
			if (x > x1 - 1) {
				x -= 2;
				//back(x, y, 1);
			}
			if (y > y1 - 1) {
				y -= 2;
				//back(x, y, 3);
			}
		}
		MoveOut(x, y, dire);//�߳�ȥ�˵�һ��
		if (dire == 1){  maze[x][y] = 2; x = x + 2;}
		if (dire == 2){  maze[x][y] = 2;x = x - 2; }
		if (dire == 3){  maze[x][y] = 2; y = y + 2;}
		if (dire == 4){ maze[x][y] = 2;y = y - 2;}
		dire = rand() % 4 + 1;
		int k = 0;
		for (int i = 0; i < x1; i++){
			for (int j = 0; j < y1; j++)
				if (maze[i][j] == 1)
					k = 1;
		}
		if (!k)
			break;
		if (IsEnd(x, y))
		{
			if (x < 1) {
				x += 2;
				//back(x, y, 2);
			}
			if (y < 1) {
				y += 2;
				//back(x, y, 4);
			}
			if (x > x1 - 1) {
				x -= 2;
				//back(x, y, 1);
			}
			if (y > y1 - 1) {
				y -= 2;
				//back(x, y, 3);
			}
			back(x, y);
		}
	} while (1);
	return;
}
void MoveOut(int x, int y, int dire){
	if (dire == 1){//rightWord
		//���½�
		if (x == x1 - 2 && y == 1)generareOfTwoLimit(x,y,1, 4);
		//�Ҳ�
		else if (x == x1 - 2 && y != 1 && y != y1 - 1)generateOfOneLimit(x, y, 1);
		//���Ͻ�
		else if (x == x1 - 2 && y == y1 - 1)generareOfTwoLimit(x, y, 1, 3);
		else 
			RightWord(x, y);
	}
	if (dire == 2){//������
		//���Ͻ�
		if (x == 1 && y == y1 - 2)generareOfTwoLimit(x, y, 2, 4);
		//���
		else if (x == 1 && y != y1 - 2 && y != 1)generateOfOneLimit(x, y, 2);
		//���½�
		else if (x == 1 && y == 1)generareOfTwoLimit(x, y, 2, 4);
		else
			LeftWord(x, y);
	}
	if (dire == 3){//������
		//���Ͻ�
		if (y == y1 - 2 && x == 1)generareOfTwoLimit(x, y, 3, 2);
		//�ϲ�
		else if (y == y1 - 2 && x != 1 && x != x1 - 2)generateOfOneLimit(x, y, 3);
		//���Ͻ�
		else if (y == y1 - 2 && x == x1 - 2)generareOfTwoLimit(x, y, 1, 3);
		else
			UpWord(x, y);
	}
	if (dire == 4){//������
		//���½�
		if (y == 1 && x == 1)generareOfTwoLimit(x, y, 2, 4);
		//�²�
		else if (y == 1 && x != 1 && x != x1 - 2)generateOfOneLimit(x, y, 4);
		//���½�
		else if (y == 1 && x== x1 - 2)generareOfTwoLimit(x, y, 4, 1);
		else
			DownWord(x, y);
	}

}
int IsEnd(x, y){
	if (x<1 || y<1 || x>x1 - 1 || y>y1 - 1){
		if (x < 1) {
			x += 2;
			//back(x, y, 2);
		}
		if (y < 1) {
			y += 2;
			//back(x, y, 4);
		}
		if (x > x1 - 1) {
			x -= 2;
			//back(x, y, 1);
		}
		if (y > y1 - 1) {
			y -= 2;
			//back(x, y, 3);
		}
	}
	if ((maze[x - 1][y] + maze[x + 1][y] + maze[x][y + 1] + maze[x][y - 1]) == 2)
		return 1;
	return 0;
}