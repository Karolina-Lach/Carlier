#pragma once
#include <algorithm>
#include <iostream>
#include <array>
#include "Zadanie.h"
#include "Wczytaj.h"
#include "Schrage.h"

class Carlier
{
public:
	Carlier();

	int n;
	std::array<Zadanie, 1000> PI_opt;

	int U; // wartoœæ funkcji celu Cmax
	int UB; // górne oszacowanie, upper bound
	int LB; // dolne oszacowanie, lower bound

	int find_a(int Cmax, int b, std::array<Zadanie, 1000> PI);
	int find_b(int Cmax, std::array<Zadanie, 1000> PI);
	int find_c(int a, int b, std::array<Zadanie, 1000> PI);
};

void carlier(Carlier &ob, std::array<Zadanie, 1000> tab);