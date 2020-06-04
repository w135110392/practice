#include<winsock.h>
#include<stdlib.h>
#include<stdio.h>
#pragma comment(lib,"ws2_32.lib")

int main(){
	//初始化套接字库
	WSADATA data;
	WORD v= MAKEWORD(2,0);
	WSAStartup(v,&data);
	//创建套接字
	SOCKET s, s2;
	s = socket(AF_INET,SOCK_STREAM,0);
	//地址处理和端口处理
	sockaddr_in addr, addr2;
	int size = sizeof(addr2);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(75);
	addr.sin_addr.S_un.S_addr = INADDR_ANY;
	//绑定套接字和地址
	bind(s,(sockaddr *)&addr,sizeof(addr));
	//监听
	listen(s,4);
	printf("服务端已经启动.\n");
	//接收连接请求
	char str[] = "HELLO CLIENT";
	while (true){ 
		s2 = accept(s, (sockaddr*)&addr2, &size); 
		if (s2!=NULL){
			printf("客户端的地址%s已经连接上.",inet_ntoa(addr2.sin_addr));
			send(s2,str,sizeof(str),0);
		}
	}
	//关闭套接字
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

