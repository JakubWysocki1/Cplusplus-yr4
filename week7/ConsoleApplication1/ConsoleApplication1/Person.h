#pragma once
#include <iostream>
using namespace std;

class Person {

public:
    Person(int ppsn, int age, string name, bool vaccinated=false);
    virtual void VaccinationStatus() const;
    int getAge() const;
    void setVaccinated(bool vaccinated);
    string getName();
    bool operator()(const Person* p1, const Person* p2);

protected:
    int ppsn;
    int age;
    string name;
    bool vaccinated;
};


class Child:public Person{

    public:
        Child(int ppsn, int age, string name, string school, bool vaccinated=false);
        void VaccinationStatus() ;

    private:
        string school;
   };


class Adult:public Person {

    public:
        Adult(int ppsn, int age, string name, string job, bool vaccinated=false);
        void VaccinationStatus();

    private:
        string job;
    
};


class Oap:public Person {
    public:
        Oap(int ppsn, int age, string name, bool retired, bool vaccinated=false);
        void VaccinationStatus();

    private:
        bool retired;
};

class PersonCompare {
public:
    bool operator()(const Person* p1, const Person* p2) {
        return p1->getAge() < p2->getAge();
    }
};
