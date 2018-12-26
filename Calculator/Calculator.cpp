#include "Calculator.h"
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

TCalculator::TCalculator()
{
	infix = "\0";
}


TCalculator::~TCalculator()
{
}

int TCalculator::Priority(const char m) const
{
	switch (m)
	{
	case '(':
		return 0;
	case  '+':
		return 1;
	case  '-':
		return 1;
	case  '*':
		return 2;
	case  '/':
		return 2;
	case  '^':
		return 3;
	case 's':
		return 4;
	case 'c':
		return 4;
	case 't':
		return 4;
	default:throw m;
	}
}

void TCalculator::ToPostfix()
{
	postfix = "";
	StackOperation.Clear();
	string tmp = "(" + infix + ")";
	for (int i = 0; i < tmp.size(); i++)
	{
		if (tmp[i] == '(')
			StackOperation.Push(tmp[i]);
		if (tmp[i] >= '0'&& tmp[i] <= '9')
			postfix += tmp[i];
		if (tmp[i] == ')')
		{
			while (StackOperation.Top() != '(')
				postfix += StackOperation.Pop();
			StackOperation.Pop();
		}
		if (tmp[i] == '+' || tmp[i] == '-' || tmp[i] == '*' || tmp[i] == '/' || tmp[i] == '^')
		{
			postfix += ' ';
			while (Priority(tmp[i]) <= Priority(StackOperation.Top()))
			{
				postfix += StackOperation.Pop();
			}
			StackOperation.Push(tmp[i]);
		}
		if (tmp[i] == 's'|| tmp[i] == 'c'|| tmp[i] == 't')
		{
			if (i == tmp.find("sin") || i == tmp.find("cos") || i == tmp.find("tg"))
			{
				StackOperation.Push(tmp[i]);
				if (tmp[i] == 's' || tmp[i] == 'c')
					i += 2;
				else
					i ++;
			}
			else
				throw 5;
		}
	}
}

void TCalculator::SetInfix(string  _infix)
{
	infix = _infix;
}
void TCalculator::SetInfix() 
{
	infix.clear();
	string tmp;
	cin >> tmp;
	infix = tmp;
}
string TCalculator::GetPostfix()
{
	return postfix;
}

bool TCalculator::CheckBrackets() 
{
	TStack <char> bracket(infix.length());
	if (infix == "")
		throw 'a';
	else
	{
		for (int i = 0; i < infix.length(); i++)
			if (infix[i] == '(')
				bracket.Push(infix[i]);
			else if (infix[i] == ')')
			{
				if (bracket.IsEmpty())
					return false;
				else
					bracket.Pop();
			}
		if (bracket.IsEmpty())
			return true;
		else
			return false;
	}
}

bool TCalculator::CheckOperator() 
{
	if (infix == "")
		throw 'a';
	if (infix[0] == '+' || infix[0] == '-' || infix[0] == '*' || infix[0] == '/' || infix[0] == '^')
		return false;
	if (infix[infix.size()-1] == '+' || infix[infix.size() - 1] == '-' || infix[infix.size() - 1] == '*' 
				|| infix[infix.size() - 1] == '/' || infix[infix.size() - 1] == '^')
		return false;
	for (int i = 0; i < infix.size()-1; i++) {
		if ((infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^') &&
			(infix[i + 1] == '+' || infix[i + 1] == '-' || infix[i + 1] == '*' || infix[i + 1] == '/' || infix[i + 1] == '^'))
			return false;
	}
	return true;
}
double TCalculator::Calculator()
{
	double num1, num2, res, tmp,a;
	int size=postfix.size();
	if (size == 0)
		throw size;
	else {
		StackNumber.Clear();
		for (int i = 0; i < postfix.size(); i++)
		{
			if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^')
			{
				num2 = StackNumber.Pop();
				num1 = StackNumber.Pop();
				switch (postfix[i])
				{
				case '+':
					res = num1 + num2;
					break;
				case '-':
					res = num1 - num2;
					break;
				case '*':
					res = num1 * num2;
					break;
				case '/':
					res = num1 / num2;
					break;
				case '^':
					res = pow(num1, num2);
					break;

				}
				StackNumber.Push(res);
				a = StackNumber.Top();
			}
			if (postfix[i] >= '0' && postfix[i] <= '9')
			{
				char *p;
				double x;
				x = strtod(&postfix[i], &p);
				StackNumber.Push(x);
				int Lenght = p - &postfix[i];
				i += Lenght - 1;
			}
			if (postfix[i] == 's' || postfix[i] == 'c' || postfix[i] == 't')
			{
				switch (postfix[i])
				{
				case 's':
					res = sin(StackNumber.Pop()*M_PI / 180);
					StackNumber.Push(res);
					break;
				case 'c':
					res = cos(StackNumber.Pop()*M_PI / 180);
					StackNumber.Push(res);
					break;
				case 't':
					res = tan(StackNumber.Pop()*M_PI / 180);
					StackNumber.Push(res);
					break;
				}
			}
		}
		tmp = StackNumber.Pop();
		if (StackNumber.IsEmpty())
			return tmp;
		else
			throw 4;
	}
}
