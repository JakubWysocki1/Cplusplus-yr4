#include "Person.h"
#include <vector>
#include <queue>
#include <random>
#include <iostream>
using namespace std;

int main() {

	vector<Person*> population;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> age_dist(1, 100);


	for (int i = 0; i < 40; ++i) {
		int age = age_dist(gen);
		if (age < 18) {
			population.push_back(new Child(i, age, "Child", "School", false));
		}
		else if (age < 65) {
			population.push_back(new Adult(i, age, "Adult", "Job", false));
		}
		else {
			population.push_back(new Oap(i, age, "Oap", true, false));
		};
	};

	
	priority_queue<Person*, vector<Person*>, PersonCompare > vaccination_queue;


	for (Person* p : population) {
		vaccination_queue.push(p);
	}

	int appointment_num = 1;
	while (!vaccination_queue.empty()) {
		Person* p = vaccination_queue.top();
		p->VaccinationStatus();
		cout << "Vaccination appointment #" << appointment_num << " for " << p->getName() << std::endl;
		vaccination_queue.pop();
		++appointment_num;
		cout << endl;
	}

	for (Person* p : population) {
		delete p;
	}

	return 0;
}