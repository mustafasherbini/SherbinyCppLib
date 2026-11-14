#include <iostream>
#include <utility> // For std::move
#include <cassert> // For runtime assertions
#include "MySrtring.h"

int main() {
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the <b>lang</b> variable name to see how CLion can help you rename it.// 1. Test Constructors (Default and C-String)
    String emptyStr;
    assert(emptyStr.Empty() && emptyStr.Size() == 0);

    String s1("Hello");
    String s2(" World");
    std::cout << "1. Constructors: '" << s1 << "' + '" << s2 << "'\n";

    // 2. Test Deep Copy (Copy Constructor & Copy Assignment)
    String s3 = s1; // Copy constructor
    s3[0] = 'J';    // Modifying s3 must NOT affect s1
    assert(s1 == "Hello" && s3 == "Jello");
    std::cout << "2. Deep Copy: s1 = " << s1 << ", s3 = " << s3 << "\n";

    emptyStr = s2; // Copy assignment
    assert(emptyStr == " World");

    // 3. Test Concatenation (operator+ and operator+=)
    String greeting = s1 + s2;
    assert(greeting == "Hello World" && greeting.Size() == 11);

    greeting += "!";
    greeting += greeting; // Test self-concatenation safety (s1 += s1)
    assert(greeting == "Hello World!Hello World!");
    std::cout << "3. Concatenation: " << greeting << "\n";

    // 4. Test Comparison Operators (operator== and operator!=)
    String a("Test");
    String b("Test");
    String c("Different");
    assert(a == b && a != c);
    std::cout << "4. Comparisons: Passed\n";

    // 5. Test Move Semantics (Move Constructor & Move Assignment)
    String movedStr = std::move(a); // Move constructor
    assert(movedStr == "Test" && a.Empty() && a.Size() == 0);

    String moveAssignTarget("Initial");
    moveAssignTarget = std::move(b); // Move assignment
    assert(moveAssignTarget == "Test" && b.Empty());
    std::cout << "5. Move Semantics: movedStr = " << movedStr << ", old 'a' size = " << a.Size() << "\n";

    // 6. Test Clear() and Reuse
    movedStr.Clear();
    assert(movedStr.Empty() && movedStr.Size() == 0);
    movedStr += "Reused after clear";
    assert(movedStr == "Reused after clear");
    std::cout << "6. Clear & Reuse: " << movedStr << "\n";

    std::cout << "\nAll tests passed successfully!\n";
    return 0;
}
