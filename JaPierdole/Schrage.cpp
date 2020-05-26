#include "Schrage.h"

int Schrage(std::array<Zadanie, 1000> &tab, int n)
{
	std::priority_queue<Zadanie, std::vector<Zadanie>, LessThanByR> N;                // zbiór zadañ nieuszeregowanych   
	std::priority_queue<Zadanie, std::vector<Zadanie>, GreaterThanByQ> G;				// zbiór zadañ gotowych do realizacji

	for (int i = 0; i < n; i++)
	{

		N.push(tab[i]);
	}

	int t = 0;
	int k = 0;
	Zadanie e;
	int Dmax = 0;

	while (!G.empty() || !N.empty())
	{
	back:
		while (!N.empty() && N.top().r <= t)
		{
			e = N.top();
			N.pop();
			G.push(e);
		}

		if (G.empty())
		{
			t = N.top().r;
			goto back;
		}

		e = G.top();
		G.pop();

		
		tab[k] = e;

		tab[k].S = t;

		t = t + e.p;


		tab[k].C = t;
		tab[k].D = t + e.q;
		Dmax = std::max(Dmax, (t + e.q));
		k = k + 1;
	}
	return Dmax;
}

int prmtSchrage(std::array<Zadanie, 1000> &tab, int n)
{
	std::priority_queue<Zadanie, std::vector<Zadanie>, LessThanByR> N;                // zbiór zadañ nieuszeregowanych   
	std::priority_queue<Zadanie, std::vector<Zadanie>, GreaterThanByQ> G;				// zbiór zadañ gotowych do realizacji

	for (int i = 0; i < n; i++)
	{
		N.push(tab[i]);
	}

	int t = 0;
	Zadanie l(0, 0, 0);
	Zadanie e(0, 0, 0);
	int Cmax = 0;

	while (!G.empty() || !N.empty())
	{
	back:
		while (!N.empty() && N.top().r <= t)
		{
			e = N.top();
			N.pop();
			G.push(e);

			if (e.q > l.q)
			{
				l.p = t - e.r;
				t = e.r;
				if (l.p > 0)
				{
					G.push(l);
				}
			}
		}

		if (G.empty())
		{
			t = N.top().r;
			goto back;
		}

		e = G.top();
		G.pop();
		l = e;
		t = t + e.p;

		Cmax = std::max(Cmax, (t + e.q));
	}
	return Cmax;
}