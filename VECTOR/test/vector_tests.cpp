#include "../googletest-main/googletest/include/gtest/gtest.h"
#include "../Include/functionsCallsVector.h"
#include "../Include/meinelib.h"



TEST(VectorTest, DefaultConstructor) {
    Vector<int> vec;
    EXPECT_TRUE(vec.Empty());
    EXPECT_EQ(vec.Size(), 0);
    EXPECT_GE(vec.Capacity(), 5);
}

TEST(VectorTest, PushBackAndAt) {
    Vector<int> vec;
    vec.PushBack(10);
    EXPECT_EQ(vec.Size(), 1);
    EXPECT_EQ(vec.At(0), 10);
}

TEST(VectorTest, AtOutOfRangeThrows) {
    Vector<int> vec;
    EXPECT_THROW(vec.At(1), std::exception);
}

TEST(VectorTest, BracketOperator) {
    Vector<int> vec;
    vec.PushBack(5);
    EXPECT_EQ(vec[0], 5);
}

TEST(VectorTest, FrontBack) {
    Vector<int> vec;
    vec.PushBack(1);
    vec.PushBack(2);
    EXPECT_EQ(vec.Front(), 1);
    EXPECT_EQ(vec.Back(), 2);
}

TEST(VectorTest, ReserveIncreasesCapacity) {
    Vector<int> vec;
    size_t oldCap = vec.Capacity();
    vec.Reserve(oldCap + 10);
    EXPECT_GT(vec.Capacity(), oldCap);
}

TEST(VectorTest, ShrinkToFitReducesCapacity) {
    Vector<int> vec;
    vec.PushBack(1);
    vec.PushBack(2);
    vec.Reserve(100);
    vec.ShrinkToFit();
    EXPECT_EQ(vec.Capacity(), vec.Size());
}

TEST(VectorTest, ClearEmptiesVector) {
    Vector<int> vec;
    vec.PushBack(1);
    vec.Clear();
    EXPECT_EQ(vec.Size(), 0);
}

TEST(VectorTest, InsertAtPosition) {
    Vector<int> vec;
    vec.PushBack(1);
    vec.Insert(1, 2);
    EXPECT_EQ(vec[1], 2);
}

TEST(VectorTest, InsertRangeWorks) {
    Vector<int> vec;
    std::vector<int> data = {3, 4, 5};
    vec.InsertRange(0, data.begin(), data.end());
    EXPECT_EQ(vec.Size(), 3);
    EXPECT_EQ(vec[0], 3);
    EXPECT_EQ(vec[1], 4);
    EXPECT_EQ(vec[2], 5);
}

TEST(VectorTest, EraseElement) {
    Vector<int> vec;
    vec.PushBack(10);
    vec.Erase(0);
    EXPECT_EQ(vec.Size(), 0);
}

TEST(VectorTest, PopBack) {
    Vector<int> vec;
    vec.PushBack(1);
    vec.PopBack();
    EXPECT_TRUE(vec.Empty());
}

TEST(VectorTest, ResizeUpAndDown) {
    Vector<int> vec;
    vec.Resize(5, 7);
    EXPECT_EQ(vec.Size(), 5);
    for (int i = 0; i < 5; ++i)
        EXPECT_EQ(vec[i], 7);
    vec.Resize(2);
    EXPECT_EQ(vec.Size(), 2);
}

TEST(VectorTest, SwapWorks) {
    Vector<int> vec;
    Vector<int> other;
    other.PushBack(100);
    vec.PushBack(5);
    vec.Swap(other);
    EXPECT_EQ(vec[0], 100);
    EXPECT_EQ(other[0], 5);
}

TEST(VectorTest, AssignWithCountValue) {
    Vector<int> vec;
    vec.Assign(3, 9);
    EXPECT_EQ(vec.Size(), 3);
    for (int i = 0; i < 3; ++i)
        EXPECT_EQ(vec[i], 9);
}

TEST(VectorTest, AssignWithIterators) {
    Vector<int> vec;
    int data[] = { 1, 2, 3 };
    vec.Assign(data, data + 3);
    EXPECT_EQ(vec.Size(), 3);
    EXPECT_EQ(vec[1], 2);
}

TEST(VectorTest, Emplace) {
    Vector<int> vec;
    vec.Emplace(0, 42);
    EXPECT_EQ(vec[0], 42);
}

TEST(VectorTest, EmplaceBack) {
    Vector<int> vec;
    vec.EmplaceBack(55);
    EXPECT_EQ(vec.Back(), 55);
}

TEST(VectorTest, AppendRange) {
    Vector<int> vec;
    std::vector<int> vals = {5, 6};
    vec.AppendRange(vals.begin(), vals.end());
    EXPECT_EQ(vec[0], 5);
    EXPECT_EQ(vec[1], 6);
}

TEST(VectorTest, EqualityOperators) {
    Vector<int> vec;
    Vector<int> other;
    vec.PushBack(1);
    other.PushBack(1);
    EXPECT_TRUE(vec == other);
    other.PushBack(2);
    EXPECT_TRUE(vec != other);
}

TEST(VectorTest, CopyConstructor) {
    Vector<int> vec;
    vec.PushBack(7);
    Vector<int> copy(vec);
    EXPECT_EQ(copy[0], 7);
}

TEST(VectorTest, AssignmentOperator) {
    Vector<int> vec;
    Vector<int> other;
    other.PushBack(3);
    vec = other;
    EXPECT_EQ(vec[0], 3);
}

TEST(VectorTest, BeginEnd) {
    Vector<int> vec;
    vec.PushBack(1);
    vec.PushBack(2);
    auto it = vec.begin();
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(*it, 2);
}

TEST(VectorTest, RBeginREnd) {
    Vector<int> vec;
    vec.PushBack(1);
    vec.PushBack(2);
    auto rit = vec.rbegin();
    EXPECT_EQ(*rit, 2);
    --rit;
    EXPECT_EQ(*rit, 1);
}
