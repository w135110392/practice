#include<winsock.h>
#include<stdlib.h>
#include<stdio.h>

#pragma comment(lib,"ws2_32.lib")

int main(){
	char str[128]="";
	//��ʼ���׽���
	WSADATA data;
	WORD v = MAKEWORD(2,0);
	WSAStartup(v,&data);
	//�����׽���
	SOCKET s = socket(AF_INET,SOCK_STREAM,0);
	//��ַ����Ͷ˿ڴ���
	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(75);
	addr.sin_addr.S_un.S_addr = inet_addr("192.168.0.104");
	printf("�ͻ���������.\n");
	//���ӷ����
	connect(s, (sockaddr *)&addr, sizeof(addr));
	recv(s,str,sizeof(str),0);
	printf("�����˵:%s",str);
	//�ر��׽���
	closesocket(s);
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