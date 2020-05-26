#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include "Zadanie.h"

void Wczytaj(std::string fileName, std::array<Zadanie, 1000> &tab, int &n);

void Wyswietl(Zadanie tab[], int n);