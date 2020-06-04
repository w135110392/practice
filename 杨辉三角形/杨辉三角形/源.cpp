#include<iostream>
#include<windows.h>
#include<iomanip>
using namespace std;

const int N = 13;
const int WIDTH = 4;
int main(){
	//一个二维数组来保存数值
	int arr[N][N] = {0};
	

	//给数组的第一列和对角线赋值 都是1
	for (int i = 0; i < N;i++){
		for (int j = 0; j <= i;j++){   //j<=i 意思是大于行的下标 都不输出 也不赋值了
			if (j == 0 || i == j){
			
				arr[i][j] = 1;
			}
			else{
				arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
			}
		}
	}

	//输出数组的每个元素
	for (int i = 0; i < N;i++){
		
		cout << setw((N-i)*(WIDTH/2))<<arr[i][0];
		for (int j = 1; j <= i;j++){  //注意 第列已经输出 j应该从1开始 也就是第二列开始
		 
			cout << setw(WIDTH) << arr[i][j];
		}
		cout << endl;
	}

	system("pause");
	return 0;
}