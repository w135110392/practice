#include<iostream>
#include<windows.h>
#include<string>
using namespace std;
//�����ַ�������λ��
void change(string **num1, string  **num2){
	/*string  *tmp = new string;*/
	string tmp;
	tmp = **num1;
	**num1 = **num2;
	**num2 = tmp;

}


int  main(){
	string a, b;
	getline(cin,a);
	getline(cin, b);
	system("cls");

	string *num1=NULL, *num2=NULL;
	num1 = &a, num2 = &b;

	cout << "����ǰ:" << *num1 << "+ " << *num2 << endl;
	change(&num1,&num2);
	cout << "������:" << *num1 << "+ " << *num2 << endl;




	system("pause");
	return 0;
}


