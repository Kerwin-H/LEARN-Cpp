#include<iostream>

using namespace std;

/*			//ģ��
try{
	// �����ı�ʶ����
}
catch (ExceptionName e1){

	// catch �� 
}catch( ExceptionName e2 ){

		// catch �� 
	}catch( ExceptionName eN ){

		// catch �� 
	}
// catch �� 
}
*/

//double Division(int a, int b) {
//	// ��b == 0ʱ�׳��쳣
//	if (b == 0)
//		throw "Division by zero condition!";
//	else
//		return ((double)a / (double)b);
//}
//void Func()
//{
//	int len, time;
//	cin >> len >> time;
//	cout << Division(len, time) << endl;
//}
//
//int main(){
//
//	try {
//		Func();
//	}
//	catch (const char* errmsg){
//		cout << errmsg << endl;
//	}
//	catch (...){
//		cout << "unkown exception" << endl;
//	}
//
//	system("pause");
//	return 0;
//}




double Division(int a, int b) {
	// ��b == 0ʱ�׳��쳣
	if (b == 0)
	{
		throw "Division by zero condition!";
	}
	return (double)a / (double)b;
}
void Func()
{
	// ������Կ������������0�����׳��쳣�����������arrayû�еõ��ͷš�
	// �������ﲶ���쳣�󲢲������쳣���쳣���ǽ������洦�����ﲶ������
	// �����׳�ȥ��
	int* array = new int[10];
	try {
		int len, time;
		cin >> len >> time;
		cout << Division(len, time) << endl;
	}
	catch (...)
	{
		cout << "delete []" << array << endl;
		delete[] array;
		throw;
	}
	// ...
	cout << "delete []" << array << endl;
	delete[] array;
}
int main1()
{
	try
	{
		Func();
	}
	catch (const char* errmsg)
	{
		cout << errmsg << endl;
	}
	return 0;
}
/*
1. �쳣��������ˣ���ȴ�����ķ�ʽ��������׼ȷ��չʾ������ĸ�����Ϣ���������԰�����ջ����
����Ϣ���������԰������õĶ�λ�����bug��
2. ���ش�����Ĵ�ͳ��ʽ�и��ܴ��������ǣ��ں����������У����ĺ��������˴�����ô���ǵò�
�㷵�ش������������õ����󣬾��忴�������ϸ���͡�

4. �ܶ���Կ�ܶ�ʹ���쳣�������ܸ��õ�ʹ�õ�Ԫ���ԵȽ��а׺еĲ��ԡ�

5. ���ֺ���ʹ���쳣���ô������繹�캯��û�з���ֵ��������ʹ�ô����뷽ʽ��������T&
operator�����ĺ��������posԽ����ֻ��ʹ���쳣������ֹ������û�취ͨ������ֵ��ʾ����

*/


/*
1. �쳣�ᵼ�³����ִ�������������ҷǳ��Ļ��ң�����������ʱ�������쳣�ͻ���������ᵼ�����Ǹ�
�ٵ���ʱ�Լ���������ʱ���Ƚ����ѡ�

3. C++û���������ջ��ƣ���Դ��Ҫ�Լ����������쳣�ǳ����׵����ڴ�й©���������쳣��ȫ���⡣
�����Ҫʹ��RAII��������Դ�Ĺ������⡣ѧϰ�ɱ��ϸߡ�

4. C++��׼����쳣��ϵ����ò��ã����´�Ҹ��Զ�����Ե��쳣��ϵ���ǳ��Ļ��ҡ�

*/