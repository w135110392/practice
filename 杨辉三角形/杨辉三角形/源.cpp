#include<iostream>
#include<windows.h>
#include<iomanip>
using namespace std;

const int N = 13;
const int WIDTH = 4;
int main(){
	//һ����ά������������ֵ
	int arr[N][N] = {0};
	

	//������ĵ�һ�кͶԽ��߸�ֵ ����1
	for (int i = 0; i < N;i++){
		for (int j = 0; j <= i;j++){   //j<=i ��˼�Ǵ����е��±� ������� Ҳ����ֵ��
			if (j == 0 || i == j){
			
				arr[i][j] = 1;
			}
			else{
				arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
			}
		}
	}

	//��������ÿ��Ԫ��
	for (int i = 0; i < N;i++){
		
		cout << setw((N-i)*(WIDTH/2))<<arr[i][0];
		for (int j = 1; j <= i;j++){  //ע�� �����Ѿ���� jӦ�ô�1��ʼ Ҳ���ǵڶ��п�ʼ
		 
			cout << setw(WIDTH) << arr[i][j];
		}
		cout << endl;
	}

	system("pause");
	return 0;
}