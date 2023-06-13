#include "MagicalContainer.hpp"

bool  MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
            
            return currentPosition == other.currentPosition;
        }

        bool  MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
            return !(*this == other);
        }

        bool MagicalContainer::AscendingIterator::operator >(const AscendingIterator& other) const{
            return  currentPosition > other.currentPosition;
        }
        bool MagicalContainer::AscendingIterator::operator <(const AscendingIterator& other) const{
            return  currentPosition < other.currentPosition;
        }

        // the AscendingIterator is go over all the elements with no special way. 
         MagicalContainer::AscendingIterator&  MagicalContainer::AscendingIterator::operator++() {
            if(*this == this->end()){
                throw runtime_error("no posibole");
            }
            ++currentPosition;
            return *this;
        }

        int  MagicalContainer::AscendingIterator::operator*() const {
            return container->elements[currentPosition];
        }
        MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other){
     
     if (other.container != this->container){
                throw runtime_error ("iterators are pointing at different containers");
            }
     
     if (this != &other) {
            this->container = other.container;
            currentPosition = other.currentPosition;
        }
        return *this;
    
}

//  MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(AscendingIterator&& otherAI) noexcept {
//         if (this != &otherAI) {
//             container = otherAI.container;
//             currentPosition = otherAI.currentPosition;
//             otherAI.currentPosition = 0;
//         }
//         return *this;
//     }
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const {
        return AscendingIterator(*this);
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const {
       return AscendingIterator(*(this->container), container->size());
    }