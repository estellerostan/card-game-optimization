#pragma once

#include <cmath>
#include <ostream>

struct Card
{
	int Cost;
	int ATK;
	int DEF;
	bool hasTaunt;
	bool hasTrample;
	bool hasDistortion;
	bool hasFirstStrike;

	Card(int atk, int def) {
		ATK = atk;
		DEF = def;
		Cost = std::ceil((ATK + DEF) / 2.f);
	}

	Card(int atk, int def, bool taunt, bool trample, bool distortion, bool firstStrike) {
		ATK = atk;
		DEF = def;

		hasTaunt = taunt;
		hasTrample = trample;
		hasDistortion = distortion;
		hasFirstStrike = firstStrike;

		Cost = std::ceil(((ATK + DEF) / 2.f)
			+ (hasTaunt ? 1.5 : 0)
			+ (hasTrample ? 1 : 0)
			+ (hasDistortion ? 1 : 0)
			+ (hasFirstStrike ? 1 : 0));
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