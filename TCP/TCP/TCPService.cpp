#include<winsock.h>
#include<stdlib.h>
#include<stdio.h>
#pragma comment(lib,"ws2_32.lib")

int main(){
	//��ʼ���׽��ֿ�
	WSADATA data;
	WORD v= MAKEWORD(2,0);
	WSAStartup(v,&data);
	//�����׽���
	SOCKET s, s2;
	s = socket(AF_INET,SOCK_STREAM,0);
	//��ַ����Ͷ˿ڴ���
	sockaddr_in addr, addr2;
	int size = sizeof(addr2);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(75);
	addr.sin_addr.S_un.S_addr = INADDR_ANY;
	//���׽��ֺ͵�ַ
	bind(s,(sockaddr *)&addr,sizeof(addr));
	//����
	listen(s,4);
	printf("������Ѿ�����.\n");
	//������������
	char str[] = "HELLO CLIENT";
	while (true){ 
		s2 = accept(s, (sockaddr*)&addr2, &size); 
		if (s2!=NULL){
			printf("�ͻ��˵ĵ�ַ%s�Ѿ�������.",inet_ntoa(addr2.sin_addr));
			send(s2,str,sizeof(str),0);
		}
	}
	//�ر��׽���
	closesocket(s);
	closesocket(s2);
	WSACleanup();
	if (getchar()){
	
		return 0;
	
	}
	else{
		Sleep(100);
	}
	
	system("pause");
	return 0;
}

