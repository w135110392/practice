#include<iostream>
#include<windows.h>
#include<fstream>
#include<string>


//�ҳ����һ��ʱ�� ÿ��������ֵĴ��� �����浽һ������ ������ģ�����

using namespace std;
const int N = 7;
bool arr_count(const char *path, int *arr_1_6){
	int result[N];
	ifstream file;
	int i = 0;
	if (!path){
			cerr << "·��Ϊ�գ�" << endl;
	}
		
		file.open(path);
		if (file.fail()){
			cerr << "���ļ�����\n";
			return false;
		}
		//��ȡ�ļ� ÿһ��ѭ�� 7������
		do{
			for (i = 0; i < N;i++){
				file >> result[i];
				if (file.eof()){
					break;
				}
				if (file.fail()){
					cerr << "��ȡ�ļ�ʧ��";
					break;
				}
			}
			if (i == 0){
				break;
			}
			if (i < N){
				cerr << "������:" << i << "������";
				file.close();
				return false;
			}
			for (int i = 0; i < N;i++){
				cout << result[i]<<" " ;
			}
			cout<<endl;
			//ͳ��ÿ������Ĵ���
			for (i = 0; i < N; i++){
				int index = *(result + i) - 1;
				if (index>=0&&index<33){
					(*(arr_1_6 + index))++;
					
				}
			}

		}while(1);
		

		file.close();
		return true;
}

int main(){
	//int arr_1_6[33] = {0}; //����ÿ�����ֳ��ֵĴ���
	//string fileName;
	//
	//cin >> fileName;
	//if (arr_count(fileName.c_str(), arr_1_6)){
	//	for (int i = 0; i < 33;i++){
	//		cout << i+1 << "�Ĵ�����:" << arr_1_6[i]<<endl;
	//	}
	//}
	//else{
	//	
	//}
	cout << "?" << 500 << "Ԫ";
		system("pause");
	return 0;
}