#include <iostream>

using namespace std;

enum EducationInstitution {noEduc,College,Instutute,University,Academy};
enum Thing {noThing,Schollchildren=1,Student=2,Worker=3,Pensioner=4};

//Class Person contains name, surname, family and age of person
class Person
{
//Public members of class
public:
	Person();//constructor without parameters
	Person(int numb, char nName[], char nSurname[], char nFamily[], Thing nThing, int a);//consrtructor with parameters
	~Person();//Destructor 

	void ShowPerson();//Function for output information

//Private members of class
private:
	int age;
	int num;
	char name[20];
	char surname[20];
	char family[20];
	Thing thing;
	
};

//Realize constructor without parameters
Person::Person()
{
	age = 0;
	num = 0;
	memset(name, 0, 20);
	memset(surname, 0, 20);
	memset(family, 0, 20);
	thing=noThing;
	
}

//Realize consrtructor with parameters
Person::Person(int numb, char nName[], char nSurname[], char nFamily[], Thing nThing, int a)
{
	age = a;
	num = numb;	
	memcpy(name, nName, 20);
	memcpy(surname, nSurname, 20);
	memcpy(family, nFamily, 20);
	thing = nThing;
	
}

//Realize destructor
Person::~Person()
{
	age = 0;
	num = 0;
	memset(name, 0, 20);
	memset(surname, 0, 20);
	memset(family, 0, 20);
	thing = noThing;
}

//Реализация функции вывода
void Person::ShowPerson()
{
	cout << "Person: " << family << " " << name << " " << surname << endl;
	cout << "Age: " << age << endl;
	cout << "Thig: " << thing << endl;	
}

//Class Schoolchildred derived from class Person and contains extra information such as a class where hi study, number school
class Schoolchildren : Person
{
//Private members of class
private:
	int numberSchool;
	int numberClass;
	char letterClass;

public:
	Schoolchildren();
	Schoolchildren(int n, char nName[],char nSurname[],char nFamily[],Thing nThing,int a,int nSchool, int nClass, char letter);
	~Schoolchildren();
	void ShowSchoolchidren();
};

//Constructor without parameters
Schoolchildren::Schoolchildren():Person()
{
	numberSchool = 0;
	numberClass = 0;
	letterClass = '0';
}

//Constructor with parameters
Schoolchildren::Schoolchildren (int n,char nName[],char nSurname[],char nFamily[],Thing nThing,int a,int nSchool,int nClass,char letter):Person(n,nName,nSurname,nFamily,nThing,a)
{
	numberSchool = nSchool;
	numberClass = nClass;
	letterClass = letter;
}

//Destructor
Schoolchildren::~Schoolchildren()
{
	numberSchool=0;
	numberClass=0;
	letterClass='0';
	Person::~Person();
}

//Function output schoolchildred parameters
void Schoolchildren::ShowSchoolchidren()
{
	ShowPerson();
	cout << "School N " << numberSchool << endl;
	cout << "Class " << numberClass << letterClass << endl;
}

//Class Worker derived from class Person and contains extra information such as a professional, name of the firm, payment and stage
class Worker : Person
{
	//Private members of class
private:
	char professonal[20];
	char nameFirm[100];
	int stage;
	float payValye;
};

//Class Student derived from class Person and contains extra information such as a type type education institution,
//name education institution, speciality and course
class Student : Person
{
	//Private members of class
private:
	EducationInstitution typeEducationInstitution;	
	char nameEducationInstitution[100];
	char speciality[100];
	int course;
};

//Class Pensioner derived from class Person and contains extra information such as a name pension fond
class Pensioner : Person
{
	//Private members of class
private:
	char namePensionFound[100];
	float payValue;
};



int main()
{
	cout << "Programm ClassThing" << endl;
	Schoolchildren schoolchidrenArray[10];
	int pAge = 0;
	int thing;
	Thing pThing;
	char pFamily[20];
	char pName[20];
	char pSurname[20];
	int pSchool;
	int pClass;
	char pLetter;

	cout << "Input data schoolchildren" << endl;
	for (int i = 0; i<2; i++)
	{
		cout << "Input family: ";
		cin >> pFamily;
		cout << "Input name: ";
		cin >> pName;
		cout << "Input surname: ";
		cin >> pSurname;
		cout << "Input age:";
		cin >> pAge;
		cout << "Input thing (Schollchildren=1, Student=2, Worker=3, Pensioner=4)";
		cin >> thing;
		switch (thing)
		{
			case 0:
				pThing = noThing;
				break;
			case 1:
				pThing = Schollchildren;
				break;
			case 2:
				pThing = Student;
				break;
			case 3:
				pThing = Worker;
				break;
			case 4:
				pThing = Pensioner;
				break;
		}
		cout << "Input number school: " << endl;
		cin >> pSchool;
		cout << "Input class: " << endl;
		cin >> pClass;
		cin >> pLetter;

	    Schoolchildren schoolchildren = Schoolchildren(i+1, pName, pSurname, pFamily, pThing, pAge, pSchool, pClass, pLetter);
		schoolchidrenArray[i] = schoolchildren;
		cout << "==================" << endl;



	}

	cout << "************************************" << endl;
	cout << "Your schoolchildred data" << endl;
	for (int i = 0; i < 2; i++)
	{		
		schoolchidrenArray[i].ShowSchoolchidren();
	}

	system("pause");

	return 0;
}