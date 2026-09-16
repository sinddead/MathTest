#include "pch.h"
#include "mathtest.h"

TEST(TestMathTests, TestDefaultInit) {
	Task t;
	int res;
	int num1 = t.getnum1();
	int num2 = t.getnum2();
	switch (t.getchar()) {
	case '+':
		res = num1 + num2;
		break;
	case '-':
		res = num1 - num2;
		break;
	case '*':
		res = num1 * num2;
		break;
	case '/':
		res = num1 / num2;
		break;
	default:
		throw std::logic_error("This operation is not exist!");
		break;
	}
	EXPECT_EQ(res,t.getres());
}

TEST(TestMathTests, TestFullConstruct) {
	Task t(1,2,'+');
	int n2=t.getnum1() + t.getnum2();
	EXPECT_EQ(3, t.getres());
}

TEST(TestMathTests, TestConstructError) {
	EXPECT_ANY_THROW(Task t(1,0));
}
