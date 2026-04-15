#include <iostream>

using namespace std;

enum EducationInstitution {NO_EDUC,COLLEGE,INSTITUTE,UNIVERSITY,ACADEMY};
enum Thing {NO_THING,SCHOOLCHILDREN,STUDENT,WORKER,PENSIONER};

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
	thing=NO_THING;
	
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
	thing = NO_THING;
}

//Реализация функции вывода
void Person::ShowPerson()
{
	cout << "Person: " << family << " " << name << " " << surname << endl;
	cout << "Age: " << age << endl;
	cout << "Thing: ";
	switch (thing)
	{
	case NO_EDUC:
		cout << "none" << endl;
		break;
	case SCHOOLCHILDREN:
		cout << "schoolchildren" << endl;
		break;
	case STUDENT:
		cout << "student" << endl;
		break;
	case WORKER:
		cout << "worker" << endl;
		break;
	case PENSIONER:
		cout << "pensioner" << endl;
		break;
	}	
}

//Class Schoolchildred derived from class Person and contains extra information such as a class where hi study, number school
class Schoolchildren : public Person
{
//Private members of class
private:
	int numberSchool;
	int numberClass;
	char letterClass;
public:
	Schoolchildren();
	Schoolchildren(int n, char nName[], char nSurname[], char nFamily[], Thing nThing, int a, int nSchool, int nClass, char letter) ;
	~Schoolchildren();
	void ShowSchoolchidren();
};

//Constructor without parameters
Schoolchildren::Schoolchildren(): Person()
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

//Class Student derived from class Person and contains extra information such as a type type education institution,
//name education institution, speciality and course
class Student :public Person
{
	//Private members of class
private:
	EducationInstitution typeEducationInstitution;
	char nameEducationInstitution[100];
	char speciality[100];
	int course;
public:
	Student();
	Student(int n, char nName[], char nSurname[], char nFamily[], Thing nThing, int a, EducationInstitution nEduc,char nNameEducInst[],char nSpec[],int nCourse);
	~Student();
	void ShowStudent();
};

//Constructor without parameters
Student::Student() : Person()
{
	typeEducationInstitution = NO_EDUC;
	memset(nameEducationInstitution, 0, 100);
	memset(speciality, 0, 100);
	course = 0;
}

//Constructor with parameters
Student::Student(int n, char nName[], char nSurname[], char nFamily[], Thing nThing, int a, EducationInstitution nEduc, char nNameEducInst[], char nSpec[], int nCourse) : Person(n,nName,nSurname,nFamily,nThing, a)
{
	typeEducationInstitution = nEduc;
	memcpy(nameEducationInstitution, nNameEducInst, 100);
	memcpy(speciality, nSpec, 100);
	course = nCourse;
}

//Destructor
Student::~Student()
{
	typeEducationInstitution = NO_EDUC;
	memset(nameEducationInstitution, 0, 100);
	memset(speciality, 0, 100);
	course = 0;
	Person::~Person();
}

//Function output schoolchildred parameters
void Student::ShowStudent()
{
	ShowPerson();
	cout << "Educational Institution: ";
	switch(typeEducationInstitution)
	{
		case NO_EDUC:
			cout << "none" << endl;
			break;
		case COLLEGE:
			cout << "college" << endl;
			break;
		case INSTITUTE:
			cout << "institute" << endl;
			break;
		case UNIVERSITY:
			cout << "university" << endl;
			break;
		case ACADEMY:
			cout << "academy" << endl;
			break;

	}
	cout << "Name educational institution:  " << nameEducationInstitution << endl;
	cout << "Speciality: " << speciality << endl;
	cout << "Course: " << course << endl;
}


//Class Worker derived from class Person and contains extra information such as a professional, name of the firm, payment and stage
class Worker : public Person
{
	//Private members of class
private:
	char professional[20];
	char nameFirm[100];
	int stage;
	float payValue;

public:
	Worker();
	Worker(int n, char nName[], char nSurname[], char nFamily[], Thing nThing, int a, char nProfessional[],char nNameFirm[],int nStage,float nPay);
	~Worker();
	void ShowWorker();


};

