#include <iostream>
#include <vector>
#include "MagicalContainer.hpp"


    void MagicalContainer:: addElement(int element) {
        elements.push_back(element);
        // this->size++;
    }

    void MagicalContainer:: removeElement(int element) {
        for (auto it = elements.begin(); it != elements.end(); ++it) {
            if (*it == element) {
                elements.erase(it);
                break;
            }
        }
    }

    int MagicalContainer:: size() const {
        return elements.size();
    }
    
    void MagicalContainer::operator=(const MagicalContainer& other){
        this->elements = other.elements;
    }

    // void MagicalContainer ::SideCrossIterator(MagicalContainer& container){
    //     SideCrossIterator(container);
    // }
    // void MagicalContainer ::PrimeIterator(MagicalContainer& container){
    //     PrimeIterator(container);
    // }
    // void MagicalContainer ::AscendingIterator(MagicalContainer& container){
    //     AscendingIterator(container);
    // }