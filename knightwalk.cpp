/* knightwalk.cpp - knight walk simulation
학번:
이름:
github id:
*/
#include "knightWalk.h"
#include <stdlib.h>
#include <time.h>

Chessboard::Chessboard(int row, int col) : rows(row), cols(col)
{
	Term = new int[rows * cols];
}
void Chessboard::initialize()
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			Term[i * cols + j] = 0;
	}
}
int Chessboard::CheckComplete()
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			if (Term[i * cols + j] == 0) return 0;
	}
	return 1;
}
int Chessboard::CheckBoundary(Offsets nextPosition)
{
	if ((0 <= nextPosition.a) && (nextPosition.a <= 7) && (0 <= nextPosition.b) && (nextPosition.b <= 7)) return 1;
	else return 0;
}
int Chessboard::CheckNext(Offsets nextPosition) {
	if (Term[nextPosition.a * cols + nextPosition.b] != 0)
		return 0;
	else return 1;
}
int Chessboard::CheckNextZero(Offsets nextPosition) {
	if (Term[nextPosition.a * cols + nextPosition.b] == 0)
		return 0;
	else return 1;
}

void Chessboard::SimpleMark(const Offsets o) {
	Term[o.a * cols + o.b]++;
}

void Chessboard::Mark(const Offsets chess, int n) {
	Term[chess.a * cols + chess.b] = n;
}

ostream& operator<<(ostream& stream, Chessboard& s)
{
	int n;
	n = s.rows * s.cols;
	for (int i = 0; i < s.rows; i++)
	{
		stream << endl;
		for (int j = 0; j < s.cols; j++)
			stream << s.Term[i * s.cols + j] << " ";
	}
	stream << endl;
	return stream;
}
// constructor, initialize,CheckComplete, CheckBoundary, Mark, operator<<를 구현
void WalkKnight(Chessboard g, const struct Offsets startPosition);
void MarkNth(Chessboard g, const struct Offsets startPosition);

int main(void) {
	Chessboard g;
	g.initialize();
	int xStart, yStart;
	cout << endl << "시작할 위치(x, y) 입력: ";
	cin >> xStart >> yStart;
	struct Offsets startPosition;
	startPosition.a = xStart; 	startPosition.b = yStart;
	WalkKnight(g, startPosition);
	cout << endl << "Work path::" << endl;
	cout << g;
	g.initialize();

	MarkNth(g, startPosition);
	cout << endl << "Mark nth visiting path::" << endl;
	cout << g;
	system("pause");
	return 1;
}
void WalkKnight(Chessboard g, const struct Offsets startPosition) {
	//start from position
	directions knightMove;;//knight number
	struct Offsets currentPosition;
	currentPosition = startPosition;
	g.SimpleMark(currentPosition);
	while (!g.CheckComplete()) {
		knightMove = (directions)(rand()%8);
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
	int nthLevel = 1;//1차 이동, 2차 이동을 표시하는 level
	struct Offsets currentPosition;
	currentPosition = startPosition;
	knightStack.Push(currentPosition);
	g.Mark(currentPosition, nthLevel);
	cout << g;
	while (!g.CheckComplete()) {
		//currentPosition = knightStack.Pop();
		
		knightMove = (directions)(rand() % 8);
		struct Offsets newPosition;
		newPosition.a = currentPosition.a + Move[knightMove].a;
		newPosition.b = currentPosition.b + Move[knightMove].b;
		if (!g.CheckBoundary(newPosition)) continue;
		else {
			if (!g.CheckNextZero(newPosition)) { 
				nthLevel++;
				g.Mark(newPosition, nthLevel);
				knightStack.Push(newPosition);
				currentPosition = newPosition;
				cout << g;
			}
			else
				nthLevel--;
				currentPosition = knightStack.Pop();
		}
	}
	cout << g;
}

