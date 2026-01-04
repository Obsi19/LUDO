
#pragma once
#include<iostream>
#include<time.h>
#include "Dice.h"


#define RESET "\u001B[0m"
#define RED "\u001B[31m"
#define GREEN "\u001B[32m"
#define YELLOW "\u001B[33m"
#define BLUE "\u001B[34m"



using namespace std;

class Ludo {
private:
	char Board[22][22], next, Boarddub[22][22];
	int Bcount, Rcount, Ycount, Gcount;
	int Bpositions[4][2], Ypositions[4][2], Rpositions[4][2], Gpositions[4][2];
	int Number, turn, choice;
	int Gin[4], Yin[4], Rin[4], Bin[4], rhome[4][2], ghome[4][2], yhome[4][2], bhome[4][2], gout[4], rout[4];
	int stars[8][2], count = 0, rwon[4], gwon[4];
public:
	

	Ludo()
	{
		for (int i = 0; i < 22; i++)
		{
			for (int j = 0; j < 22; j++)
			{
				Board[i][j] = ' ';
			}
		}
		Board[4][9] = '.'; Board[4][10] = '.'; Board[4][11] = '.';
		for (int k = 5; k <= 9; k++)
		{
			Board[k][9] = '.'; Board[k][11] = '.';
		}
		for (int k = 4; k <= 16; k++)
		{
			if (k != 10)
			{
				Board[9][k] = '.';
			}
		}
		Board[10][4] = '.'; Board[10][16] = '.';
		for (int k = 4; k <= 16; k++)
		{
			if (k != 10)
			{
				Board[11][k] = '.';
			}
		}
		for (int k = 11; k <= 16; k++)
		{
			Board[k][9] = '.'; Board[k][11] = '.';
		}
		Board[16][10] = '.';
		Board[5][11] = ' '; Board[6][9] = ' '; Board[9][5] = ' '; Board[11][6] = ' '; Board[9][14] = ' '; Board[11][15] = ' ';
		Board[15][9] = ' '; Board[14][11] = ' ';

		bhome[0][0] = 4; bhome[0][1] = 5; bhome[1][0] = 3; bhome[1][1] = 5; bhome[2][0] = 4; bhome[2][1] = 6; bhome[3][0] = 3; bhome[3][1] = 6;
		ghome[0][0] = 4; ghome[0][1] = 13; ghome[1][0] = 3; ghome[1][1] = 13; ghome[2][0] = 4; ghome[2][1] = 14; ghome[3][0] = 3; ghome[3][1] = 14;
		yhome[0][0] = 16; yhome[0][1] = 13; yhome[1][0] = 17; yhome[1][1] = 13; yhome[2][0] = 16; yhome[2][1] = 14; yhome[3][0] = 17; yhome[3][1] = 14;
		rhome[0][0] = 16; rhome[0][1] = 5; rhome[1][0] = 17; rhome[1][1] = 5; rhome[2][0] = 16; rhome[2][1] = 6; rhome[3][0] = 17; rhome[3][1] = 6;

		Bpositions[0][0] = 4; Board[4][5] = 'B';
		Bpositions[0][1] = 5;
		Bpositions[1][0] = 3; Board[3][5] = 'B';
		Bpositions[1][1] = 5;
		Bpositions[2][0] = 4; Board[4][6] = 'B';
		Bpositions[2][1] = 6;
		Bpositions[3][0] = 3; Board[3][6] = 'B';
		Bpositions[3][1] = 6;

		Gpositions[0][0] = 4; Board[4][13] = 'G';
		Gpositions[0][1] = 13;
		Gpositions[1][0] = 3; Board[3][13] = 'G';
		Gpositions[1][1] = 13;
		Gpositions[2][0] = 4; Board[4][14] = 'G';
		Gpositions[2][1] = 14;
		Gpositions[3][0] = 3; Board[3][14] = 'G';
		Gpositions[3][1] = 14;

		Rpositions[0][0] = 16; Board[16][5] = 'R';
		Rpositions[0][1] = 5;
		Rpositions[1][0] = 17; Board[17][5] = 'R';
		Rpositions[1][1] = 5;
		Rpositions[2][0] = 16; Board[16][6] = 'R';
		Rpositions[2][1] = 6;
		Rpositions[3][0] = 17; Board[17][6] = 'R';
		Rpositions[3][1] = 6;

		Ypositions[0][0] = 16; Board[16][13] = 'Y';
		Ypositions[0][1] = 13;
		Ypositions[1][0] = 17; Board[17][13] = 'Y';
		Ypositions[1][1] = 13;
		Ypositions[2][0] = 16; Board[16][14] = 'Y';
		Ypositions[2][1] = 14;
		Ypositions[3][0] = 17; Board[17][14] = 'Y';
		Ypositions[3][1] = 14;

		Bcount = 0, Gcount = 0, Ycount = 0, Rcount = 0;
		for (int i = 0; i < 4; i++)
		{
			Gin[i] = 0, Yin[i] = 0, Bin[i] = 0, Rin[i] = 0; rwon[i] = 0, gwon[i] = 0, gout[i] = 0, rout[i] = 0;
		}
		turn = 1;

		for (int i = 5; i < 16; i++)
		{
			if (i != 10)
			{
				Board[10][i] = 'O';
			}
		}
		for (int i = 5; i < 16; i++)
		{
			if (i != 10)
			{
				Board[i][10] = 'O';
			}
		}
		Board[10][10] = '$';

		stars[0][0] = 11;
		stars[0][1] = 6;

		stars[1][0] = 9;
		stars[1][1] = 5;

		stars[2][0] = 9;
		stars[2][1] = 14;

		stars[3][0] = 11;
		stars[3][1] = 15;

		stars[4][0] = 14;
		stars[4][1] = 11;

		stars[5][0] = 15;
		stars[5][1] = 9;

		stars[6][0] = 5;
		stars[6][1] = 11;

		stars[7][0] = 6;
		stars[7][1] = 9;

		for (int i = 0; i < 22; i++)
		{
			for (int j = 0; j < 22; j++)
			{
				Boarddub[i][j] = Board[i][j];
			}
		}
		for (int i = 0; i < 4; i++)
		{
			Boarddub[Gpositions[i][0]][Gpositions[i][1]] = '#';
			Boarddub[Rpositions[i][0]][Rpositions[i][1]] = '#';
			Boarddub[Ypositions[i][0]][Ypositions[i][1]] = '#';
			Boarddub[Bpositions[i][0]][Bpositions[i][1]] = '#';
		}
	}

