 #include "MagicalContainer.hpp"



    // Equality comparison (operator==)
    bool  MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
        // return forwardPosition == other.forwardPosition && backwardPosition == other.backwardPosition && forward == other.forward;
        return startiter == other.startiter && enditer == other.enditer && forward == other.forward; 
    }

    // Inequality comparison (operator!=)
    bool  MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
        return !(*this == other);
    }

    // GT, LT comparison (operator>, operator<)
    bool  MagicalContainer::SideCrossIterator:: operator>(const SideCrossIterator& other) const {
        if (*this == other){return false;}
        else{
            if (startiter != other.startiter) {
        return startiter > other.startiter;
        // return forwardPosition > other.forwardPosition;
    } else if (enditer != other.enditer) {
        return enditer < other.enditer;
        // return backwardPosition > other.backwardPosition;
    }  else {
        if (forward && !other.forward) {
            return true;  // this is in forward direction, other is in backward direction
        } else if (!forward && other.forward) {
            return false; // this is in backward direction, other is in forward direction
        } else {
            return startiter > enditer;
            // return forwardPosition > backwardPosition; // same direction, compare positions
        }
    }
        return startiter > other. startiter && enditer < other.enditer ;
        // return forwardPosition > other.forwardPosition && backwardPosition > other.backwardPosition;
    }
        }
         

    bool  MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
        if (*this == other){return false;}
        return !(*this > other);
    }

    // Dereference operator (operator*)
    int MagicalContainer::SideCrossIterator::operator*() const {
      if (forward)
            return *startiter;
            // return container->elements[ forwardPosition];
        else
            return *enditer;
            // return container->elements[backwardPosition ];
}
MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other){
     if (other.container != container){
                throw runtime_error ("iterators are pointing at different containers");
            }
     
     if (this != &other) {
            this->container = other.container;
            //  forwardPosition= other.forwardPosition;
            //  backwardPosition = other.backwardPosition;
             forward = other.forward;
             startiter = other.startiter;
             enditer = other.enditer;
        }
        return *this;
    
}

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
        if(this->end() == *this ){
            throw runtime_error ("Increment Beyond End is imposible");
        }
    
    if(container->elements.size() % 2 != 0)
    {
            if (startiter < enditer) {
            if (forward) {
                // ++forwardPosition;
                ++startiter;
            
            } else {
                // --backwardPosition;
                --enditer;
                
            }
            forward = !forward;
        } 
        else if (startiter == enditer) {
            // ++forwardPosition;
            ++startiter;
            forward =false;
        }
    } 
    else if  (container->elements.size() % 2 == 0){
        if (startiter < enditer) {
            if (forward) {
                // ++forwardPosition;
                 ++startiter;
            } else {
                // --backwardPosition;
                --enditer;
            }
            forward = !forward;
        } 
        else if (startiter == enditer){
            --enditer;
            forward = false;
        }
        else  { //if (forwardPosition > backwardPosition)
            // ++forwardPosition;
             ++startiter;
            forward =false;
        }
    }
        return *this;
    }


    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const{
    return SideCrossIterator(*this->container);
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const{
 SideCrossIterator it = SideCrossIterator(*this->container);
 
    if (container->size() == 0 ){
        it.enditer = this->enditer;
        it.startiter = this->startiter;
        // it.forwardPosition = 0;
        // it.backwardPosition = 0;
        it.forward = true;
    }   
else if (container->size() %2 == 0){
    it.enditer -= container->size()/2;
    it.startiter += container->size()/2;
    // it.forwardPosition = container->size()/2+1;
    // it.backwardPosition = container->size()/2;
    it.forward = false;}
   else{
    it.enditer -= container->size()/2;
    it.startiter += container->size()/2+1;
    // it.forwardPosition = container->size()/2+1;
    // it.backwardPosition = container->size()/2;
    it.forward = false;
    // cout<< "it.forwardPosition ,it.backwardPosition : "<<it.forwardPosition<< "," <<it.backwardPosition<<"\n";
   }
    
    return it; 
    
}



