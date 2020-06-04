#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

int main(){
	char direct[10];
	char pwd[7];
	int index=0;
	for (int i = 0; i < 10; i++){
		direct[index] = '0' + i;
		index++;
		printf("%c", direct[i]);
	}
	printf("\n");
	printf("%d",index);
	int n = index;for (int p1 = 0; p1 <index; p1++){
		for (int p2 = 0; p2 < index; p2++){
			for (int p3 = 0; p3 < index; p3++){
				for (int p4 = 0; p4 < index; p4++){
					for (int p5 = 0; p5 <index; p5++){
						for (int p6 = 0; p6 < index; p6++){

							pwd[0] =direct[p1]; //зЂвт
							pwd[1] = direct[p2];
							pwd[2] = direct[p3];
							pwd[3] = direct[p4];
							pwd[4] = direct[p5];
							pwd[5] = direct[p6];
							pwd[6] = '\0';
							cout << pwd << endl;
						}


					}


				}


			}


		}
	
	
	}


	
	return 0;
}