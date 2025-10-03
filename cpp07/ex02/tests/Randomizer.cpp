#include "Randomizer.hpp"

int Randomizer::getRandom(int min, int max) {
	static bool isInit = false;
	if (!isInit) {
		srand(static_cast<unsigned>(time(NULL)));
		isInit = true;
	}
	return min + rand() % (max - min);
}

int Randomizer::randomInt() {
	return getRandom(MIN, MAX);
}

std::string Randomizer::randomString() {
	std::string str;
	int len = getRandom(3, 8);
	for (int i = 0; i < len; ++i)
		str += 'a' + getRandom(0, 26);
	return str;
}

Point Randomizer::randomPoint() {
	return Point(getRandom(-50, 50), getRandom(-50, 50));
}
