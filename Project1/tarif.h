#pragma once
#include <string>

class tarif {
private:
	double name;
	int cost = 0;
	int prob = 0;
	double overcost = 0.0;
public:
	double getname();
	int getcost();
	int getprob();
	double getovercost();

	void setname(double a );
	void setcost(int a);
	void setprob(int a);
	void setovercost(double a);

	double pay(double allkm, double alltime, double allprost);
};

