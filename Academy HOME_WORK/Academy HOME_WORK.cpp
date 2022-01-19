// Academy HOME_WORK.cpp : 

#include <iostream>
#include<string>
#include<fstream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define HUMAN_TAKE_PARAMETRS const std::string& last_name, const std::string& first_name, unsigned int age
#define HUMAN_GIVE_PARAMETRS last_name, first_name, age

class Human
{
	std::string last_name;
	std::string first_name;
	unsigned int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}
	//         Constructor:
	Human(HUMAN_TAKE_PARAMETRS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);

		cout << " HConstructor:\t" << this << endl;
	}
	virtual~Human()
	{
		cout << " HDestructor:\t" << this << endl;

	}
	virtual std::ostream& print(std::ostream& os)const
	{
		os << left;
		os.width(10);
		os << last_name;
		os.width(8);
		os << first_name;
		os.width(3);
		os << age <<"лет";
		return os;
	}
	virtual std::ofstream& print(std::ofstream& os)const
	{
		os << left;
		os.width(10);
		os << last_name;
		os.width(8);
		os << first_name;
		os.width(3);
		os << age;
		return os;
	}
	virtual ifstream& scan(ifstream& is)
	{
		is >> last_name >> first_name >> age;
		return is;
	}
};
ostream& operator<<(ostream& os, const Human& obj)
{
	return obj.print(os);
}
ofstream& operator<<(ofstream& os, const Human& obj)
{
	return obj.print(os);
}
ifstream& operator>>(ifstream& is, Human& obj)
{
	return obj.scan(is);
}
#define STUDENT_TAKE_PARAMETERS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS speciality, group, rating, attendance
class Student :public Human
{
	std::string speciality;
	std::string group;
	double rating;
	double attendance;

public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	const std::string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendance()const
	{
		return attendance;
	}
	void set_speciality(const std::string speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}

	// Conctractors:
	Student(HUMAN_TAKE_PARAMETRS, STUDENT_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETRS)

	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}

	std::ostream& print(std::ostream& os)const
	{
		Human::print(os) << " ";
		os << right;
		os.width(20);
		os << speciality;
		os.width(8);
		os << group;
		os.width(6);
		os << rating;
		os.width(6);
		os << attendance;
		return os;
	}
	std::ofstream& print(std::ofstream& os)const
	{
		Human::print(os) << " ";
		os << right;
		os.width(20);
		os << speciality;
		os.width(8);
		os << group;
		os.width(6);
		os << rating;
		os.width(6);
		os << attendance;
		return os;
	}
	std::ifstream& scan(std::ifstream& is)
	{
		Human::scan(is);
		is >> speciality;
		is >> group;
		is >> rating;
		is >> attendance;
		return is;
	}
};
#define TEACHER_TAKE_PARAMETERS const std::string& speciality,unsigned int experience
#define TEACHER_GIVE_PARAMETERS  speciality,experience
class Teacher :public Human
{
	std::string speciality;
	unsigned int experience;

public:

	const std::string& get_speciality()const
	{
		return speciality;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	void set_speciality(const std::string speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}
	Teacher(HUMAN_TAKE_PARAMETRS, TEACHER_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETRS)

	{
		set_speciality(speciality);
		set_experience(experience);

		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}

	std::ostream& print(std::ostream& os)const
	{
		Human::print(os) << " ";
		os << left;
		os.width(10);
		os << speciality;
		//os.width(20);
		os << experience;
		return os;
	}
	std::ofstream& print(std::ofstream& os)const
	{
		Human::print(os) << " ";
		os << left;
		os.width(10);
		os << speciality;
		os << experience;
		return os;
	}
	std::ifstream& scan(std::ifstream& is)
	{
		Human::scan(is);
		is >> speciality;
		is >> experience;
		return is;
	}
};
#define GRADUATE_TAKE_PARAMETRS const std::string& graduate
#define GRADUATE_GIVE_PARAMETRS  graduate
class Graduate : public Student
{
	std::string graduate;

public:
	const std::string& get_graduate()const
	{
		return graduate;
	}
	void set_graduate(const std::string& graduate)
	{
		this->graduate = graduate;
	}

