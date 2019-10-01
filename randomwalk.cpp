/* randomwalk.cpp - random walk simulation 
학번: 201524561
이름: 장석환
github id: jsh5879
*/
#include "randomwalk.h"
#include <stdlib.h>
#include <time.h>

Goboard::Goboard(int row, int col) : rows(row), cols(col)
{
	Term = new int[rows * cols];
}

void Goboard::initialize()
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			Term[i * cols + j] = 0;
	}
}
int Goboard::CheckComplete()
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			if (Term[i * cols + j] == 0) return 0;
	}
	return 1;
}
int Goboard::CheckBoundary(Offsets nextPosition)
{
	if ((0 <= nextPosition.a) && (nextPosition.a <= 18) && (0 <= nextPosition.b) && (nextPosition.b <= 18)) return 1;
	else return 0;
}
void Goboard::Mark(const Offsets o) {
	Term[o.a * cols + o.b]++;
}

void Walk(Goboard g, const struct Offsets position);

ostream& operator<<(ostream& stream, Goboard& s)
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
int main(void) {
	srand((unsigned)time(NULL)); //seed초기화
	Goboard g;
	g.initialize();
	int xStart, yStart;
	cout << endl<<"시작할 위치(x, y) 입력: ";
	cin >> xStart >> yStart;
	struct Offsets startPosition;
	startPosition.a = xStart; 	startPosition.b = yStart;
	Walk(g, startPosition);
	cout << endl<< "Work path::"<<endl;
	cout << g;
	system("pause");
	return 1;
}

void Walk(Goboard g, const struct Offsets position) {
	//start from position
	directions randomMove;//random number
	struct Offsets currentPosition;
	currentPosition = position;
	g.Mark(position);

	while (!g.CheckComplete()) {
		randomMove = (directions)(rand() % 8);//난수를 사용하여 8가지 중에서 선택
		struct Offsets newPosition;
		newPosition.a = currentPosition.a + Move[randomMove].a;
		newPosition.b = currentPosition.b + Move[randomMove].b;
		if (!g.CheckBoundary(newPosition)) continue;
		else {
			g.Mark(newPosition);
			currentPosition = newPosition;
		}
	}
	cout << g;
}
