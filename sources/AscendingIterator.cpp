#include "AscendingIterator.hpp"

bool AscendingIterator::operator==(const AscendingIterator& other) const {
            return currentPosition == other.currentPosition;
        }

        bool AscendingIterator::operator!=(const AscendingIterator& other) const {
            return !(*this == other);
        }


        // the AscendingIterator is go over all the elements with no special way. 
        AscendingIterator& AscendingIterator::operator++() {
            ++currentPosition;
            return *this;
        }

        int AscendingIterator::operator*() const {
            return container.elements[currentPosition];
        }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const {
        return AscendingIterator(*this);
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const {
        return AscendingIterator(*this);
    }