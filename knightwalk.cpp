/* knightwalk.cpp - knight walk simulation
학번:
이름:
github id:
*/
#include "knightwalk.h"
void Chessboard::Mark(const Offsets) {

}
int main(void) {
	Chessboard g(8, 8);
	struct Offsets startPosition;
	Walk(g, startPosition);
}
void Walk(Chessboard g, const struct Offsets startPosition) {
	
Stack knightStack;
knightStack.Push(startPosition);
	//start from position
	directions knightMove;;//knight number
	struct Offsets currentPosition;
	g.Mark(currentPosition);
	while (!g.CheckComplete()) {
		currentPosition = knightStack.Pop();
		knightMove = (directions)(8.0 * rand());
		struct Offsets newPosition;
		newPosition.a = currentPosition.a + Move[knightMove].a;
		newPosition.b = currentPosition.b + Move[knightMove].b;
		if (!g.CheckBoundary(newPosition)) continue;
		else
			g.Mark(newPosition);
		currentPosition = newPosition;
	}
	cout << g;
}