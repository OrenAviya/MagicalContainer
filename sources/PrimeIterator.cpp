#include "MagicalContainer.hpp"


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
        return container->elements[currentPosition];
    }

     MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
        ++currentPosition;
        while (currentPosition < container->size() && !isPrime(container->elements[currentPosition])) {
            ++currentPosition;
        }
        return *this;
    }
    MagicalContainer:: PrimeIterator& MagicalContainer:: PrimeIterator::operator=(const PrimeIterator& other) {
        if (this != &other) {
            this->container = other.container;
            currentPosition = other.currentPosition;
        }
        return *this;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator:: begin() {
        size_t counter=0;
        while(counter < (this)->container->elements.size() ){
            if(isPrime((this)->container->elements[counter])){return PrimeIterator(*this);}
            ++*this;
            ++counter;
        }
        //if there is no prime numbers:
        return PrimeIterator();
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator:: end() {
    return PrimeIterator(*(this->container), container->size());
}