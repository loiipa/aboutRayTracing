#include <iostream>

using namespace std;

class Student
{
	private:
		char	name[10];
		int		age;
		int		studentID;
	public:
	Student(char *_name, int _age, int _studentID) : age(_age), studentID(_studentID)
	{
		strcpy(name, _name);
	}
	void	Getinfo()
	{
		cout << "name: " << name << endl;
		cout << "age: " << age << endl;
		cout << "id: " << studentID << endl;
	}
};

int		main(void)
{
	Student	*student[3];
	char	name[10];
	int		age;
	int		studentID;

	for (int i = 0; i < 3; i++)
	{
		cin >> name >> age >> studentID;
		student[i] = new Student(name, age, studentID);
	}
	for (int i = 0; i < 3; i++)
	{
		student[i]->Getinfo();
	}
	for (int i = 0; i < 3; i++)
	{
		delete student[i];
	}
}
