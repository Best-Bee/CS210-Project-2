/********************************************************
/
/   Author: Bee
/   Date: 2/11/2024
/   Program: Investment Calculator
/
/   Purpose: Output reports of interest in a bank
/            account based on inputs of the initial
/            amount, monthly deposit, interest rate, and
/            year amount.
/
********************************************************/

#include <iostream>
#include "InvestmentCalculator.h"

using namespace std;

int main() {
    //init vars
    double initialInvestmentAmount, monthlyDeposit, annualInterestRate;
    int numberOfYears;

    //user prompts with validation
    try {
        cout << "Enter Initial Investment Amount: $";
        cin >> initialInvestmentAmount;
        if (initialInvestmentAmount <= 0) {
            throw invalid_argument("Initial Investment Amount must be greater than zero (also must be a number).");
        }

        cout << "Enter Monthly Deposit: $";
        cin >> monthlyDeposit;
        if (monthlyDeposit < 0) {
            throw invalid_argument("Monthly Deposit cannot be negative (also must be a number).");
        }

        cout << "Enter Annual Interest Rate (%): ";
        cin >> annualInterestRate;
        if (annualInterestRate < 0) {
            throw invalid_argument("Annual Interest Rate cannot be negative (also must be a number).");
        }

        cout << "Enter Number of Years: ";
        cin >> numberOfYears;
        if (numberOfYears <= 0) {
            throw invalid_argument("Number of Years must be greater than zero (also must be a number).");
        }
    //yoink any additional errors
    } catch (const invalid_argument& e) {
        cout << "Invalid input: " << e.what() << endl;
        return 1;
    }

    //object creation
    InvestmentCalculator calculator(initialInvestmentAmount, monthlyDeposit, annualInterestRate, numberOfYears);

    //reports
    calculator.showYearEndReportWithoutDeposits();
    calculator.showYearEndReportWithMonthlyDeposits();

    //EXIT
    return 0;
}