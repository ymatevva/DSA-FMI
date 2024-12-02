#include <iostream>
#include "DLL.hpp"
#include"SLL.hpp"

//bool testInitialization() {
//    DLL<int> list;
//    if (list.empty() && list.getSize() == 0) {
//        std::cout << "testInitialization passed\n";
//        return true;
//    }
//    else {
//        std::cout << "testInitialization failed\n";
//        return false;
//    }
//}
//
//bool testPushBackAndBack() {
//    DLL<int> list;
//    list.push_back(10);
//    if (!list.empty() && list.getSize() == 1 && list.back() == 10) {
//        list.push_back(20);
//        if (list.getSize() == 2 && list.back() == 20) {
//            std::cout << "testPushBackAndBack passed\n";
//            return true;
//        }
//    }
//    std::cout << "testPushBackAndBack failed\n";
//    return false;
//}
//
//bool testPushFrontAndFront() {
//    DLL<int> list;
//    list.push_front(10);
//    if (!list.empty() && list.getSize() == 1 && list.front() == 10) {
//        list.push_front(20);
//        if (list.getSize() == 2 && list.front() == 20) {
//            std::cout << "testPushFrontAndFront passed\n";
//            return true;
//        }
//    }
//    std::cout << "testPushFrontAndFront failed\n";
//    return false;
//}
//
//bool testPopBack() {
//    DLL<int> list;
//    list.push_back(10);
//    list.push_back(20);
//    list.pop_back();
//    if (list.getSize() == 1 && list.back() == 10) {
//        list.pop_back();
//        if (list.empty()) {
//            std::cout << "testPopBack passed\n";
//            return true;
//        }
//    }
//    std::cout << "testPopBack failed\n";
//    return false;
//}
//
//bool testPopFront() {
//    DLL<int> list;
//    list.push_front(10);
//    list.push_front(20);
//    list.pop_front();
//    if (list.getSize() == 1 && list.front() == 10) {
//        list.pop_front();
//        if (list.empty()) {
//            std::cout << "testPopFront passed\n";
//            return true;
//        }
//    }
//    std::cout << "testPopFront failed\n";
//    return false;
//}
//
//bool testInsertAndRemove() {
//    DLL<int> list;
//    list.push_back(10);
//    list.push_back(30);
//    auto it = list.begin();
//    ++it;
//
//    list.insertBefore(20, it);
//
//    std::cout << list.getSize() << " " << *list.begin() << " " << *++list.begin() << " " << *++(++list.begin()) << std::endl;
//    if (list.getSize() == 3 && *++list.begin() == 20) {
//        list.removeAt(list.begin());
//        if (list.getSize() == 2 && list.front() == 20) {
//            std::cout << "testInsertAndRemove passed\n";
//            return true;
//        }
//    }
//    std::cout << "testInsertAndRemove failed\n";
//    return false;
//}
//
//bool testIteratorTraversal() {
//    DLL<int> list;
//    list.push_back(10);
//    list.push_back(20);
//    list.push_back(30);
//    auto it = list.begin();
//    if (*it == 10 && *(++it) == 20 && *(++it) == 30) {
//        std::cout << "testIteratorTraversal passed\n";
//        return true;
//    }
//    std::cout << "testIteratorTraversal failed\n";
//    return false;
//}
//
//bool testFrontOnEmptyList() {
//    DLL<int> list;
//    try {
//        list.front();
//        std::cout << "testFrontOnEmptyList failed\n";
//        return false;
//    }
//    catch (...) {
//        std::cout << "testFrontOnEmptyList passed\n";
//        return true;
//    }
//}
//
//bool testBackOnEmptyList() {
//    DLL<int> list;
//    try {
//        list.back();
//        std::cout << "testBackOnEmptyList failed\n";
//        return false;
//    }
//    catch (...) {
//        std::cout << "testBackOnEmptyList passed\n";
//        return true;
//    }
//}
//
//bool testPushBackMultipleElements() {
//    DLL<int> list;
//    for (int i = 1; i <= 10; ++i) {
//        list.push_back(i);
//    }
//    bool passed = list.getSize() == 10 && list.back() == 10;
//    std::cout << (passed ? "testPushBackMultipleElements passed\n" : "testPushBackMultipleElements failed\n");
//    return passed;
//}
//
//bool testPushFrontMultipleElements() {
//    DLL<int> list;
//    for (int i = 1; i <= 10; ++i) {
//        list.push_front(i);
//    }
//    bool passed = list.getSize() == 10 && list.front() == 10;
//    std::cout << (passed ? "testPushFrontMultipleElements passed\n" : "testPushFrontMultipleElements failed\n");
//    return passed;
//}
//
//bool testClearList() {
//    DLL<int> list;
//    for (int i = 0; i < 5; ++i) {
//        list.push_back(i);
//    }
//    list.clear();  // Explicitly call destructor to clear list
//    bool passed = list.empty() && list.getSize() == 0;
//    std::cout << (passed ? "testClearList passed\n" : "testClearList failed\n");
//    return passed;
//}
//
//bool testCopyConstructor() {
//    DLL<int> list;
//    list.push_back(10);
//    list.push_back(20);
//    DLL<int> copyList(list);
//    bool passed = (copyList.getSize() == 2) && (copyList.front() == 10) && (copyList.back() == 20);
//    std::cout << (passed ? "testCopyConstructor passed\n" : "testCopyConstructor failed\n");
//    return passed;
//}
//
//bool testAssignmentOperator() {
//    DLL<int> list1;
//    list1.push_back(10);
//    list1.push_back(20);
//    DLL<int> list2;
//    list2.push_back(30);
//    list2 = list1;  // Test assignment operator
//
//    bool passed = (list2.getSize() == 2) && (list2.front() == 10) && (list2.back() == 20);
//    std::cout << (passed ? "testAssignmentOperator passed\n" : "testAssignmentOperator failed\n");
//    return passed;
//}
//
//bool testIteratorIncrement() {
//    DLL<int> list;
//    list.push_back(10);
//    list.push_back(20);
//    list.push_back(30);
//    auto it = list.begin();
//    if (*it == 10 && *(++it) == 20 && *(++it) == 30) {
//        std::cout << "testIteratorIncrement passed\n";
//        return true;
//    }
//    std::cout << "testIteratorIncrement failed\n";
//    return false;
//}
//
//bool testIteratorDecrement() {
//    DLL<int> list;
//    list.push_back(10);
//    list.push_back(20);
//    list.push_back(30);
//    auto it = list.end();
//    --it;
//    if (*it == 30 && *(--it) == 20 && *(--it) == 10) {
//        std::cout << "testIteratorDecrement passed\n";
//        return true;
//    }
//    std::cout << "testIteratorDecrement failed\n";
//    return false;
//}


