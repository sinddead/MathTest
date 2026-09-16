#include "mathtest.h"
#include <random>
#include <stdexcept>

Task::Task() {
	int r;
	std::random_device rd;
	std::mt19937 generate(rd());
	std::uniform_int_distribution<int> distr1(1, 10000);
	std::uniform_int_distribution<int> distr2(1, 4);
	num1 = distr1(generate);
	num2 = distr1(generate);
	r = distr2(generate);
	switch (r) {
	case 1:
		op = '+';
		result = num1 + num2;
		break;
	case 2:
		op = '-';
		result = num1 - num2;
		break;
	case 3:
		op = '*';
		result = num1 * num2;
		break;
	case 4:
		op = '/';
		result = num1 / num2;
		break;
	default:
		throw std::logic_error("This operation is not exist!");
		break;
	}
}

Task::Task(const Task& t) {
	num1 = t.num1;
	num2 = t.num2;
	op = t.op;
	result = t.result;
}

Task::Task(const char c): Task() {
	switch (c) {
	case '+':
		op = '+';
		result = num1 + num2;
		break;
	case '-':
		op = '-';
		result = num1 - num2;
		break;
	case '*':
		op = '*';
		result = num1 * num2;
		break;
	case '/':
		op = '/';
		result = num1 / num2;
		break;
	default:
		throw std::logic_error("This operation is not exist!");
		break;
	}
}

Task::Task(const int n1, const int n2): Task() {
	num1 = n1;
	num2 = n2;
	if (num2 == 0) {
		throw std::logic_error("You can't divide by zero!");
	}
	switch (op) {
	case '+':
		op = '+';
		result = num1 + num2;
		break;
	case '-':
		op = '-';
		result = num1 - num2;
		break;
	case '*':
		op = '*';
		result = num1 * num2;
		break;
	case '/':
		op = '/';
		result = num1 / num2;
		break;
	default:
		throw std::logic_error("This operation is not exist!");
		break;
	}
}

Task::Task(const int n1, const int n2, const char c): Task() {
	int r;
	std::random_device rd;
	std::mt19937 generate(rd());
	std::uniform_int_distribution<int> distr1(n1, n2);
	num1 = distr1(generate);
	num2 = distr1(generate);
	op = c;
	num1 = n1;
	num2 = n2;
	switch (op) {
	case '+':
		result = num1 + num2;
		break;
	case '-':
		result = num1 - num2;
		break;
	case '*':
		result = num1 * num2;
		break;
	case '/':
		result = num1 / num2;
		break;
	default:
		throw std::logic_error("This operation is not exist!");
		break;
	}
}

int const Task::getres() {
	return result;
}

int const Task::getnum1() {
	return num1;
}

int const Task::getnum2() {
	return num2;
}

char const Task::getchar(){
	return op;
}