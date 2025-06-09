#include "Qbit.h"


void Qbit::mult(std::complex<double> a11, std::complex<double> a12, std::complex<double> a21, std::complex<double> a22) {
	std::complex<double> amp_n[2] = { amp[0] * a11 + amp[1] * a12,  amp[0] * a21 + amp[1] * a22 };
	amp[0] = amp_n[0];
	amp[1] = amp_n[1];
};

std::string Qbit::to_string() {
	std::string ans("");	
	ans += ((amp[0].imag() * amp[0].real() != 0) ? ("(" + std::to_string(amp[0].real()) + std::string(" + i") + std::to_string(amp[0].imag()) + std::string("|0>")) : ((amp[0].imag() != 0) ? (std::string("i") + std::to_string(amp[0].imag()) + std::string("|0>")) : ((amp[0].real() != 0) ? (std::to_string(amp[0].real()) + std::string("|0>")) : "")));
	ans += (abs(amp[0]) * abs(amp[1]) != 0) ? " + " : "";
	ans += ((amp[1].imag() * amp[1].real() != 0) ? ("(" + std::to_string(amp[1].real()) + std::string(" + i") + std::to_string(amp[1].imag()) + std::string("|1>")) : ((amp[1].imag() != 0) ? (std::string("i") + std::to_string(amp[1].imag()) + std::string("|1>")) : ((amp[1].real() != 0) ? (std::to_string(amp[1].real()) + std::string("|1>")) : "")));
	return ans;
}

std::string complex_to_string(std::complex<double> num) {
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

std::string Qbit::to_string_1()
{
	std::string ans("");
	if (abs(amp[1]) == 1) ans = "1";
	else if (abs(amp[1]) == 0) ans = "0";
	else ans += ">(" + complex_to_string(amp[0]) + " * |0> + " + complex_to_string(amp[1]) + " * |1>)|";
	return ans;
}