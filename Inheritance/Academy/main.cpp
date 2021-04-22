#include <iostream>
using namespace std;

class Human
{
	string last_name;
	string first_name;
	unsigned int age;
public:
	const string& get_last_name()const
	{
		return last_name;
	}
	const string& get_first_name()const
	{
		return first_name;
	}
	unsigned int get_age() const
	{
		return age;
	}
	void set_last_name(const string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		if (age >= 15 && age <= 100)
			this->age = age;
		else
			this->age = 0;
	}
	// Constructors
	Human(const string& last_name, const string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HumanConstructor:\t" << this << endl;
	}
	~Human()
	{
		cout << "HumanDestructor:\t" << this << endl;
	}
	// Methods
	void info() const
	{
		cout << last_name << " " << first_name << ", " << age << " years old." << endl;
	}
};

class Student : public Human
{
	string specialty;
	double rating;
	unsigned int semester;
public:
	const string& get_specialty() const
	{
		return specialty;
	}
	double get_rating() const
	{
		return rating;
	}
	unsigned int get_semester() const
	{
		return semester;
	}
	void set_specialty(const string& specialty)
	{
		this->specialty = specialty;
	}
	void set_rating(double rating)
	{
		if (rating > 0 && rating <= 5)
			this->rating = rating;
		else
			this->rating = 0;
	}
	void set_semester(unsigned int semester)
	{
		if (semester <= 5)
			this->semester = semester;
		else
			this->semester = 0;
	}
	// Constructors
	Student(
		const string& last_name, const string& first_name, unsigned int age, // parent class attribs
		const string& specialty, double rating, unsigned int semester // derived class attribs
	) : Human(last_name, first_name, age)
	{
		set_specialty(specialty);
		set_rating(rating);
		set_semester(semester);
		cout << "StudentConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "StudentDestructor:\t" << this << endl;
	}
	// Methods
	void info() const
	{
		Human::info();
		cout << "Specialty: " << specialty << ", Rating: " << rating << ", Semester: " << semester << endl;
	}
};

class Teacher : public Human
{
	string specialty;
	unsigned int experience;
	double evil;
public:
	const string& get_specialty() const
	{
		return specialty;
	}
	unsigned int get_experience() const
	{
		return experience;
	}
	double get_evil() const
	{
		return evil;
	}
	void set_specialty(const string& specialty)
	{
		this->specialty = specialty;
	}
	void set_experience(unsigned int experience)
	{
		if (experience < 80)
			this->experience = experience;
		else
			this->experience = 0;
	}
	void set_evil(double evil)
	{
		if (evil >= 0 && evil <= 10)
			this->evil = evil;
		else
			this->evil = 0;
	}
	// Constructors
	Teacher(
		const string& last_name, const string& first_name, unsigned int age,
		const string& specialty, unsigned int experience, double evil
	) : Human(last_name, first_name, age)
	{
		set_specialty(specialty);
		set_experience(experience);
		set_evil(evil);
		cout << "TeacherConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TeacherDestructor:\t" << this << endl;
	}
	// Methods
	void info()
	{
		Human::info();
		cout << "Specialty: " << specialty << ", Experience: " << experience << " years, Evil: " << evil << " points." << endl;
	}
};

class Graduate : public Student
{
	string thesis;
	bool is_hired;
public:
	const string& get_thesis() const
	{
		return thesis;
	}
	bool get_hired() const
	{
		return is_hired;
	}
	void set_thesis(const string& thesis)
	{
		this->thesis = thesis;
	}
	void set_is_hired(bool is_hired)
	{
		this->is_hired = is_hired;
	}
	// Constructors
	Graduate(
		const string& last_name, const string& first_name, unsigned int age,
		const string& specialty, double rating, unsigned int semester,
		const string& thesis, bool is_hired
	) : Student(last_name, first_name, age, specialty, rating, semester)
	{
		set_thesis(thesis);
		set_is_hired(is_hired);
		cout << "GraduateConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GraduateDestructor:\t" << this << endl;
	}
	// Methods
	void info() const
	{
		Student::info();
		cout << "Thesis: " << thesis << "; Is hired? " << (is_hired ? "Yes" : "No") << ".\n";
	}
};

#define del "---------------------------------------------------------"

int main()
{
	setlocale(LC_ALL, "");
	cout << del << endl;
	Human vasily("Pupkin", "Vasily", 18);
	vasily.info();
	cout << del << endl;
	Student borya("Pupkin", "Boris", 19, "math", 4.4, 2);
	borya.info();
	cout << del << endl;
	Teacher ivanich("Ivan", "Ivanov", 56, "physics", 23, 7.6);
	ivanich.info();
	cout << del << endl;
	Graduate max("Maxim", "Maximov", 21, "chemistry", 4.7, 5, "How to make water from acid", true);
	max.info();
	cout << del << endl;
}