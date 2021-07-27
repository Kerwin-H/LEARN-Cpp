#include<iostream>

using namespace std;

/*			//模板
try{
	// 保护的标识代码
}
catch (ExceptionName e1){

	// catch 块 
}catch( ExceptionName e2 ){

		// catch 块 
	}catch( ExceptionName eN ){

		// catch 块 
	}
// catch 块 
}
*/

//double Division(int a, int b) {
//	// 当b == 0时抛出异常
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
	// 当b == 0时抛出异常
	if (b == 0)
	{
		throw "Division by zero condition!";
	}
	return (double)a / (double)b;
}
void Func()
{
	// 这里可以看到如果发生除0错误抛出异常，另外下面的array没有得到释放。
	// 所以这里捕获异常后并不处理异常，异常还是交给外面处理，这里捕获了再
	// 重新抛出去。
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
1. 异常对象定义好了，相比错误码的方式可以清晰准确的展示出错误的各种信息，甚至可以包含堆栈调用
的信息，这样可以帮助更好的定位程序的bug。
2. 返回错误码的传统方式有个很大的问题就是，在函数调用链中，深层的函数返回了错误，那么我们得层
层返回错误，最外层才能拿到错误，具体看下面的详细解释。

4. 很多测试框架都使用异常，这样能更好的使用单元测试等进行白盒的测试。

5. 部分函数使用异常更好处理，比如构造函数没有返回值，不方便使用错误码方式处理。比如T&
operator这样的函数，如果pos越界了只能使用异常或者终止程序处理，没办法通过返回值表示错误。

*/


/*
1. 异常会导致程序的执行流乱跳，并且非常的混乱，并且是运行时出错抛异常就会乱跳。这会导致我们跟
踪调试时以及分析程序时，比较困难。

3. C++没有垃圾回收机制，资源需要自己管理。有了异常非常容易导致内存泄漏、死锁等异常安全问题。
这个需要使用RAII来处理资源的管理问题。学习成本较高。

4. C++标准库的异常体系定义得不好，导致大家各自定义各自的异常体系，非常的混乱。

*/