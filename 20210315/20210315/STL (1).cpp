#include<iostream>
#include<string>
using namespace std;

//STL========String��

//====6�ֳ�ʼ����ʽ
//void test(){
//	
//	//1.�����յ�string����
//	//string();
//	string str;
//
//	//2.����
//	//string(const string& str);
//	string copy(str);
//
//	//3.ͨ���ڲ����ַ�������һ������
//	//string(const char* s);
//	string str2("abc");
//
//	//4.ͨ��һ���ַ����Ĳ��������������µ��ַ�������
//	//string(const string& str,size_t pos,size_t len=npos);
//	string substr(str2, 1, 2); // "bc" (��Ӧ���ַ���,����һ����ʼ,���󼸸��ַ�)
//
//	//5.��ȡ�������ַ�����ǰ����
//	//string(const char* s,size_t n);
//	string str3("12345678", 5);  //"12345"
//
//	//6.����һ���ַ������м���������ַ�
//	//string(size_t n, char c);
//	string str4(10, 'a');	//"aaaaaaaaaa"
//	
//	//7.����
//	string str5 = "abcde";	//���ι������ʽ����ת��
//
//
//	str5 = str4;
//	str5 = "123";
//	str5 = 'b';
//}

//====string�����ļ򵥹���
//void test(){
//
//	const string str="12345";
//	string str2 = "12345";
//	
//
//	//const����,���ýӿ�: const char& operator[](size_t pos) const
//	//����ʹ������������ķ�ʽ���ַ������з���
//	
//	//==1.�ɶ�ȡ���е��ַ���
//	char ch = str[3];
//	const char& ref = str[3];
//
//	//==2.�����޸����е��ַ���(������const��ʽ,�����޸�)
//	/*str[3] = 'f';
//	str[3] = 'a';*/
//
//	//��const����: char& operator[](size_t pos) const
//	char& ref = str2[3];
//	str2[3] = 'a';
//
//	//==������ֱ������at���Զ���ֱ�ӽ��и�ֵ
//	str2.at(3) = 'b';
//
//
//	//==[]Խ��:�����Դ���
//	//char ch2 = str2[10];
//	
//	//==atԽ��:���쳣
//	//char ch2 = str2.at(10);
//
//}

//====1.������
//ʹ�÷�����ָ������
//��ƹ淶:
//1.begin������:ָ���һ��Ԫ��
//2.end������:ָ�����һ��Ԫ�ص�ĩβ
//3.��������:ͨ������������� : *,->
//4.�������ƶ�: ++�ƶ�����һ��Ԫ��,--�ƶ�����һ��Ԫ��
//5.λ�õ��ж�: ֧��!= ,== 
//�����е���Щ�����д��ڷ��������
//6.rbegin������: ָ�����һ��Ԫ�ص�λ��		(������ʼ,����������)
//7.rend������: ָ���һ��Ԫ�ص�ǰһ��λ��

//====���������
//void test(){
//
//	string str = "12345";
//	//��ʼλ�õĵ�����
//	string::iterator it = str.begin();
//	for (; it != str.end(); ++it){
//		
//		//�������Ľ�����
//		cout << *it <<" ";
//
//		//����ͨ�������������ݽ����޸�
//		*it = 'a';
//
//	}
//	const string str2 = "abcde";
//	//ֻ���Ĳ���
//	string::const_iterator it2 = str2.begin();
//	while (it2!=str2.end()){
//		
//		cout << *it2 << " ";
//		//ֻ��������,�����Է����޸�,��Ϊ��const
//		//*it2 = 's';
//		++it2;
//	}
//}

//====���������
//void test(){
//
//	string str = "12345";
//	//���һ��Ԫ�ص�λ��
//	string::reverse_iterator it = str.rbegin();
//	while (it != str.rend()){
//		
//		cout << *it << " ";	//54321
//		//�����ƶ�
//		*it = 'a';
//		++it;
//	}
//
//
//	//ֻ���ķ��������
//	const string str2 = "abcde";
//
//	string::const_reverse_iterator it2 = str2.rbegin();
//	while (it2 != str2.rend()){
//		
//		cout << *it2 << " ";
//		//ֻ��������:const�����Է����޸�
//		//*it2 = "d";
//		++it2;
//	}
//}

//====2.��Χfor
//void test(){
//	
//	//==��Χfor:���ʷ�Χȷ��������
//	int arr[] = { 1, 2, 3, 4, 5 };
//	for (const auto& e : arr){
//		
//		cout << e << " ";
//	}
//	cout << endl;
//
//	for (auto& e : arr){
//		
//		e = 10;
//	}
//
//	string str = "12345";
//	//��Χfor:ʵ���Ͼ���ͨ������������ʵ�ֵ�
//	//		  ֧�ֵ��������ʵ��Զ������Ͷ�����֧�ַ�Χfor
//	for (auto& ch : str){
//
//		cout << ch << " ";
//		ch = 'a';
//	}
//}

