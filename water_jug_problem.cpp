#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd (b, a % b);
}

int pour (int fromJug, int toJug, int d) {
	int from = fromJug;
	int to = 0;
	int step = 1; // Needed to fill "from" Jug

	while (from != d && to != d) {
		int temp = min (from, toJug - to);

		// Pour "temp" litres from "from" to "to"
		to += temp;
		from -= temp;
		step++;

		if (from == d || to == d)
			break;

		// If first jug becomes empty, fill it
		if (from == 0) {
			from = fromJug;
			step++;
		}

		// If second jug becomes full, empty it
		if (to == toJug) {
			to = 0;
			step++;
		}
	}
	return step;
}

int minSteps(int jug1, int jug2, int d) {
	if (jug1 > jug2)
		swap (jug1, jug2);

	if (d > jug2)
		return -1;

	if ((d % gcd(jug1, jug2)) != 0)
		return -1;

	// Return minimum two cases:
	// a) Water of jug2 is poured into jug1
	// b) Vice versa of "a"
	return min (pour (jug2, jug1, d), pour (jug1, jug2, d));
}

int main() {
	int jug1 = 3;
	int jug2 = 5;
	int d = 4;
	cout << "Steps = " << minSteps(jug1, jug2, d) << endl;

	return 0;
}
