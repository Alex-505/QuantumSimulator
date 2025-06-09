#ifndef QBIT_H
#define QBIT_H

#include <complex>
#include <string>

class Qbit {
private:
	int num;
	std::complex<double> amp[2] = { std::complex<double>(1), std::complex<double>(0) };
public:
	Qbit(int num_p) :num(num_p) {};
	Qbit(std::complex<double>* amp_p) { amp[0] = amp_p[0]; amp[1] = amp_p[1]; };
	std::complex<double>* Getamp() { return amp; };
	void mult(std::complex<double> a11, std::complex<double> a12, std::complex<double> a21, std::complex<double> a22);
	void X() { mult(0, 1, 1, 0); };
	void Y() { mult(0, std::complex<double>(0, -1), std::complex<double>(0, 1), 0); };
	void Z() { mult(1, 0, 0, -1); };
	void H() { mult(1 / sqrt(2), 1 / sqrt(2), 1 / sqrt(2), -1 / sqrt(2)); };
	std::string to_string();
	std::string to_string_1();
	void setAmp(std::complex<double> amp_0, std::complex<double> amp_1) { amp[0] = amp_0; amp[1] = amp_1; };
};


#endif // QBIT_H