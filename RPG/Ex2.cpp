#include <iostream>
#include <iomanip>

//������ �迭

using namespace std;
const int MAX = 100;
int board[MAX][MAX] = {};
int N;

void PrintBoard() {

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {

			cout <<setfill('0') << setw(2) << board[y][x] << " ";
			//setfill() ������ ����� ���÷��̿��� ������ ä��µ� ����� ���ڸ� ����
			//setw() ��Ʈ������ ���� ��ҿ� ���� ǥ�� �ʵ��� �ʺ� ����

		}
		cout << endl;
	}

}

enum DIR {
	RIGHT = 0,
	DOWN = 1,
	LEFT = 2,
	UP = 3,

};

//��ȿ �������� ����ų� ä���� �ִ� ���
bool CanGo(int y, int x) {
	if (y < 0 || y >= N)
		return false;
	if (x < 0 || x >= N)
		return false;
	if (board[y][x] != 0)
		return false;
	return true;
}

void SetBoard() {
	int dir = RIGHT;
	int num = 1;
	int y = 0;
	int x = 0;
	int dy[] = { 0,1,0,-1 }; //������(��ȭ���� 0), �Ʒ�(���� +1), ����(��ȭ����), ��(���� -1)
	int dx[] = { 1,0,-1,0 }; //������(���� +1), �Ʒ�(��ȭ���� 0), ����(���� -1), ��(��ȭ����)

	while (true) {
		board[y][x] = num;

		//������ �迭�� ������ �κ�(N=5�̸� 5*5 25�� ������)
		if (num == N * N) 
			break;

		int nextY = y+dy[dir];
		int nextX = x+dx[dir];


		if (CanGo(nextY, nextX)) {
			y = nextY;
			x = nextX;
			num++;

		}
		//������ �ٲ�� �κ�(���� ȸ��)
		else {
			dir = (dir + 1) % 4; //������ �������� 4�� �� ����
	
		}
	}


}

int main() {


	cin >> N;
	SetBoard();
	PrintBoard();
	
	return 0;
}