#include <iostream>
#include <iomanip>

//달팽이 배열

using namespace std;
const int MAX = 100;
int board[MAX][MAX] = {};
int N;

void PrintBoard() {

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {

			cout <<setfill('0') << setw(2) << board[y][x] << " ";
			//setfill() 오른쪽 맞춤된 디스플레이에서 공백을 채우는데 사용할 문자를 설정
			//setw() 스트림에서 다음 요소에 대한 표시 필드의 너비를 지정

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

//유효 범위에서 벗어나거나 채워져 있는 경우
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
	int dy[] = { 0,1,0,-1 }; //오른쪽(변화없음 0), 아래(증가 +1), 왼쪽(변화없음), 위(감소 -1)
	int dx[] = { 1,0,-1,0 }; //오른쪽(증가 +1), 아래(변화없음 0), 왼쪽(감소 -1), 위(변화없음)

	while (true) {
		board[y][x] = num;

		//달팽이 배열이 끝나는 부분(N=5이면 5*5 25가 마지막)
		if (num == N * N) 
			break;

		int nextY = y+dy[dir];
		int nextX = x+dx[dir];


		if (CanGo(nextY, nextX)) {
			y = nextY;
			x = nextX;
			num++;

		}
		//방향이 바뀌는 부분(방향 회전)
		else {
			dir = (dir + 1) % 4; //나머지 연산으로 4가 안 나옴
	
		}
	}


}

int main() {


	cin >> N;
	SetBoard();
	PrintBoard();
	
	return 0;
}