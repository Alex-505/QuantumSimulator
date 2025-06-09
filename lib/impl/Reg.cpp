#include "Reg.h"

Reg Reg::dublicate(int num)
{
	Reg ans = *this;
	ans.multAmp(ans[num].Getamp()[1]);
	ans[num].setAmp(std::complex<double>(0), std::complex<double>(1));
	multAmp(qbit[num].Getamp()[0]);
	qbit[num].setAmp(std::complex<double>(1), std::complex<double>(0));
	return ans;
}

std::string Reg::to_string()
{
	std::string ans("");
	ans += "|";
	for (int i = 0; i < size; i++) {
		ans += qbit[i].to_string_1();
	}
	ans += ">";
	return ans;
}