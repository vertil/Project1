#include "tarif.h"

double tarif::getname(){
	return name;
}

int tarif::getcost() {
	return cost;
}

int tarif::getprob() {
	return prob;
}

double tarif::getovercost() {
	return overcost;
}
////////////////
void tarif::setname(double a) {
	this->name = a;
}

void tarif::setcost(int a) {
	this->cost = a;
}

void tarif::setprob(int a) {
	this->prob = a;
}

void tarif::setovercost(double a) {
	this->overcost = a;
}

double tarif::pay(double allkm, double alltime, double allprost){
	if (allkm <= (this->prob)) {
		return this->cost;
	}
	else {
		return this->cost + ((allkm - this->prob) * this->overcost);
	}
	
};