#include <iostream>
#include<Windows.h>
#include<string>


using namespace std;

class A
{

public:
	
	virtual void info() {

		cout << "Я объект класса А" <<  endl;
	}

	virtual ~A() {
		cout << "Декструктор А" << endl;
	}
};

class B : public A {

public:
	
	void info() {

		cout << "Я объект класса B " << endl;
	}
	~B() {
		cout << "Декструктор B" << endl;
	}
};

class C : public B {

public:
	
	void info() {

		cout << "Я объект класса C " << endl;
	}
	~C() {
		cout << "Декструктор C" << endl;
	}
};





//int main() {
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//	/*полиморфизм
//	
//
//
//
//
//
//
//	*/
//	A* a1 = new A();
//	B* b1 = new B();
//	C* c1 = new C();
//	a1->info();
//	b1->info();
//	c1->info();
//	cout << "----------------------------------------------" << endl;
//	A* base = NULL;
//
//	base = a1;
//	base->info();
//	delete base;
//
//
//	base = b1;
//	base->info();
//	delete base;
//
//	base = c1;
//	base->info();
//	delete base;
//
//
//
//
//	cout << "----------------------------------------------" << endl;
//
//	/*delete a1;
//	a1 = NULL;
//	delete b1;
//	b1 = NULL;
//	delete c1;
//	c1 = NULL;*/
//
//
//	system("pause");
//	return 0;
//}