//Constructor without parameters
Worker::Worker() : Person()
{
	memset(professional, 0,20);
	memset(nameFirm, 0, 100);
	stage=0;
	payValue = 0.0;
}

//Constructor with parameters
Worker::Worker(int n, char nName[], char nSurname[], char nFamily[], Thing nThing, int a, char nProfessional[], char nNameFirm[], int nStage, float nPay) : Person(n, nName, nSurname, nFamily, nThing, a)
{
	memcpy(professional, nProfessional, 20);
	memcpy(nameFirm, nNameFirm, 100);
	stage = nStage;
	payValue = nPay;
}

//Destructor
Worker::~Worker()
{
	memset(professional, 0, 20);
	memset(nameFirm, 0, 100);
	stage = 0;
	payValue = 0.0;
	Person::~Person();
}

//Function output schoolchildred parameters
void Worker::ShowWorker()
{
	ShowPerson();	
	cout << "Firm:  " << nameFirm << endl;
	cout << "Profession: " << professional << endl;
	cout << "Staeg: " << stage << endl;
	cout << "Pay: " << payValue << endl;
}



//Class Pensioner derived from class Person and contains extra information such as a name pension fond
class Pensioner : public Person
{
	//Private members of class
private:
	char namePensionFound[100];
	float payValue;
public:
	Pensioner();
	Pensioner(int n, char nName[], char nSurname[], char nFamily[], Thing nThing, int a, char nPensionFound[], float nPay);
	~Pensioner();
	void ShowPensioner();
};

//Constructor without parameters
Pensioner::Pensioner() : Person()
{
	memset(namePensionFound, 0, 100);	
	payValue = 0.0;
}

//Constructor with parameters
Pensioner::Pensioner(int n, char nName[], char nSurname[], char nFamily[], Thing nThing, int a, char nPensionFound[], float nPay) : Person(n, nName, nSurname, nFamily, nThing, a)
{
	memcpy(namePensionFound, nPensionFound, 100);
	payValue = 0.0;
}

//Destructor
Pensioner::~Pensioner()
{
	memset(namePensionFound, 0, 100);
	payValue = 0.0;
	Person::~Person();
}

//Function output schoolchildred parameters
void Pensioner::ShowPensioner()
{
	ShowPerson();
	cout << "Name pension found:  " << namePensionFound << endl;
	cout << "Pay: " << payValue << endl;
}






