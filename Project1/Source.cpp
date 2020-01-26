#include <iostream>
#include "tarif.h"
#include "bezlim.h"
#include <string>
#include <vector>
#include <fstream>
#include <windows.h>


int main() {
	//��� �������
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
	//������ ���� 
	bez.setcost(std::stod(b, &sz));
	bez.setwait(std::stod(b.substr(sz)));
	sz = NULL;

	b = {};
	std::cout << "�������� �����: ������������� - " << bez.getcost() << "���/��� �������� - " << bez.getwait() << "���/���" << std::endl;
	
	//������ ������ ������

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
		std::cout << "����� �� " << tar.getname() << " ����(��), ��������� - " << tar.getcost() << "���/���, ���������� ������ - " << tar.getprob() << "���/���, ���������� - " << tar.getovercost() << "���/���" << std::endl;
	}
	double alltime = 0;
	double allkm = 0;
	double allprost = 0;


	std::cout << "����� ���� �������" << std::endl;
	for (int end = 0; end == 0;) {
		int a = 0;
		std::cout << "��� �� ������ 1 - �����, 2 - ����� ��������. 3 - ��������� �������" << std::endl;
		std::cin >> a;
		if (a == 1) {
			double km,time;
			double min;
			double hour;
			std::cout << "������� �����(� ����� � �������) � ����������(� ��), ������(3� 40��� 100��): 3 40 100" << std::endl;
			std::cin >> hour>>min >> km;
			time = (hour * 60) + min;
			alltime += time;
			allkm += km;
		}
		if (a == 2) {
			double prost;
			double min;
			double hour;
			std::cout << "������� ����� ��������(���� � ������, ������ 2 20 (2 ����, 20 �����))" << std::endl;
			std::cin >> hour >> min;
			prost = (hour * 60) + min;
			allprost += prost;
		}
		if (a == 3) {
			end = 1;
		}

	}

	std::cout << "��������� ��������� ������ - " << bez.pay(allkm, allprost) <<" ���"<< std::endl;
	for (auto i : tarifs) {
		if ((i.getname())<((alltime+allprost)/60)) {
			std::cout << "����� �� " << i.getname() << " ����(�����)� �� ��������(������� ����� ����� ������������� ����������)" << std::endl;
		}
		else {
			std::cout << "��������� ������ �� " << i.getname() << " ����� ����� "<<i.pay(allkm,alltime,allprost)<<" ���" << std::endl;

		}


	}
}

