#include<iostream>
#include<windows.h>
#include<string>
#include<conio.h>
using namespace std;
#define WIDTH 100
#define HIGH  30
//���ÿ���̨���к���
void setConsole(int a,int b){
	char cmd[128];
	sprintf_s(cmd, "mode con:cols=%d lines=%d", a, b);
	system(cmd);

}
//����һ���ַ��� ���ж���  
void printMiddle(string str){
	//����Ļ(WIDTH -str.length())/2 �͵������ߵĿո��� Ȼ������ո��� ����
	int space = (WIDTH - str.length()) / 2;
	for (int i = 0; i < space;i++){
		
		cout << " ";
	}
	cout << str<<endl;
}


//�������ַ���������� �������ַ������� ���������
void memu(string str,string menu[],unsigned int count){
	printMiddle(str);
	//��������˵�����
	int max = 0;
	for (int i = 0; i < (int)count; i++){
		if (menu[i].length()>(unsigned int) max){
			max = menu[i].length();
		}
	}

	int leftspace = (WIDTH - max) / 2;
	for (int i = 0; i < (int)count; i++){
		for (int j = 0; j < leftspace;j++){
			cout << " ";
		}
		cout << menu[i] << endl;
	}
}

//�������� ����*������
string inputPwd(char pwd[], int max_len){
	char c;
	string str = "����������:";
	int i = 0;
	cout << str;
	while (1){
		
		c = _getch();
		if (c == '\r'){
			pwd[i] = '\0';
			return pwd;
		}
		pwd[i++] = c;
		printf("*");
	}
}

//�ж������Ƿ���ȷ 
void judgePwd(){
	char pwd[16];

	//��Ҫ��ͣ���ж������Ƿ���ȷ
	while (1){
		system("cls");
		 inputPwd(pwd, sizeof(pwd));   //ѭ���������� ���� �ͼ�������  ����ѭ������
		if (strcmp(pwd,"88888888")==0){
		
			break;
		
		}
		else{
			cout << "�������!"<<endl;
			system("pause");
			
		}
	}
}
int Max(int a1, int a2, int a3){
	int max = 0;
	cout << "����3���Ƚϵ���:";
	cin >> a1 >> a2 >> a3;
	if (a1>a3){
		if (a1>a2){
			max = a1;
		}
		else{
			max = a2;
		}
	}
	else{
		if (a2>a3){
			max = a2;
		}
		else{
			max = a3;
		}
	
	}
	return max;
}

int add(int a, int b){
	int s = a + b;
	return s;
}
int add(int a, int b,int c){
	int s = a + b+c;
	return s;
}
float add(float a, float b){
	float s = a + b;
	return s;
}

int main(){
	int a1=0, a2=0, a3=0;
	float b1 = 0, b2 = 0;
	
	judgePwd();
	setConsole(WIDTH,HIGH);

	string str = "-----------TPLINK·�ɹ���ϵͳ-----------";
	string menu[] = {
		"1.IP��ַ����.",
		"2.�û������������.",
		"3.�˳�."
	};
	memu(str,menu,sizeof(menu)/sizeof(menu[0])); //������ַ�������ĸ��� sizeof(menu)/sizeof(menu[0]

	int max = Max(a1,a2,a3);
	cout << "���ֵ��:" << max << endl;

	cout << "�����������:";
	cin >> a1 >> a2;
	system("cls");
	cout << a1<<"+"<<a2<<"="<<add(a1, a2)<<endl;

	cout << "�����������:";
	cin >> a1 >> a2>>a3;
	system("cls");
	cout << a1 << "+" << a2 <<"+"<<a3<<"="<< add(a1, a2, a3) << endl;

	cout << "���������ȸ��������:";
	cin >> b1 >> b2;
	system("cls");
	cout <<b1<<"+"<<b2<<"="<<add(b1, b2);
	
	system("pause");
	return 0;
}