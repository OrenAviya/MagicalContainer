 #include "MagicalContainer.hpp"



    // Equality comparison (operator==)
    bool  MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
        return forwardPosition == other.forwardPosition && backwardPosition == other.backwardPosition && forward == other.forward;
    }

    // Inequality comparison (operator!=)
    bool  MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
        return !(*this == other);
    }

    // GT, LT comparison (operator>, operator<)
    bool  MagicalContainer::SideCrossIterator:: operator>(const SideCrossIterator& other) const {
        return forwardPosition > other.forwardPosition && backwardPosition > other.backwardPosition;
    }

    bool  MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
        return forwardPosition < other.forwardPosition && backwardPosition < other.backwardPosition;
    }

    // Dereference operator (operator*)
    int MagicalContainer::SideCrossIterator::operator*() const {
      if (forward)
            return container.elements[ forwardPosition];
        else
            return container.elements[backwardPosition ];
}
MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other){
     if (this != &other) {
            this->container = other.container;
             forwardPosition= other.forwardPosition;
             backwardPosition = other.backwardPosition;
             forward = other.forward;
        }
        return *this;
    
}

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
        if (forwardPosition < backwardPosition) {
        if (forward) {
            ++forwardPosition;
           
        } else {
            --backwardPosition;
             
        }
        forward = !forward;
    } 
    else if (forwardPosition == backwardPosition) {
        ++forwardPosition;
        forward =false;
    }
        
        return *this;
    }


    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const{
    return SideCrossIterator(*this);
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const{
 SideCrossIterator it = SideCrossIterator(*this);
 
   if (container.size() %2 == 0){
    it.forwardPosition = container.size()/2;
    it.backwardPosition = container.size()/2-1;
    it.forward = false;}
   else{
    it.forwardPosition = container.size()/2+1;
    it.backwardPosition = container.size()/2;
    it.forward = false;
    // cout<< "it.forwardPosition ,it.backwardPosition : "<<it.forwardPosition<< "," <<it.backwardPosition<<"\n";
   }
    
    return it; 
    
}



