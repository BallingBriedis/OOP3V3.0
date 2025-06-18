#include "../googletest-main/googletest/include/gtest/gtest.h"
#include "../Include/studentas.h"
#include "../Include/zmogus.h"
#include "../Include/functionsCallsVector.h"
#include "../Include/meinelib.h"

TEST(StudentTest, ConstructorTest) {
	Stud student("TestVardas", "TestPavarde", { 7, 8, 9 }, 10);
	EXPECT_EQ(student.getVar(), "TestVardas");
	EXPECT_EQ(student.getPav(), "TestPavarde");
	EXPECT_EQ(student.getEgz(), 10);
}

TEST(StudentTest, EmptyConstructorTest) {
	Stud student;
	EXPECT_EQ(student.getVar(), "");
	EXPECT_EQ(student.getPav(), "");
	EXPECT_TRUE(student.getPazymys().Empty());
	EXPECT_EQ(student.getEgz(), 0);
}

TEST(StudentTest, CopyConstructorTest) {
	Stud original("OriginalVardas", "OriginalPavarde", { 7, 8, 9 }, 10);
	original.calculateGalMediana();
	original.calculateGalVidurkis();
	Stud copy(original);
	EXPECT_EQ(copy.getVar(), original.getVar());
	EXPECT_EQ(copy.getPav(), original.getPav());
	EXPECT_EQ(copy.getPazymys(), original.getPazymys());
	EXPECT_EQ(copy.getEgz(), original.getEgz());
	EXPECT_FLOAT_EQ(copy.getVidurkis(), original.getVidurkis());
	EXPECT_FLOAT_EQ(copy.getMediana(), original.getMediana());
}

TEST(StudentTest, CopyAssignmentOperatorTest) {
	Stud original("OriginalVardas", "OriginalPavarde", { 7, 8, 9 }, 10);
	original.calculateGalMediana();
	original.calculateGalVidurkis();
	Stud copy;
	copy = original;
	EXPECT_EQ(copy.getVar(), original.getVar());
	EXPECT_EQ(copy.getPav(), original.getPav());
	EXPECT_EQ(copy.getPazymys(), original.getPazymys());
	EXPECT_EQ(copy.getEgz(), original.getEgz());
	EXPECT_FLOAT_EQ(copy.getVidurkis(), original.getVidurkis());
	EXPECT_FLOAT_EQ(copy.getMediana(), original.getMediana());
}

TEST(StudentTest, MoveConstructorTest) {
	Stud original("OriginalVardas", "OriginalPavarde", { 7, 8, 9 }, 10);
	Stud moved(std::move(original));
	EXPECT_EQ(moved.getVar(), "OriginalVardas");
	EXPECT_EQ(moved.getPav(), "OriginalPavarde");
	EXPECT_EQ(moved.getPazymys(), Vector<int>({ 7, 8, 9 }));
	EXPECT_EQ(moved.getEgz(), 10);
}

TEST(StudentTest, MoveAssignmentOperatorTest) {
	Stud original("OriginalVardas", "OriginalPavarde", { 7, 8, 9 }, 10);
	Stud moved;
	moved = std::move(original);
	EXPECT_EQ(moved.getVar(), "OriginalVardas");
	EXPECT_EQ(moved.getPav(), "OriginalPavarde");
	EXPECT_EQ(moved.getPazymys(), Vector<int>({ 7, 8, 9 }));
	EXPECT_EQ(moved.getEgz(), 10);
}