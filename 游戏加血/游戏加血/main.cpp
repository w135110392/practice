#include<iostream>
#include<stdio.h>
#include<windows.h>

#define bossEXP 1000
#define mbossEXP 800
#define sbossEXP 200
#define Mlevel 1000
using namespace std;
struct hero{
	int exp;  //�ܾ���
	int addexp; //���ӵľ���
	int level; //�ȼ�
	int addlevel;//���ӵĵȼ�
	int mexp = Mlevel; //��ǰ��1����Ҫ�ľ���

	int blood ;  //��Ѫ��
	int addblood;     //���ӵ�Ѫ��
	int mblood = 100;  //��1�����ӵ�Ѫ��
};
//�趨���ֹ�
enum monster{
	boss=1,
	mboss=2,
	sboss=3
};
//ʵ�ּӾ��� ���������˶��پ���
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
	miss->addexp = exp; //���ӵľ���
	miss->exp = miss->addexp + miss->exp; //���Ӻ���ܾ���
	
}
//���ݾ������ӵȼ� ���������˶��ټ�
void addlevel(struct hero *miss){
		//ȡ�����ӵľ��� ��������ÿ��1���ľ��� �������ӵĵȼ�
		int level = miss->addexp / miss->mexp;
		miss->addlevel = level; //�������ӵĵȼ�
		miss->level = miss->level + miss->addlevel; //�������Ӻ���ܵȼ�

		   //�������ӵĵȼ�
}
//�������ӵĵȼ� ��Ѫ 1����100
void addblood(struct hero *miss){
	
	miss->addblood= (miss->mblood* (miss->addlevel)); //�������ӵ�Ѫ��

	miss->blood = miss->blood + miss->addblood; //������Ѫ��

}


int main(){
	//���鴦��
	
	int count = 0; //����boss�ĸ���
	struct hero *miss=new hero ;
	enum monster m =boss;
	
	
	miss->exp = 1000; //miss ����ʼ����
	int exp= miss->exp; //������ʼ����
	miss->level = 1; //miss����ʼ�ȼ�
	int level = miss->level; //������ʼ�ȼ�
	miss->blood = 1000; //miss����ʼѪ��
	int blood = miss->blood; //����miss����ʼѪ��
	
	
	
	
	cout << "��������������BOSS:\n";
	cin >> count;
	system("cls");
	 Generalexp(count, sboss, miss);//����6����boss
	cout << "miss������:" <<count<<"����boss\n";
	/*cout << "miss����ʼ�ȼ���:" << level << "��\n";*/
	//cout << "miss����ʼ������:" << exp << "��\n";
	//cout << "miss������: " << miss->addexp << " ����"<< "\n";
	cout << "miss������: " << miss->exp<< " ����" << "\n";
	

	//�ȼ�����
	
	if ((miss->exp)%(miss->level) == 0){
		 addlevel(miss);
		/*cout << "miss������" << miss->addlevel << "��\n";*/

		cout << "miss�ȼ�:" << miss->level << "��\n";
	}

	//�����ӵȼ� ��Ѫ

	addblood(miss);
	/*cout << "miss����ʼѪ��:" << blood<< "Ѫ\n";
	cout << "miss������:" << miss->addblood << "Ѫ��\n";*/
	cout << "missѪ��:" << miss->blood<< "Ѫ\n";
	cout << "\n";
	system("pause");
	return 0;
}