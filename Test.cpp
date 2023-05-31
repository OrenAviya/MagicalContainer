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
// this iterator suppose to represent a side-cross order *after sorting!*
    MagicalContainer::SideCrossIterator it(magic); // the first element 
    MagicalContainer::SideCrossIterator it1(magic , 1); //the second
    MagicalContainer::SideCrossIterator it2(magic , 2); // third
    MagicalContainer::SideCrossIterator it3(magic , 3); // ...
    MagicalContainer::SideCrossIterator it4(magic , 4); // the second from end .....
    MagicalContainer::SideCrossIterator it5(magic , 5); //the last element
    CHECK(*it == 4); 
    CHECK(*it1 == 5); 
    CHECK(*it2 == 12);
    CHECK(*it3 ==13);
    CHECK(*it4 == 21);
    CHECK(*it5 ==36);

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
    CHECK(sideIter.container->size() == magic.size());
    CHECK(sideIter.container->size() ==5);
    CHECK(*sideIter.PbackwardPosition == magic.elements[4]);
    
}

// check ++ operator with iter.end() SideCrossIterator ":
    TEST_CASE("with even size of container:"){
        std::stringstream ss;
        MagicalContainer magicEven  = MagicalContainer();
        magicEven.addElement(5);
        magicEven.addElement(36);
        magicEven.addElement(13);
        magicEven.addElement(12);
        MagicalContainer::SideCrossIterator sicIter(magicEven);
        for (auto it = sicIter.begin(); it != sicIter.end(); ++it) {
            ss << *it << ' ';   // 5 36 12 13
        }
        CHECK(ss.str() == "5 36 12 13 ");
        }
    TEST_CASE ("with odd size of container:"){
        std::stringstream ss1;
        MagicalContainer magicOdd  = MagicalContainer();
        magicOdd.addElement(5);
        magicOdd.addElement(36);
        magicOdd.addElement(13);
        
        MagicalContainer::SideCrossIterator sicIter2(magicOdd);
        for (auto it = sicIter2.begin(); it != sicIter2.end(); ++it) {
            ss1 << *it << ' ';   // 5 36 13
        }
        CHECK(ss1.str() == "5 36 13 ");
    }

TEST_CASE("check comparing operators (==,>,<) SideCrossIterator"){
    MagicalContainer magic  = MagicalContainer();
    magic.addElement(5);
    magic.addElement(36);
    magic.addElement(13);
    magic.addElement(12);
    //5 12 13 36 
    // iterator : 5 36 12 13
    //
    MagicalContainer::SideCrossIterator it1(magic); //5
    MagicalContainer::SideCrossIterator it2(magic , 1); //12
    MagicalContainer::SideCrossIterator it3(magic , 2); //13
    MagicalContainer::SideCrossIterator it4(magic , 3); //36
    
    CHECK(it2 < it3);
    // CHECK(it2 > it4);
    CHECK(it3 >it1);

    CHECK(it1 == it1);
    CHECK (it2 != it1);


}

TEST_CASE("check assinment operator (=) SideCrossIterator "){
    MagicalContainer magic  = MagicalContainer();
    magic.addElement(5);
    magic.addElement(36);
    MagicalContainer::SideCrossIterator it1(magic); //5
    MagicalContainer::SideCrossIterator it2(magic , 1); //36
    it1 = it2;

    CHECK (*it1 == 36);

}

// check AscendingIterator
TEST_CASE("check constructors AscendingIterator "){
    MagicalContainer magic  = MagicalContainer();
    magic.addElement(5);
    magic.addElement(36);
    magic.addElement(13);
    magic.addElement(12);
    magic.addElement(4);
    magic.addElement(21);
    CHECK_NOTHROW(MagicalContainer::AscendingIterator ascIter(magic));
    //begin index in the range of container size 
    CHECK_NOTHROW(MagicalContainer::AscendingIterator ascIter(magic , 5));
    // begin index out of range - bigger than container size
    CHECK_THROWS([&]() { MagicalContainer magic;
    magic.addElement(5);
    magic.addElement(36);
    MagicalContainer::AscendingIterator ascIter(magic , 7);
    }()
    );

}
TEST_CASE("check if the order is realy ascending in AscendingIterator"){
// this iterator suppose to represent an Ascending *after sorting!*
    MagicalContainer magic  = MagicalContainer();
    magic.addElement(5);
    magic.addElement(36);
    magic.addElement(13);
    magic.addElement(12);
    magic.addElement(4);
    magic.addElement(21);
    MagicalContainer::AscendingIterator it(magic); // the first element 
    MagicalContainer::AscendingIterator it1(magic , 1); //the second
    MagicalContainer::AscendingIterator it2(magic , 2); // third
    MagicalContainer::AscendingIterator it3(magic , 3); // ...
    MagicalContainer::AscendingIterator it4(magic , 4); // the second from end .....
    MagicalContainer::AscendingIterator it5(magic , 5); //the last element
    CHECK(*it == 4); 
    CHECK(*it1 == 5); 
    CHECK(*it2 == 12);
    CHECK(*it3 ==13);
    CHECK(*it4 == 21);
    CHECK(*it5 ==36);
}

TEST_CASE("check begin & end AscendingIterator"){
    MagicalContainer magic  = MagicalContainer();
    magic.addElement(5);
    magic.addElement(36);
    magic.addElement(13);
    magic.addElement(12);
    magic.addElement(4);
    magic.addElement(21);
    MagicalContainer::AscendingIterator acsIter(magic);
    CHECK (acsIter.currentPosition == 0);
    magic.removeElement(12);
    CHECK(magic.size()==5);
    CHECK(acsIter.container->size() == magic.size());
    CHECK(acsIter.container->size() ==5);
  
}

