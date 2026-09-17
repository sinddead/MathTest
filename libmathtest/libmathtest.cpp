#include "mathtest.h"
#include <random>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>


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
	if (lc == rc && lc==0) throw std::logic_error(")))))))) left corner and right can't both be zero");
	std::uniform_int_distribution<int> dist(lc, rc);
	int res = dist(gen);
	while (res == 0) res = dist(gen);
	return res;
}

char Task::random_op() {
	static const char ops[] = { '+', '-', '*', '/' };
	return ops[random_int(0, 3)];
}

MathTest::MathTest(int count)
    : MathTest(count, 1, 100, Task::random_op())
{
}

MathTest::MathTest(int count, int lc, int rc)
    : MathTest(count, lc, rc, Task::random_op())
{
}

MathTest::MathTest(int count, int lc, int rc, char op) :
	_tasks(nullptr), _count(count), _user_answers(nullptr), _pc_answers(nullptr), _correct_count(0)
{
    if (count <= 0) throw std::logic_error("count must be > 0");
    _tasks = new Task[_count];
    _user_answers = new int[_count];
    _pc_answers = new int[_count];
    generate_tasks(lc, rc, op);
}

MathTest::~MathTest() {
    delete[] _tasks;
    delete[] _user_answers;
    delete[] _pc_answers;
}

void MathTest::generate_tasks(int lc, int rc, char op) {
    for (int i = 0; i < _count; i++) {
        int f = Task::random_int(lc, rc);
        int s = Task::random_int(lc, rc);
        if (f == s && s == 0) s = 1; //на случай бага, немного костыльно
        _tasks[i] = Task(f, s, op);
        _pc_answers[i] = _tasks[i].getres();
    }
}

void MathTest::run() {
    _correct_count = 0;
    for (int i = 0; i < _count; ++i) {
        ask_question(i);
        if (_user_answers[i] == _pc_answers[i])
            _correct_count++;
    }
}

void MathTest::ask_question(int index) {
    std::cout << "Question " << (index + 1) << "/" << _count << ": "
        << _tasks[index].getnum1() << ' '
        << _tasks[index].getchar() << ' '
        << _tasks[index].getnum2() << " = ";
    while (!(std::cin >> _user_answers[index])) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input, please enter a number: ";
    }
}

char MathTest::calc_mark() const {
	double p = double(_correct_count) / _count;
	if (p >= 0.9) return '5';
	else if (p >= 0.7) return '4';
	else if (p >= 0.5) return '3';
	return '2';
}

void MathTest::show_statistics() const {
    std::cout << '|' << std::setw(12) << "No" << " |";
    for (int i = 0; i < _count; ++i)
        std::cout << std::setw(8) << (i + 1) << " |";
    std::cout << '\n';
    std::cout << '+';
    for (int i = 0; i < 13 + 10 * _count; ++i) std::cout << '-';
    std::cout << "+\n";
    std::cout << "|    Question |";
    for (int i = 0; i < _count; ++i) {
        std::string expr = std::to_string(_tasks[i].getnum1()) + " " +
            std::string(1, _tasks[i].getchar()) + " " +
            std::to_string(_tasks[i].getnum2());
        std::cout << std::setw(8) << expr << " |";
    }
    std::cout << '\n';
    std::cout << "| True Answer |";
    for (int i = 0; i < _count; ++i)
        std::cout << std::setw(8) << _pc_answers[i] << " |";
    std::cout << '\n';
    std::cout << "| Your Answer |";
    for (int i = 0; i < _count; ++i)
        std::cout << std::setw(8) << _user_answers[i] << " |";
    std::cout << '\n';
    std::cout << "|      Result |";
    for (int i = 0; i < _count; ++i) {
        char r = (_user_answers[i] == _pc_answers[i]) ? '+' : '-';
        std::cout << std::setw(8) << r << " |";
    }
    std::cout << '\n';
    std::cout << '+';
    for (int i = 0; i < 13 + 10 * _count; ++i) std::cout << '-';
    std::cout << "+\n";
    std::cout << "Total Result: " << _correct_count << " / " << _count
        << " (mark: " << calc_mark() << ")\n";
}
