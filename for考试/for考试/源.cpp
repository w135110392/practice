#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<iomanip>
using namespace std;
void pyramids(){
	int rows = 0;

	scanf_s("%d", &rows, sizeof(rows)); //��һ�д�ӡһ�� 
	/*
	�ո��Ҫ��ӡ�ġ�*�����������������������
	*
	***
	*****  �ո� rows-i  * 2�ı���-1 Ҳ����  2*i-1

	*/
	for (int i = 1; i <= rows; i++){
		//��ӡ�ո�
		for (int j = 0; j < rows - i; j++){

			printf(" ");
		}
		for (int j = 0; j <(2 * i) - 1; j++){

			printf("*");
		}
		printf("\n"); //ע��
	}
}

void mulTable(){
	int width = 2;
	//���� ÿ��һ�� ÿ��Ϊ��ǰ��������������
	for (int i = 1; i <= 14;i++){
		for (int j = 1; j <= i;j++){
			/*width = (j == 1) ? 1 : 2;*/
			
			cout << j << "*" << left << setw(width) << i << "=" << left << setw(3) << i*j << " ";
		
		}
		printf("\n");
	}

}
void daffodil(){
	printf("ˮ�ɻ�����:");
	int a, b, c;
	for (int i = 100; i <= 999;i++){ //ˮ�ɻ�������λ ���Ǵ�100��ʼ
		a = i / 100;
		b = (i / 10) % 10; //ȡ����ȡʮλ���ĸ�λ  ȡ����ȡʮλ����ʮλ �԰�λ��ȡ���������λ 
		c = i % 10;
		if (a*a*a+b*b*b+c*c*c==i){
			printf("%d  ",i);
		}
	}
	printf("\n");
}
void wenBo(){
	//������ 1 1 2 3 5 8 13 21 ......

	int  n; //aΪ��һ��ֵ bΪ�ڶ���ֵ value Ϊa+b��ֵ  nΪ����Ҫ��ӡ�ĸ���
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
//����һ��ʮ���������� תΪ��������
//������ ȡ�� ȡ�� n%2  n%2==0

void decimalToBinary(){
	int n=0;
	int ret[32];
	int i=0;
	cin >> n;
	//��ÿ�ε����������鱣������
	if (n>0){
		while(!n%2==0){
			ret[i] = n % 2;
			n = n / 2;               //n/2����ʾʣ�µ��� ֱ�ӱ��浽n ��ȥȡ��
			i++;
			}
		}
	
	for (i--; i >= 0;i--){ //�����֪���� ֱ��i--
	
		cout << ret[i];
	 }
	cout << endl;
	}
void arr(){
	int i = 4;
	int arr[] = { 1, 2, 4, 8 };

	for (i--; i >= 0;i--){  //�����֪���� ֱ��i--
	
		cout << arr[i]<<" ";
	
	}

}

void binaryToDecimal(){ //��֪�������Ƶ�Ȩֵ �ڿ���û�� 1λ�� ����1 0�ͳ���0 �ٰ�Ȩֵ���
	//��Ȩ��ӷ�
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
		p *= 2;   //ÿ������һλ Ȩֵ����2
		
	}
	cout << sum;
}
//����һ���ַ��� Ȼ��ת���
void str(){
	char str[128];
	scanf_s("%s",str,sizeof(str));
	
	for (int i = strlen(str) - 1; i >= 0;i--){
			cout << str[i];
		}
	cout << endl;

}
//ǧǮ�ټ� �����㷨
void buyChicken(){
	//1000��Ǯ Ҫ��100��  ����50/ֻ ĸ�� 30/ֻ С�� 10/3ֻ һ���ж�������
	int n_max=1000/50, m_max=1000/30, k; //�����1000�� ÿһ�ּ� ����������ֻ 
	//��ÿһ�ּ�ÿһֻ��Ǯ���Կ��ܵ�ֻ�����=1000   �������� ��� ÿ�ּ���ֻ��
	for (int i =1; i <= n_max;i++){
		for (int j = 1; j <= m_max;j++){
			k = 100 - i - j;
			if (k%3==0&&i * 50 + j * 30 + (k / 3) * 10 == 1000){
			
				cout << "����Ϊ" << i << "ֻ" << endl
					<< "ĸ��Ϊ" << j << "ֻ" << endl
					<< "С��Ϊ" << k << "ֻ" << endl;
				cout << endl;
				}
			}
		}
	
}
void wordsReverse(){
	char str[256];
	int i = 0; //�����ո� ָ���һ����ĸ
	int j = 0; //������ĸ ָ�򵥴ʺ�ĵ�һ���ո�
	gets_s(str,sizeof(str)); //�����ַ���
	while (str[i] != '\0'){
	 //��iָ��ո��ʱ������ ѭ�������� iָ���һ����ĸ
		while (str[i] == ' ')i++;
		j = i; //��i��j ��Ϊ�������ʵ���ʼλ��
		//��j��������ĸ ֱ�����ʽ���  ѭ�������� jָ�򵥴ʺ�ĵ�һ���ո�
		while (str[j] != ' '&&str[j] != '\0')j++;
		//���ʵĵ�һ��λ��ȷ���� Ϊi ���һ��λ��ȷ���� Ϊj-1 ��ʼ��ת
		for (int k1 = i, k2 = j - 1; k1 < k2;k1++,k2--){
		
			char tmp = str[k1];
			str[k1] = str[k2];
			str[k2] = tmp;
		}
		//������һ������ �ٰ�jΪi����ʼλ��
		i = j;
	}
	//������ת ��� i-1Ϊѭ������λ��
	for (int k1 = 0, k2 = i - 1; k1 < k2;k1++,k2--){
	
		char tmp = str[k1];
		str[k1] = str[k2];
		str[k2] = tmp;
	}
	cout << str << endl;
	}
	


int main(){
	//��ӡ������
	//pyramids();
	//9*9�˷���
	//mulTable();
	//ˮ�ɻ���
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