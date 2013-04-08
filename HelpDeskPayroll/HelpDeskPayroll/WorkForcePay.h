#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void WorkForcePay::CalculateTotalPays(){
	for (int Counter = 0; Counter < NumberOfEmployees; Counter++){
		WorkForcePay::PayArray[Counter]->CalculatePay();
		switch (WorkForcePay::PayArray[Counter]->Position)
		{
		case Contracted:
			ContractorPay += WorkForcePay::PayArray[Counter]->PayAmount;
			break;
		case EmployeeTypes::Ordinary:
			OrdinaryPay += WorkForcePay::PayArray[Counter]->PayAmount;
			break;
		case EmployeeTypes::Senior:
			SeniorPay += WorkForcePay::PayArray[Counter]->PayAmount;
			break;
		default:
			break;
		}
	}
	TotalPay = SeniorPay + OrdinaryPay + ContractorPay;
}
void WorkForcePay::OutputPay(){
	/*for (int Counter = 0; Counter < WorkForcePay::NumberOfEmployees; Counter++){
		cout << WorkForcePay::PayArray[Counter]->Name << " was paid " << (char)156 << WorkForcePay::PayArray[Counter]->PayAmount << endl;
	}*/

	cout << "Total Workforce Payments" << endl << endl;
	cout << HelperFunctions::PadString("\tStaff Total", 39) << (char)156 << OrdinaryPay << endl;
	cout << HelperFunctions::PadString("\tSenior Staff Total", 39) << (char)156 << SeniorPay << endl;
	cout << HelperFunctions::PadString("\tContractor Total", 39) << (char)156 << ContractorPay << endl;
	cout << HelperFunctions::PadString("\tGrand Total", 39) << (char)156 << TotalPay << endl;
	int DrawValues[3] = {OrdinaryPay, SeniorPay, ContractorPay};
	string LegendValues[3] = {"Staff", "Senior", "Contractor"};
	HelperFunctions::DrawSeperator("#","~");
	HelperFunctions::DrawVisualPayBar(DrawValues, LegendValues);
	//HelperFunctions::DrawSeperator("#","~");
}