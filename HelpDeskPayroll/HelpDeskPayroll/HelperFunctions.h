#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const string DefaultFile = "PayDetails.txt";
const int DefaultWidth = 70; 
const int Array_Size = 100;

int HelperFunctions::GetEmployees(){
	int EnteredEmployees = 0;

	char Temp[Array_Size];
	int OrdinaryStaffCount = 0;
	cout << PadString("How many ordinary staff do you have?", 40);
	cin >> Temp;
	OrdinaryStaffCount = atoi(Temp);
	for (int Counter = 0; Counter<OrdinaryStaffCount; Counter++){
		WorkForcePay::PayArray[Counter] = new OrdinaryStaff();
		WorkForcePay::PayArray[Counter]->GetName();
		WorkForcePay::PayArray[Counter]->GetPay();
	}

	HelperFunctions::DrawSeperator("#","~");

	char Temp2[Array_Size];
	int SeniorStaffCount = 0;
	cout << PadString("How many senior staff do you have?", 40);
	cin >> Temp2;
	SeniorStaffCount = atoi(Temp2);
	for (int Counter = OrdinaryStaffCount; Counter<(OrdinaryStaffCount + SeniorStaffCount); Counter++){
		WorkForcePay::PayArray[Counter] = new SeniorStaff();
		WorkForcePay::PayArray[Counter]->GetName();
		WorkForcePay::PayArray[Counter]->GetPay();
	}

	HelperFunctions::DrawSeperator("#","~");

	char Temp3[Array_Size];
	int ContractedStaffCount = 0;
	cout << PadString("How many contracted staff do you have?", 40);
	cin >> Temp3;
	ContractedStaffCount = atoi(Temp3);
	for (int Counter = (OrdinaryStaffCount + SeniorStaffCount); Counter<(OrdinaryStaffCount + SeniorStaffCount + ContractedStaffCount); Counter++){
		WorkForcePay::PayArray[Counter] = new Contractor();
		WorkForcePay::PayArray[Counter]->GetName();
		WorkForcePay::PayArray[Counter]->GetPay();
	}

	HelperFunctions::DrawSeperator("#","~");

	WorkForcePay::NumberOfEmployees = ContractedStaffCount + SeniorStaffCount + OrdinaryStaffCount;
	return 0;
}
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
		if (!isdigit(Short) & Short != '.'){
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
	cout << endl;
	cout << Sides;
	for (int Counter = 0; Counter <= (Width - 1); Counter++){
		cout << Middle;
	}
	cout << Sides;
	cout << endl << endl;
}
void HelperFunctions::DrawVisualPayBar(int* ValuesToUse,string* Legend){HelperFunctions::DrawVisualPayBar(ValuesToUse, Legend, DefaultWidth);}
void HelperFunctions::DrawVisualPayBar(int* ValuesToUse,string* Legend, int Width){
	cout << "Visual Representation of Pay" << endl;
	cout << "Key:" << endl << "--------" << endl << endl;
	for (int Counter = 0; Counter <= 2; Counter++){
		cout << Counter << " | " << Legend[Counter] << endl;
	}
	cout << "--------" << endl << endl;

	double AdjustedValues[3];
	double Total = 0;
	for (int Counter = 0; Counter <= 2; Counter++){Total += ValuesToUse[Counter];}
		for (int Counter = 0; Counter <= 2; Counter++){
		double Value = (double)ValuesToUse[Counter];
		AdjustedValues[Counter] = ((Value / Total) * (double)DefaultWidth);
		int Padding = AdjustedValues[Counter];
		cout << Counter << ">" << PadString(" ", Padding-2);
	}
		cout << endl;
	for (int Counter = 0; Counter <= 2; Counter++){
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
void HelperFunctions::ConvertStringToCharArray(string In, char* Target){
	for (int Counter = 0; Counter < In.size(); Counter++){
		Target[Counter] = In[Counter];
	}
}