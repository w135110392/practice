#include<iostream>
#include<stdio.h>
#include<windows.h>

#define bossEXP 1000
#define mbossEXP 800
#define sbossEXP 200
#define Mlevel 1000
using namespace std;
struct hero{
	int exp;  //总经验
	int addexp; //增加的经验
	int level; //等级
	int addlevel;//增加的等级
	int mexp = Mlevel; //当前升1级需要的经验

	int blood ;  //总血量
	int addblood;     //增加的血量
	int mblood = 100;  //升1级增加的血量
};
//设定三种怪
enum monster{
	boss=1,
	mboss=2,
	sboss=3
};
//实现加经验 返回增加了多少经验
void Generalexp(int count, enum monster m, struct hero *miss){
	int exp = 0;
	if (count>0){
		switch (m){
		case boss:
			exp = count * bossEXP;
			
			break;
		case mboss:
			exp = count * mbossEXP;
			
			break;
		case sboss:
			exp = count * sbossEXP;
			
			break;
		default:
			break;
		}
	}
	miss->addexp = exp; //增加的经验
	miss->exp = miss->addexp + miss->exp; //增加后的总经验
	
}
//根据经验增加等级 返回增加了多少级
void addlevel(struct hero *miss){
		//取得增加的经验 除以现在每升1级的经验 就是增加的等级
		int level = miss->addexp / miss->mexp;
		miss->addlevel = level; //保存增加的等级
		miss->level = miss->level + miss->addlevel; //保存增加后的总等级

		   //返回增加的等级
}
//根基增加的等级 加血 1级加100
void addblood(struct hero *miss){
	
	miss->addblood= (miss->mblood* (miss->addlevel)); //计算增加的血量

	miss->blood = miss->blood + miss->addblood; //保存总血量

}


int main(){
	//经验处理
	
	int count = 0; //打死boss的个数
	struct hero *miss=new hero ;
	enum monster m =boss;
	
	
	miss->exp = 1000; //miss 的起始经验
	int exp= miss->exp; //保存起始经验
	miss->level = 1; //miss的起始等级
	int level = miss->level; //保存起始等级
	miss->blood = 1000; //miss的起始血量
	int blood = miss->blood; //保存miss的起始血量
	
	
	
	
	cout << "假设打死了输入个BOSS:\n";
	cin >> count;
	system("cls");
	 Generalexp(count, sboss, miss);//打死6个大boss
	cout << "miss打死了:" <<count<<"个大boss\n";
	/*cout << "miss的起始等级是:" << level << "级\n";*/
	//cout << "miss的起始经验是:" << exp << "级\n";
	//cout << "miss增加了: " << miss->addexp << " 经验"<< "\n";
	cout << "miss经验是: " << miss->exp<< " 经验" << "\n";
	

	//等级处理
	
	if ((miss->exp)%(miss->level) == 0){
		 addlevel(miss);
		/*cout << "miss增加了" << miss->addlevel << "级\n";*/

		cout << "miss等级:" << miss->level << "级\n";
	}

	//按增加等级 加血

	addblood(miss);
	/*cout << "miss的起始血量:" << blood<< "血\n";
	cout << "miss增加了:" << miss->addblood << "血量\n";*/
	cout << "miss血量:" << miss->blood<< "血\n";
	cout << "\n";
	system("pause");
	return 0;
}