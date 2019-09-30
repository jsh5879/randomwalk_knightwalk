/*
�й�:
�̸�:

*/
/* knightwalk.h - knightm Walk�� �ʿ��� header file */
#pragma once
#include <iostream>
using namespace std;
struct Offsets {
	int a, b;
};
enum directions { NE, EN, ES, SE, SW, WS, WN, NW };
Offsets Move[8] = { {1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2} };
//[g,h] <= [i,j], g = i + move[NE].a; h = j + move[NE].b;

class Stack {
	Offsets data[50];
	int nElements;
public:
	Stack() :
		nElements(0)
	{}
	void Push(Offsets elem);
	Offsets Pop();
	int Number();
	int Empty();
};
void Stack::Push(Offsets elem) {
	data[nElements] = elem;
	nElements++;
}

Offsets Stack::Pop() {
	nElements--;
	return data[nElements];
}

int Stack::Number() {
	return nElements;
}

int Stack::Empty() {
	return (nElements == 0);
}

class Chessboard {
public:
	Chessboard(int row=8, int col=8);//ü���� �迭�� �����ڷ� ȣ��
	void initialize();//ü���� �迭�� �� cell = 0���� �ʱ�ȭ
	Offsets Walk(Offsets now);//������ �ҷ� now ���� ��ġ�� ����
	int CheckComplete();//��� cell�� nonzero�� ����
	int CheckBoundary(Offsets nextPosition);
	void Mark(const Offsets chess);
	void MarkNth(const Offsets chess, int n);
	friend ostream& operator << (ostream& stream, Chessboard& s);
private:
	int rows, cols;
	int* Term;//1���� �迭�� pointer�� ����Ͽ� ����
};