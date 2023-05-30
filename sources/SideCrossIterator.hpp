#pragma once
#include "MagicalContainer.hpp"
using namespace std;
class SideCrossIterator {
private:
    const MagicalContainer& container;
    int forwardPosition;
    int backwardPosition;

public:
    SideCrossIterator(const MagicalContainer& container) : container(container), forwardPosition(0), backwardPosition(container.getSize() - 1) {}

    // Copy constructor
    SideCrossIterator(const SideCrossIterator& other) : container(other.container), forwardPosition(other.forwardPosition), backwardPosition(other.backwardPosition) {}

    // Destructor (no additional cleanup needed)
    ~SideCrossIterator() {}

    // Assignment operator
    SideCrossIterator& operator=(const SideCrossIterator& other) = default;
    // Equality comparison (operator==)
    bool operator==(const SideCrossIterator& other) const;
    // Inequality comparison (operator!=)
    bool operator!=(const SideCrossIterator& other) const;

    // GT, LT comparison (operator>, operator<)
    bool operator>(const SideCrossIterator& other) const ;

    bool operator<(const SideCrossIterator& other) const;
    // Dereference operator (operator*)
    int operator*() const ;
};


