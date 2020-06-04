#include<iostream>
#include<windows.h>
#include<string>
#include<conio.h>
using namespace std;
#define WIDTH 100
#define HIGH  30
//设置控制台的列和行
void setConsole(int a,int b){
	char cmd[128];
	sprintf_s(cmd, "mode con:cols=%d lines=%d", a, b);
	system(cmd);

}
//给出一个字符串 居中对齐  
void printMiddle(string str){
	//用屏幕(WIDTH -str.length())/2 就等于两边的空格数 然后输出空格数 即可
	int space = (WIDTH - str.length()) / 2;
	for (int i = 0; i < space;i++){
		
		cout << " ";
	}
	cout << str<<endl;
}


//将给的字符串标题居中 将给的字符串数组 居中左对齐
void memu(string str,string menu[],unsigned int count){
	printMiddle(str);
	//居中输出菜单内容
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

//输入密码 并用*号隐藏
string inputPwd(char pwd[], int max_len){
	char c;
	string str = "请输入密码:";
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

//判断密码是否正确 
void judgePwd(){
	char pwd[16];

	//需要不停的判断密码是否正确
	while (1){
		system("cls");
		 inputPwd(pwd, sizeof(pwd));   //循环输入密码 不对 就继续输入  放在循环体内
		if (strcmp(pwd,"88888888")==0){
		
			break;
		
		}
		else{
			cout << "密码错误!"<<endl;
			system("pause");
			
		}
	}
}
int Max(int a1, int a2, int a3){
	int max = 0;
	cout << "输入3个比较的数:";
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

	string str = "-----------TPLINK路由管理系统-----------";
	string menu[] = {
		"1.IP地址设置.",
		"2.用户名和密码管理.",
		"3.退出."
	};
	memu(str,menu,sizeof(menu)/sizeof(menu[0])); //计算出字符串数组的个数 sizeof(menu)/sizeof(menu[0]

	int max = Max(a1,a2,a3);
	cout << "最大值是:" << max << endl;

	cout << "两个整数相加:";
	cin >> a1 >> a2;
	system("cls");
	cout << a1<<"+"<<a2<<"="<<add(a1, a2)<<endl;

	cout << "三个整数相加:";
	cin >> a1 >> a2>>a3;
	system("cls");
	cout << a1 << "+" << a2 <<"+"<<a3<<"="<< add(a1, a2, a3) << endl;

	cout << "两个单精度浮点数相加:";
	cin >> b1 >> b2;
	system("cls");
	cout <<b1<<"+"<<b2<<"="<<add(b1, b2);
	
	system("pause");
	return 0;
}