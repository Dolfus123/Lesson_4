#include <iostream>
#include<Windows.h>
#include<string>


using namespace std;

class Pet
{
private:
	string name;
	int age;
public:
	Pet(string name, int age) {
		this->name = name;
		this->age = age;
	}

	Pet() {
		name = name;
		age = age;
	}

	void setName(string name) {
		this->name = name;
	}

	string getName() {
		return this->name;
	}

	void setAge(int age) {
		this->age = age;
	}

	int getAge() {
		return this->age;
	}

	virtual void voice() = 0; // ������ ����������� �����, �� �� ��� ����������, 
	//������������ ��������� ������������ ��������������� ������ � ����������� �����, 
	//����� ����������� ����� ����� ����� �����������

	virtual void info() = 0;

	virtual ~Pet() {
		cout << "����������� Pet" << endl;
	}
};

class Cat : public Pet {

public:
	Cat(string name, int age) :Pet(name, age) {
	}

	Cat() :Pet() {
	}
	void voice() {
		cout << "���-���" << endl;
	}

	void info() {

		cout << "����� �� ������: "<<this->getName()<<", �������: "<<this->getAge() << endl;
	}

	~Cat() {
		cout << "����������� Cat" << endl;
	}
};

class Dog : public Pet {

public:
	Dog(string name, int age) :Pet(name, age) {
	}

	Dog() :Pet() {
	}

	void voice() {
		cout << "���-���" << endl;
	}

	void info() {
		cout << "������� �� ������: " << this->getName() << ", �������: " << this->getAge() << endl;
	}

	~Dog() {
		cout << "����������� Dog" << endl;
	}
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	//Pet* pet = new Pet(); ����������� ������ �� ����� ��������� ������� ��-�� ������� 
	//������ 1 �� �� �������������� ������(������������, ����� ����.)

	Pet** pets = NULL;
	int size = 5;

	pets = new Pet * [size];
	pets[0] = new Cat("�����", 3);
	pets[1] = new Dog("����", 7);
	pets[2] = new Cat("������", 2);
	pets[3] = new Cat("�����", 1);
	pets[4] = new Dog("������", 5);

	cout << "����������" << endl;
	for (int i = 0; i < size; i++){
		cout << i + 1 << ") ";
		pets[i]->info();
		pets[i]->voice();
	}
	for (int i = 0; i < size; i++)
	{
		delete pets[i];
	}
	delete[] pets;
	
	
	cout << "----------------------------------------------" << endl;
	
	

	system("pause");
	return 0;
}