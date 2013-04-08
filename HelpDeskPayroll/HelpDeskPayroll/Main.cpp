/*
* Program Title:		Tech Genius Helpdesk Payroll
* Program Authors:		Daniel Fay, Alexander Jones
* Program Description:	Calculates the pay details for different helpdesk employees	
*/

#include <iostream>
#include <string>
#include <fstream>
#include "Prototypes.h"
#include "Employee.h"
#include "WorkForcePay.h"
#include "HelperFunctions.h"

using namespace std;

int main ()
{
	system("color 17");
	//----//
	HelperFunctions::GetEmployees();
	WorkForcePay::CalculateTotalPays();
	HelperFunctions::DrawSeperator("#","~");
	WorkForcePay::OutputPay();
	HelperFunctions::DrawSeperator("#","~");
	//----//
	system("pause");
	return 0;
}