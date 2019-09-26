/* randomwalk.cpp - random walk simulation */
#include "randomwalk.h"
void Goboard::Mark(const Offsets) {

}
int main(void) {
	Goboard g(10,10);
	struct Offsets startPosition;
	Walk(g, startPosition);
}
void Walk(Goboard g, const struct Offsets position) {
	//start from position
	directions randomMove;;//random number
	struct Offsets nextPosition;
	nextPosition = position;
	g.Mark(position);
	while (!g.CheckComplete()) {
		randomMove = (directions)(8.0 * rand());
		struct Offsets newPosition;
		newPosition.a = nextPosition.a + Move[randomMove].a;
		newPosition.b = nextPosition.b + Move[randomMove].b;
		if (!g.CheckBoundary(newPosition)) continue;
		else
			g.Mark(newPosition);
		nextPosition = newPosition;
	}
	cout << g;
}