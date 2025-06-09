#ifndef SUPERREG_H
#define SUPERREG_H


#include "Reg.h"
#include <vector>
#include <map>

class SuperReg {
private:
	std::vector<Reg> arr;
	int size;
public:
	SuperReg(int size_in = 1000, int size_p = 1) : size(size_p) { arr.push_back(Reg(size_in)); };
	Reg& operator[](int n) { return arr[n]; };
	int getSize() { return size; };
	void gate_X(int);
	void gate_Y(int);
	void gate_Z(int);
	void gate_H(int);
	void gate_C(std::vector<int>, std::map<int, void(Qbit::*)()>);
	std::string to_string();
	void clean();

};


#endif // SUPERREG_H