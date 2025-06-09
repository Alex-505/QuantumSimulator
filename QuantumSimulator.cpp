#include "QuantumSimulator.h"

int main()
{
	SuperReg rg(7, 1);
	for (int i = 0; i < rg[0].getSize() - 1; i++) rg.gate_H(i);
	std::map<int, void(Qbit::*)()> doing;
	doing[rg.getSize() - 1] = &Qbit::X;
	for (int i = 0; i < rg[0].getSize() - 2; i++) rg.gate_C({ i, i + 1 }, doing);
	for (int i = 0; i < rg[0].getSize() - 1; i++) rg.gate_H(i);
	//rg.clean();
	std::cout << rg.to_string();
	return 0;
}
