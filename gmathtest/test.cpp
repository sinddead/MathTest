#include "pch.h"
#include "mathtest.h"

TEST(TaskConstructor, TestDefaultInit) {
	Task t;
	EXPECT_EQ(calculation(t.getnum1(), t.getnum2(), t.getchar()),t.getres());
}

TEST(TaskConstructor, TestFullConstruct) {
	Task t(1,2,'+');
	EXPECT_EQ(3, t.getres());
}

TEST(TaskConstructor, TestEveryOperation) {
	EXPECT_EQ(Task(10, 5, '+').getres(), 15);
	EXPECT_EQ(Task(10, 5, '-').getres(), 5);
	EXPECT_EQ(Task(10, 5, '*').getres(), 50);
	EXPECT_EQ(Task(10, 5, '/').getres(), 2);
}

TEST(TaskConstructor, TestConstructError) {
	EXPECT_THROW(Task t(1,0), std::logic_error);
}

TEST(MathTestConstructor, ImpossibleCountError) {
	EXPECT_THROW(MathTest(0), std::logic_error);
}

TEST(MathTestConstructor, PcAnswersMatchTasks) {
	MathTest t(20, 1, 50, '+');
	for (int i = 0; i < t.get_count(); ++i) {
		EXPECT_EQ(t.get_pc_answer(i), t.get_task(i).getres());
	}
}