	void DisplayBoard()
	{
		for (int i = 0; i < 22; i++)
		{
			for (int j = 0; j < 22; j++)
			{
				if ((i == 4 && j == 5) || (i == 3 && j == 5) || (i == 4 && j == 6) || (i == 3 && j == 6))
					cout << "\u001B[34m" << Board[i][j] << RESET;
				else if ((i == 4 && j == 13) || (i == 3 && j == 13) || (i == 4 && j == 14) || (i == 3 && j == 14))
					cout << GREEN << Board[i][j] << RESET;
				else if ((i == 16 && j == 5) || (i == 17 && j == 5) || (i == 16 && j == 6) || (i == 17 && j == 6))
					cout <<	RED << Board[i][j] << RESET;

				else
				cout << Board[i][j];
			}
			cout << "\n";
		}
	}
	void DisplayBoardWOnum()
	{
		for (int i = 0; i < 22; i++)
		{
			for (int j = 0; j < 22; j++)
			{
				if ((i == 4 && j == 5) || (i == 3 && j == 5) || (i == 4 && j == 6) || (i == 3 && j == 5))
					cout << "\u001B[34m" << Board[i][j] << RESET;
				else if ((i == 4 && j == 13) || (i == 3 && j == 13) || (i == 4 && j == 14) || (i == 3 && j == 14))
					cout << GREEN << Board[i][j] << RESET;
				else if ((i == 16 && j == 5) || (i == 17 && j == 5) || (i == 16 && j == 6) || (i == 17 && j == 6))
					cout << RED << Board[i][j] << RESET;


				else
					cout << Board[i][j];
			}
			cout << "\n";
		}
	}

