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
	int getnum1() const { return num1; }
	int getnum2() const { return num2; }
	int getres() const { return result; }
	char getchar() const { return op; }
	void setnum1(int n);
	void setnum2(int n);
	void setchar(char c);
	static int random_int(int lc, int rc);
	static char random_op();
};

int calculation(int n1, int n2, char op);

class MathTest{
};