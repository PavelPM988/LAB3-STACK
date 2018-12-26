#include <iostream>
#include "Stack.h"
#include "..\Calculator\Calculator.h"
using namespace std;
//Формы починились

void main()
{
	TCalculator tcal;
	setlocale(LC_ALL, "Russian");
	while (1) {
		system("cls");
		cout << "Введите пример" << endl;
		tcal.SetInfix();
		if (!(tcal.CheckBrackets()))
			cout << "Введены неправильно скобки" << endl;
		if (!(tcal.CheckOperator()))
			cout << "Неправильно введены операции" << endl;
		if (tcal.CheckBrackets() && tcal.CheckOperator())
		{
			try
			{
				tcal.ToPostfix();
				cout << "Ответ: " << tcal.Calculator() << endl;
			}
			catch (int k)
			{
				cout << "Неправильно введены данные" << endl;
			}
		}
		system("pause");
	}
	
}