bool testPushFront()
{
    SLL<int> list;
    list.push_front(10);
    list.push_front(20);
    return list.front() == 20 && list.back() == 10 && list.getSize() == 2;
}

bool testPushBack()
{
    SLL<int> list;
    list.push_back(10);
    list.push_back(20);
    return list.front() == 10 && list.back() == 20 && list.getSize() == 2;
}

bool testPopFront()
{
    SLL<int> list;
    list.push_back(10);
    list.push_back(20);
    list.pop_front();
    return list.front() == 20 && list.getSize() == 1;
}

bool testFrontBack()
{
    SLL<int> list;
    list.push_back(10);
    list.push_back(20);
    return list.front() == 10 && list.back() == 20;
}

bool testConstFrontBack()
{
    const SLL<int> list = []() {
        SLL<int> temp;
        temp.push_back(10);
        temp.push_back(20);
        return temp;
    }();
    return list.front() == 10 && list.back() == 20;
}

bool testGetSizeIsEmpty()
{
    SLL<int> list;
    bool emptyBefore = list.empty();
    list.push_back(10);
    bool notEmptyAfter = !list.empty();
    bool correctSize = list.getSize() == 1;
    return emptyBefore && notEmptyAfter && correctSize;
}

bool testConcat()
{
    SLL<int> list1, list2;
    list1.push_back(1);
    list1.push_back(2);
    list2.push_back(3);
    list2.push_back(4);
    SLL<int> concatenated = concat(list1, list2);
    return concatenated.front() == 1 && concatenated.back() == 4 && concatenated.getSize() == 4;
}

bool testPrint()
{
    SLL<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
   // list.print();
    // Expected output: "10 20 30" (No validation, just visual)
    return true;
}

bool testIterator()
{
    SLL<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    int sum = 0;
    for (auto it = list.cbegin(); it != list.cend(); ++it)
        sum += *it;

    return sum == 60;
}

bool testConstIterator()
{
    const SLL<int> list = []() {
        SLL<int> temp;
        temp.push_back(10);
        temp.push_back(20);
        temp.push_back(30);
        return temp;
    }();

    int sum = 0;
    for (auto it = list.cbegin(); it != list.cend(); ++it)
        sum += *it;

    return sum == 60;
}

bool testInsertAfter()
{
    SLL<int> list;
    list.push_back(10);
    list.push_back(20);
    auto it = list.begin();
    list.insertAfter(15, it);
    ++it;
    return *it == 15 && list.getSize() == 3;
}

bool testRemoveAfter()
{
    SLL<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    auto it = list.begin();
    list.removeAfter(it);
    return *it == 10 && *(++it) == 30 && list.getSize() == 2;
}

bool testPushFrontMultipleElements()
{
    SLL<int> list;
    list.push_front(10);
    list.push_front(20);
    list.push_front(30);
    return list.front() == 30 && list.back() == 10 && list.getSize() == 3;
}

bool testPushBackMultipleElements()
{
    SLL<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    return list.front() == 10 && list.back() == 30 && list.getSize() == 3;
}

