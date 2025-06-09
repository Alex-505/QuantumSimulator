#include "SuperReg.h"

#include <iostream>

void SuperReg::gate_X(int n) {
	for (int i = 0; i < size; i++) {
		arr[i][n].X();
	}
}

void SuperReg::gate_Y(int n) {
	for (int i = 0; i < size; i++) {
		arr[i][n].Y();
	}
}

void SuperReg::gate_Z(int n) {
	for (int i = 0; i < size; i++) {
		arr[i][n].Z();
	}
}

void SuperReg::gate_H(int n) {
	for (int i = 0; i < size; i++) {
		arr[i][n].H();
	}
}


void SuperReg::gate_C(std::vector<int> con, std::map<int, void(Qbit::*)()> gate) {
	std::cout << "HEREWEARE" << std::endl;
	for (int i = size-1; i >= 0; i--) {
		std::vector<int> con_t;
		bool pass = true;
		for (int j = 0; j < con.size(); j++) {
			pass &= (abs(arr[i][con[j]].Getamp()[1]) > 0.00001);
			if (pass && (abs(arr[i][con[j]].Getamp()[0]) > 0.00001))
				con_t.push_back(con[j]);
		}
		if (pass) {
			Reg* nrg = &(arr[i]);
			for (int j = 0; j < con_t.size(); j++) {
				arr.push_back(nrg->dublicate(con_t[j]));
				nrg = &(arr[size]);
				size++;
			}
			for (auto j : gate) {
				((*nrg)[j.first].*j.second)();
			}

		}
	}
};

std::string complex_to_string_1(std::complex<double> num) {
	std::string ans("");
	if ((num.real() != 0) && (num.imag() != 0)) ans += "(";
	if (num.real() != 0) {
		ans += std::to_string(num.real()) + " ";
		if (num.imag() > 0)
			ans += "+ ";
	}
	if (num.imag() < 0)
		ans += "- ";
	if (num.imag() != 0)
		ans += "i*" + std::to_string(num.imag());
	if ((num.real() != 0) && (num.imag() != 0)) ans += ")";
	return ans;
}

std::string SuperReg::to_string() {
	std::string ans("");
	for (int i = 0; i < size; i++) {
		ans += complex_to_string_1(arr[i].getAmp()) + "*" + arr[i].to_string();
		if (i != size - 1) ans += " + ";
	}
	return ans;
};

void SuperReg::clean() {
	for (int i = size; i > 0 ; i--) {
		for (int j = 0; j < i; j++) {
			int count = 0;
			int num = 0;
			for (int k = 0; k < arr[0].getSize(); k++) {
				if (!((abs(arr[i][k].Getamp()[0] - arr[j][k].Getamp()[0]) < 0.00001) && (abs(arr[i][k].Getamp()[1] - arr[j][k].Getamp()[1]) < 0.00001))) {
					count++;
					num = k;
				}
			}
			if (count == 0) {
				arr[j].addAmp(arr[i].getAmp());
				arr.erase(arr.begin() + i);
			}
			if (count == 1) {
				arr[j][num].setAmp(arr[j][num].Getamp()[0] + arr[i][num].Getamp()[0] * arr[i].getAmp() / arr[j].getAmp(), arr[j][num].Getamp()[1] * arr[i].getAmp() / arr[j].getAmp());
			}
		}
	}
};