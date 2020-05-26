#include "Wczytaj.h"

void Wczytaj(std::string fileName, std::array<Zadanie, 1000> &tab, int &n)
{
	std::ifstream file;
	file.open(fileName.c_str());

	if (file.is_open())
	{
		file >> n;

		for (int i = 0; i < n; i++)
		{
			file >> tab[i].r;
			file >> tab[i].p;
			file >> tab[i].q;
			tab[i].ID = i + 1;
		}
	}

	file.close();

}

void Wyswietl(Zadanie tab[], int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << tab[i].ID << "  " << tab[i].r << "  " << tab[i].p << "  " << tab[i].q << std::endl;
	}
}