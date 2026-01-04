
#include<iostream>
#include<time.h>
#include "Ludo.h"
using namespace std;

int main()
{
	Ludo obj;
	obj.DisplayBoardWOnum();
	while (obj.checkwin() == false)
	{
		obj.Taketurn();
	}
}