#pragma once

struct Zadanie
{
public:
	int r, p, q;
	int ID;
	int C, S, D;

	Zadanie()
	{
		r = 0;
		p = 0;
		q = 0;
	}

	Zadanie(int R, int P, int Q)
	{
		r = R;
		p = P;
		q = Q;
	}

	Zadanie& operator = (const Zadanie& other)
	{
		r = other.r;
		p = other.p;
		q = other.q;
		ID = other.ID;
		C = other.C;
		S = other.S;
		D = other.D;
		return *this;
	}
};

