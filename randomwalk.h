/* randomwalk.h - random Walk�� �ʿ��� header file 
�й�:
�̸�:
github id:
worm(����)�� �� ��ġ���� 8���� �������� random�ϰ� �̵��Ѵ�.
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
	Goboard(int row= 19, int col=19);//�ٵ��� �迭�� �����ڷ� ȣ��
	void initialize();//�ٵ��� �迭�� �� cell = 0���� �ʱ�ȭ
	int CheckComplete();//19x19 cell ��ΰ� 0�� �ƴ� ��� return 1
	int CheckBoundary(Offsets nextPosition); //(0<= a <= 18 && 0 <= b <= 18)�̸� return 1
	void Mark(const Offsets go); //(*Term)++; �ѹ� �湮�ø��� 1 ����
	friend ostream& operator << (ostream& stream, Goboard& s);
private:
	int rows, cols;
	int* Term;
};