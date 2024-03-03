#include "InvestmentCalculator.h"
#include <iostream>
#include <iomanip>

using namespace std;

//constructor
InvestmentCalculator::InvestmentCalculator(double initialInvestmentAmount, double monthlyDeposit, double annualInterestRate, int numberOfYears)
    : m_initialInvestmentAmount(initialInvestmentAmount),
    m_monthlyDeposit(monthlyDeposit),
    m_annualInterestRate(annualInterestRate),
    m_numberOfYears(numberOfYears) {}

//report 1
void InvestmentCalculator::showYearEndReportWithoutDeposits() {
    //init total interest (for output at the end)
    double totalInterest = 0;
    
    //start report
    cout << "Year end report without monthly deposits:" << endl;
    cout << setw(50) << setfill('-') << "-" << endl;
    cout << setfill(' ');

    //init opening amount
    double openingAmount = m_initialInvestmentAmount;

    //calculate and display each year (no monthly input so no intermediate steps necessary)
    for (int year = 1; year <= m_numberOfYears; ++year) {
        //get the interest earned that year
        double yearInterest = (openingAmount) * (m_annualInterestRate / 100);
        //get the total amount of money after the year
        double total = openingAmount + yearInterest;
        //set money to the total amount after the year
        openingAmount += yearInterest;
        //output with formatting
        cout << setw(8) << left << "Year: " << setw(2) << year;
        cout << setw(15) << left << "End Balance: $" << fixed << setprecision(2) << setw(15) << left << total;
        cout << setw(15) << left << "Interest: $" << fixed << setprecision(2) << setw(15) << left << yearInterest << endl;

        //keep track of total interest
        totalInterest += yearInterest;
    }
    //display total interest
    cout << "\nTotal Interest Earned: $" << totalInterest << "\n\n";
}

//report 2
void InvestmentCalculator::showYearEndReportWithMonthlyDeposits() {
    //init total interest (for output at the end)
    double totalInterest = 0;

    //start report
    cout << "Year end report with monthly deposits:" << endl;
    cout << setw(50) << setfill('-') << "-" << endl;
    cout << setfill(' ');

    //init opening amount
    double openingAmount = m_initialInvestmentAmount;

    //calculate and display each year
    for (int year = 1; year <= m_numberOfYears; ++year) {

        //init the interest earned that year (calculated as an accumulation of monthly interest so requires init)
        double yearInterest = 0;

        //begin loop to calculate the interest each month (interest gained changes due to monthly deposit)
        for (int month = 1; month <= 12; ++month) {
            //calculate monthly interest
            double monthlyInterest = (openingAmount + m_monthlyDeposit) * (m_annualInterestRate / 100 / 12);
            //add that month's interest to the total accumulated year's interest
            yearInterest += monthlyInterest;
            //add that month's inteest and the monthly deposit amount to the total money
            openingAmount += m_monthlyDeposit + monthlyInterest;
        }

        //output with formatting
        cout << setw(8) << left << "Year: " << setw(2) << year;
        cout << setw(15) << left << "End Balance: $" << fixed << setprecision(2) << setw(15) << left << openingAmount;
        cout << setw(15) << left << "Interest: $" << fixed << setprecision(2) << setw(15) << left << yearInterest << endl;

        //keep track of total interest
        totalInterest += yearInterest;
    }
    //display total interest
    cout << "\nTotal Interest Earned: $" << totalInterest << "\n\n";
}