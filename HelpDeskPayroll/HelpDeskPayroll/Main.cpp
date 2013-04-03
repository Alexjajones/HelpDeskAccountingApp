/*
* Program Title:		Tech Genius Helpdesk Payroll
* Program Authors:		Daniel Fay, Alexander Jones
* Program Description:	Calculates the pay details for different helpdesk employees	
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

enum EmployeeTypes{
	Senior,
	Ordinary,
	Contractor
};

class Employee{
	public:
		int ID, EmployeeType;
		double Name, Position;
		void CalculatePay();
		void GetName();
};

class SalriedStaff : public Employee{ 
	public:
		void CalculatePay();
		void GetPay();
};

class HourlyStaff : public Employee{ 
	public:
		void CalculatePay();
		void GetPay();
};

class SeniorStaff : public SalriedStaff{
	public:
		SeniorStaff(){this->EmployeeType=EmployeeTypes::Senior;}
		int Salary, PayIncrease;
};

class OrdinaryStaff : public SalriedStaff{ 
	public:
		OrdinaryStaff(){this->EmployeeType=EmployeeTypes::Ordinary;}
		int Salary;
};

class Contractor : public HourlyStaff{
	public:
		Contractor(){this->EmployeeType=EmployeeTypes::Contractor;}
		int Salary;
};

const string DefaultFile = "PayDetails.txt";
const int DefaultWidth = 70; 

static class HelperFunctions{
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
		static void DrawVisualPayBar(int* ValuesToUse);
				static void DrawVisualPayBar(int* ValuesToUse, int Width);
		static string ConvertCharArrayToString(char* Target);
		static void ConvertStringToCharArray(string In, char* Target);
};

void HelperFunctions::WriteToFile(string What){HelperFunctions::WriteToFile(What, DefaultFile);}
void HelperFunctions::WriteToFile(string What, string FilePath){
	ofstream OutFile;
	OutFile.open (FilePath,  fstream::in | fstream::out | fstream::app);
	OutFile << What + "\n";
	OutFile.close();
}
string HelperFunctions::ReadFromFile(string LeftSide){return HelperFunctions::ReadFromFile(LeftSide, DefaultFile);}
string HelperFunctions::ReadFromFile(string LeftSide, string FilePath){
	string CurrentLine;
	int SplitLength = LeftSide.length();
	ifstream CurrentFile (FilePath);
	if (CurrentFile.is_open()){
		while (CurrentFile.good()){
			getline (CurrentFile,CurrentLine);
			string Right = CurrentLine.substr(SplitLength+1,string::npos);
			string Left = CurrentLine.substr(0, SplitLength);
			if (Left == LeftSide){return Right;}
		}
		CurrentFile.close();
	}
	else cout << "The file could not be opened"; 
}
bool HelperFunctions::ValidateName(string Target){
	for (string::iterator Counter = Target.begin(), End = Target.end(); Counter != End; ++Counter){
		char Short = *Counter;
		if (!isalpha(Short) & !isspace(Short)){
			return false;
		}
	}
	return true;
}
bool HelperFunctions::ValidatePay(string Target){
		for (string::iterator Counter = Target.begin(), End = Target.end(); Counter != End; ++Counter){
		char Short = *Counter;
		if (!isdigit(Short)){
			return false;
		}
	}
	return true;
}
string HelperFunctions::PadString(string Target){return HelperFunctions::PadString(Target, DefaultWidth);}
string HelperFunctions::PadString(string Target, int Width){
	if (Target.length() >= Width) {
		 //Possible truncation?
	} else {
		int AddLength = Width - Target.length();
		for (int Counter = 0; Counter <= AddLength; Counter++){
			Target += " ";
		}
	}
	return Target;
}
void HelperFunctions::DrawSeperator(string Sides, string Middle){HelperFunctions::DrawSeperator(Sides,Middle,DefaultWidth);}
void HelperFunctions::DrawSeperator(string Sides, string Middle, int Width){
	cout << Sides;
	for (int Counter = 0; Counter <= (Width - 1); Counter++){
		cout << Middle;
	}
	cout << Sides;
}
void HelperFunctions::DrawVisualPayBar(int* ValuesToUse){HelperFunctions::DrawVisualPayBar(ValuesToUse, DefaultWidth);}
void HelperFunctions::DrawVisualPayBar(int* ValuesToUse, int Width){
	double AdjustedValues[3];
	double Total = 0;
	for (int Counter = 0; Counter <= 2; Counter++){Total += ValuesToUse[Counter];}
	for (int Counter = 0; Counter <= 2; Counter++){
		double Value = (double)ValuesToUse[Counter];
		AdjustedValues[Counter] = ((Value / Total) * (double)DefaultWidth);
		cout << "|";
		for (int InnerCounter = 0; InnerCounter <= (AdjustedValues[Counter] - 2); InnerCounter++){
			cout << "*";
		}
		cout << "|";
	}
	cout << endl;
}
string HelperFunctions::ConvertCharArrayToString(char* Target){
	return string(Target);
}
void ConvertStringToCharArray(string In, char* Target){
	for (int Counter = 0; Counter < In.size(); Counter++){
		Target[Counter] = In[Counter];
	}
}

static class WorkForcePay{
public:
	WorkForcePay(){
		NumberOfEmployees = 0;
		Total = 0;
		Senior = 0;
		Ordinary = 0;
		Contractor = 0;
		DefaultSalaried = 0;
		DefaultHourly = 0;
		DefaultPayIncrease = 0;
	}
	static double Total, Senior, Ordinary, Contractor, DefaultSalaried, DefaultHourly, DefaultPayIncrease, NumberOfEmployees;
	void CalculateTotalPays(Employee PayArray[]);
};

void WorkForcePay::CalculateTotalPays(Employee PayArray[]){
	for (int Counter = 0; Counter <= NumberOfEmployees; Counter++){
		PayArray[Counter].CalculatePay();
	}
	Total = Senior + Ordinary + Contractor;
}

int main ()
{
	system("pause");
	return 0;
}