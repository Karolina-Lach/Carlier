#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#include <array>
#include <queue> 
#include "Zadanie.h"
#include "Wczytaj.h"

int Schrage(std::array<Zadanie, 1000> &tab, int n);

int prmtSchrage(std::array<Zadanie, 1000> &tab, int n);

struct LessThanByR
{
	bool operator()(Zadanie& a, Zadanie& b)
	{
		return a.r > b.r;
	}
};

struct GreaterThanByQ
{
	bool operator()(Zadanie& a, Zadanie& b)
	{
		return a.q < b.q;
	}
};