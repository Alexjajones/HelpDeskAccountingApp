#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//----//
enum EmployeeTypes{
	Senior,
	Ordinary,
	Contracted
};

class Employee{
public:
	int ID;
	double PayRate, PayAmount;
	string Name;
	EmployeeTypes Position;
	virtual void CalculatePay(){}
	void GetName();
	virtual void GetPay(){}
};
//----//
class WorkForcePay{
public:
	static double TotalPay;
	static double SeniorPay;
	static double OrdinaryPay;
	static double ContractorPay;
	static double DefaultSalaried;
	static double DefaultHourly;
	static double DefaultPayIncrease;
	static double NumberOfEmployees;
	static Employee * PayArray [200];
	static void CalculateTotalPays();
	static void OutputPay();
};

double WorkForcePay::TotalPay=0;
double WorkForcePay::SeniorPay=0;
double WorkForcePay::OrdinaryPay=0;
double WorkForcePay::ContractorPay=0;
double WorkForcePay::DefaultSalaried=20000;
double WorkForcePay::DefaultHourly=8;
double WorkForcePay::DefaultPayIncrease=0.1;
double WorkForcePay::NumberOfEmployees=0;
Employee * WorkForcePay::PayArray[200];

//----//
class SalriedStaff : public Employee{ 
public:
	void CalculatePay();
	void GetPay();
};

class HourlyStaff : public Employee{ 
public:
	int HoursWorked;
	void CalculatePay();
	void GetPay();
};

class SeniorStaff : public SalriedStaff{
public:
	void CalculatePay();
	SeniorStaff(){this->Position=Senior;}
	int Salary, PayIncrease;
};

class OrdinaryStaff : public SalriedStaff{ 
public:
	void CalculatePay();
	OrdinaryStaff(){this->Position=Ordinary;}
	int Salary;
};

class Contractor : public HourlyStaff{
public:
	void CalculatePay();
	Contractor(){this->Position=Contracted;}
	int Salary;
};
//----//
class HelperFunctions{
public:
	static void WriteToFile(string What);
	static void WriteToFile(string What, string FilePath);
	static string ReadFromFile(string LeftSide);
	static string ReadFromFile(string LeftSide, string FilePath);
	static bool ValidateName(string Target);
	static bool ValidatePay(string Target);
	static string PadString(string Target);
	static string PadString(string Target,  int Width);
	static void DrawSeperator(string Sides, string Middle);
	static void DrawSeperator(string Sides, string Middle, int Width);
	static void DrawVisualPayBar(int* ValuesToUse, string* Legend);
	static void DrawVisualPayBar(int* ValuesToUse,string* Legend, int Width);
	static string ConvertCharArrayToString(char* Target);
	static void ConvertStringToCharArray(string In, char* Target);
	static int GetEmployees();
};
//----//