bool testPopFrontUntilEmpty()
{
    SLL<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.pop_front();
    list.pop_front();
    list.pop_front();
    return list.empty() && list.getSize() == 0;
}

bool testMixedPushFrontAndBack()
{
    SLL<int> list;
    list.push_back(10);
    list.push_front(20);
    list.push_back(30);
    list.push_front(40);

    bool testPass = list.front() == 40 && list.back() == 30 && list.getSize() == 4;

    list.pop_front();
    list.pop_front();
    testPass = testPass && (list.front() == 10 && list.back() == 30);

    return testPass;
}


bool testConcatLargeLists()
{
    SLL<int> list1, list2;
    for (int i = 1; i <= 100; ++i) list1.push_back(i);
    for (int i = 101; i <= 200; ++i) list2.push_back(i);

    SLL<int> concatenated = concat(list1, list2);

    bool testPass = concatenated.getSize() == 200 && concatenated.front() == 1 && concatenated.back() == 200;

    // Verify ordering of elements in concatenated list
    auto it = concatenated.begin();
    for (int i = 1; i <= 200; ++i, ++it) {
        testPass = testPass && (*it == i);
    }

    return testPass;
}

bool testIteratorOnEmptyList()
{
    SLL<int> list;
    bool testPass = true;
    for (auto it = list.begin(); it != list.end(); ++it) {
        testPass = false; // Should never enter this loop
    }
    return testPass && list.empty();
}

bool testIteratorIncrementAndComparison()
{
    SLL<int> list;
    for (int i = 1; i <= 5; ++i) list.push_back(i);

    auto it = list.begin();
    it += 2; // Move to the third element
    bool testPass = *it == 3;

    // Test operator+
    auto it2 = it + 2; // Should point to the 5th element
    testPass = testPass && (*it2 == 5);

    return testPass;
}

bool testConstIteratorUsage()
{
    const SLL<int> list = []() {
        SLL<int> temp;
        for (int i = 1; i <= 5; ++i) temp.push_back(i);
        return temp;
    }();

    bool testPass = true;
    int expectedValue = 1;
    for (auto it = list.cbegin(); it != list.cend(); ++it) {
        testPass = testPass && (*it == expectedValue++);
    }

    return testPass && expectedValue == 6;
}
int main() {
   // int passedTests = 0;
   // passedTests += testInitialization();
   // passedTests += testPushBackAndBack();
   // passedTests += testPushFrontAndFront();
   // passedTests += testPopBack();
   // passedTests += testPopFront();
   // passedTests += testInsertAndRemove();
   // passedTests += testIteratorTraversal();
   // passedTests += testFrontOnEmptyList();
   // passedTests += testBackOnEmptyList();
   //passedTests += testPushBackMultipleElements();
   // passedTests += testPushFrontMultipleElements();
   // passedTests += testClearList();
   // passedTests += testCopyConstructor();
   // passedTests += testAssignmentOperator();
   // passedTests += testIteratorIncrement();
   // passedTests += testIteratorDecrement();

   // std::cout << passedTests << " out of 16 tests passed\n";
   // return 0;


    std::cout << "Test Push Front: " << testPushFront() << std::endl;
    std::cout << "Test Push Back: " << testPushBack() << std::endl;
    std::cout << "Test Pop Front: " << testPopFront() << std::endl;
    std::cout << "Test Front and Back: " << testFrontBack() << std::endl;
    std::cout << "Test Const Front and Back: " << testConstFrontBack() << std::endl;
    std::cout << "Test Get Size and Is Empty: " << testGetSizeIsEmpty() << std::endl;
    std::cout << "Test Concat: " << testConcat() << std::endl;
    std::cout << "Test Print (Visual): " << testPrint() << std::endl;
    std::cout << "Test Iterator: " << testIterator() << std::endl;
    std::cout << "Test Const Iterator: " << testConstIterator() << std::endl;
    std::cout << "Test Insert After: " << testInsertAfter() << std::endl;
    std::cout << "Test Remove After: " << testRemoveAfter() << std::endl;
    std::cout << "Test Push Front Multiple Elements: " << testPushFrontMultipleElements() << std::endl;
    std::cout << "Test Push Back Multiple Elements: " << testPushBackMultipleElements() << std::endl;
    std::cout << "Test Pop Front Until Empty: " << testPopFrontUntilEmpty() << std::endl;
    std::cout << "Test Mixed Push Front and Back: " << testMixedPushFrontAndBack() << std::endl;
   // std::cout << "Test Remove After Various Positions: " << testRemoveAfterVariousPositions() << std::endl;
    std::cout << "Test Concat Large Lists: " << testConcatLargeLists() << std::endl;
    std::cout << "Test Iterator on Empty List: " << testIteratorOnEmptyList() << std::endl;
    std::cout << "Test Iterator Increment and Comparison: " << testIteratorIncrementAndComparison() << std::endl;
    std::cout << "Test Iterator Increment and Comparison: " << testConstIteratorUsage() << std::endl;

}

