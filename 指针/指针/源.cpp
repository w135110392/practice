#include<windows.h>
#include<iostream>
#include<conio.h>
using namespace std;

const int N = 64;

//��ָ��ʵ�ּӷ����� ����������ٸ��� ���ܼ���
int * pointAdd(){
	int *n = new int(0);
	int *sum=new int(0);
	
	
		while (cin>>*n){  //�������
			*sum= *sum +*n;
			
				if (cin.peek()== '='){ //���ָ��س� �˳�ѭ��
					return sum; //���ؼ�����
	
			}
		}
	}

		
	

//ʵ�ʵ��üӷ�
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
	p = &b; // const���ε���ֵ ֵ�����Ա� ��ַ���Ա� 
	
	int * const p2=&a;
	*p2 = 13; // const ���ε���ָ�� Ҳ���ǵ�ַ�����Ա� ֵ���Ա�
	
	cout << "p��ֵ��:" << *p << endl;
	cout << "p2��ֵ��:" << *p2 << endl;
}

int main(void){
	/*actual_pointAdd();*/
	point();
	system("pause");

	return 0;
}