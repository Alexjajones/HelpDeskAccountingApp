#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void Employee::GetName(){
	string TempName = "";
	cout << HelperFunctions::PadString("\tEnter a name: ", 40); 
	cin.ignore(INT_MAX, '\n');
	getline(cin, TempName); //cin >> Name;

	while (!HelperFunctions::ValidateName(TempName)){
		cout << HelperFunctions::PadString("\t  -> Enter staff name: ", 40);; cin >> TempName;
	};
	this -> Name = TempName ;
	cout << "";
}

void HourlyStaff::GetPay(){
	char Temp[200];
	char Temp2[200];

	string TempHours;
	cout << HelperFunctions::PadString("\tEnter hours worked: ", 40);
	cin >> TempHours;

	while (!HelperFunctions::ValidatePay(TempHours)){
		cout << HelperFunctions::PadString("\t  -> Enter valid hours:", 40); cin >> TempHours;
	};
	HelperFunctions::ConvertStringToCharArray(TempHours, Temp);
	this -> HoursWorked = atoi(Temp);

	string Pay = "";
	cout << HelperFunctions::PadString("\tEnter hourly pay: ", 39) << (char)156;
	cin >> Pay;
	while (!HelperFunctions::ValidatePay(Pay)){
		cout << HelperFunctions::PadString("\t  -> Enter valid hourly pay:", 39) << (char)156; cin >> Pay;
	};
	HelperFunctions::ConvertStringToCharArray(Pay, Temp);
	this -> PayRate = atoi(Temp) ;
}


void SalriedStaff::GetPay(){	
	string Pay = "";
	cout << HelperFunctions::PadString("\tEnter salaried pay for Employee", 39) << (char)156;
	//cin.ignore(INT_MAX, '\n');
	cin >> Pay;
	while (!HelperFunctions::ValidatePay(Pay)){
		cout << HelperFunctions::PadString("\t  -> Please enter a valid pay", 39) << (char)156 << endl; cin >> Pay;
	};
	char Temp[200];
	HelperFunctions::ConvertStringToCharArray(Pay, Temp);
	this -> PayRate = atoi(Temp);
}

void HourlyStaff::CalculatePay(){
	cout << HelperFunctions::PadString("Calculating pay for -> " + this->Name, 40) << "\t\t[Contractor]" << endl;
	this->PayAmount = (this->HoursWorked * this->PayRate);
}

void SalriedStaff::CalculatePay(){
	cout << HelperFunctions::PadString("Calculating pay for -> " + this->Name, 40) << (this->Position == Senior ? "\t\t[Senior]" : "\t\t[Staff]") << endl;
	this->PayAmount = PayRate/12;
	this->PayAmount *= (this->Position == EmployeeTypes::Senior) ? (1 + WorkForcePay::DefaultPayIncrease) : 1 ;
}

void OrdinaryStaff::CalculatePay(){SalriedStaff::CalculatePay();}
void SeniorStaff::CalculatePay(){SalriedStaff::CalculatePay();}
void Contractor::CalculatePay(){HourlyStaff::CalculatePay();}