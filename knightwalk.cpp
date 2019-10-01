/* knightwalk.cpp - knight walk simulation
학번:
이름:
github id:
*/
#include "knightWalk.h"
void Chessboard::Mark(const Offsets, int n) {
//구현 필요
}
void Chessboard::SimpleMark(const Offsets) {
	//구현 필요
}
// constructor, initialize,CheckComplete, CheckBoundary, Mark, operator<<를 구현
int WalkKnight(Chessboard g, const struct Offsets startPosition);
int main(void) {
Chessboard g;
	int xStart, yStart;
	cout << endl << "시작할 위치(x, y) 입력: ";
	cin >> xStart >> yStart;
	struct Offsets startPosition;
	startPosition.a = xStart; 	startPosition.b = yStart;
	WalkKnight(g, startPosition);
	cout << endl << "Work path::" << endl;
	cout << g;
	MarkNth(g, startPosition);
	cout << endl << "Mark nth visiting path::" << endl;
	cout << g;
	system("pause");
	return 1;
}
int WalkKnight(Chessboard g, const struct Offsets startPosition) {
	//start from position
	directions knightMove;;//knight number
	struct Offsets currentPosition;
	currentPosition = startPosition;
	g.SimpleMark(currentPosition);
	while (!g.CheckComplete()) {
		knightMove = (directions)(8.0 * rand());
		struct Offsets newPosition;
		newPosition.a = currentPosition.a + Move[knightMove].a;
		newPosition.b = currentPosition.b + Move[knightMove].b;
		if (!g.CheckBoundary(newPosition)) continue;
		else {
			g.SimpleMark(newPosition);
			currentPosition = newPosition;
		}
	}
	cout << g;
}
void MarkNth(Chessboard g, const struct Offsets startPosition) {
	Stack knightStack;
	directions knightMove;;//knight number
	int nthLevel = 0;//1차 이동, 2차 이동을 표시하는 level
	struct Offsets currentPosition;
	currentPosition = startPosition;
	knightStack.Push(currentPosition);
	g.Mark(currentPosition, nthLevel++);
	while (!g.CheckComplete()) {
		currentPosition = knightStack.Pop();
		knightMove = (directions)(8.0 * rand());
		struct Offsets newPosition;
		newPosition.a = currentPosition.a + Move[knightMove].a;
		newPosition.b = currentPosition.b + Move[knightMove].b;
		if (!g.CheckBoundary(newPosition)) continue;
		else {
			g.Mark(newPosition, nthLevel);
			currentPosition = newPosition;
			nthLevel++;
		}
	}
	cout << g;
}