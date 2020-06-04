#include<iostream>
using namespace std;

class father{
	public:
		virtual void play();


};
void father::play(){
	cout << "到KTV唱歌." << endl;
}
class son:public father{
	virtual void play();

};
void son:: play(){
	cout << "一起打王者." << endl;

}
int main(){
	father *f,*f2;
	f2 = new father;
	son s;
	f = &s;
	f->play();
	f2->play();
	delete f2;
	system("pause");
	
	return 0;
}