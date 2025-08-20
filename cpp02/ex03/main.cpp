#include <iostream>
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point );

struct Case {
	Point p;
	const char *label;
	bool expected;
};

static bool runCase(const Point &A,const Point &B,const Point &C,const Case &tc) {
	bool inside = bsp(A,B,C,tc.p);
	bool pass = (inside == tc.expected);
	std::cout << (pass ? "[OK]  " : "[ERR] ")
		<< tc.label << " -> " << (inside ? "inside" : "outside")
		<< " (expected " << (tc.expected ? "inside" : "outside") << ")\n";
	return pass;
}

int main() {
	Point A(0.f, 0.f);
	Point B(10.f, 0.f);
	Point C(0.f, 10.f);

	std::cout << "Triangle ABC: A(0,0) B(10,0) C(0,10)\n";
	// Points to test (inside points should satisfy x>0, y>0, x+y<10)
	Case tests[] = {
		{ Point(2.f, 2.f),   "P1  (2,2) inside",            true },
		{ Point(3.f, 4.f),   "P2  (3,4) inside",            true },
		{ Point(0.5f, 0.5f), "P3  (0.5,0.5) near vertex in",true },
		{ Point(4.9f, 1.f),  "P4  (4.9,1) inside",          true },
		{ Point(1.f, 4.9f),  "P5  (1,4.9) inside",          true },

		{ Point(5.f, 0.f),   "E1  (5,0) edge AB",           false },
		{ Point(0.f, 7.f),   "E2  (0,7) edge AC",           false },
		{ Point(6.f, 4.f),   "E3  (6,4) hyp (x+y=10)",      false },
		{ Point(5.f, 5.f),   "E4  (5,5) hyp (x+y=10)",      false },

		{ Point(0.f, 0.f),   "V1  (0,0) vertex A",          false },
		{ Point(10.f,0.f),   "V2  (10,0) vertex B",         false },
		{ Point(0.f,10.f),   "V3  (0,10) vertex C",         false },

		{ Point(10.f,10.f),  "O1  (10,10) far outside",     false },
		{ Point(5.f, 5.1f),  "O2  (5,5.1) just outside",    false },
		{ Point(-0.1f,0.1f), "O3  (-0.1,0.1) outside left", false },
		{ Point(2.f,-0.01f), "O4  (2,-0.01) below base",    false },
	};

	// Additional triangle
	Point A2(-5.f, -1.f), B2(2.f, 3.f), C2(4.f, -2.f);
	Case tests2[] = {
		{ Point(1.f, 0.f),   "T2 P1 (1,0) inside",          true },
		{ Point(-2.f, 0.f),  "T2 P2 (-2,0) inside",         true },
		{ Point(3.5f,-1.5f), "T2 P3 (3.5,-1.5) inside",     true },
		{ Point(4.f, -2.f),  "T2 V  (4,-2) vertex",         false },
		{ Point(0.f, 1.6f),  "T2 O1 (0,1.6) outside",       false },
		{ Point(-6.f,-2.f),  "T2 O2 (-6,-2) outside",       false }
	};

	size_t passCount = 0;
	size_t total = sizeof(tests)/sizeof(tests[0]);

	std::cout << "\n=== Triangle ABC tests ===\n";
	for (size_t i=0;i<total;++i)
		if (runCase(A,B,C,tests[i])) ++passCount;

	std::cout << "\nTriangle A2B2C2: A2(-5,-1) B2(2,3) C2(4,-2)\n";
	std::cout << "=== Triangle A2B2C2 tests ===\n";
	size_t total2 = sizeof(tests2)/sizeof(tests2[0]);
	for (size_t i=0;i<total2;++i)
		if (runCase(A2,B2,C2,tests2[i])) ++passCount;

	std::cout << "\nSummary: " << passCount << "/" << (total + total2) << " passed.\n";
	return (0);
}
