#include "pch.h"
#include "mathtest.h"

TEST(TestMathTests, TestDefaultInit) {
	Task t;
	EXPECT_EQ(calculation(t.getnum1(), t.getnum2(), t.getchar()),t.getres());
}

TEST(TestMathTests, TestFullConstruct) {
	Task t(1,2,'+');
	EXPECT_EQ(3, t.getres());
}

TEST(TestMathTests, TestConstructError) {
	EXPECT_ANY_THROW(Task t(1,0));
}
