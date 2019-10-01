/* randomwalk.cpp - random walk simulation 
학번:
이름:
github id:
*/
#include "randomwalk.h"
void Goboard::Mark(const Offsets) {

}
// constructor, initialize,CheckComplete, CheckBoundary, Mark, operator<<를 구현
int main(void) {
	Goboard g;
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
	directions randomMove;;//random number
	struct Offsets currentPosition;
	currentPosition = position;
	g.Mark(position);
	while (!g.CheckComplete()) {
		randomMove = (directions)(8.0 * rand());//난수를 사용하여 8가지 중에서 선택
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