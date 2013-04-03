#include <iostream>
using namespace std;

class WorkForcePay{
	int Total, Senior, Ordinary, Contractor, DefaultSalaried, DefaultHourly, DefaultPayIncrease;
public:
	void CalculateTotalPays();
};

class Employee{
	int ID, EmployeeType;
	double Name, Position;
public:
	void GetName();
};

class SalriedStaff : public Employee{ 
public:
	void CalculatePay();
	void GetPay();
};

class SeniorStaff : public SalriedStaff{ 
int Salary, PayIncrease;
};

class OrdinaryStaff : public SalriedStaff{ 
int Salary, PayIncrease;
};


class HourlyStaff : public Employee{ 
public:
	void CalculatePay();
	void GetPay();
};

class Contractor : public HourlyStaff{
int Salary;
};

enum EmployeeTypes{
	Senior,
	Ordinary,
	Contractor
};

int main ()
{
	return 0;
}