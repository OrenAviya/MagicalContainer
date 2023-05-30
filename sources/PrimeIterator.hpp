#pragma once
#include "MagicalContainer.hpp"
using namespace std;
class PrimeIterator {
public:
    const MagicalContainer& container;
    int currentPosition;

    bool isPrime(int number) const {
        if (number <= 1) {
            return false;
        }
        for (int i = 2; i * i <= number; ++i) {
            if (number % i == 0) {
                return false;
            }
        }
        return true;
    }

    PrimeIterator(const MagicalContainer& container) : container(container), currentPosition(0) {}
    PrimeIterator(MagicalContainer& container, size_t index) ;
    // Copy constructor
    PrimeIterator(const PrimeIterator& PI) : container(PI.container), currentPosition(PI.currentPosition) {}


    // Destructor (no additional cleanup needed)
    ~PrimeIterator() {}

    // Assignment operator
     PrimeIterator& operator=(const PrimeIterator&) = default;
    // PrimeIterator& operator=(const PrimeIterator& other) {
    //     if (this != &other) {
    //         container = other.container;
    //         currentPosition = other.currentPosition;
    //     }
    //     return *this;
    // }

    // Equality comparison (operator==)
    bool operator==(const PrimeIterator& other) const; 

    // Inequality comparison (operator!=)
    bool operator!=(const PrimeIterator& other) const;

    // GT, LT comparison (operator>, operator<)
    bool operator>(const PrimeIterator& other) const;

    bool operator<(const PrimeIterator& other) const ;

    // Dereference operator (operator*)
    int operator*() const;

    // Pre-increment operator (operator++)
    // this function uniqe to each iterator. here, it is doing ++ until it reach to the next prime number 
    // such that we will ignore the oters and the iterator will go over only on the primes.
    PrimeIterator& operator++() ;

    // begin(type): Returns the appropriate iterator pointing to the first prime element.
    static PrimeIterator begin();

    // end(type): Returns the appropriate iterator pointing one position past the last element.
   static PrimeIterator end();
};