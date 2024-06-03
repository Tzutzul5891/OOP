#include <iostream>
#include "Template.h"

namespace temperature_literals {
    constexpr float operator"" _Kelvin(long double k) {
        return static_cast<float>(k) - 273.15f;
    }

    constexpr float operator"" _Fahrenheit(long double f) {
        return (static_cast<float>(f) - 32) * 5.0f / 9.0f;
    }
}

int main() {
    using namespace temperature_literals;

    float a = 300.0_Kelvin;
    float b = 120.0_Fahrenheit;

    std::cout << "300 Kelvin in Celsius: " << a << std::endl;
    std::cout << "120 Fahrenheit in Celsius: " << b << std::endl;

    Tree<int> tree;
    tree.add_child(nullptr, 10);
    auto root = tree.get_node(nullptr);
    tree.add_child(root, 20);
    tree.add_child(root, 30);

    auto child = tree.get_node(root, 1);
    tree.add_child(child, 40);

    std::cout << "Tree contains " << tree.node_count(nullptr) << " nodes." << std::endl;

    return 0;
}