#pragma once

class InvestmentCalculator {
private:
    double m_initialInvestmentAmount;
    double m_monthlyDeposit;
    double m_annualInterestRate;
    int m_numberOfYears;

public:
    InvestmentCalculator(double initialInvestmentAmount, double monthlyDeposit, double annualInterestRate, int numberOfYears);

    void showYearEndReportWithoutDeposits();
    void showYearEndReportWithMonthlyDeposits();
};