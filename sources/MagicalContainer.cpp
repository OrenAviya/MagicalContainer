#include <iostream>
#include <vector>
#include "MagicalContainer.hpp"


    void MagicalContainer:: addElement(int element) {
        elements.push_back(element);
        std::sort(elements.begin(), elements.end());
    }

    void MagicalContainer:: removeElement(int element) {
       auto it = elements.begin();
        for (it = elements.begin(); it != elements.end(); ++it) {
            if (*it == element) {
                elements.erase(it);
                break;
            }
        }
        if ( it == elements.end()){ //the loop not break, the element not exist
            throw std::runtime_error("the element is not exist");
        }
        
    }

    size_t MagicalContainer:: size() const {
        return elements.size();
    }

    MagicalContainer& MagicalContainer::operator=(const MagicalContainer& other) {
    if (this != &other) {
        // Copy the elements from the other container
        elements = other.elements;
    }
    return *this;
}

MagicalContainer& MagicalContainer::operator=(MagicalContainer&& other) noexcept {
        if (this != &other) {
            elements = std::move(other.elements);
        }
        return *this;
    }

