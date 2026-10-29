// This file does not compile on purpose: 150 is not a valid percentage.
// Change 150 to a value from 0 to 100 and build the target again.
#include <iostream>

#include "percent.h"

using namespace demo::literals;

int main() {
    demo::Percent discount = 150_pct;
    std::cout << "discount: " << discount.value << "%\n";
}
