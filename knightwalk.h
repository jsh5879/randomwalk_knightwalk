/* knightwalk.h - knightm Walk�� �ʿ��� header file 
�й�:
�̸�:
github id:
knight(���)�� �� ��ġ���� 8���� �������� random�ϰ� �̵��Ѵ�.
*/

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
	int CheckComplete();//��� cell�� nonzero�� return 1
	int CheckBoundary(Offsets nextPosition);//(0<= a <= 7 && 0 <= b <= 7)�̸� return 1
	void SimpleMark(const Offsets chess);//(*Term)++; �ѹ� �湮�ø��� 1 ����
	void Mark(const Offsets chess, int n);//(*Term)++; �ѹ� �湮�ø��� 1 ����
	friend ostream& operator << (ostream& stream, Chessboard& s);
private:
	int rows, cols;
	int* Term;//1���� �迭�� pointer�� ����Ͽ� ����
};