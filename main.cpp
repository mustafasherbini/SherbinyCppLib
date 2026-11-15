#include <iostream>
#include <utility>
#include <cassert>
#include "../include/Vector.h"
#include "../include/MyString.h"

int main() {
    std::cout << "========================================\n";
    std::cout << "      TESTING CUSTOM STRING CLASS       \n";
    std::cout << "========================================\n";

    String emptyStr;
    assert(emptyStr.Empty() && emptyStr.Size() == 0);

    String s1("Hello");
    String s2(" World");
    std::cout << "1. String Constructors: '" << s1 << "' + '" << s2 << "'\n";

    String s3 = s1; // Copy constructor
    s3[0] = 'J';
    assert(s1 == "Hello" && s3 == "Jello");
    std::cout << "2. Deep Copy: s1 = " << s1 << ", s3 = " << s3 << "\n";

    emptyStr = s2; // Copy assignment
    assert(emptyStr == " World");

    String greeting = s1 + s2;
    assert(greeting == "Hello World" && greeting.Size() == 11);

    greeting += "!";
    assert(greeting == "Hello World!");
    std::cout << "3. Concatenation: " << greeting << "\n";

    String a("Test");
    String b("Test");
    String c("Different");
    assert(a == b && a != c);
    std::cout << "4. Comparisons: Passed\n";

    String movedStr = std::move(a); // Move constructor
    assert(movedStr == "Test" && a.Empty() && a.Size() == 0);
    std::cout << "5. Move Semantics Passed!\n\n";

    std::cout << "========================================\n";
    std::cout << "      TESTING CUSTOM VECTOR CLASS       \n";
    std::cout << "========================================\n";

    Vector<int> v1(5, 42);
    assert(v1.Size() == 5 && v1[0] == 42);
    std::cout << "1. Vector Parametric Constructor Passed!\n";

    Vector<int> v2;
    v2.Push_back(10);
    v2.Push_back(20);
    v2.Push_back(30);
    assert(v2.Size() == 3 && v2.Back() == 30);
    std::cout << "2. Vector Push_back Passed!\n";

    Vector<int> v3 = v1; // Copy Constructor
    assert(v3[0] == 42);

    Vector<int> movedVec = std::move(v1); // Move Constructor
    assert(movedVec.Size() == 5 && v1.Empty());
    std::cout << "3. Vector Rule of 5 (Copy/Move) Passed!\n";

    std::cout << "4. Iterators Test: ";
    for (const auto& val : v2) {
        std::cout << val << " ";
    }
    std::cout << "\n\nAll tests for BOTH String and Vector passed successfully! 🎉\n";
    return 0;
}