#include<iostream>
#include<string>

using namespace std;

//========�ַ������޸�
//====erase
//void test(){
//
//	string str = "123456";
//	str.erase(3, 2);  //1236
//	str.erase(0, 1);  //236
//
//	str.erase(str.begin());  //36
//	str.erase(str.begin(),str.end());  //3
//
//	str.erase(0);	//""
//
//	string str1 = "12/34567/89";
//	str1.replace(2, 5, "abc");   //12abc89
//
//	str1.replace(++str1.begin(), --str1.end(), "dddddddd");
//	
//	//��Ա����
//	str1.swap(str);		//�ַ������н���
//	//ȫ��
//	swap(str, str1);	//�������Լ�����ģ���ʼ����һ������
//
//
//}
//====
//void test(){
//
//	string str = "123456";
//
//	str.resize(20);
//
//	cout << str << "end" << endl;	//������е���Ч�ַ�,�Ὣ������ڵ�\0Ҳ��������
//	
//	//����C�ķ�ʽ���������
//	cout << str.c_str() <<"end"<< endl;	//������\0�ͻ�ֱ�ӽ���,�������\0
//	cout << str.data() << "end" << endl;
//
//
//}

//====cout����δ������Ϊ

//void test(){
//
//	string str = "23456123123";
//	string str2 = "123";
//	
//	//findѰ�Ҷ�Ӧ���ַ���,ֻ�ҵ�һ��
//	//�Ҳ�������
//	size_t pos = str.find("666663");	//�Ҳ���������������//4G
//	pos = str.find(str2);
//
//	pos = str.find("456abd", 0, 2);	//���Ҵ�0��ʼ2���ַ��Ķ�Ӧ  //45
//
//	//�������
//	pos = str.rfind(str2);
//
//	//����һ��������Ӧ��λ��
//	string str4 = "https://blog.csdn.net/weixin_46554582/article/details/114886749";
//	pos = str4.find("://");
//	size_t end = str4.find("/", pos + 3);
//	string sub = str4.substr(pos + 3, end - pos-3);
//
//
//	string file = "test.tar.gz.txt";
//	pos = file.rfind('.');
//	string suff = file.substr(pos + 1);
//
//	//��ز��ҵĺ���
//	pos = str.find_first_not_of;	//�������Ժ��һ��
//	pos = str.find_first_of;		//�ҵ�����ĵ�һ��
//	pos = str.find_last_not_of;		//�����ڵ����һ��
//	pos = str.find_last_of;			//���һ��
//
//
//}

//====�Ƚ�
void test(){

	string str = "123455";
	string str2 = "ab";



	//string�ıȽ�:����ÿһ���õ�һ��ASCII��ֵ���бȽ�
	bool ret = str == str2;
	ret = str > str2;
	ret = str < str2;
	

	//����:
	//cin���������ո����/���н���
	cin >> str;

	//getline:�������н���
	getline(cin, str);

	getline(cin, str, ',');		//�������Ž���


}



int main(){

	test();

	system("pause");
	return 0;
}