TEST_CASE("check ++ operator AscendingIterator "){
    std::stringstream ss;
    MagicalContainer magic  = MagicalContainer();
    magic.addElement(5);
    magic.addElement(36);
    magic.addElement(13);
    magic.addElement(12);
    MagicalContainer::AscendingIterator acsIter(magic);
    for (auto it = acsIter.begin(); it != acsIter.end() ; ++it) {
        ss<< *it << ' ';  // 5 12 13 36
    }
    CHECK (ss.str() == "5 12 13 36 ");

}

TEST_CASE("check comparing operators (==,>,<) AscendingIterator"){
    MagicalContainer magic  = MagicalContainer();
    magic.addElement(5);
    magic.addElement(36);
    magic.addElement(13);
    magic.addElement(12);
    //5 12 13 36 
    // iterator : 5 12 13 36
    //
    MagicalContainer::AscendingIterator it1(magic); //5
    MagicalContainer::AscendingIterator it2(magic , 1); //12
    MagicalContainer::AscendingIterator it3(magic , 2); //13
    MagicalContainer::AscendingIterator it4(magic , 3); //36
    
    CHECK(it2 < it3);
    CHECK(it2 < it4);
    CHECK(it3 >it1);

    CHECK(it1 == it1);
    CHECK (it2 != it1);
}

TEST_CASE("check assinment operator (=) AscendingIterator "){
    MagicalContainer magic  = MagicalContainer();
    magic.addElement(5);
    magic.addElement(36);
    MagicalContainer::AscendingIterator it1(magic); //5
    MagicalContainer::AscendingIterator it2(magic , 1); //36
    it1 = it2;

    CHECK (*it1 == 36);
}

// check PrimeIterator
TEST_CASE("check constructors PrimeIterator"){
    MagicalContainer magic  = MagicalContainer();
    magic.addElement(5);
    magic.addElement(36);
    magic.addElement(13);
    magic.addElement(12);
    magic.addElement(4);
    magic.addElement(21);
    CHECK_NOTHROW(MagicalContainer::PrimeIterator prmIter(magic));
    //begin index in the range of container size 
    CHECK_NOTHROW(MagicalContainer::PrimeIterator prmIter(magic , 5));
    // begin index out of range - bigger than container size
    CHECK_THROWS([&]() { MagicalContainer magic;
    magic.addElement(5);
    magic.addElement(36);
    MagicalContainer::PrimeIterator prmIter(magic , 7);
    }()
    );

}

TEST_CASE("check if there is only prime numbers in primeiterator"){
    MagicalContainer magic  = MagicalContainer();
    magic.addElement(5);
    magic.addElement(36);
    magic.addElement(13);
    magic.addElement(12);
    magic.addElement(4);
    magic.addElement(21);
    CHECK_NOTHROW(MagicalContainer::PrimeIterator prmIter(magic));
    MagicalContainer::PrimeIterator prmIter(magic);
    for (auto it = prmIter.begin(); it != prmIter.end() ; ++it) {
        bool isP = MagicalContainer::PrimeIterator::isPrime(*it);
        cout<<*it;
        CHECK(isP);  // 5 13
    }
}

TEST_CASE("check begin & end PrimeIterator"){
    MagicalContainer magic  = MagicalContainer();
    magic.addElement(5);
    magic.addElement(36);
    magic.addElement(13);
    magic.addElement(12);
    magic.addElement(4);
    magic.addElement(21);
    MagicalContainer::PrimeIterator prmIter(magic);

    CHECK (prmIter.currentPosition == 0);
    magic.removeElement(12);
    CHECK(magic.size()==5);

    CHECK(prmIter.container->size() == magic.size());
    CHECK(prmIter.container->size() ==5);
}

TEST_CASE("check ++ operator PrimeIterator "){
  std::stringstream ss;
    MagicalContainer magic  = MagicalContainer();
    magic.addElement(4);
    magic.addElement(5);
    magic.addElement(36);
    magic.addElement(13);
    magic.addElement(12);
    MagicalContainer::PrimeIterator prmIter(magic);
    for (auto it = prmIter.begin(); it != prmIter.end() ; ++it) {
        ss<< *it << ' ';  // 5 13
    }
    CHECK (ss.str() == "5 13 ");
  
}

TEST_CASE("check comparing operators (==,>,<) PrimeIterator"){
    MagicalContainer magic  = MagicalContainer();
    magic.addElement(5);
    magic.addElement(36);
    magic.addElement(13);
    magic.addElement(12);
    //5 12 13 36 
    // iterator : 5 12 13 36
    //
    MagicalContainer::PrimeIterator it1(magic); //5
    MagicalContainer::PrimeIterator it2(magic , 1); //12
    MagicalContainer::PrimeIterator it3(magic , 2); //13
    MagicalContainer::PrimeIterator it4(magic , 3); //36
    
    CHECK(it2 < it3);
    CHECK(it2 < it4);
    CHECK(it3 >it1);

    CHECK(it1 == it1);
    CHECK (it2 != it1);
}

TEST_CASE("check assinment operator (=) PrimeIterator "){
    MagicalContainer magic  = MagicalContainer();
    magic.addElement(5);
    magic.addElement(36);
    MagicalContainer::PrimeIterator it1(magic); //5
    MagicalContainer::PrimeIterator it2(magic , 1); //36
    it1 = it2;

    CHECK (*it1 == 36);
}

