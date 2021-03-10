#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void PrintStats(vector<Person> persons)
{
    cout << "Median age = " << ComputeMedianAge(persons.begin(), persons.end()) << endl;
    
    auto fem = partition(persons.begin(), persons.end(), [](const Person& pers) { return pers.gender == Gender::FEMALE; });
    cout << "Median age for females = " << ComputeMedianAge(persons.begin(), fem) << endl;
    cout << "Median age for males = " << ComputeMedianAge(fem, persons.end()) << endl;

    auto fem_emp = partition(persons.begin(), fem, [](const Person& pers) { return pers.is_employed; });
    cout << "Median age for employed females = " << ComputeMedianAge(persons.begin(), fem_emp) << endl;
    cout << "Median age for unemployed females = " << ComputeMedianAge(fem_emp, fem) << endl;

    auto m_emp = partition(fem, persons.end(), [](const Person& pers) { return pers.is_employed; });
    cout << "Median age for employed males = " << ComputeMedianAge(fem, m_emp) << endl;
    cout << "Median age for unemployed males = " << ComputeMedianAge(m_emp, persons.end()) << endl;

}
