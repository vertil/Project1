#include "bezlim.h"

double bezlim::getcost() {
	return cost;
}

double bezlim::getwait() {
	return wait;
}

void bezlim::setcost(double a) {
	this->cost = a;
};

void bezlim::setwait(double a) {
	this->wait = a;
};

double bezlim::pay(double allkm, double allprost) {
	double all = 0;
	all = (allkm * cost) + (allprost * wait);
	return all;
};