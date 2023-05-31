#include <iostream>
#include <vector>
#include "MagicalContainer.hpp"


    void MagicalContainer:: addElement(int element) {
        elements.push_back(element);
        std::sort(elements.begin(), elements.end());
    }

    void MagicalContainer:: removeElement(int element) {
       
        for (auto it = elements.begin(); it != elements.end(); ++it) {
            if (*it == element) {
                elements.erase(it);
                break;
            }
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
