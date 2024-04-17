#pragma once

#include <cmath>
#include <ostream>

struct Card
{
	int Cost;
	int ATK;
	int DEF;

	Card(int atk, int def) {
		ATK = atk;
		DEF = def;
		Cost = std::ceil((ATK + DEF) / 2.f);
	}

	//for file debug log
	friend std::ostream& operator <<(std::ostream& r_os, Card const& r_a)
	{
		return r_os << "(" << r_a.Cost << ";" << r_a.ATK << ';' << r_a.DEF << ")";
	}
};

inline bool operator==(Card const& r_left, Card const& r_right)
{
	return r_left.ATK == r_right.ATK && r_left.DEF == r_right.DEF;
}