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

	virtual void voice() = 0; // чистый виртуальный метод, он же без риализации, 
	//абстрактнеый требуется обязательное переопределение метода в производном клссе, 
	//иначе производный класс также будет абстрактным

	virtual void info() = 0;

	virtual ~Pet() {
		cout << "Декструктор Pet" << endl;
	}
};

class Cat : public Pet {

public:
	Cat(string name, int age) :Pet(name, age) {
	}

	Cat() :Pet() {
	}
	void voice() {
		cout << "Мяу-мяу" << endl;
	}

	void info() {

		cout << "Котик по кличке: "<<this->getName()<<", возраст: "<<this->getAge() << endl;
	}

	~Cat() {
		cout << "Декструктор Cat" << endl;
	}
};

class Dog : public Pet {

public:
	Dog(string name, int age) :Pet(name, age) {
	}

	Dog() :Pet() {
	}

	void voice() {
		cout << "Гав-гав" << endl;
	}

	void info() {
		cout << "Собачка по кличке: " << this->getName() << ", возраст: " << this->getAge() << endl;
	}

	~Dog() {
		cout << "Декструктор Dog" << endl;
	}
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	//Pet* pet = new Pet(); абстрактные классы не могут порождать объекты из-за наличия 
	//хотябы 1 го не реализованного метода(абстрактного, чисто вирт.)

	Pet** pets = NULL;
	int size = 5;

	pets = new Pet * [size];
	pets[0] = new Cat("Борис", 3);
	pets[1] = new Dog("Рекс", 7);
	pets[2] = new Cat("Марсик", 2);
	pets[3] = new Cat("Пушок", 1);
	pets[4] = new Dog("Барсик", 5);

	cout << "Перекличка" << endl;
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