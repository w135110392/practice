#include<windows.h>
#include<iostream>
#include<conio.h>
using namespace std;

const int N = 64;

//用指针实现加法功能 不管输入多少个数 都能计算
int * pointAdd(){
	int *n = new int(0);
	int *sum=new int(0);
	
	
		while (cin>>*n){  //如果输入
			*sum= *sum +*n;
			
				if (cin.peek()== '='){ //如果指向回车 退出循环
					return sum; //返回计算结果
	
			}
		}
	}

		
	

//实际调用加法
void actual_pointAdd(){

	int *sum = new int(0);
	sum=pointAdd();
	cout << *sum<<endl;

}
void point(){
	int a = 1;
	int b = 10;
	const int *p;
	p = &a;
	p = &b; // const修饰的是值 值不可以变 地址可以变 
	
	int * const p2=&a;
	*p2 = 13; // const 修饰的是指针 也就是地址不可以变 值可以变
	
	cout << "p的值是:" << *p << endl;
	cout << "p2的值是:" << *p2 << endl;
}

int main(void){
	/*actual_pointAdd();*/
	point();
	system("pause");

	return 0;
}