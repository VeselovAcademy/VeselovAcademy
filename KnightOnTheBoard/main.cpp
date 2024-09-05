#include <iostream>
#include <windows.h>
using namespace std;

int command{};
const short side = 8;
constexpr int side2 = side * side;
bool found{ false };
short count{ 0 };
bool chessBoard[side][side]{};

short path[side2][2]{};

void mytime() {
	unsigned seconds = time(0);
	int hours = seconds / 3600;
	seconds -= hours * 3600;
	int minutes = seconds / 60;
	seconds -= minutes * 60;
	hours %= 24;
	cout << hours+7 << ":" << minutes << ":" << seconds << endl;
}


void getMoves(int mov[8][2], int x, int y) {
	mov[0][0] = x + 1;
	mov[0][1] = y + 2;

	mov[1][0] = x + 2;
	mov[1][1] = y + 1;

	mov[2][0] = x + 2;
	mov[2][1] = y - 1;

	mov[3][0] = x + 1;
	mov[3][1] = y - 2;
	 
	mov[4][0] = x - 1;
	mov[4][1] = y - 2;

	mov[5][0] = x - 2;
	mov[5][1] = y - 1;

	mov[6][0] = x - 2;
	mov[6][1] = y + 1;

	mov[7][0] = x - 1;
	mov[7][1] = y + 2;

}

void makeMove(short i, short j) {
	if (::count == side2) {
		cout << "\nPath Found!" << endl;
		cout << '\a';
		found = true;
		return;
	}
	if (i < 0 || i >= side || j < 0 || j >= side) {
		return;
	}
	if (chessBoard[i][j] == true)
		return;


	short moveIndex{0};
	short moves[8][2]{
		{{i + 1}, {j + 2}},
		{{i + 2}, {j + 1}},
		{{i + 2}, {j - 1}},
		{{i + 1}, {j - 2}},
		{{i - 1}, {j - 2}},
		{{i - 2}, {j - 1}},
		{{i - 2}, {j + 1}},
		{{i - 1}, {j + 2}}
	};
	chessBoard[i][j] = true;
	path[::count][0] = side - i;
	path[::count][1] = j + 65;
	::count++;


	while (moveIndex < 8) {
		makeMove(moves[moveIndex][0], moves[moveIndex][1]);
		moveIndex++;
		if (found)
		return;
	}
	chessBoard[i][j] = false;
	::count--;
}



int main() {
	int begin{};
	begin = time(0);

	char x{};//column A
	char y{};//row 8
	//cout << "Enter initial position on the board, example - A8: ";
	//cin >> x >> y;
	cout << "Starting time: ";
	mytime();
	cout << "Loading...";
	
	makeMove( 0, 1); //A -65, 8 - 56
	//system("cls");
	//cout << "Initial position: " << x << y << endl;
	for (int i = 0; i < side * side; i++) {
	
			cout << (char)path[i][1] << " " << path[i][0];
		
		cout << endl;
	}
	
	int end{};
	end = time(0);
	int seconds = end - begin;
	int hours = seconds / 3600;
	seconds -= hours * 3600;
	int minutes = seconds / 60;
	seconds -= minutes * 60;
	cout << "Time elapsed: " << hours << ":" << minutes << ":" << seconds << endl;
}