	void Taketurn()
	{
		Dice dice;
		srand(time(0));
		Number = rand() % 6 + 1;
		dice.displayResult(Number);
		if (turn == 1)
		{
			cout << "Green take turn\n";
			system("pause");
			if (Gcount == 0 && Number != 6)
			{
				cout << "\nno move possible\n";
				turn = 0;
				system("cls");
				DisplayBoard();
			}
			else if (Gcount == 0 && Number == 6)
			{
				cout << "piece freed\n";
				Gcount++;
				Board[Gpositions[Gcount - 1][0]][Gpositions[Gcount - 1][1]] = '#';
				Gpositions[Gcount - 1][0] = 5, Gpositions[Gcount - 1][1] = 11;
				gout[0] = 1;
				/*/ Board[Gpositions[Gcount - 1][0]][Gpositions[Gcount - 1][1]] = 'G'; /*/
				UpdateArray();
				system("cls");
				DisplayBoard();
				turn = 0;
			}
			else if (Gcount > 1 && Number != 6)
			{
				choice = 0;
				while (choice == 0)
				{
					cout << "choose which goati to move ";
					cout << " or press 0 to view goati numbers\n";
					cin >> choice;
					while (gout[choice - 1] == 0)
					{
						cout << "piece not freed\n";
						cin >> choice;
					}
					while (gwon[choice - 1] == 1)
					{
						cout << "goati has aleady won, select a different one\n";
						cin >> choice;
					}
					if (choice == 0)
					{
						for (char i = 0; i < 4; i++)
						{
							if (gout[i] == 1)
							{
								Board[Gpositions[i][0]][Gpositions[i][1]] = i;
							}
						}
						system("cls");
						DisplayBoard();
						system("pause");
						for (int i = 0; i < Gcount; i++)
						{
							Board[Gpositions[i][0]][Gpositions[i][1]] = 'G';
						}
						system("cls");
						DisplayBoard();
					}
				}
				MoveGoati();
				turn = 0;
			}
			else if (Gcount >= 1 && Number == 6 && Gcount <= 4)
			{
				choice = 0;
				while (choice == 0)
				{
					cout << "choose which goati to move ";
					cout << " or press 0 to view goati numbers\nPress 6 to free goati\n";
					cin >> choice;
					if (choice != 6)
					{
						while (gout[choice - 1] == 0)
						{
							cout << "goati has not yet been freed\n";
							cin >> choice;
						}
						while (gwon[choice - 1] == 1)
						{
							cout << "goati has aleady won, select a different one\n";
							cin >> choice;
						}
					}
					if (choice == 0)
					{
						for (char i = 0; i < 4; i++)
						{
							if (gout[i] == 1)
							{
								Board[Gpositions[i][0]][Gpositions[i][1]] = i + 1;
							}
						}
						system("cls");
						DisplayBoard();
						system("pause");
						for (int i = 0; i < Gcount; i++)
						{
							Board[Gpositions[i][0]][Gpositions[i][1]] = 'G';
						}
						system("cls");
						DisplayBoard();
					}
				}
				if (choice == 6)
				{
					int i = 0;
					while (gout[i] != 0)
					{
						i++;
					}
					Gcount++;
					Board[Gpositions[i][0]][Gpositions[i][1]] = '#';
					Gpositions[i][0] = 5, Gpositions[i][1] = 11;
					gout[i] = 1;
					UpdateArray();
					system("cls");
					DisplayBoard();
					turn = 0;
				}
				else
				{
					MoveGoati();
					turn = 0;
				}
			}
			else
			{
				if (Gcount == 1 && Number != 6)
				{
					choice = 1;
					MoveGoati();
					turn = 0;
				}
			}
		}
		else
		{
			cout << "Red take turn\n";
			system("pause");
			if (Rcount == 0 && Number != 6)
			{
				cout << "\nno move possible\n";
				system("cls");
				DisplayBoard();
				turn = 1;
			}
			else if (Rcount == 0 && Number == 6)
			{
				cout << "piece freed\n";
				system("cls");
				Board[16][6] = '#';
				Rpositions[Rcount][0] = 15, Rpositions[Rcount][1] = 9;
				/*/ Board[Rpositions[Rcount - 1][0]][Rpositions[Rcount - 1][1]] = 'R'; /*/
				Rcount++;
				rout[0] = 1;
				UpdateArray();
				system("cls");
				DisplayBoard();
				turn = 1;
			}
			else if (Rcount > 1 && Number != 6)
			{
				choice = 0;
				while (choice == 0)
				{
					cout << "choose which goati to move ";
					cout << " or press 0 to view goati numbers\n";
					cin >> choice;
					while (rout[choice - 1] == 0)
					{
						cout << "piece not yet freed\n";
						cin >> choice;
					}
					while (rwon[choice - 1] == 1)
					{
						cout << "goati has aleady won, select a different one\n";
						cin >> choice;
					}
					if (choice == 0)
					{
						for (int i = 0; i < Rcount; i++)
						{
							Board[Rpositions[i][0]][Rpositions[i][1]] = i + 1;
						}
						system("cls");
						DisplayBoard();
						system("pause");
						for (int i = 0; i < Rcount; i++)
						{
							Board[Rpositions[i][0]][Rpositions[i][1]] = 'R';
						}
						system("cls");
						DisplayBoard();
					}
				}
				MoveGoati();
				turn = 1;
			}
			else if (Rcount >= 1 && Number == 6 && Rcount <= 4)
			{
				choice = 0;
				while (choice == 0)
				{
					cout << "choose which goati to move ";
					cout << " or press 0 to view goati numers\nPress 6 to free goati\n";
					cin >> choice;
					if (choice != 6)
					{
						while (rout[choice - 1] == 0)
						{
							cout << "piece not yet freed\n";
							cin >> choice;
						}
						while (rwon[choice - 1] == 1)
						{
							cout << "goati has aleady won, select a different one\n";
							cin >> choice;
						}
					}
					if (choice == 0)
					{
						for (int i = 0; i < Rcount; i++)
						{
							Board[Rpositions[i][0]][Rpositions[i][1]] = i + 1;
						}
						system("cls");
						DisplayBoard();
						system("pause");
						for (int i = 0; i < Rcount; i++)
						{
							Board[Rpositions[i][0]][Rpositions[i][1]] = 'R';
						}
						system("cls");
						DisplayBoard();
					}
				}
				if (choice == 6)
				{
					int i = 0;
					while (rout[i] != 0)
					{
						i++;
					}
					Rcount++;
					Board[Rpositions[i][0]][Rpositions[i][1]] = '#';
					Rpositions[i][0] = 15, Rpositions[i][1] = 9;
					rout[i] = 1;
					UpdateArray();
					system("cls");
					DisplayBoard();
					turn = 1;
				}
				else
				{
					MoveGoati();
					turn = 1;
				}
			}
			else
			{
				if (Rcount == 1 && Number != 6)
				{
					choice = 1;
					MoveGoati();
					turn = 1;
				}
			}
		}
	}

