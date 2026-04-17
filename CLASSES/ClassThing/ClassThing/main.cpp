#include <iostream>
#include <string>

using namespace std;


//Class Person contains name, surname, family and age of person
class Person
{
//Public members of class
public:
	Person();//constructor without parameters
	Person(int aNumberRecord, string aNamePeron, string aSurnamePerson, string aFamilyPerson, int aCodeThing, int aAgePerson);//consrtructor with parameters
	~Person();//Destructor 

	void ShowPerson();//Function for output information

//Private members of class
private:	
	string namePerson;
	string surnamePerson;
	string familyPerson;
	int agePerson;
	int numberRecord;
	int codeThing;
	
};

//Realize constructor without parameters
Person::Person()
{	
	agePerson = 0;
	numberRecord = 0;
	namePerson = "";
	surnamePerson = "";
	familyPerson = "";
	codeThing = 0;
	
}

//Realize consrtructor with parameters
Person::Person(int aNumberRecord, string aNamePerson, string aSurnamePerson, string aFamilyPerson, int aCodeThing, int aAgePerson)
{
	agePerson = aAgePerson;
	numberRecord = aNumberRecord;
	namePerson = aNamePerson;
	surnamePerson = aSurnamePerson;
	familyPerson = aFamilyPerson;
	codeThing = aCodeThing;
}

//Realize destructor
Person::~Person()
{
	agePerson = 0;
	numberRecord = 0;
	namePerson = "";
	surnamePerson = "";
	familyPerson = "";
	codeThing = 0;
}