//====3.forѭ��
//void test(){
//	
//	string str = "12345";
//	for (size_t i = 0; i < str.size(); ++i){
//		
//		cout << str[i] << " ";
//		str[i] = 'a';
//	}
//	cout << endl;
//}

//========����string���ʵķ�ʽ
//1.forѭ��+operator[]
//2.������
//3.��Χfor
//�����ַ�ʽ�������޸�������
 

//========������صĽӿ�size
//void test(){
//
//	string  str;
//	cout << str.size() << endl;
//	
//	//====resize:�޸���Ч�ַ��ĸ���
//	//resize(n):�����Ч�ַ���������,�µ�λ�����'\0'
//	//resize(n, ch): �����Ч�ַ��ĸ�������,��������λ�����ch
//	//���size��С,�򲻻�������
//
//	//==�޸���Ч�ַ��ĸ���
//	//��Ч�ַ��ǰ���size���յĴ�С���涨��,\0Ҳ�п�������Ч�ַ�
//	str.resize(10);
//
//	cout << str.size() << endl;
//
//	string str2 = "123";		//����ЧԪ�ز�����ʱ��,����������7��\0
//	cout << str2.size() << endl;
//	str2.resize(10);
//	cout << str2.size() << endl;
//
//	str2.resize(2);		//����Ч�ַ�����
//	cout << str2.size() << endl;
//
//	//���������ռ�Ļ�,����Ҫ���Ŀռ佫a��������,�Ͳ�Ϊ\0
//	str2.resize(5, 'a');	//12aaa
//
//	str2.resize(2, 'b');	//�����С,û����Ҫ����λ����û����
//
//}

//====capacity
//void test(){
//
//	string str = "123";
//	int sz = str.size();
//	//capacity��ǰstring �������Դ�ŵ�Ԫ�ظ���
//	int cap = str.capacity();
//	str.resize(10);
//	sz = str.size();
//	cap = str.capacity();
//	str.resize(1);
//	sz = str.size();
//	cap = str.capacity();
//	str.resize(20);
//	//resize:������֮���size����������ʱ��,����Ҳ�ᷢ���仯
//	sz = str.size();
//	cap = str.capacity();
//
//	//reserve:�޸�����:ֻ�ܽ�������������,���ܼ�С
//	//��Ӱ��size
//	str.reserve(60);
//	sz = str.size();
//	cap = str.capacity();
//
//	str.reserve(10);
//	sz = str.size();
//	cap = str.capacity();
//
//
//	//clear: �����Ч�ַ�	ֻӰ��size 
//	str.clear();
//	sz = str.size();
//	cap = str.capacity();
//
//}

//====shrink�ӿ�
//void test(){
//
//	string str = "123";
//	int sz = str.size();
//	int cap = str.capacity();
//
//	//��Ҫ���þ��ǰѽ�������'\0'����û�����õ��ַ���������,��֤ÿ���ַ�������Ч��
//	str.shrink_to_fit();	
//	int sz = str.size();
//	int cap = str.capacity();
//
//}

//====push_back
//void test(){
//	
//	//����1.5���Ŀռ��������
//	string str;
//	int cap = str.capacity();
//
//	//����Ƶ��������,��ߴ����Ч��
//	//ֱ�����ݵ�200,�Ͳ����ڹ���
//	str.reserve(200);
//	
//	cout << cap << endl;
//	for (int i = 0; i < 200; ++i){
//		
//		str.push_back('a');
//		if (cap != str.capacity()){
//			
//			cap = str.capacity();
//			cout << cap << endl;
//		}
//	}
//}

//+=	������β��
//void test(){
//
//	string str;
//	string str2 = "123";
//	
//	//��������
//	str += str2;	//123
//	str += "abc";	//123abc
//	str += '4';		//123abc4
//	//������ʽ
//	str.operator+=('5');	//123abc45
//
//}

//append���������
//void test(){
//
//	string str;
//	string str2 = "123";
//
//	str.append(str2);	//123
//
//	str.append(str2, 1, 1);		//1232
//
//	str.append("abc");	//1232abc
//
//	str.append("123456", 6);	//1232abc123456
//
//	str.append(5, 'm');	//1232abc123456mmmmm
//
//	char arr[] = "abcdefg";
//	str.append(arr, arr + sizeof(arr) / sizeof(arr[0]));	//1232abc123456mmmmmabcdefg 
//	str.append(str2.begin(), str2.end());	//1232abc123456mmmmmabcdefg123
//
//}

//==insert
void test(){

	string str="123";
	string str2 = "abc";

	str.insert(0, str2);	//abc123

	str.insert(4, str2, 1, 2);	//abc1bc23

	str.insert(str.size(), "abc");	//abc1bc23abc

	str.insert(5, "12345", 4);	//abc1b1234c23abc

	str.insert(str.begin(), 2, '0');	//00abc1b1234c23abc

	str.insert(str.end(), str2.begin(), str2.end());	//00abc1b1234c23abc123



}




int main(){
	
	test();
	system("pause");
	return 0;
}