	void UpdateArray()
	{
		for (int i = 0; i < 22; i++)
		{
			for (int j = 0; j < 22; j++)
			{
				Board[i][j] = Boarddub[i][j];
			}
		}
		for (int i = 0; i < 4; i++)
		{
			Board[Ypositions[i][0]][Ypositions[i][1]] = 'Y';
			Board[Bpositions[i][0]][Bpositions[i][1]] = 'B';
			if (rout[i] == 0)
			{
				Board[Rpositions[i][0]][Rpositions[i][1]] = 'R';
			}
			if (gout[i] == 0)
			{
				Board[Gpositions[i][0]][Gpositions[i][1]] = 'G';
			}
		}
		if (turn == 1)
		{
			CheckOverlappingBT('G');
		}
		else
		{
			CheckOverlappingBT('R');
		}
	}

	void CheckOverlappingDT(int x, int y, char a)
	{
		if (Board[x][y] != '*' && Board[x][y] != '.' && Number == 1)
		{
			if (Board[x][y] == 'G')
			{
				checkkill(x, y, 'G', a);
			}
			else if (Board[x][y] == 'B')
			{
				checkkill(x, y, 'B', a);
			}
			else if (Board[x][y] == 'R')
			{
				checkkill(x, y, 'R', a);
			}
			else
			{
				checkkill(x, y, 'Y', a);
			}
		}
	}