//Реализация функции вывода
void Person::ShowPerson()
{
	cout << "Person: " << familyPerson << " " << namePerson << " " << surnamePerson << endl;
	cout << "Age: " << agePerson << endl;
	cout << "Thing: ";
	switch (codeThing)
	{
	case 0:
		cout << "none" << endl;
		break;
	case 1:
		cout << "schoolchildren" << endl;
		break;
	case 2:
		cout << "student" << endl;
		break;
	case 3:
		cout << "worker" << endl;
		break;
	case 4:
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
	string nameClass;
public:
	Schoolchildren();
    Schoolchildren(int aNumberRecord, string aNamePerson, string aSurnamePerson, string aFamilyPerson, int aCodeThing, int aAgePerson, int aNumberSchool, string aNameClass);
	~Schoolchildren();
	void ShowSchoolchidren();
};

//Constructor without parameters
Schoolchildren::Schoolchildren(): Person()
{
	numberSchool = 0;
	nameClass = "";
}

//Constructor with parameters
Schoolchildren::Schoolchildren(int aNumberRecord, string aNamePerson, string aSurnamePerson, string aFamilyPerson, int aCodeThing, int aAgePerson, int aNumberSchool, string aNameClass) :Person(aNumberRecord,aNamePerson,aSurnamePerson,aFamilyPerson,aCodeThing,aAgePerson)
{
	//numberSchool = nSchool;
	//numberClass = nClass;
	//letterClass = letter;

	numberSchool = aNumberSchool;
	nameClass = aNameClass;
}

//Destructor
Schoolchildren::~Schoolchildren()
{
	numberSchool=0;
	nameClass = "";
	Person::~Person();
}

//Function output schoolchildred parameters
void Schoolchildren::ShowSchoolchidren()
{
	ShowPerson();
	cout << "School N " << numberSchool << endl;
	cout << "Class " << nameClass << endl;
}

//Class Student derived from class Person and contains extra information such as a type type education institution,
//name education institution, speciality and course
class Student :public Person
{
	//Private members of class
private:
	int codeEducationInstitution;
	string nameEducationInstitution;
	string speciality;
	int course;
public:
	Student();
	Student(int aNumberRecord, string aNamePerson, string aSurnamePerson, string aFamilyPerson, int aCodeThing, int aAgePerson, int aCodeEducationInstitution, string aNameEducationInstitution, string aSpeciality, int aCourse);
	~Student();
	void ShowStudent();
};

//Constructor without parameters
Student::Student() : Person()
{
	codeEducationInstitution = 0;
	nameEducationInstitution = "";
	speciality = "";
	course = 0;
}

//Constructor with parameters
Student::Student(int aNumberRecord, string aNamePerson, string aSurnamePerson, string aFamilyPerson, int aCodeThing, int aAgePerson, int aCodeEducationInstitution, string aNameEducationInstitution, string aSpeciality, int aCourse) : Person(aNumberRecord, aNamePerson, aSurnamePerson, aFamilyPerson, aCodeThing, aAgePerson)
{
	codeEducationInstitution = aCodeEducationInstitution;
	nameEducationInstitution = aNameEducationInstitution;
	speciality = aSpeciality;
	course = aCourse;
}

//Destructor
Student::~Student()
{
	codeEducationInstitution = 0;
	nameEducationInstitution = "";
	speciality = "";
	course = 0;
	Person::~Person();
}

//Function output schoolchildred parameters
void Student::ShowStudent()
{
	ShowPerson();
	cout << "Educational Institution: ";
	switch(codeEducationInstitution)
	{
		case 0:
			cout << "none" << endl;
			break;
		case 1:
			cout << "college" << endl;
			break;
		case 2:
			cout << "institute" << endl;
			break;
		case 3:
			cout << "university" << endl;
			break;
		case 4:
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
	string profession;
	string nameFirm;
	int stage;
	float payment;

public:
	Worker();
	Worker(int aNumberRecord, string aNamePerson, string aSurnamePerson, string aFamilyPerson, int aCodeThing, int aAgePerson, string aProfession,string aNameFirm,int aStage,float aPayment);
	~Worker();
	void ShowWorker();


};

//Constructor without parameters
Worker::Worker() : Person()
{
	profession = "";
	nameFirm = "";
	payment = 0.0;
	stage = 0;
}

//Constructor with parameters
Worker::Worker(int aNumberRecord, string aNamePerson, string aSurnamePerson, string aFamilyPerson, int aCodeThing, int aAgePerson, string aProfession, string aNameFirm, int aStage, float aPayment) : Person(aNumberRecord, aNamePerson, aSurnamePerson, aFamilyPerson, aCodeThing, aAgePerson)
{
	profession = aProfession;
	nameFirm = aNameFirm;
	stage = aStage;
	payment = aPayment;
}

//Destructor
Worker::~Worker()
{
	profession = "";
	nameFirm = "";
	payment = 0.0;
	stage = 0;
	Person::~Person();
}

//Function output schoolchildred parameters
void Worker::ShowWorker()
{
	ShowPerson();	
	cout << "Firm:  " << nameFirm << endl;
	cout << "Profession: " <<profession << endl;
	cout << "Stage: " << stage << endl;
	cout << "Pay: " << payment << endl;
}



//Class Pensioner derived from class Person and contains extra information such as a name pension fond
class Pensioner : public Person
{
	//Private members of class
private:
	string namePensionFound;
	float payment;
public:
	Pensioner();
	Pensioner(int aNumberRecord, string aNamePerson, string aSurnamePerson, string aFamilyPerson, int aCodeThing, int aAgePerson, string aPensionFound, float aPayment);
	~Pensioner();
	void ShowPensioner();
};

//Constructor without parameters
Pensioner::Pensioner() : Person()
{
	namePensionFound = "";
	payment = 0.0;
}

//Constructor with parameters
Pensioner::Pensioner(int aNumberRecord, string aNamePerson, string aSurnamePerson, string aFamilyPerson, int aCodeThing, int aAgePerson, string aNamePensionFound, float aPayment) : Person(aNumberRecord, aNamePerson, aSurnamePerson, aFamilyPerson, aCodeThing, aAgePerson)
{
	//memcpy(namePensionFound, nPensionFound, 100);
	namePensionFound = aNamePensionFound;
	payment = aPayment;
}

//Destructor
Pensioner::~Pensioner()
{
	namePensionFound = "";
	payment = 0.0;
	Person::~Person();
}

//Function output schoolchildred parameters
void Pensioner::ShowPensioner()
{
	ShowPerson();
	cout << "Name pension found:  " << namePensionFound << endl;
	cout << "Pay: " << payment << endl;
}






int main()
{
	cout << "Programm ClassThing" << endl;	
	Schoolchildren schoolchidrenArray[10];
	int idxSchool = 0;
	int pAge = 0;
	int pCodeThing;
	int pSchool;
	string pNameClass;
	string pFamily;
	string pName;
	string pSurname;

	Student studentArray[10];
	int idxStud = 0;
	int pCodeEducationInstitution;
	string pNameEducationInstitution;
	string pSpeciality;
	int pCourse;

	Worker workerArray[10];
	int idxWork = 0;
	string pProfessional;
	string pNameFirm;
	int pStage;
	float pPayWorker;

	Pensioner pensionerArray[10];
	int idxPens = 0;
	string pNamePensionFound;
	float pPayPensioner;

	int quit = 0;
	int number = 1;

	cout << "Input data persons" << endl;
	while (!quit)
	{
		cout << "Input person data" << endl;
		cout << "Input family: ";
		cin >> pFamily;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Input name: ";
		cin >> pName;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Input surname: ";
		cin >> pSurname;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Input age:";
		cin >> pAge;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Choohe his thing: Schoolchildren-1; Student-2; Worker-3; Pensioner-4" << endl;
		cin >> pCodeThing;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		switch (pCodeThing)
		{
			case 1:
			{
				cout << "Input schoolchildren data" << endl;
				cout << "Input number school: " << endl;
				cin >> pSchool;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Input class: " << endl;			
				cin >> pNameClass;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');				
				Schoolchildren schoolchildren = Schoolchildren(number, pName, pSurname, pFamily, pCodeThing, pAge, pSchool, pNameClass);
				if (idxSchool < 10)
				{
					schoolchidrenArray[idxSchool] = schoolchildren;
					idxSchool++;
				}
			}
			break;
			case 2:
			{			
				cout << "Input sudent data" << endl;
				cout << "Chose type educational: College-1; Institute-2; University-3; Academy-4" << endl;				
				cin >> pCodeEducationInstitution;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');				
				cout << "Name educational institution: " << endl;				
				getline(cin, pNameEducationInstitution);
				cout << "Speciality: " << endl;				
				getline(cin, pSpeciality);
				cout << "Course: " << endl;
				cin >> pCourse;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');				
				Student student = Student(number, pName, pSurname, pFamily, pCodeThing, pAge, pCodeEducationInstitution, pNameEducationInstitution, pSpeciality, pCourse);
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
				cout << "Name firm: " << endl;								
				getline(cin, pNameFirm);
				cout << "Profession: " << endl;				
				getline(cin, pProfessional);
				cout << "Your stage: " << endl;
				cin >> pStage;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Yuor payment: " << endl;
				cin >> pPayWorker;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');				
				Worker worker = Worker(number, pName, pSurname, pFamily, pCodeThing, pAge, pProfessional, pNameFirm, pStage, pPayWorker);
				if (idxWork < 10)
				{
					workerArray[idxWork] = worker;
					idxWork++;
				}
				
			}
			break;
			case 4:
			{				
				cout << "Input pensinoner data" << endl;
				cout << "Input wour pension foud" << endl;				
				getline(cin, pNamePensionFound);
				cout << "Your pension payment" << endl;
				cin>>pPayPensioner;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');				
				Pensioner pensioner = Pensioner(number, pName, pSurname, pFamily, pCodeThing, pAge, pNamePensionFound, pPayPensioner);
				if (idxPens < 10)
				{
					pensionerArray[idxPens] = pensioner;
					idxPens++;
				}
			}
			break;
		}
		cout << "Do you want finish input? Yes-1/No-0" << endl;
		cin >> quit;

		number++;
	}
		
	cout << "************************************" << endl;
	cout << "Your data" << endl << endl;

	if (idxSchool>0)
	{
		cout << "Schoolchildreds data" << endl;
		cout << "====================" << endl;
		for (int i = 0; i < idxSchool; i++)
		{
			schoolchidrenArray[i].ShowSchoolchidren();
		}
	}
	if (idxStud>0)
	{
		cout << "Students data" << endl;
		cout << "=============" << endl;
		for (int i = 0; i < idxStud; i++)
		{
			studentArray[i].ShowStudent();
		}
	}
	if (idxWork>0)
	{
		cout << "Workers data" << endl;
		cout << "============" << endl;
		for (int i = 0; i < idxWork; i++)
		{
			workerArray[i].ShowWorker();
		}
	}
	if (idxPens>0)
	{
		cout << "Pensioners data" << endl;
		cout << "===============" << endl;
		for (int i = 0; i < idxPens; i++)
		{
			pensionerArray[i].ShowPensioner();
		}
	}
	


	system("pause");
	return 0;
}