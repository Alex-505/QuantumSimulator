#ifndef REG_H
#define REG_H 


#include <vector>
#include <complex>
#include "Qbit.h"

class Reg {
private:
	std::vector<Qbit> qbit;
	std::complex<double> amp = std::complex<double>(1);
	int size;
public:
	Reg(int size_p = 1) : size(size_p) { for (int i = 0; i < size; i++) qbit.push_back(Qbit(i)); };
	Qbit& operator[](int i) { return qbit[i]; };
	std::complex<double> getAmp() { return amp; };
	int getSize() { return qbit.size(); };
	void multAmp(std::complex<double> val) { amp *= val; };
	void addAmp(std::complex<double> val) { amp += val; };
	Reg dublicate(int num);
	std::string to_string();
};

#endif // !REG_H