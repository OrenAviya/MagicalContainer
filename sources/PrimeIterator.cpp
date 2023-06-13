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
        if(this->end() == *this ){
            throw runtime_error ("Increment Beyond End is imposible");
        }
    
        ++currentPosition;
        while (currentPosition < container->size() && !isPrime(container->elements[currentPosition])) {
            ++currentPosition;
        }
        return *this;
    }
    MagicalContainer:: PrimeIterator& MagicalContainer:: PrimeIterator::operator=(const PrimeIterator& other) {
        if (other.container != this->container){
                throw runtime_error ("iterators are pointing at different containers");
            }
        
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