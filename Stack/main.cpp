#include <iostream>
#include "Stack.h"
#include "..\Calculator\Calculator.h"
using namespace std;
//����� ����������

void main()
{
	TCalculator tcal;
	setlocale(LC_ALL, "Russian");
	while (1) {
		system("cls");
		cout << "������� ������" << endl;
		tcal.SetInfix();
		if (!(tcal.CheckBrackets()))
			cout << "������� ����������� ������" << endl;
		if (!(tcal.CheckOperator()))
			cout << "����������� ������� ��������" << endl;
		if (tcal.CheckBrackets() && tcal.CheckOperator())
		{
			try
			{
				tcal.ToPostfix();
				cout << "�����: " << tcal.Calculator() << endl;
			}
			catch (int k)
			{
				cout << "����������� ������� ������" << endl;
			}
		}
		system("pause");
	}
	
}