	void checkkill(int x, int y, char t, char a)
	{

		int count = 0;
		bool flag = false;
		for (int i = 0; i < 4; i++)
		{
			if (turn == 1)
			{
				if (Gpositions[i][0] == x && Gpositions[i][1] == y)
				{
					count++;
				}
			}
			else
			{
				if (Rpositions[i][0] == x && Rpositions[i][1] == y)
				{
					count++;
				}
			}
		}
		if (count < 2)
		{
			flag = true;
		}
		if (flag == true)
		{
			if (Boarddub[x][y] != '*' && Board[x][y] != '.' && Number == 1)
			{
				if (Board[x][y] == 'G' && turn == 0)
				{
					for (int i = 0; i < 4; i++)
					{
						if (Gpositions[i][0] == x)
						{
							if (Gpositions[i][1] == y)
							{
								Gpositions[i][0] = ghome[i][0];
								Gpositions[i][1] = ghome[i][1];
								gout[i] = 0;
								Gcount--;
							}

						}
					}
				}
				else if (Board[x][y] == 'R' && turn == 1)
				{
					for (int i = 0; i < 4; i++)
					{
						if (Rpositions[i][0] == x)
						{
							if (Rpositions[i][1] == y)
							{
								Rpositions[i][0] = rhome[i][0];
								Rpositions[i][1] = rhome[i][1];
								rout[i] = 0;
								Rcount--;
							}
						}
					}
				}
				else if (Board[x][y] == 'Y')
				{

				}
				else
				{

				}
			}
		}
	}

	void CheckOverlappingBT(char a)
	{
		for (int i = 0; i < Gcount; i++)
		{
			if (gwon[i] != 1 && Gin[i] != 1 && gout[i] == 1)
			{
				if (Board[Gpositions[i][0]][Gpositions[i][1]] != '.' && Board[Gpositions[i][0]][Gpositions[i][1]] != '*' && Board[Gpositions[i][0]][Gpositions[i][1]] != '#')
				{
					if (Board[Gpositions[i][0] + 1][Gpositions[i][1]] != 'O' && Board[Gpositions[i][0] + 1][Gpositions[i][1]] != '.')
					{
						int x = Gpositions[i][0];
						while (Board[x][Gpositions[i][1]] != ' ')
						{
							x++;
						}
						Board[x][Gpositions[i][1]] = 'G';

					}
					else if (Board[Gpositions[i][0] - 1][Gpositions[i][1]] != 'O' && Board[Gpositions[i][0] - 1][Gpositions[i][1]] != '.')
					{
						int x = Gpositions[i][0];
						while (Board[x][Gpositions[i][1]] != ' ')
						{
							x--;
						}
						Board[x][Gpositions[i][1]] = 'G';

					}
					else if (Board[Gpositions[i][0]][Gpositions[i][1] + 1] != 'O' && Board[Gpositions[i][0]][Gpositions[i][1] + 1] != '.')
					{
						int y = Gpositions[i][1];
						while (Board[Gpositions[i][0]][y] != ' ')
						{
							y++;
						}
						Board[Gpositions[i][0]][y] = 'G';

					}
					else if (Board[Gpositions[i][0]][Gpositions[i][1] - 1] != 'O' && Board[Gpositions[i][0]][Gpositions[i][1] - 1] != '.')
					{

						int y = Gpositions[i][1];
						while (Board[Gpositions[i][0]][y] != ' ')
						{
							y--;
						}
						Board[Gpositions[i][0]][y] = 'G';
					}
					else
					{
						Board[Gpositions[i][0]][Gpositions[i][1]] = 'G';
					}
				}
				else
				{
					Board[Gpositions[i][0]][Gpositions[i][1]] = 'G';
				}
			}
			else
			{
				if (Gin[i] == 1)
				{
					Board[Gpositions[choice - 1][0]][Gpositions[choice - 1][1]] = 'G';
				}
			}
		}
		for (int i = 0; i < Rcount; i++)
		{
			if (rwon[i] != 1 && Rin[i] != 1 && rout[i] == 1)
			{
				if (Board[Rpositions[i][0]][Rpositions[i][1]] != '.' && Board[Rpositions[i][0]][Rpositions[i][1]] != '*' && Board[Rpositions[i][0]][Rpositions[i][1]] != '#')
				{
					if (Board[Rpositions[i][0] + 1][Rpositions[i][1]] != 'O' && Board[Rpositions[i][0] + 1][Rpositions[i][1]] != '.')
					{
						int x = Rpositions[i][0];
						while (Board[x][Rpositions[i][1]] != ' ')
						{
							x++;
						}
						Board[x][Rpositions[i][1]] = 'R';

					}
					else if (Board[Rpositions[i][0] - 1][Rpositions[i][1]] != 'O' && Board[Rpositions[i][0] - 1][Rpositions[i][1]] != '.')
					{
						int x = Rpositions[i][0];
						while (Board[x][Rpositions[i][1]] != ' ')
						{
							x--;
						}
						Board[x][Rpositions[i][1]] = 'R';

					}
					else if (Board[Rpositions[i][0]][Rpositions[i][1] + 1] != 'O' && Board[Rpositions[i][0]][Rpositions[i][1] + 1] != '.')
					{
						int y = Rpositions[i][1];
						while (Board[Rpositions[i][0]][y] != ' ')
						{
							y++;
						}
						Board[Rpositions[i][0]][y] = 'R';

					}
					else if (Board[Rpositions[i][0]][Rpositions[i][1] - 1] != 'O' && Board[Rpositions[i][0]][Rpositions[i][1] - 1] != '.')
					{
						int y = Rpositions[i][1];
						while (Board[Rpositions[i][0]][y] != ' ')
						{
							y--;
						}
						Board[Rpositions[i][0]][y] = 'R';
					}
					else
					{
						Board[Rpositions[i][0]][Rpositions[i][1]] = 'R';
					}
				}
				else
				{
					Board[Rpositions[i][0]][Rpositions[i][1]] = 'R';
				}
			}
			else
			{
				if (Rin[i] == 1)
				{
					Board[Rpositions[choice - 1][0]][Rpositions[choice - 1][1]] = 'R';
				}
			}
		}

	}

