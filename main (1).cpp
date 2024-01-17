#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <numeric> 
using namespace std;
vector<int> generateCommissions() {
    vector<int> commissions;
    for (int i = 0; i < 12; ++i) {
        commissions.push_back(rand() % (5000 - 1000 + 1) + 1000);
    }
    return commissions;
}
int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    vector<pair<string, vector<int>>> employeesData;
    for (int i = 1; i <= 100; ++i) {
        string employeeName = "Employee" + to_string(i);
        employeesData.push_back(make_pair(employeeName, generateCommissions()));
    }
    vector<pair<string, double>> averageCommissions;
    for (const auto& employee : employeesData) {
        const auto& commissions = employee.second;
        double average = accumulate(commissions.begin(), commissions.end(), 0.0) / commissions.size();
        averageCommissions.push_back(make_pair(employee.first, average));
    }
    sort(averageCommissions.begin(), averageCommissions.end(),
              [](const auto& a, const auto& b) { return a.second > b.second; });
    cout << "Top 5 Employees with the Highest Average Commission:\n";
    for (int i = 0; i < 5; ++i) {
        cout << fixed <<setprecision(2)
                  << i + 1 << ". " << averageCommissions[i].first << ": $" << averageCommissions[i].second << "\n";
    }
    return 0;
}
