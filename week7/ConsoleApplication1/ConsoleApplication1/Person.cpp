#include "Person.h"
#include <iostream>
using namespace std;

Person::Person(int ppsn, int age, string name, bool vaccinated)
    : ppsn(ppsn), age(age), name(name), vaccinated(vaccinated)
{}

int Person::getAge() const {
    return age;
}

void Person::VaccinationStatus() const {
    string status;
    if (vaccinated == true) {
        status = "True";
    }
    else {
        status = "False";
    }

    cout << name << ", " << age << " years old, vaccination status: " << status << endl;

    
}

void Person::setVaccinated(bool vaccinatedin) {
    vaccinated = vaccinatedin;

}

string Person::getName() {
    return name;
}

bool Person::operator()(const Person* p1, const Person* p2)
{
    return p1->age > p2->age;
}

Child::Child(int ppsn, int age, string name, string school, bool vaccinated)
    : Person(ppsn, age, name, vaccinated), school(school)
{}

void Child::VaccinationStatus(){
    string status;
    if (vaccinated == true) {
        status = "True";
    }
    else {
        status = "False";
    }
    cout << name << ", " << age << " years old, student at " << school << ", vaccination status: " << status << endl;
}

Adult::Adult(int ppsn, int age, string name, string job, bool vaccinated)
    : Person(ppsn, age, name, vaccinated), job(job)
{}

void Adult::VaccinationStatus(){
    string status;
    if (vaccinated == true) {
        status = "True";
    }
    else {
        status = "False";
    }
    cout << name << ", " << age << " years old, works as " << job << ", vaccination status: " << status << endl;
}

Oap::Oap(int ppsn, int age, string name, bool retired, bool vaccinated)
    : Person(ppsn, age, name, vaccinated), retired(retired)
{}

void Oap::VaccinationStatus() {
    string status;
    if (vaccinated == true){
        status = "True";
    }
    else {
        status = "False";
    }
    cout << name << ", " << age << " years old, " << (retired ? "retired" : "still working") << ", vaccination status: " << status << endl;
}