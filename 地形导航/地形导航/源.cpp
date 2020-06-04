#include<iostream>
#include<windows.h>
#include<fstream>
#include<string>
using namespace std;

#define size  64
//�ж��Ƿ�Ϊ���Ĺ���ʵ��
bool isPeak(int map[][size],int i,int j){
	if ((map[i][j]>map[i-1][j])&&
		(map[i][j]>map[i+1][j])&&
		(map[i][j]>map[i][j-1])&&
		(map[i][j]>map[i][j+1])){
		return true;
	}
	else return false;
	
	
}
int main(){
	//���ļ���ȡ�������� �ж� ��� 
	int map[size][size];
	string fileName;
	ifstream file;
	int nlines = 0, ncols = 0;

	//���ļ�
	cout<<"�����ļ���:";
	cin >> fileName;
	file.open(fileName.c_str());
	if (file.fail()){
		cerr << "�ļ��򿪳���.\n";
		exit(1);
	}
	//��ȡ�ļ��е� ���� �� ����
	file >> nlines >> ncols;
	if (nlines > size || ncols > size){
		cerr << "����̫����Ҫ��������.\n";
		exit(1);
	}
	for (int i = 0; i < nlines; i++){
		for (int j = 0; j < ncols; j++){

			file >> map[i][j];
		}
	}
	//�ж��Ƿ�Ϊ��� ע��forѭ������ д����Ϊλ�� ����1��Сʱ..................
	for (int i = 0; i < nlines; i++){
		for (int j = 0; j < ncols; j++){
			               //��ǰ��ʵ��i  ʵ��j
			if (isPeak(map, i, j)){
				
				cout << "����ڵ�"<<i+1<<"��"<<"��"<<j+1 <<"�� ";
				cout << map[i][j] << " \n";
			}
		}
	}



	file.close();
	system("pause");
	return 0;
}

