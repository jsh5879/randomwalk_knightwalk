/* randomwalk.h - Random Walk�� �ʿ��� header file */
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
	Goboard(int row, int col);//�ٵ��� �迭�� �����ڷ� ȣ��
	void initialize();//�ٵ��� �迭�� �� cell = 0���� �ʱ�ȭ
	Offsets Walk(Offsets now);//������ �ҷ� now ���� ��ġ�� ����
	int CheckComplete();
	int CheckBoundary(Offsets nextPosition);
	void Mark(const Offsets go);
	friend ostream& operator << (ostream& stream, Goboard& s);
private:
	int rows, cols;
	int* Term;//the add 2.6ress of a[i][j] = 0 + i * cols + j => Fig2.6
};