/* randomwalk.h - Random Walk에 필요한 header file */
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
	Goboard(int row, int col);//바둑판 배열을 생성자로 호출
	void initialize();//바둑판 배열의 각 cell = 0으로 초기화
	Offsets Walk(Offsets now);//난수를 불러 now 다음 위치를 결정
	int CheckComplete();
	int CheckBoundary(Offsets nextPosition);
	void Mark(const Offsets go);
	friend ostream& operator << (ostream& stream, Goboard& s);
private:
	int rows, cols;
	int* Term;//the add 2.6ress of a[i][j] = 0 + i * cols + j => Fig2.6
};