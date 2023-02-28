#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "sys/stat.h"

using namespace std;

#define KEY_EXIT 27
#define KEY_ENTER 13

#define NONE_TITLE ""

#define MENU_SIZE 6

#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_LEFT 75
#define KEY_ARROW_UP 72
#define KEY_ARROW_DOWN 80

// 2 3 4 5 6 7 8 9 10 J Q K A

enum RANGE_ERROR { OUT_OF_RANGE };

int alphabet2_10[9] = { 2,3,4,5,6,7,8,9,10 };
char alphabet11_14[4] = { 'J','Q','K','A' };

class Game {
public:
	char cards[14];
	int count;
	Game(int _count = 6) : count(_count) {
		for (int i = 0; i < count; i += 2) {
			cards[i] = 2 + i;
			cards[i + 1] = cards[i];
		}
		for (int i = 0; i < count; i++) {
			swap(cards[i], cards[rand() % count]);
		}
	}
};

void printcard(int index) {
	try {
		if (index >= 2 && index <= 10)
			cout << "[" << alphabet2_10[index - 2] << "]";
		else if (index >= 11 && index <= 14)
			cout << "[" << alphabet11_14[index - 11] << "]";
		else if (index == -1)
			cout << "[ ]";
		else
			throw OUT_OF_RANGE;
	}
	catch (RANGE_ERROR) {
		cout << "?";
	}
}

void printdeck(int* openedcards, int count) {
	system("cls");
	for (int i = 0; i < count; i++) {
		printcard(openedcards[i]);

	}
}

int main() {

	system("Cards");

	srand(time(0));

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);

	SetConsoleTextAttribute(hStdOut, 10);

	system("cls");

	int iKey = 67;
	int menupos = 0;
	int count;
	bool flag = 0;

	while (!flag) {
		try {
			cout << "Enter even number of elements(4 - 14): ";
			cin >> count;
			if (count % 2 != 0) 
				count++;
			if (count < 4 || count > 14) {
				throw OUT_OF_RANGE;
			}
			cout << "Count of cards: " << count;
			flag = 1;
		}
		catch (RANGE_ERROR) {
			cerr << "out of range: try againg\n";
			if (char(cin.peek()) == '\n')
				cin.ignore();

			if (cin.fail())
			{
				cin.clear();
				cin.ignore(32767, '\n');
			}
			flag = 0;
			Sleep(2000);
			system("cls");
		}
	}

	Game game(count);

	int opened_cards[14];
	int opened = 0;
	char last = -1, past = -1;

	flag = 0;
	for (int i = 0; i < 14; i++) { opened_cards[i] = -1; }
	while (!flag) {
		if (opened == count)
			break;
		int iKey = 67;
		while (iKey != KEY_ENTER) {
			switch (iKey) {
			case KEY_ARROW_LEFT:
				menupos--;
				break;
			case KEY_ARROW_RIGHT:
				menupos++;
				break;
			}

			if (menupos < 0) { menupos = count - 1; }
			if (menupos > count - 1) { menupos = 0; }
			printdeck(opened_cards, count);
			cout << endl << " ";
			for (int i = 0; i < menupos; i++) {
				cout << "   ";
			}
			cout << "^";

			iKey = _getch();
		}
		if (opened_cards[menupos] == -1) {
			opened++;
			past = last;
			last = menupos;
			opened_cards[menupos] = game.cards[menupos];
			if (opened % 2 == 0) {
				if (opened_cards[past] != opened_cards[last]) {
					printdeck(opened_cards, count);
					Sleep(500);
					opened -= 2;
					opened_cards[past] = -1;
					opened_cards[last] = -1;
				}
			}
		}
	}
	system("cls");
	cout << "You win!";
}