#pragma once
class bezlim
{
private:
	double cost = 0.0;
	double wait = 0.0;
public:
	double getcost();
	double getwait();
	void setcost(double a);
	void setwait(double a);
	double pay(double allkm, double allprost);
};

