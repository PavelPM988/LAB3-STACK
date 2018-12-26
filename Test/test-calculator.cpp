#include "pch.h"
#include "..\Calculator\Calculator.h"

TEST(TCalculator,check_brackets_1_true) 
{
	TCalculator tmp;
	tmp.SetInfix("()");
	EXPECT_EQ(true, tmp.CheckBrackets());
}

TEST(TCalculator, check_brackets_2_true)
{
	TCalculator tmp;
	tmp.SetInfix("(())");
	EXPECT_EQ(true, tmp.CheckBrackets());
}

TEST(TCalculator, check_brackets_3_true)
{
	TCalculator tmp;
	tmp.SetInfix("()()");
	EXPECT_EQ(true, tmp.CheckBrackets());
}

TEST(TCalculator, check_brackets_4_true)
{
	TCalculator tmp;
	tmp.SetInfix("(()())");
	EXPECT_EQ(true, tmp.CheckBrackets());
}

TEST(TCalculator, check_brakets_1_false) 
{
	TCalculator tmp;
	tmp.SetInfix("(");
	EXPECT_EQ(false, tmp.CheckBrackets());
}
TEST(TCalculator, check_brakets_2_false)
{
	TCalculator tmp;
	tmp.SetInfix(")");
	EXPECT_EQ(false, tmp.CheckBrackets());
}
TEST(TCalculator, check_brakets_3_false)
{
	TCalculator tmp;
	tmp.SetInfix("(()");
	EXPECT_EQ(false, tmp.CheckBrackets());
}
TEST(TCalculator, check_brakets_4_false)
{
	TCalculator tmp;
	tmp.SetInfix("())");
	EXPECT_EQ(false, tmp.CheckBrackets());
}
TEST(TCalculator, check_brakets_5_false)
{
	TCalculator tmp;
	tmp.SetInfix("()(");
	EXPECT_EQ(false, tmp.CheckBrackets());
}
TEST(TCalculator, check_brakets_6_false)
{
	TCalculator tmp;
	tmp.SetInfix("((()");
	EXPECT_EQ(false, tmp.CheckBrackets());
}
TEST(TCalculator, check_brakets_7_false)
{
	TCalculator tmp;
	tmp.SetInfix("(()))");
	EXPECT_EQ(false, tmp.CheckBrackets());
}

TEST(TCalculator, check_empty_string) 
{
	TCalculator tmp;
	EXPECT_ANY_THROW(tmp.CheckBrackets());
}
TEST(TCalculator, check_operator_1_true) 
{
	TCalculator tmp;
	tmp.SetInfix("2+2");
	EXPECT_EQ(true, tmp.CheckOperator());
}
TEST(TCalculator, check_operator_2_true)
{
	TCalculator tmp;
	tmp.SetInfix("(2+2)*2");
	EXPECT_EQ(true, tmp.CheckOperator());
}
TEST(TCalculator, check_operator_3_true)
{
	TCalculator tmp;
	tmp.SetInfix("(2+2)*1-(1/4)");
	EXPECT_EQ(true, tmp.CheckOperator());
}

TEST(TCalculator, check_operator_1_false)
{
	TCalculator tmp;
	tmp.SetInfix("2++2");
	EXPECT_EQ(false, tmp.CheckOperator());
}
TEST(TCalculator, check_operator_2_false)
{
	TCalculator tmp;
	tmp.SetInfix("(2+2)+*5");
	EXPECT_EQ(false, tmp.CheckOperator());
}

TEST(TCalculator, check_operator_3_false)
{
	TCalculator tmp;
	tmp.SetInfix("*58+45");
	EXPECT_EQ(false, tmp.CheckOperator());
}
TEST(TCalculator, check_operator_4_false)
{
	TCalculator tmp;
	tmp.SetInfix("4568-468+");
	EXPECT_EQ(false, tmp.CheckOperator());
}

TEST(TCalculator, simple_example_plus)
{
	TCalculator tmp;
	tmp.SetInfix("2+2");
	tmp.ToPostfix();
	EXPECT_EQ("2 2+", tmp.GetPostfix());
	EXPECT_EQ(4, tmp.Calculator());
}

TEST(TCalculator, simple_example_minus)
{
	TCalculator tmp;
	tmp.SetInfix("2-2");
	tmp.ToPostfix();
	EXPECT_EQ("2 2-", tmp.GetPostfix());
	EXPECT_EQ(0, tmp.Calculator());
}

