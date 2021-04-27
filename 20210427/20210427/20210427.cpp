#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;



void test1(){

	//cin: ��istream�Ķ���  ,��ʵ��������һ�����غ���
	int a;
	cin >> a;
	cin.operator>>(a);	//������ʵ�ڲ���ͨ�����غ�����ʵ��

	float f;
	cin >> f;
	cin.operator>>(f);	//���ڲ�ͬ������ֱ��ͨ����ͬ���͵�������ʵ�ֶ��ڲ�ͬ������


	//cout: ostream�Ķ���
	//Ҳ��ͨ��������ʵ��
	cout << a;
	cout.operator<<(a).operator<<(endl);	//��������ĳ���Ҳ��һ�µ�

	//scanf  ///printf //�����߶��ǿ⺯��,ϵͳ�޷��������͵Ĳ�ͬ��ʵ������
	scanf("%s", a);
	//��������Ŀ⺯���Ĵ������Ǿ���Ҫ�������ڲ�Ҫ��������ͽ��ж���,�޷���ϵͳ�ڲ���������Ĳ�ͬ����������

}


struct Student{

	int age;
	char name[20];
};
void test2(){
	
	//ofstream : �����ļ���
	//ifstream : ����ļ���

	//д�ļ�: �ļ�������,�����µ��ļ�
	ofstream fout("test.txt");
	//fout.open("test.txt");

	if (!fout.is_open())
		cout << "not open" << endl;

	//д���Ӧ������
	//=====1.�ı��ļ�  :�ַ�����д

	fout << "test.txt" << endl;		//!!!�ڲ����������������close���ļ����йر�
		
	fout.put('a');
	//fout.close();

	//���ļ�: �ļ�������,��ʧ��
	ifstream fin("test.txt");
	char arr[100];
	fin >> arr;

	//��ȡ�������ַ�
	char ch;
	ch = fin.get();
	fin.get(ch);		//��ȡ�������ַ�
	fin.get(arr, 100);	//��ȡ��Ӧ��100���ַ�

	fin.getline(arr, 100);	//��ȡ��Ӧ��һ�д���,����ַ�����Ϊ��,����ֻ��ǰ100


	ofstream fout("test.txt");
	//Student stu;		//�����ṹ������ڲ������ݽ��ж�д
	//stu.age = 30;
	//strcpy(stu.name,"abc");
	//fout << stu.name << endl;		//���
	//fout << stu.age << endl;

	fout.close();


	//=====2.�����ƶ�д: �ֽ�����д

	ofstream fout2("test.binary.txt");

	//fout2.write((char*)&stu,sizeof(stu));	//�������char*����ֱ�ӽ���ǿת
	fout2.close();


	//�����ƵĶ��ļ�
	ifstream fin("test.binary.txt", ifstream::binary);//�����Ƕ��ڶ����Ƶ�����

	//Student stu;

	//fin.read((char*)&stu, sizeof(stu));	
	//����������ļ����Ƚ���char���͵�ǿת
	//Ȼ���ٶԶ�Ӧ��size���д�С�ֽڵĶ���


}





void test(){

	//1.stringstream : ��ֵ--->�ַ���


	//stringstream ss;

	int a = 10;
	//int b = 010;
	//int c = 0x10;

	//char arr[100];
	//itoa(a, arr, 10);
	//itoa(b, arr, 8);
	//itoa(c, arr, 16);
	//
	////sprintf
	//sprintf(arr, "%f", a);
	float f = 2.3;
	//sprintf(arr,"%d",f);
	//printf("%d",a);

	stringstream ss;
	string str;
	ss << a;
	ss >> str;

	//clear(): ��һ��ת��֮ǰ,����clear�ӿ����״̬λ
	//�������������
	ss.clear();
	ss << f;
	ss >> str;


	//str(��������)  :����stringstream�����е�����
	ss.str("");

	//str() : ��ȡstringstream����������
	str = ss.str();

	ss.clear();
	ss << f;

	str = ss.str();

	//2.�ַ���ƴ��
	ss.str("");
	ss << "123" << "456" << "789";
	cout << ss.str() << endl;

}





int main(){

	test();
	system("pause");
	return 0;
}