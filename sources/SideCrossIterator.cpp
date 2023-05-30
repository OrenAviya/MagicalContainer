#include "SideCrossIterator.hpp"



    // Equality comparison (operator==)
    bool SideCrossIterator::operator==(const SideCrossIterator& other) const {
        return forwardPosition == other.forwardPosition && backwardPosition == other.backwardPosition;
    }

    // Inequality comparison (operator!=)
    bool SideCrossIterator::operator!=(const SideCrossIterator& other) const {
        return !(*this == other);
    }

    // GT, LT comparison (operator>, operator<)
    bool SideCrossIterator:: operator>(const SideCrossIterator& other) const {
        return forwardPosition > other.forwardPosition && backwardPosition > other.backwardPosition;
    }

    bool SideCrossIterator::operator<(const SideCrossIterator& other) const {
        return forwardPosition < other.forwardPosition && backwardPosition < other.backwardPosition;
    }

    // Dereference operator (operator*)
    int MagicalContainer::SideCrossIterator::operator*() const {
    if (forward)
        return forwardPosition;
    else
        return backwardPosition;
}

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
    if (forward) {
        ++forwardPosition;
        forward = false;
    } else {
        --backwardPosition;
        forward = true;
    }
    return *this;
}


    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const{
    return SideCrossIterator(*this);
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const{
    return SideCrossIterator(this->container, container.size());
}



