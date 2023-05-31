#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include <iostream>
#include <sstream>
#include <string>

TEST_CASE("Check the MagicalContainer constructors  "){
    MagicalContainer it  = MagicalContainer();
    MagicalContainer copy = MagicalContainer(it);

        CHECK(it.elements.empty());
        CHECK(copy.elements.empty());
}

TEST_CASE("MagicalContainer- add() , remove() , size()"){
    MagicalContainer magic  = MagicalContainer();
    magic.addElement(5);
    magic.addElement(36);
    magic.addElement(13);
    magic.addElement(12);
    magic.addElement(4);
    magic.addElement(21);

    CHECK(magic.size() == 6);
    // remove an existing element:
    magic.removeElement(36);
    CHECK(magic.size() == 5);
    // remove non-existing element- no change
    magic.removeElement(1);
    CHECK(magic.size() == 5);

}
// check SideCrossIterator
TEST_CASE("check constructors SideCrossIterator"){
    MagicalContainer magic  = MagicalContainer();
    magic.addElement(5);
    magic.addElement(36);
    magic.addElement(13);
    magic.addElement(12);
    magic.addElement(4);
    magic.addElement(21);
    CHECK_NOTHROW(MagicalContainer::SideCrossIterator sideIter(magic));
    //begin index in the range of container size 
    CHECK_NOTHROW(MagicalContainer::SideCrossIterator sideIter(magic , 5));
    // begin index out of range - bigger than container size
    CHECK_THROWS([&]() { MagicalContainer magic;
    magic.addElement(5);
    magic.addElement(36);
    MagicalContainer::SideCrossIterator sideIter(magic , 7);
    }()
    );
}

TEST_CASE("check begin & end SideCrossIterator"){
   MagicalContainer magic  = MagicalContainer();
    magic.addElement(5);
    magic.addElement(36);
    magic.addElement(13);
    magic.addElement(12);
    magic.addElement(4);
    magic.addElement(21);
    MagicalContainer::SideCrossIterator sideIter(magic);
    CHECK (sideIter.backwardPosition == 6-1);
    CHECK (sideIter.forwardPosition == 0);
    magic.removeElement(12);
    CHECK(magic.size()==5);
    CHECK(sideIter.container.size() == magic.size());
    CHECK(sideIter.container.size() ==5);
    CHECK(*sideIter.PbackwardPosition == magic.elements[4]);
    
}

TEST_CASE("check ++ operator with iter.end() SideCrossIterator "){
    std::stringstream ss;
    MagicalContainer magic  = MagicalContainer();
    magic.addElement(5);
    magic.addElement(36);
    magic.addElement(13);
    magic.addElement(12);
    MagicalContainer::SideCrossIterator sicIter(magic);
    for (auto it = sicIter.begin(); it != sicIter.end(); ++it) {
        ss << *it << ' ';   // 5 12 36 13
    }
    CHECK(ss.str() == "5 12 36 13 ");
}

TEST_CASE("check comparing operators (==,>,<) SideCrossIterator"){
    
}

TEST_CASE("check assinment operator (=) SideCrossIterator "){
    
}

// check AscendingIterator
TEST_CASE("check constructors AscendingIterator "){
    
}
TEST_CASE("check begin & end AscendingIterator"){
    
}

TEST_CASE("check ++ operator AscendingIterator "){
    
}

TEST_CASE("check comparing operators (==,>,<) AscendingIterator"){
    
}

TEST_CASE("check assinment operator (=) AscendingIterator "){
    
}

// check PrimeIterator
TEST_CASE("check constructors PrimeIterator"){
    
}
TEST_CASE("check begin & end PrimeIterator"){
    
}

TEST_CASE("check ++ operator PrimeIterator "){
    
}

TEST_CASE("check comparing operators (==,>,<) PrimeIterator"){
    
}

TEST_CASE("check assinment operator (=) PrimeIterator "){
    
}


TEST_CASE(""){
    
}

TEST_CASE(""){
    
}

TEST_CASE(""){
    
}