	Graduate(HUMAN_TAKE_PARAMETRS, STUDENT_TAKE_PARAMETERS, GRADUATE_TAKE_PARAMETRS)
		:Student(HUMAN_GIVE_PARAMETRS, STUDENT_GIVE_PARAMETERS)
	{
		set_graduate(graduate);
		cout << "GDestructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}
	std::ostream& print(std::ostream& os)const
	{
		Student::print(os) << " ";
		os << graduate;
		return os;
	}
	std::ofstream& print(std::ofstream& os)const
	{
		Student::print(os) << " ";
		os << graduate;
		return os;
	}
	std::ifstream& scan(std::ifstream& is)
	{
		Student::scan(is);
		is >> graduate;
		return is;
	}
};
Human* HumanFactory(const string& type)
{
	if (type.find("Student") != std::string::npos)return new Student("", "", 0, "", "", 0, 0);
	if (type.find("Teacher") != std::string::npos)return new Teacher("", "", 0, "", 0);
	if (type.find("Graduate") != std::string::npos)return new Graduate("", "", 0, "", "", 0, 0, "");
}
//#define INHERITANCE_CHEK
#define SAFE_TO_FILE

int main()
{
	setlocale(LC_ALL, "");
#ifdef INHERITANCE_CHEK
	Human human("Connor", "John", 18);
	human.print();

	Student stud("Pinkman", "Jessie", 25, " Chemistry", "WW_123", 85, 95);
	stud.print();

	Teacher teach("Ivanov", "Ivan", 40, "Historian", 10);
	teach.print();
	Graduate grad("Pinkman", "Jessie", 25, " Chemistry", "WW_123", 85, 95, "Дипломник");
	cout << "n-------------------------------- - :\t" << endl;
	grad.print();

#endif //  INHERITANCE_CHEK

#ifdef SAFE_TO_FALE
	Human* group[] =
	{
		new Student("Pinkman", "Jessie",25, "Chemistry", "WW_123", 85, 95),
		new Teacher("Scoot", "Smith", 40, "Historian", 10),
		new Graduate("Roberts", "Mary", 25, "Chemistry", "WW_123", 85, 95, "Graduate"),
		new Student("Versetti","Tomas",30,"City dusiness","Vice",90,80)
	};
	cout << sizeof(group) / sizeof(Human*) << endl;

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		cout << typeid(*group[i]).name() << endl;
		//group[i]->print();
		cout << *group[i] << endl;
		cout << "\n-----------------------------\n";
	}

	ofstream fout("file.txt", ios::in | ios::out);
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		fout.width(20);
		fout << left;
		fout << string(typeid(*group[i]).name()) + ":";
		fout << *group[i] << endl;
	}
	fout.close();
	system("start notepad file.txt");
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}
#endif // SAFE_TO_FALE


	Human** group = nullptr;
	int g = 0;

	ifstream fin("file.txt");
	if (fin.is_open())
	{
		std::string human_type;
		for (; !fin.eof(); g++)
		{
			std::getline(fin, human_type);
		}
		group = new Human * [g] {};
		fin.clear();
		fin.seekg(0);
		for (int i = 0; i < g; i++)
		{
			std::getline(fin, human_type, ':');
			group[i] = HumanFactory(human_type);
			fin >> *group[i];
		}
	}
	else
	{
		cerr << "Error:file not found" << endl;
	}
	for (int i = 0; i < g; i++)
	{
		cout << *group[i] << endl;
	}
	for (int i = 0; i < g; i++)
	{
		delete[] group[i];
	}

	fin.close();
	system("start notepad file.txt");
	delete[]group;


}
    

