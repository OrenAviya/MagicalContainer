#pragma once
#include "MagicalContainer.hpp"
using namespace std;

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

    AscendingIterator beginAscending() const ;

    AscendingIterator endAscending() const ;
    };