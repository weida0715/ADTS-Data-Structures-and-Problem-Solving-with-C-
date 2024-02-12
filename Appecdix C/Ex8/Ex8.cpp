/*
    A modification of the program in Ex7 for computing wages for
    several employees. Permanent employee information is read from a file.

    Input (file)    : Id-number, number of dependents, and hourly rate
                        for each of several employees
    Input (keyboard): Hours worked by employees
    Output (screen) : Prompts to user, including id-numbers.
    Output (file)   : Id-numbers, hours worked, gross pay, taxes withheld
                        and net pay
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

void instruct();
void getEmployeeInfo(ifstream &in, int &empNumber, int &dependents,
                     double &hours, double &rate, bool &done);
double grossWages(int dependents, double hours, double rate);
void computeNetPay(double grossPay, int dependents,
                   double &tax, double &netPay);
void printEmpInfo(ofstream &out, int idNumber, double hours,
                  double grossPay, double taxes, double netPay);

int main()
{
    string inFilename, outFilename;

    cout << "Enter names of input and output files: ";
    cin >> inFilename >> outFilename;
    ifstream inStream(inFilename.data());
    ofstream outStream(outFilename.data());

    int idNumber,       // employee's id-number
        numDependents;  // number of dependents
    double hoursWorked, // hours worked for this pay period
        hourlyRate,     // dollars per hour
        grossPay,       // gross pay (before taxes)
        taxWithheld,    // amount of tax withheld
        netPay;         // grossPay - taxWithheld
    bool endOfData;     // signals end of data

    instruct();
    for (;;)
    {
        getEmployeeInfo(inStream, idNumber, numDependents,
                        hoursWorked, hourlyRate, endOfData);
        if (endOfData)
            break;
        grossPay = grossWages(numDependents, hoursWorked, hourlyRate);
        computeNetPay(grossPay, numDependents, taxWithheld, netPay);

        printEmpInfo(outStream, idNumber, hoursWorked, grossPay,
                     taxWithheld, netPay);
    }
}

void instruct()
/*
    Display instructions to the user.
    Output: Instructions
*/
{
    cout << "This program computes gross pay, tax withheld, and net pay for"
            "employees.\n\tWhen prompted, enter hours worked and hourly rate"
            "\n\t(separated by spaces) for the indicated employee.\n\n";
}

void getEmployeeInfo(ifstream &in, int &empNumber, int &dependents,
                     double &hours, double &rate, bool &done)
/*
    Get employee information and/or signal there is no more.

    Receive         : ifstream
    Input (file)    : Id-number, number of dependents, and hourly rate
    Input (keyboard): Hours worked by employee
    Output (screen) : Prompts to user, including id-number
    Pass back:      : Modified ifstream, the four input values, done is
                        true if end of data was signaled, false otherwise
*/
{
    in >> empNumber; // get employee number from file
    done = in.eof();
    if (done)
        return;               // if end of file, return
                              // else
    in >> dependents >> rate; // get other info from file
    cout << "Enter hours worked by " << empNumber << ": ";
    cin >> hours; // get hours worked from user
}

double grossWages(int dependents, double hours, double rate)
/*
    Compute gross wages as determined by number of hours employee worked
    plus a dependency allowance for each dependent.
    Receive: Number of dependents, hours worked, hourly rate
    Return: Gross wages
*/
{
    const double DEP_ALLOWANCE = 100; // bonus per dependent
    double wages;                     // wages earned
    if (hours <= 40)                  // no overtime
        wages = hours * rate;
    else
        wages = 40 * rate + 1.5 * rate * (hours - 40);

    // return wages + allowance for deps
    return wages + DEP_ALLOWANCE * dependents;
}

void computeNetPay(double grossPay, int dependents,
                   double &tax, double &netPay)
/*
    Compute taxes withheld and net pay as gross pay minus taxes withheld.
    Receive: Gross pay and number of dependents
    Return: Taxes withheld and net pay (via parameters)
*/
{
    const double
        DEDUCTION = 25.00, // deduction per dependent
        TAX_RATE = 0.12;   // withholding rate
    tax = TAX_RATE * (grossPay - DEDUCTION * dependents);

    if (tax < 0) // check if any tax to be withheld
        tax = 0;

    netPay = grossPay - tax; // compute net pay
}

void printEmpInfo(ofstream &out, int idNumber, double hours,
                  double grossPay, double taxes, double netPay)
/*
    Write employee information to a file.
    Receive     : ofstream, employee's id number, hours worked, gross pay,
                    taxes withheld, and net pay
    Pass back   : the modified ofstream
*/
{
    out << setprecision(2) << setiosflags(ios::showpoint | ios::fixed)
        << "Employee " << idNumber << ":\n"
        << "\tHours worked:     " << setw(6) << hours << endl
        << "\tGross Pay:       $" << setw(6) << grossPay << endl
        << "\tTaxes withheld:  $" << setw(6) << taxes << endl
        << "\tNet Pay:         $" << setw(6) << netPay << endl;
}
