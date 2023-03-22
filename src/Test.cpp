#include "Test.h"

//test for Vector class functions
void Test::testVector() {
    std::cout << "Vector test start\n";

    Vector v1(5, 1);
    std::cout << "v1: ";
    for (size_t i = 0; i < v1.size(); i++) {
        std::cout << v1[i] << " ";
    }
    std::cout << "\n\n";

    std::cout << "Creating a vector using the copy constructor:\n";
    Vector v2(v1);
    std::cout << "v2: ";
    for (size_t i = 0; i < v2.size(); i++) {
        std::cout << v2[i] << " ";
    }
    std::cout << "\n\n";

    std::cout << "Creating a vector using the move constructor:\n";
    Vector v3(std::move(v1));
    std::cout << "v3: ";
    for (size_t i = 0; i < v3.size(); i++) {
        std::cout << v3[i] << " ";
    }
    std::cout << "\nv1: ";
    for (size_t i = 0; i < v1.size(); i++) {
        std::cout << v1[i] << " ";
    }
    std::cout << "\n\n";

    std::cout << "Creating a vector using the copy assignment operator:\n";
    Vector v4;
    v4 = v3;
    std::cout << "v4: ";
    for (size_t i = 0; i < v4.size(); i++) {
        std::cout << v4[i] << " ";
    }
    std::cout << "\n\n";

    std::cout << "Creating a vector using the move assignment operator:\n";
    Vector v5;
    v5 = std::move(v4);
    std::cout << "v5: ";
    for (size_t i = 0; i < v5.size(); i++) {
        std::cout << v5[i] << " ";
    }
    std::cout << "\n\n";

    std::cout << "Testing the [] operator:\n";
    for (size_t i = 0; i < v5.size(); i++) {
        v5[i] = i;
    }
    std::cout << "v5: ";
    for (size_t i = 0; i < v5.size(); i++) {
        std::cout << v5[i] << " ";
    }
    std::cout << "\n\n";

    std::cout << "Testing the const [] operator:\n";
    const Vector v6(v5);
    std::cout << "v6: ";
    for (size_t i = 0; i < v6.size(); i++) {
        std::cout << v6[i] << " ";
    }
    std::cout << "\n\n";

    std::cout << "Testing the push_back function:\n";
    for (int i = 5; i < 10; i++) {
        v5.push_back(i);
    }
    std::cout << "v5: ";
    for (size_t i = 0; i < v5.size(); i++) {
        std::cout << v5[i] << " ";
    }
    std::cout << "\n\n";

    std::cout << "Testing the pop_back function:\n";
    v5.pop_back();
    std::cout << "v5: ";
    for (size_t i = 0; i < v5.size(); i++) {
        std::cout << v5[i] << " ";
    }
    std::cout << "\n\n";

    std::cout << "Testing the clear function:\n";
    v5.clear();
    std::cout << "v5 size after clear: " << v5.size() << "\n\n";

    std::cout << "Vector test ends\n";
}


//test for Stack class functions
void Test::testStack() {

    // Test default constructor
    Stack stack1;
    std::cout << "Is stack1 empty? " << stack1.is_empty() << std::endl;

    // Test push function
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);

    // Test copy constructor and operator==
    Stack stack2 = stack1;
    std::cout << "Are stack1 and stack2 equal? " << (stack1 == stack2) << std::endl;

    // Test move constructor
    Stack stack3 = std::move(stack1);
    std::cout << "Is stack1 empty? " << stack1.is_empty() << std::endl;
    std::cout << "Is stack3 equal to the original stack1? " << (stack3 == stack2) << std::endl;

    // Test pop function
    std::cout << "Popped value from stack3: " << stack3.pop() << std::endl;

    // Test operator!=
    std::cout << "Are stack2 and stack3 not equal? " << (stack2 != stack3) << std::endl;

    // Test operator<
    std::cout << "Is stack2 smaller than stack3? " << (stack2 < stack3) << std::endl;

    // Test operator>
    std::cout << "Is stack2 greater than stack3? " << (stack2 > stack3) << std::endl;

    // Test operator+=
    stack2 += stack3;
    std::cout << "stack2 after adding stack3: ";
    while (!stack2.is_empty()) {
        std::cout << stack2.pop() << " ";
    }
    std::cout << std::endl;

    // Test operator+
    Stack stack4 = stack2 + stack3;
    std::cout << "stack4 after adding stack2(empty) and stack3: ";
    while (!stack4.is_empty()) {
        std::cout << stack4.pop() << " ";
    }
    std::cout << std::endl;

    // Test operator+= with integer value
    stack3 += 5;
    auto stack5 = stack3;
    std::cout << "stack3 after adding 5 to all elements: ";
    while (!stack3.is_empty()) {
        std::cout << stack3.pop() << " ";
    }
    std::cout << std::endl;

    // Test operator-= with integer value
    stack5 -= 2;
    auto stack6 = stack5;
    std::cout << "stack5 after subtracting 2 from all elements: ";
    while (!stack5.is_empty()) {
        std::cout << stack5.pop() << " ";
    }
    std::cout << std::endl;

    // Test operator*= with integer value
    stack6 *= 3;
    std::cout << "stack6 after multiplying all elements by 3: ";
    while (!stack6.is_empty()) {
        std::cout << stack6.pop() << " ";
    }
    std::cout << std::endl;

    std::cout << "\n end of stack test" << std::endl;
    std::cout << std::endl;
}