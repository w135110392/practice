#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<iomanip>
using namespace std;
void pyramids(){
	int rows = 0;

	scanf_s("%d", &rows, sizeof(rows)); //第一行打印一列 
	/*
	空格和要打印的“*”都跟输入的行数关联起来
	*
	***
	*****  空格 rows-i  * 2的倍数-1 也就是  2*i-1

	*/
	for (int i = 1; i <= rows; i++){
		//打印空格
		for (int j = 0; j < rows - i; j++){

			printf(" ");
		}
		for (int j = 0; j <(2 * i) - 1; j++){

			printf("*");
		}
		printf("\n"); //注意
	}
}

void mulTable(){
	int width = 2;
	//九行 每行一列 每列为当前的列数乘以行数
	for (int i = 1; i <= 14;i++){
		for (int j = 1; j <= i;j++){
			/*width = (j == 1) ? 1 : 2;*/
			
			cout << j << "*" << left << setw(width) << i << "=" << left << setw(3) << i*j << " ";
		
		}
		printf("\n");
	}

}
void daffodil(){
	printf("水仙花数有:");
	int a, b, c;
	for (int i = 100; i <= 999;i++){ //水仙花数是三位 就是从100开始
		a = i / 100;
		b = (i / 10) % 10; //取余是取十位数的个位  取商是取十位数的十位 对百位数取余会余下两位 
		c = i % 10;
		if (a*a*a+b*b*b+c*c*c==i){
			printf("%d  ",i);
		}
	}
	printf("\n");
}
void wenBo(){
	//输出结果 1 1 2 3 5 8 13 21 ......

	int  n; //a为第一个值 b为第二个值 value 为a+b的值  n为输入要打印的个数
	long long a = 1, b = 1, value;
	cin >> n;
	if (n==1){
	
		cout << "1"<<" ";

	}	
	if (n == 2){

		cout << "1 1"<<"";

	}
	if (n>2){
	cout << "1 1"<<" ";
	for (int i = 0; i < n;i++){
	
		value = a + b;
		a = b;
		b = value;
		cout << value << " ";
		}
	}
}
//输入一个十进制正整数 转为二进制数
//倒除法 取余 取反 n%2  n%2==0

void decimalToBinary(){
	int n=0;
	int ret[32];
	int i=0;
	cin >> n;
	//把每次的余数用数组保存起来
	if (n>0){
		while(!n%2==0){
			ret[i] = n % 2;
			n = n / 2;               //n/2来表示剩下的商 直接保存到n 再去取余
			i++;
			}
		}
	
	for (i--; i >= 0;i--){ //输出已知数组 直接i--
	
		cout << ret[i];
	 }
	cout << endl;
	}
void arr(){
	int i = 4;
	int arr[] = { 1, 2, 4, 8 };

	for (i--; i >= 0;i--){  //输出已知数组 直接i--
	
		cout << arr[i]<<" ";
	
	}

}

void binaryToDecimal(){ //先知道二进制的权值 在看有没有 1位有 乘以1 0就乘以0 再把权值相加
	//按权相加法
	//100101     2^5+2^4+2^3+2^2+2^1+2^0  1011=2^3*1+2^2*0+2^1*1+2^0*1=8+0+2+1=11
	//          =32*1+16*0+8*0+4+2*0+1
	//          =32+0+0+4+0+1
	//          =37
	char ret[64] ;
	int p = 1;
	int sum = 0;
	cin >> ret;
	for (int i = strlen(ret) - 1; i >= 0;i--){
		int x = ret[i] - '0';
		sum += x*p;
		p *= 2;   //每进入下一位 权值乘以2
		
	}
	cout << sum;
}
//输入一个字符串 然后反转输出
void str(){
	char str[128];
	scanf_s("%s",str,sizeof(str));
	
	for (int i = strlen(str) - 1; i >= 0;i--){
			cout << str[i];
		}
	cout << endl;

}
//千钱百鸡 经典算法
void buyChicken(){
	//1000块钱 要买100鸡  公鸡50/只 母鸡 30/只 小鸡 10/3只 一共有多少种买法
	int n_max=1000/50, m_max=1000/30, k; //计算出1000块 每一种鸡 最多能买多少只 
	//用每一种鸡每一只的钱乘以可能的只数相加=1000   满足条件 输出 每种鸡的只数
	for (int i =1; i <= n_max;i++){
		for (int j = 1; j <= m_max;j++){
			k = 100 - i - j;
			if (k%3==0&&i * 50 + j * 30 + (k / 3) * 10 == 1000){
			
				cout << "公鸡为" << i << "只" << endl
					<< "母鸡为" << j << "只" << endl
					<< "小鸡为" << k << "只" << endl;
				cout << endl;
				}
			}
		}
	
}
void wordsReverse(){
	char str[256];
	int i = 0; //跳过空格 指向第一个字母
	int j = 0; //跳过字母 指向单词后的第一个空格
	gets_s(str,sizeof(str)); //输入字符串
	while (str[i] != '\0'){
	 //当i指向空格的时候跳过 循环结束后 i指向第一个字母
		while (str[i] == ' ')i++;
		j = i; //把i给j 做为跳过单词的起始位置
		//用j来跳过字母 直到单词结束  循环结束后 j指向单词后的第一个空格
		while (str[j] != ' '&&str[j] != '\0')j++;
		//单词的第一个位置确定了 为i 最后一个位置确定了 为j-1 开始逆转
		for (int k1 = i, k2 = j - 1; k1 < k2;k1++,k2--){
		
			char tmp = str[k1];
			str[k1] = str[k2];
			str[k2] = tmp;
		}
		//继续下一个单词 再把j为i的起始位置
		i = j;
	}
	//整个逆转 输出 i-1为循环结束位置
	for (int k1 = 0, k2 = i - 1; k1 < k2;k1++,k2--){
	
		char tmp = str[k1];
		str[k1] = str[k2];
		str[k2] = tmp;
	}
	cout << str << endl;
	}
	


int main(){
	//打印金字塔
	//pyramids();
	//9*9乘法表
	//mulTable();
	//水仙花数
	/*daffodil();*/
	/*wenBo();*/
	/*decimalToBinary();*/
	/*arr();*/
	/*binaryToDecimal();*/
	/*str();*/

	/*buyChicken();*/
	wordsReverse();
	system("pause");
	return 0;
}