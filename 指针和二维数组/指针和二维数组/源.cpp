#include<iostream>
#include<windows.h>
using namespace std;

//����һ��ָ�������ָ�� ����������ָ������
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
	int (*p)[4]; //����һ��ָ��4����Ա��ָ�����
	p = &ages[0];
	arr(p,count,5);
	system("pause");

	/*a[0];
	 &(*p)[0]������ַ; *(*p)[0]��������  */

	return 0;
}