#include<winsock.h>
#include<stdlib.h>
#include<stdio.h>

#pragma comment(lib,"ws2_32.lib")

int main(){
	char str[128]="";
	//初始化套接字
	WSADATA data;
	WORD v = MAKEWORD(2,0);
	WSAStartup(v,&data);
	//创建套接字
	SOCKET s = socket(AF_INET,SOCK_STREAM,0);
	//地址处理和端口处理
	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(75);
	addr.sin_addr.S_un.S_addr = inet_addr("192.168.0.104");
	printf("客户端已启动.\n");
	//连接服务端
	connect(s, (sockaddr *)&addr, sizeof(addr));
	recv(s,str,sizeof(str),0);
	printf("服务端说:%s",str);
	//关闭套接字
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