#include "mathtest.h"
#include <random>
#include <stdexcept>

Task::Task() {
	num1 = random_int(1, 10000);
	num2 = random_int(1, 10000);
	op = random_op();
	result = calculation(num1, num2, op);
}

Task::Task(const Task& t) {
	num1 = t.num1;
	num2 = t.num2;
	op = t.op;
	result = t.result;
}

Task::Task(const char c) : Task() {
	op = c;
	result = calculation(num1, num2, op);
}

Task::Task(const int n1, const int n2) : Task() {
	num1 = n1;
	num2 = n2;
	if (num2 == 0) throw std::logic_error("You can't divide by zero!");
	result = calculation(num1, num2, op);
}

Task::Task(const int n1, const int n2, const char c) {
	num1 = n1;
	num2 = n2;
	op = c;
	result = calculation(num1, num2, op);
}

void Task::setnum1(int n) { num1 = n; result = calculation(num1, num2, op); }
void Task::setnum2(int n) { num2 = n; result = calculation(num1, num2, op); }
void Task::setchar(char c) { op = c;   result = calculation(num1, num2, op); }

int calculation(int n1, int n2, char op) {
	switch (op) {
	case '+':
		return n1 + n2;
		break;
	case '-':
		return n1 - n2;
		break;
	case '*':
		return n1 * n2;
		break;
	case '/':
		if (n2 == 0) throw std::logic_error("You can't divide by zero!");
		return n1 / n2;
		break;
	default:
		throw std::logic_error("This operation is not exist!");
	}
}

int Task::random_int(int lc, int rc) {
	static std::mt19937 gen(std::random_device{}());
	if (lc > rc) std::swap(lc,rc);
	if (lc == rc) throw std::logic_error(")))))))) left corner and right can't both be zero");
	std::uniform_int_distribution<int> dist(lc, rc);
	int res = dist(gen);
	while (res == 0) res = dist(gen);
	return res;
}

char Task::random_op() {
	static const char ops[] = { '+', '-', '*', '/' };
	return ops[random_int(0, 3)];
}