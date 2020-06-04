#include<graphics.h>
#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;

#define PIC_SIZE 61
#define KEY_UP 'w'
#define KEY_DOWN 's'
#define KEY_LEFT 'a'
#define KEY_RIGHT 'd'
#define KEY_Q  'q'
#define COLS  12
#define LINES 9
void gameControl(enum DIRCTION dirct);

IMAGE pic[6];
//ǽ:0  �ذ�: 1  ����Ŀ�ĵ�: 2  С��:3  ����: 4  ��������Ŀ�� :5
int map[LINES][COLS] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
	{ 0, 1, 4, 1, 0, 2, 1, 0, 2, 1, 0, 0 },
	{ 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0 },
	{ 0, 1, 0, 2, 0, 1, 1, 4, 1, 1, 1, 0 },
	{ 0, 1, 1, 1, 0, 3, 1, 1, 1, 4, 1, 0 },
	{ 0, 1, 2, 1, 1, 4, 1, 1, 1, 1, 1, 0 },
	{ 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};


enum unit{
	wall,
	flor,
	des,
	man,
	box
};
enum DIRCTION{
	UP,
	DOWN,
	LEFT,
	RIGHT

};
struct pos{   //��ʾ�˵�λ��
	int X;
	int Y;

};
struct pos men;



void changePic(int line, int col, enum unit u){
	map[line][col] = u;
	putimage(110 + col*PIC_SIZE, 130 + line*PIC_SIZE, &pic[u]);

}


void gameControl(enum DIRCTION dirct){
	int x = men.X;
	int y = men.Y;
	struct pos nextPos = men;
	switch (dirct){
	case UP:
		nextPos.X--;
		break;
	case DOWN:
		nextPos.X++;
		break;
	case LEFT:
		nextPos.Y--;
		break;
	case RIGHT:
		nextPos.Y++;
		break;
	}


	if (dirct == UP){
		if (x>0 && map[nextPos.X][nextPos.Y] == flor){
			changePic(nextPos.X, nextPos.Y, man); //С��ǰ��λ�� ��ΪС��
			changePic(men.X, men.Y, flor);
			men = nextPos;
			
		}
		
	}
	else if (dirct == RIGHT){
		if (x>0 && map[nextPos.X][nextPos.Y] == flor){
			changePic(nextPos.X, nextPos.Y, man); //С��ǰ��λ�� ��ΪС��
			changePic(men.X, men.Y, flor);
			men = nextPos;

		}
		
		
	}
	else if (dirct == DOWN){
		if (x>0 && map[nextPos.X][nextPos.Y] == flor){
			changePic(nextPos.X, nextPos.Y, man); //С��ǰ��λ�� ��ΪС��
			changePic(men.X, men.Y, flor);
			men = nextPos;

		}
	}
	else if (dirct==LEFT){
	
		if (x>0 && map[nextPos.X][nextPos.Y] == flor){
			changePic(nextPos.X, nextPos.Y, man); //С��ǰ��λ�� ��ΪС��
			changePic(men.X, men.Y, flor);
			men = nextPos;

		}
	
	}


}


int main(){
	IMAGE bg_img;
	char picName[6][32];
	
	initgraph(960, 768);
	loadimage(&bg_img, _T("blackground.bmp"), 960, 768, true); //����ͼƬ
	putimage(0, 0, &bg_img); //ʹ��ͼƬ
	sprintf_s(picName[wall], "%s", "wall_right.bmp");
	sprintf_s(picName[flor], "%s", "floor.bmp");
	sprintf_s(picName[des], "%s", "des.bmp");
	sprintf_s(picName[man], "%s", "man.bmp");
	sprintf_s(picName[box], "%s", "box.bmp");

	for (int i = 0; i < 5; i++){
		loadimage(&pic[i], picName[i], PIC_SIZE, PIC_SIZE, true); //����Ԫ��ͼƬ

	}

	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 12; j++){
			if (map[i][j]==3){
				men.X = i;
				men.Y = j;
			}
			putimage(110 + j*PIC_SIZE, 130 + i*PIC_SIZE, &pic[map[i][j]]); //����������еľ���ֵ ��Ӧ��ʾͼƬ���±�  ��Ϊ�����ֵ�Ǽ� ��Ӧ�ľ����±�Ϊ����ͼƬ

		}
	}
	//��Ϸ����
	bool quit = false;
	do{
		if (_kbhit()){
			char ch = _getch();
			if (ch == KEY_UP){
				gameControl(UP);
			}
			else if (ch == KEY_DOWN){
				gameControl(DOWN);
			}
			else if (ch == KEY_LEFT){
				gameControl(LEFT);
			}
			else if (ch == KEY_RIGHT){
				gameControl(RIGHT);
			}
			else if (ch == KEY_Q){
				quit = true;
			}

		}
		Sleep(100);
	} while (quit == false);




	
	
	
	system("pause");
	closegraph();
    return 0;
}