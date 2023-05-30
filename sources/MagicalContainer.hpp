#pragma once
#include "stdlib.h"
#include "vector"
#include <iostream>
#include "PrimeIterator.hpp"
#include "AscendingIterator.hpp"
#include "SideCrossIterator.hpp"

using namespace std;
namespace ariel
{} // namespace ariel

using namespace ariel;

class MagicalContainer {

public:
    vector<int> elements; 
    // int size;
    
    //constructors:
    MagicalContainer(): elements() {}

    // destructor - don't need to manually delete the elements 
    //vector because it will be automatically destroyed when the MagicalContainer object goes out of scope
    //with the default vector destructor

    ~ MagicalContainer() {}
    
    void addElement(int element);

    void removeElement(int element);

    int size() const;

    void operator=(const MagicalContainer& other);

    // void SideCrossIterator(MagicalContainer& container);
    // void PrimeIterator(MagicalContainer& container);
    // void AscendingIterator(MagicalContainer& container);


class AscendingIterator {
    private:
        const MagicalContainer& container;
        int currentPosition;

    public:
        // constructor
        AscendingIterator(const MagicalContainer& container) : container(container), currentPosition(0) {}
        //copy constructor
        AscendingIterator( const AscendingIterator& AI): container(AI.container), currentPosition(AI.currentPosition){}

        bool operator==(const AscendingIterator& other) const;
        bool operator!=(const AscendingIterator& other) const;

        AscendingIterator& operator++() ;

        int operator*() const ;

    AscendingIterator begin() const ;

    AscendingIterator end() const ;
    };

class SideCrossIterator {
private:
    const MagicalContainer& container;
    int forwardPosition;
    int backwardPosition;
    bool forward;

public:
    SideCrossIterator(const MagicalContainer& container) : container(container), forwardPosition(0), backwardPosition(container.size() - 1) , forward(true) {}
    SideCrossIterator(MagicalContainer container, int idx)  : container(container), forwardPosition(idx) , backwardPosition(container.size() - 1) , forward(true){}
    // Copy constructor
    SideCrossIterator(const SideCrossIterator& other) : container(other.container), forwardPosition(other.forwardPosition), backwardPosition(other.backwardPosition) , forward(true){}

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

     MagicalContainer::SideCrossIterator&  operator++();
    MagicalContainer::SideCrossIterator begin() const;

    MagicalContainer::SideCrossIterator end() const;

};

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
    PrimeIterator(MagicalContainer container, int idx)  : container(container), currentPosition(idx){}
    // Copy constructor
    PrimeIterator(const PrimeIterator& PI) : container(PI.container), currentPosition(PI.currentPosition) {}

    // Destructor (no additional cleanup needed)
    ~PrimeIterator() {}

    // Assignment operator
     MagicalContainer::PrimeIterator& operator=(const PrimeIterator&) = default;

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
     PrimeIterator begin();

    // end(type): Returns the appropriate iterator pointing one position past the last element.
    PrimeIterator end();
};


};