int main()
{
	cout << "Programm ClassThing" << endl;	
	Schoolchildren schoolchidrenArray[10];
	int idxSchool = 0;
	int pAge = 0;
	int thing;
	Thing pThing;
	char pFamily[20];
	char pName[20];
	char pSurname[20];
	int pSchool;
	int pClass;
	char pLetter;

	Student studentArray[10];
	int idxStud = 0;
	EducationInstitution pTypeEducationInstitution;
	int type;
	char pNameEducationInstitution[100];
	char pSpeciality[100];
	int pCourse;

	Worker workerArray[10];
	int idxWork = 0;
	char pProfessional[20];
	char pNameFirm[100];
	int pStage;
	float pPayWorker;

	Pensioner pensionerArray[10];
	int idxPens = 0;
	char pNamePensionFound[100];
	float pPayPensioner;

	int quit = 0;
	int number = 1;

	cout << "Input data persons" << endl;
	while (!quit)
	{
		cout << "Input person data" << endl;
		cout << "Input family: ";
		cin >> pFamily;
		cout << "Input name: ";
		cin >> pName;
		cout << "Input surname: ";
		cin >> pSurname;
		cout << "Input age:";
		cin >> pAge;
		cout << "Choohe his thing: Schoolchildren-1; Student-2; Worker-3; Pensioner-4" << endl;
		cin >> thing;
		switch (thing)
		{
			case 1:
			{
				pThing = SCHOOLCHILDREN;
				cout << "Input schoolchildren data" << endl;
				cout << "Input number school: " << endl;
				cin >> pSchool;
				cout << "Input class: " << endl;
				cin >> pClass;
				cin >> pLetter;
				Schoolchildren schoolchildren = Schoolchildren(number, pName, pSurname, pFamily, pThing, pAge, pSchool, pClass, pLetter);
				if (idxSchool < 10)
				{
					schoolchidrenArray[idxSchool] = schoolchildren;
					idxSchool++;
				}
			}
			break;
			case 2:
			{
				pThing = STUDENT;
				cout << "Input sudent data" << endl;
				cout << "Chose type educational: College-1; Institute-2; University-3; Academy-4" << endl;
				cin >> type;
				switch (type)
				{
					case 1:
						pTypeEducationInstitution = COLLEGE;
						break;
					case 2:
						pTypeEducationInstitution = INSTITUTE;
						break;
					case 3:
						pTypeEducationInstitution = UNIVERSITY;
						break;
					case 4:
						pTypeEducationInstitution = ACADEMY;
						break;
				}
				cout << "Name educational institution: " << endl;
				cin >> pNameEducationInstitution;
				cout << "Speciality: " << endl;
				cin >> pSpeciality;
				cout << "Course: " << endl;
				cin >> pCourse;
				Student student = Student(number, pName, pSurname, pFamily, pThing, pAge, pTypeEducationInstitution,pNameEducationInstitution,pSpeciality,pCourse);
				if (idxStud < 10)
				{
					studentArray[idxStud] = student;
					idxStud++;
				}
			}
			break;
			case 3:
			{
				cout << "Input worker data" << endl;
			}
			break;
			case 4:
			{
				cout << "Input pensinoner data" << endl;
			}
			break;
		}
		cout << "Do you want finish input? Yes-1/No-0" << endl;
		cin >> quit;

		number++;
	}
	

	//cout << "Input data schoolchildren" << endl;
	//for (int i = 0; i<2; i++)
	//{
	//	cout << "Input family: ";
	//	cin >> pFamily;
	//	cout << "Input name: ";
	//	cin >> pName;
	//	cout << "Input surname: ";
	//	cin >> pSurname;
	//	cout << "Input age:";
	//	cin >> pAge;
	//	cout << "Input thing (Schollchildren=1, Student=2, Worker=3, Pensioner=4)";
	//	cin >> thing;
	//	switch (thing)
	//	{
	//		case 0:
	//			pThing = NO_THING;
	//			break;
	//		case 1:
	//			pThing = SCHOOLCHILDREN;
	//			break;
	//		case 2:
	//			pThing = STUDENT;
	//			break;
	//		case 3:
	//			pThing = WORKER;
	//			break;
	//		case 4:
	//			pThing = PENSIONER;
	//			break;
	//	}
	//	cout << "Input number school: " << endl;
	//	cin >> pSchool;
	//	cout << "Input class: " << endl;
	//	cin >> pClass;
	//	cin >> pLetter;
	//    Schoolchildren schoolchildren = Schoolchildren(i+1, pName, pSurname, pFamily, pThing, pAge, pSchool, pClass, pLetter);
	//	schoolchidrenArray[i] = schoolchildren;
	//	cout << "==================" << endl;
	//}
	cout << "************************************" << endl;
	if (idxSchool>0)
	{
		cout << "Your schoolchildred data" << endl;
		for (int i = 0; i < 2; i++)
		{
			schoolchidrenArray[i].ShowSchoolchidren();
		}
	}
	if (idxStud>0)
	{
		cout << "Your student data" << endl;
		for (int i = 0; i < 2; i++)
		{
			studentArray[i].ShowStudent();
		}
	}
	


	system("pause");
	return 0;
}