TEST(TCalculator, simple_example_multiplication)
{
	TCalculator tmp;
	tmp.SetInfix("2*3");
	tmp.ToPostfix();
	EXPECT_EQ("2 3*", tmp.GetPostfix());
	EXPECT_EQ(6, tmp.Calculator());
}
TEST(TCalculator, simple_example_division)
{
	TCalculator tmp;
	tmp.SetInfix("2/4");
	tmp.ToPostfix();
	EXPECT_EQ("2 4/", tmp.GetPostfix());
	EXPECT_EQ(0.5, tmp.Calculator());

}
TEST(TCalculator, simple_example_degree)
{
	TCalculator tmp;
	tmp.SetInfix("2^3");
	tmp.ToPostfix();
	EXPECT_EQ("2 3^", tmp.GetPostfix());
	EXPECT_EQ(8, tmp.Calculator());
}
TEST(TCalculator, example_1) 
{
	TCalculator tmp;
	tmp.SetInfix("(2+2)*3");
	tmp.ToPostfix();
	EXPECT_EQ("2 2+ 3*", tmp.GetPostfix());
	EXPECT_EQ(12, tmp.Calculator());
}

TEST(TCalculator, example_2)
{
	TCalculator tmp;
	tmp.SetInfix("2/(2+2)+2");
	tmp.ToPostfix();
	EXPECT_EQ("2 2 2+ /2+", tmp.GetPostfix());
	EXPECT_EQ(2.5,tmp.Calculator());
}
TEST(TCalculator, example_3)
{
	TCalculator tmp;
	tmp.SetInfix("1/(1+1)^3+2");
	tmp.ToPostfix();
	EXPECT_EQ("1 1 1+ 3 ^/2+", tmp.GetPostfix());
	EXPECT_EQ(2.125, tmp.Calculator());
}

TEST(TCalculator, example_4)
{
	TCalculator tmp;
	tmp.SetInfix("(5+7)/40*2^5");
	tmp.ToPostfix();
	EXPECT_EQ("5 7+ 40 /2 5^*", tmp.GetPostfix());
	EXPECT_EQ(9.6, tmp.Calculator());
}
TEST(TCalculator, example_5)
{
	TCalculator tmp;
	tmp.SetInfix("256-12^2/2");
	tmp.ToPostfix();
	EXPECT_EQ("256 12 2 ^2/-", tmp.GetPostfix());
	EXPECT_EQ(184, tmp.Calculator());
}
TEST(TCalculator, test_sin)
{
	TCalculator tmp;
	bool check;
	tmp.SetInfix("sin(30)");
	tmp.ToPostfix();
	if (abs(0.5 - tmp.Calculator()) < pow(10, -10))
		check = true;
	else
		check = false;
	EXPECT_EQ("30s", tmp.GetPostfix());
	EXPECT_EQ(true, check);
}
TEST(Tcalculator, test_sin_2)
{
	TCalculator tmp;
	bool check;
	tmp.SetInfix("5*sin(30)+2");
	tmp.ToPostfix();
	if (abs(4.5 - tmp.Calculator()) < pow(10, -10))
		check = true;
	else
		check = false;
	EXPECT_EQ("5 30 s*2+", tmp.GetPostfix());
	EXPECT_EQ(true, check);
}
TEST(TCalculator, test_cos)
{
	TCalculator tmp;
	bool check;
	tmp.SetInfix("cos(60)");
	tmp.ToPostfix();
	if (abs(0.5 - tmp.Calculator()) < pow(10, -10))
		check = true;
	else
		check = false;
	EXPECT_EQ("60c", tmp.GetPostfix());
	EXPECT_EQ(true, check);
}

TEST(TCalculator, test_cos_2)
{
	TCalculator tmp;
	bool check;
	tmp.SetInfix("cos(60)*2");
	tmp.ToPostfix();
	if (abs(1 - tmp.Calculator()) < pow(10, -10))
		check = true;
	else
		check = false;
	EXPECT_EQ("60 c2*", tmp.GetPostfix());
	EXPECT_EQ(true, check);
}

TEST(TCalculator, test_tg)
{
	TCalculator tmp;
	bool check;
	tmp.SetInfix("tg(45)");
	tmp.ToPostfix();
	if (abs(1 - tmp.Calculator()) < pow(10, -10))
		check = true;
	else
		check = false;
	EXPECT_EQ("45t", tmp.GetPostfix());
	EXPECT_EQ(true, check);
}
TEST(TCalculator, test_tg_2)
{
	TCalculator tmp;
	bool check;
	tmp.SetInfix("tg(10+35)*2");
	tmp.ToPostfix();
	if (abs(2 - tmp.Calculator()) < pow(10, -10))
		check = true;
	else
		check = false;
	EXPECT_EQ("10 35+ t2*", tmp.GetPostfix());
	EXPECT_EQ(true, check);
}
TEST(TCalculator, error_symbol) 
{
	TCalculator tmp;
	tmp.SetInfix("son(35)");
	EXPECT_ANY_THROW(tmp.ToPostfix());
}