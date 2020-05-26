#include "Carlier.h"

using namespace std;

Carlier::Carlier() : U(0), UB(INT_MAX), LB(0) {}

void carlier(Carlier &ob, array<Zadanie, 1000> PI)
{	
	// KROK 1
	ob.U = Schrage(PI, ob.n);
	cout << "U " << ob.U << endl;
	// KROK 2
	if (ob.U < ob.UB)
	{
		cout << "Nowe najlepsze rozwi¹zanie" << endl;
		ob.UB = ob.U;
		for (int i = 0; i < ob.n; i++)
		{
			ob.PI_opt[i] = PI[i];
		}
	}

	// KROK 3 Wyznaczanie bloku a, b i zadania referencyjnego c
	int b = ob.find_b(ob.U, PI);
	int a = ob.find_a(ob.U, b, PI);
	int c = ob.find_c(a, b, PI);

	// KROK 4 - je¿eli c nie istnieje to koniec
	if (c == -1)
	{
		return;
	}

	// KROK 5 
	int p_prim = 0;
	int q_prim = INT_MAX;
	int r_prim = INT_MAX;
	for (int j = (c + 1); j <= b; j++)
	{
		r_prim = min(r_prim, PI[j].r);
		p_prim += PI[j].p;
		q_prim = min(q_prim, PI[j].q);
	}

	// zapamiêtywanie starych wartoœci
	int r_old = PI[c].r;

	// KROK 6 - Przesuwanie zadania c w prawo
	PI[c].r = max(PI[c].r, r_prim + p_prim);

	// KROK 7
	ob.LB = prmtSchrage(PI, ob.n);
	cout << "LB po r: " << ob.LB << endl;

	// KROK 8
	if (ob.LB < ob.UB)
	{
		// KROK 9 
		carlier(ob, PI);
	}

	// KROK 10 - odtwarzenie wartoœci
	
	PI[c].r = r_old;
	

	// Zapamiêtywanie starej wartoœci q
	int q_old = PI[c].q;

	// KROK 11 - przesuniêcie zadania c w lewo
	PI[c].q = max(PI[c].q, q_prim + p_prim);

	// KROK 12
	ob.LB = prmtSchrage(PI, ob.n);
	cout << "LB po q: " << ob.LB << endl;

	// KROK 13
	if (ob.LB < ob.UB)
	{
		//  KROK 14
		carlier(ob, PI);
	}

	// KROK 15
	
	PI[c].q = q_old;
		
}

int Carlier::find_b(int Cmax, std::array<Zadanie, 1000> PI)
{
	int b = 0;
	int i = 0;
	for (i = n - 1; i >= 0; i--)
	{
		if (Cmax == PI[i].C + PI[i].q)
		{
			b = i;
			break;
		}
	}

	return b;
}

int Carlier::find_a(int Cmax, int b, std::array<Zadanie, 1000> PI)
{
	int suma = 0, i;
	int a = 0;
	for (a = 0; a < n; a++)
	{

		suma = 0;
		for (i = a; i <= b; i++)
		{
			suma += PI[i].p; // suma P zadañ od a do b
		}

		if (Cmax == (PI[a].r + suma + PI[b].q))
		{
			return a;
		}
	}
	return a;

}

int Carlier::find_c(int a, int b, std::array<Zadanie, 1000> PI)
{
	int c = -1;
	int i;

	for (i = b; i >= a; i--)
	{
		if (PI[i].q < PI[b].q)
		{
			c = i;
			break;
		}
	}

	return c;
}