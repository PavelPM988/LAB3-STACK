#pragma once
#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>
#include "..\Stack\Stack.h"

//using namespace std;

class TCalculator
{
private:
	std::string infix, postfix;
	TStack <char> StackOperation;
	TStack <double> StackNumber;
	int Priority(const char m) const;
public:
	void ToPostfix();
	void SetInfix(std::string _infix);
	void SetInfix();
	std::string GetPostfix();
	bool CheckBrackets(); 
	bool CheckOperator();
	double Calculator();
	TCalculator();
	~TCalculator();
};