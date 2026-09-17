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
private:
	Task* _tasks;
	int _count;
	int* _user_answers;
	int* _pc_answers;
	int _correct_count;

	void generate_tasks(int lñ, int rñ, char op);
	void ask_question(int index);
	char calc_mark() const;
public:
	explicit MathTest(int count);
	MathTest(int count, int lñ, int rñ);
	MathTest(int count, int lñ, int rñ, char op);
	~MathTest();

	void run();
	void show_statistics() const;

	int get_count() const { return _count; }
	int get_correct_count() const { return _correct_count; }
	int get_pc_answer(int i) const { return _pc_answers[i]; }
	int get_user_answer(int i) const { return _user_answers[i]; }
	const Task& get_task(int i) const { return _tasks[i]; }
};