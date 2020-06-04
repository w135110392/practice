#include<iostream>
#include<windows.h>
#include<fstream>
#include<string>
using namespace std;

#define size  64
//判断是否为峰点的功能实现
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
	//从文件读取数组数据 判断 峰点 
	int map[size][size];
	string fileName;
	ifstream file;
	int nlines = 0, ncols = 0;

	//打开文件
	cout<<"输入文件名:";
	cin >> fileName;
	file.open(fileName.c_str());
	if (file.fail()){
		cerr << "文件打开出错.\n";
		exit(1);
	}
	//读取文件中的 行数 和 列数
	file >> nlines >> ncols;
	if (nlines > size || ncols > size){
		cerr << "数组太大，需要调整程序.\n";
		exit(1);
	}
	for (int i = 0; i < nlines; i++){
		for (int j = 0; j < ncols; j++){

			file >> map[i][j];
		}
	}
	//判断是否为峰点 注意for循环括号 写错了为位置 找了1个小时..................
	for (int i = 0; i < nlines; i++){
		for (int j = 0; j < ncols; j++){
			               //当前的实参i  实参j
			if (isPeak(map, i, j)){
				
				cout << "峰点在第"<<i+1<<"行"<<"第"<<j+1 <<"列 ";
				cout << map[i][j] << " \n";
			}
		}
	}



	file.close();
	system("pause");
	return 0;
}

