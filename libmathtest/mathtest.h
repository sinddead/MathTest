#pragma once

struct Task {
private:
	int num1;
	int num2;
	int result;
	char op;
public:
	Task();
	Task(const Task&);
	Task(const char);
	Task(const int, const int);
	Task(const int, const int, const char);
	int const getres();
	int const getnum1();
	int const getnum2();
	char const getchar();

};

class MathTest{
};