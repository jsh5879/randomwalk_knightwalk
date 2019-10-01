/* randomwalk.h - random Walk에 필요한 header file 
학번:
이름:
github id:
worm(벌레)가 현 위치에서 8가지 방향으로 random하게 이동한다.
*/

#pragma once
#include <iostream>
using namespace std;
struct Offsets {
	int a, b;
};
enum directions {N,NE,E,SE,S,SW,W,NW};
Offsets Move[8] = { {-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1} };
//[g,h] <= [i,j], g = i + move[SW].a; h = j + move[SW].b;
class Goboard {
public:
	Goboard(int row= 19, int col=19);//바둑판 배열을 생성자로 호출
	void initialize();//바둑판 배열의 각 cell = 0으로 초기화
	int CheckComplete();//19x19 cell 모두가 0이 아닐 경우 return 1
	int CheckBoundary(Offsets nextPosition); //(0<= a <= 18 && 0 <= b <= 18)이면 return 1
	void Mark(const Offsets go); //(*Term)++; 한번 방문시마다 1 증가
	friend ostream& operator << (ostream& stream, Goboard& s);
private:
	int rows, cols;
	int* Term;
};