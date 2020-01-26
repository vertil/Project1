#include <iostream>
#include "tarif.h"
#include "bezlim.h"
#include <string>
#include <vector>
#include <fstream>
#include <windows.h>


int main() {
	//вкл русский
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char name[10];
	std::string b;
	std::string::size_type sz;
	bezlim bez;
	std::vector<tarif> tarifs;
	//tarifs.resize(10);
	//
	std::fstream fil;
	fil.open("Text.txt", std::fstream::in);
	fil.getline(name, 10);
	b = std::string(name);
	//парсим файл 
	bez.setcost(std::stod(b, &sz));
	bez.setwait(std::stod(b.substr(sz)));
	sz = NULL;

	b = {};
	std::cout << "МИНУТНЫЙ ТАРИФ: Использование - " << bez.getcost() << "руб/мин ожидание - " << bez.getwait() << "руб/мин" << std::endl;
	
	//парсим часвые тарифы

	for (int i = 0; i < 5; i++) {

		char nam[30];
		fil.getline(nam, 30);
		b = std::string(nam);
		tarif tar;

		tar.setname(std::stod(b, &sz));
		tar.setcost(std::stod(b.substr(sz + 1)));
		tar.setprob(std::stod(b.substr(sz + 3)));
		tar.setovercost(0.29);
		


		tarifs.push_back(tar);
		std::cout << "Тариф на " << tar.getname() << " часа(ов), стоимость - " << tar.getcost() << "руб/мин, включенный пробег - " << tar.getprob() << "руб/мин, перепробег - " << tar.getovercost() << "руб/мин" << std::endl;
	}
	double alltime = 0;
	double allkm = 0;
	double allprost = 0;


	std::cout << "ВВЕДИ ПЛАН ПОЕЗДКИ" << std::endl;
	for (int end = 0; end == 0;) {
		int a = 0;
		std::cout << "Что вы хотите 1 - ехать, 2 - режим ожидаиня. 3 - посчитать поездку" << std::endl;
		std::cin >> a;
		if (a == 1) {
			double km,time;
			double min;
			double hour;
			std::cout << "Введите время(в часах и минутах) и расстояние(в км), пример(3ч 40мин 100км): 3 40 100" << std::endl;
			std::cin >> hour>>min >> km;
			time = (hour * 60) + min;
			alltime += time;
			allkm += km;
		}
		if (a == 2) {
			double prost;
			double min;
			double hour;
			std::cout << "Введите время ожидания(часы и минуты, пример 2 20 (2 часа, 20 минут))" << std::endl;
			std::cin >> hour >> min;
			prost = (hour * 60) + min;
			allprost += prost;
		}
		if (a == 3) {
			end = 1;
		}

	}

	std::cout << "стоимость минутного тарифа - " << bez.pay(allkm, allprost) <<" руб"<< std::endl;
	for (auto i : tarifs) {
		if ((i.getname())<((alltime+allprost)/60)) {
			std::cout << "Тариф на " << i.getname() << " часа(часов)б не подходит(большое общее время использования транспорта)" << std::endl;
		}
		else {
			std::cout << "стоимостю тарифа на " << i.getname() << " будет стоит "<<i.pay(allkm,alltime,allprost)<<" руб" << std::endl;

		}


	}
}