	void MoveGoati()
	{
		if (turn == 1)
		{
			while (Number > 0)
			{
				if (Gpositions[choice - 1][0] > 9 && Gpositions[choice - 1][1] <= 9)
				{
					//
					if (Board[Gpositions[choice - 1][0] - 1][Gpositions[choice - 1][1]] != 'O')
					{
						next = Board[Gpositions[choice - 1][0] - 1][Gpositions[choice - 1][1]];
						if (next == 'R')
						{
							checkkill(Gpositions[choice - 1][0] - 1, Gpositions[choice - 1][1], next, 'G');
						}
						Gpositions[choice - 1][0]--;
						Number--;
					}
					else if (Board[Gpositions[choice - 1][0]][Gpositions[choice - 1][1] - 1] != 'O')
					{
						next = Board[Gpositions[choice - 1][0]][Gpositions[choice - 1][1] - 1];
						if (next == 'R')
						{
							checkkill(Gpositions[choice - 1][0], Gpositions[choice - 1][1] - 1, next, 'G');
						}
						Gpositions[choice - 1][1]--;
						Number--;
					}
					else
					{
						//
					}
				}
				//
				else if (Gpositions[choice - 1][0] <= 9 && Gpositions[choice - 1][1] < 11)
				{
					if (Gin[choice - 1] == 1)
					{
						if (Board[Gpositions[choice - 1][0] + 1][Gpositions[choice - 1][1]] != '$' && Number > 0)
						{
							Gpositions[choice - 1][0]++;
							Number--;
						}
						else if (Board[Gpositions[choice - 1][0] + 1][Gpositions[choice - 1][1]] == '$' && Number == 1)
						{
							cout << "goati won\n";
							Number = 0;
							Board[Gpositions[choice - 1][0]][Gpositions[choice - 1][1]] = 'O';
							gwon[choice - 1] = 1;
							Gpositions[choice - 1][0] = 0; Gpositions[choice - 1][1] = 0;
						}
						else
						{
							cout << "couldnt reach $\n";
							system("pause");
							Number = 0;
						}

					}
					else if (Gpositions[choice - 1][0] == 4 && Gpositions[choice - 1][1] == 10)
					{
						Gpositions[choice - 1][0]++;
						Number--;
						Gin[choice - 1] = 1;
					}
					else if (Board[Gpositions[choice - 1][0]][Gpositions[choice - 1][1] + 1] != 'O')
					{
						next = Board[Gpositions[choice - 1][0]][Gpositions[choice - 1][1] + 1];
						if (next == 'R')
						{
							checkkill(Gpositions[choice - 1][0], Gpositions[choice - 1][1] + 1, next, 'G');
						}
						Gpositions[choice - 1][1]++;
						Number--;
					}
					else if (Board[Gpositions[choice - 1][0] - 1][Gpositions[choice - 1][1]] != 'O')
					{
						next = Board[Gpositions[choice - 1][0] - 1][Gpositions[choice - 1][1]];
						if (next == 'R')
						{
							checkkill(Gpositions[choice - 1][0] - 1, Gpositions[choice - 1][1], next, 'G');
						}
						Gpositions[choice - 1][0]--;
						Number--;
					}
					else
					{
						//
					}
				}
				//
				else if (Gpositions[choice - 1][0] < 11 && Gpositions[choice - 1][1] >= 11)
				{
					if (Board[Gpositions[choice - 1][0] + 1][Gpositions[choice - 1][1]] != 'O')
					{
						next = Board[Gpositions[choice - 1][0] + 1][Gpositions[choice - 1][1]];
						if (next == 'R')
						{
							checkkill(Gpositions[choice - 1][0] + 1, Gpositions[choice - 1][1], next, 'G');
						}
						Gpositions[choice - 1][0]++;
						Number--;
					}
					else if (Board[Gpositions[choice - 1][0]][Gpositions[choice - 1][1] + 1] != 'O')
					{
						next = Board[Gpositions[choice - 1][0]][Gpositions[choice - 1][1] + 1];
						if (next == 'R')
						{
							checkkill(Gpositions[choice - 1][0], Gpositions[choice - 1][1] + 1, next, 'G');
						}
						Gpositions[choice - 1][1]++;
						Number--;
					}
					else
					{
						//
					}
				}
				else
				{
					//
					if (Board[Gpositions[choice - 1][0]][Gpositions[choice - 1][1] - 1] != 'O')
					{
						next = Board[Gpositions[choice - 1][0]][Gpositions[choice - 1][1] - 1];
						if (next == 'R')
						{
							checkkill(Gpositions[choice - 1][0], Gpositions[choice - 1][1] - 1, next, 'G');
						}
						Gpositions[choice - 1][1]--;
						Number--;
					}
					else if (Board[Gpositions[choice - 1][0] + 1][Gpositions[choice - 1][1]] != 'O')
					{
						next = Board[Gpositions[choice - 1][0] + 1][Gpositions[choice - 1][1]];
						if (next == 'R')
						{
							checkkill(Gpositions[choice - 1][0] + 1, Gpositions[choice - 1][1], next, 'G');
						}
						Gpositions[choice - 1][0]++;
						Number--;
					}
					else
					{
						//
					}
				}
			}
			UpdateArray();
			system("cls");
			DisplayBoard();
		}
		else
		{
			while (Number > 0)
			{
				if (Rpositions[choice - 1][0] > 9 && Rpositions[choice - 1][1] <= 9)
				{
					//
					if (Board[Rpositions[choice - 1][0] - 1][Rpositions[choice - 1][1]] != 'O')
					{
						next = Board[Rpositions[choice - 1][0] - 1][Rpositions[choice - 1][1]];
						if (next == 'G')
						{
							checkkill(Rpositions[choice - 1][0] - 1, Rpositions[choice - 1][1], next, 'R');
						}
						Rpositions[choice - 1][0]--;
						Number--;
					}
					else if (Board[Rpositions[choice - 1][0]][Rpositions[choice - 1][1] - 1] != 'O')
					{
						next = Board[Rpositions[choice - 1][0]][Rpositions[choice - 1][1] - 1];
						if (next == 'G')
						{
							checkkill(Rpositions[choice - 1][0], Rpositions[choice - 1][1] - 1, next, 'R');
						}
						Rpositions[choice - 1][1]--;
						Number--;
					}
					else
					{
						//
					}
				}
				//
				else if (Rpositions[choice - 1][0] <= 9 && Rpositions[choice - 1][1] < 11)
				{
					if (Rpositions[choice - 1][0] == 16 && Rpositions[choice - 1][1] == 10)
					{
						Rpositions[choice - 1][0]--;
						Number--;
						Rin[choice - 1] = 1;
					}
					else if (Board[Rpositions[choice - 1][0]][Rpositions[choice - 1][1] + 1] != 'O')
					{
						next = Board[Rpositions[choice - 1][0]][Rpositions[choice - 1][1] + 1];
						if (next == 'G')
						{
							checkkill(Rpositions[choice - 1][0], Rpositions[choice - 1][1] + 1, next, 'R');
						}
						Rpositions[choice - 1][1]++;
						Number--;
					}
					else if (Board[Rpositions[choice - 1][0] - 1][Rpositions[choice - 1][1]] != 'O')
					{
						next = Board[Rpositions[choice - 1][0] - 1][Rpositions[choice - 1][1]];
						if (next == 'G')
						{
							checkkill(Rpositions[choice - 1][0] - 1, Rpositions[choice - 1][1], next, 'R');
						}
						Rpositions[choice - 1][0]--;
						Number--;
					}
					else
					{
						//
					}
				}
				//
				else if (Rpositions[choice - 1][0] < 11 && Rpositions[choice - 1][1] >= 11)
				{
					if (Board[Rpositions[choice - 1][0] + 1][Rpositions[choice - 1][1]] != 'O')
					{
						next = Board[Rpositions[choice - 1][0] + 1][Rpositions[choice - 1][1]];
						if (next == 'G')
						{
							checkkill(Rpositions[choice - 1][0] + 1, Rpositions[choice - 1][1], next, 'R');
						}
						Rpositions[choice - 1][0]++;
						Number--;
					}
					else if (Board[Rpositions[choice - 1][0]][Rpositions[choice - 1][1] + 1] != 'O')
					{
						next = Board[Rpositions[choice - 1][0]][Rpositions[choice - 1][1] + 1];
						if (next == 'G')
						{
							checkkill(Rpositions[choice - 1][0], Rpositions[choice - 1][1] + 1, next, 'R');
						}
						Rpositions[choice - 1][1]++;
						Number--;
					}
					else
					{
						//
					}
				}
				else
				{
					//
					if (Rin[choice - 1] == 1)
					{
						if (Board[Rpositions[choice - 1][0] - 1][Rpositions[choice - 1][1]] != '$' && Number > 0)
						{
							Rpositions[choice - 1][0]--;
							Number--;
						}
						else if (Board[Rpositions[choice - 1][0] - 1][Rpositions[choice - 1][1]] == '$' && Number == 1)
						{
							cout << "goati won\n";
							Number = 0;
							Board[Rpositions[choice - 1][0]][Rpositions[choice - 1][1]] = 'O';
							rwon[choice - 1] = 1;
							Rpositions[choice - 1][0] = 0; Rpositions[choice - 1][1] = 0;
						}
						else
						{
							cout << "couldnt reach $\n";
							system("pause");
							Number = 0;
						}

					}
					else if (Rpositions[choice - 1][0] == 16 && Rpositions[choice - 1][1] == 10)
					{
						Rpositions[choice - 1][0]--;
						Number--;
						Rin[choice - 1] = 1;
					}
					else if (Board[Rpositions[choice - 1][0]][Rpositions[choice - 1][1] - 1] != 'O')
					{
						next = Board[Rpositions[choice - 1][0]][Rpositions[choice - 1][1] - 1];
						if (next == 'G')
						{
							checkkill(Rpositions[choice - 1][0], Rpositions[choice - 1][1] - 1, next, 'R');
						}
						Rpositions[choice - 1][1]--;
						Number--;
					}
					else if (Board[Rpositions[choice - 1][0] + 1][Rpositions[choice - 1][1]] != 'O')
					{
						next = Board[Rpositions[choice - 1][0] + 1][Rpositions[choice - 1][1]];
						if (next == 'G')
						{
							checkkill(Rpositions[choice - 1][0] + 1, Rpositions[choice - 1][1], next, 'R');
						}
						Rpositions[choice - 1][0]++;
						Number--;
					}
					else
					{
						//
					}
				}
			}
		}
		UpdateArray();
		system("cls");
		DisplayBoard();
	}

	bool checkwin()
	{
		bool win = true;
		for (int i = 0; i < 4; i++)
		{
			if (gwon[i] != 1)
			{
				win = false;
			}
		}
		if (win == true)
		{
			return true;
			cout << "green won\n";
		}
		for (int i = 0; i < 4; i++)
		{
			if (rwon[i] != 1)
			{
				win = false;
			}
		}
		if (win == true)
		{
			return true;
			cout << "red won\n";
		}
		else
		{
			return false;
		}
	}

};