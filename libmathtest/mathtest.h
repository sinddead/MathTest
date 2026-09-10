#pragma once

struct Task {
	int num1;
	int num2;
	int result;
	char op;

	Task();
	Task(const Task&);
	Task(const char);
	Task(const int, const int);
};

class MathTest{
};