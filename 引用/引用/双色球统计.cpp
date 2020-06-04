#include<iostream>
#include<windows.h>
#include<fstream>
#include<string>


//找出最近一段时间 每个号码出现的次数 并保存到一个数组 供其他模块调用

using namespace std;
const int N = 7;
bool arr_count(const char *path, int *arr_1_6){
	int result[N];
	ifstream file;
	int i = 0;
	if (!path){
			cerr << "路径为空！" << endl;
	}
		
		file.open(path);
		if (file.fail()){
			cerr << "打开文件出错\n";
			return false;
		}
		//读取文件 每一次循环 7个数字
		do{
			for (i = 0; i < N;i++){
				file >> result[i];
				if (file.eof()){
					break;
				}
				if (file.fail()){
					cerr << "读取文件失败";
					break;
				}
			}
			if (i == 0){
				break;
			}
			if (i < N){
				cerr << "仅读到:" << i << "个数据";
				file.close();
				return false;
			}
			for (int i = 0; i < N;i++){
				cout << result[i]<<" " ;
			}
			cout<<endl;
			//统计每个数组的次数
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
	//int arr_1_6[33] = {0}; //保存每个数字出现的次数
	//string fileName;
	//
	//cin >> fileName;
	//if (arr_count(fileName.c_str(), arr_1_6)){
	//	for (int i = 0; i < 33;i++){
	//		cout << i+1 << "的次数是:" << arr_1_6[i]<<endl;
	//	}
	//}
	//else{
	//	
	//}
	cout << "?" << 500 << "元";
		system("pause");
	return 0;
}