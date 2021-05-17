//����ָ��

#include <iostream>
#include <memory>
using namespace std;

class Test {
public:
	Test(int a = 0) : m_a(a) {}
	~Test() {
		cout << "Calling destructor" << endl;
	}

public:
	int m_a;
};

int main()
{
	auto_ptr<Test> p(new Test(5));
	cout << p->m_a << endl;
	return 0;
}


#include <iostream>
#include <memory>

using namespace std;

class Test {
public:
	Test(int a = 0) : m_a(a) {}
	~Test() {
		cout << "Calling destructor" << endl;
	}

public:
	int m_a;
};


int main()
{
	// �����������ʽ����ֻ�����delete���򲻻����
	// delete[ ]; ��ʱֻ�����һ����������
	shared_ptr<Test> sptr1(new Test[5]);

	// ����������ʽ��lambda���ʽ����ʾ����
	// delete[] ��ɾ�����еĶ���
	shared_ptr<Test> sptr2(new Test[5],
		[](Test* p) {delete[] p; });
	return 0;
}


#include <iostream>
#include <memory>

using namespace std;

class B;
class A
{
public:
	A() : m_a(5) {};
	~A() {
		cout << "A is destroyed" << endl;
	}
	void PrintSpB();
	weak_ptr<B> m_sptrB;
	int m_a;
};

class B {
public:
	B() : m_b(10) {};
	~B() {
		cout << "B is destroyed" << endl;
	}
	weak_ptr<A> m_sptrA;
	int m_b;
};

void A::PrintSpB()
{
	if (!m_sptrB.expired())
		cout << m_sptrB.lock()->m_b << endl;
}

int main()
{
	shared_ptr<B> sptrB(new B);
	shared_ptr<A> sptrA(new A);
	sptrB->m_sptrA = sptrA;
	sptrA->m_sptrB = sptrB;
	sptrA->PrintSpB();

	return 0;
}


