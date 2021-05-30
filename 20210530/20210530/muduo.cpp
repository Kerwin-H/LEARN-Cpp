/*

muduo������ṩ��������:
TcpServer:���ڱ�д����������
TcpClient:���ڱ�д�ͻ��˵ĳ���

epoll+�̳߳�
�ô�: �ܹ�������I/O�Ĵ����ҵ��������ֿ�

�û������ӺͶϿ�   ����Ŀɶ�д�¼�
*/

#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <iostream>
#include <string>

#include <functional>
using namespace std;
using namespace muduo;
using namespace muduo::net;
using namespace placeholders;

/*
����muduo����⿪������������
1.���TcpServer����
2.����EnventLoop�¼�ѭ������ָ��
3.��ȷTcpServer�Ĺ��캯����Ҫʲô����
4.�ڵ�ǰ��������Ĺ��캯����,ע�ᴦ�����ӵĻص������ʹ����д�¼��Ļص�����
5.���ú��ʵķ�����߳�����,muduo���Լ�����IO��worker�߳�
*/

class ChatServer
{

public:
	ChatServer(EventLoop *loop,               //�¼�ѭ��
		const InetAddress &listenAddr, //ip+port
		const string &nameArg)         //����������
		: _server(loop, listenAddr, nameArg), _loop(loop)
	{

		//��������ע���û����ӵĴ����ͶϿ��ص�
		_server.setConnectionCallback(std::bind(&ChatServer::onConnection, this, _1));
		//��������ע���û���д�¼��ص�
		_server.setMessageCallback(std::bind(&ChatServer::onMessage, this, _1, _2, _3));
		//���÷������˵��߳�����    1��IO�߳�  3��worker�߳�
		_server.setThreadNum(4);
	}

	//�����¼�ѭ��
	void start()
	{

		_server.start();
	}

private:
	//ר�Ŵ����û������Ӵ����ͶϿ�
	void onConnection(const TcpConnectionPtr &conn)
	{
		if (conn->connected())
		{
			cout << conn->peerAddress().toIpPort() << "->" << conn->localAddress().toIpPort() << "state: online" << endl;
		}
		else
		{
			cout << conn->peerAddress().toIpPort() << "->" << conn->localAddress().toIpPort() << "state: offline" << endl;
			conn->shutdown(); //close(fd)
			//_loop->quit();
		}
	}
	//ר�Ŵ����û��Ķ�д�¼�
	void onMessage(const TcpConnectionPtr &conn, //���ӷ�������
		Buffer *buffer,               //������
		Timestamp time)               //�������ݵ�ʱ����Ϣ
	{
		string buf = buffer->retrieveAllAsString();
		cout << "rece data:" << buf << "time:" << time.toString() << endl;
		conn->send(buf);
	}

	TcpServer _server;
	EventLoop *_loop; //epoll
};

int main()
{

	EventLoop loop;
	InetAddress addr("127.0.0.1", 6000);
	ChatServer server(&loop, addr, "ChatServer");

	server.start();
	loop.loop(); //epoll_wait,��������ʽ�ȴ��µ��û�������

	return 0;
}
