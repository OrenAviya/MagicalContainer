#include "PrimeIterator.hpp"


bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
        return currentPosition == other.currentPosition;
    }

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
        return !(*this == other);
    }

    bool MagicalContainer::PrimeIterator:: operator>(const PrimeIterator& other) const {
        return currentPosition > other.currentPosition;
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
        return currentPosition < other.currentPosition;
    }

     int MagicalContainer::PrimeIterator::operator*() const {
        return container.elements[currentPosition];
    }

     MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
        ++currentPosition;
        while (currentPosition < container.size() && !isPrime(container.elements[currentPosition])) {
            ++currentPosition;
        }
        return *this;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator:: begin() {
         return PrimeIterator(*this);
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator:: end() {
    return PrimeIterator(this->container, container.size());
}