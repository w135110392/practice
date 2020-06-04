#include<iostream>
#include<windows.h>
using namespace std;

//定义一个指向数组的指针 将内容增加指定的数
void arr(int (*ages)[4],int count,int numb){
	
	for (int i = 0; i < count; i++){
		int j = 0;
		ages[i] = &j;
		ages[i] = ages[i] + numb;
		cout << *ages[i] << "\n";
	}



}
int main(){
	int ages[3][4] = { 
					 { 24, 18, 16, 17 }, 
					 { 24, 18, 16, 17 }, 
	                 { 24, 18, 16, 17 } };
	int count = sizeof(ages) / sizeof(ages[0]);
	int (*p)[4]; //定义一个指向4个成员的指针变量
	p = &ages[0];
	arr(p,count,5);
	system("pause");

	/*a[0];
	 &(*p)[0]赋给地址; *(*p)[0]赋给变量  */

	return 0;
}