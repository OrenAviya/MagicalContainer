#pragma once
#include "stdlib.h"
#include "vector"
#include "iterator"
#include <iostream>

using namespace std;
namespace ariel
{
} // namespace ariel

using namespace ariel;

class MagicalContainer
{

public:
    vector<int> elements;

    // Default constructor
    MagicalContainer() {}

    // Copy constructor
    MagicalContainer(const MagicalContainer &other) : elements(other.elements) {}

    // Move constructor
    MagicalContainer(MagicalContainer &&other) noexcept : elements(std::move(other.elements)) {}

    // destructor - don't need to manually delete the elements
    // vector because it will be automatically destroyed when the MagicalContainer object goes out of scope
    // with the default vector destructor

    ~MagicalContainer() {}

    void addElement(int element);

    void removeElement(int element);

    size_t size() const;
    // assignment operator
    MagicalContainer &operator=(const MagicalContainer &other);

    // Move assignment operator
    MagicalContainer &operator=(MagicalContainer &&other) noexcept;

    std::vector<int>::iterator begin()
    {
        return elements.begin();
    }

    std::vector<int>::iterator end()
    {
        return elements.end();
    }

    class AscendingIterator
    {
    public:
        MagicalContainer *container;
        size_t currentPosition;

        // constructor
        AscendingIterator() : container(nullptr), currentPosition(0) {}
        AscendingIterator(MagicalContainer &container) : container(&container), currentPosition(0) {}

        AscendingIterator(MagicalContainer &container, size_t idx) : container(&container), currentPosition(idx)
        {
            if (idx > container.size())
            {
                throw std::out_of_range("Invalid index");
            }
        }

        // copy constructor
        AscendingIterator(const AscendingIterator &otherAI) : container(otherAI.container), currentPosition(otherAI.currentPosition) {}

        // move constructor
        AscendingIterator(AscendingIterator &otherAI) noexcept : container(otherAI.container), currentPosition(otherAI.currentPosition)
        {
            otherAI.currentPosition = 0;
        }

        bool operator==(const AscendingIterator &other) const;
        bool operator!=(const AscendingIterator &other) const;
        bool operator>(const AscendingIterator &other) const;
        bool operator<(const AscendingIterator &other) const;
        // Assignment operator
        AscendingIterator &operator=(const AscendingIterator &other);
        // Move Assignment operator
        // AscendingIterator &operator=(AscendingIterator &&otherAI) ;
        AscendingIterator &operator++();

        int operator*() const;

        AscendingIterator begin() const;

        AscendingIterator end() const;
    };

    //    // SideCrossIterator class
    class SideCrossIterator
    {
    public:
        MagicalContainer *container;
        std::vector<int>::iterator enditer;
        std::vector<int>::iterator startiter;
        size_t forwardPosition;
        size_t backwardPosition;

        bool forward;
        // Constructors
        SideCrossIterator() : container(nullptr), forwardPosition(0), backwardPosition(0)
        {
            startiter = container->elements.begin(); // Iterator pointing to the start of the container
            enditer = container->elements.end()-1;
        }
        SideCrossIterator(MagicalContainer &Ocontainer) : container(&Ocontainer), forwardPosition(0), backwardPosition(Ocontainer.size() - 1), forward(true)
        {
            
            startiter = container->begin(); // Iterator pointing to the start of the container
            enditer = container->end()-1;     // Iterator pointing to the end of the container
        }
        SideCrossIterator(MagicalContainer &Ocontainer, size_t idx) : container(&Ocontainer), forwardPosition(idx), backwardPosition(Ocontainer.size() - 1), forward(true)
        {
            if (idx > Ocontainer.size())
            {
                throw std::out_of_range("Invalid index");
            }
            startiter = container->elements.begin(); // Iterator pointing to the start of the container
            enditer = container->elements.end()-1;
        }
        // Copy constructor
        SideCrossIterator(const SideCrossIterator &other) : container(other.container), forwardPosition(other.forwardPosition), backwardPosition(other.container->size() - 1), forward(true) {}

        // Destructor (no additional cleanup needed)
        ~SideCrossIterator() {}

        // Assignment operator
        SideCrossIterator &operator=(const SideCrossIterator &other);
        // Equality comparison (operator==)
        bool operator==(const SideCrossIterator &other) const;
        // Inequality comparison (operator!=)
        bool operator!=(const SideCrossIterator &other) const;

        // GT, LT comparison (operator>, operator<)
        bool operator>(const SideCrossIterator &other) const;

        bool operator<(const SideCrossIterator &other) const;
        // Dereference operator (operator*)
        int operator*() const;

        MagicalContainer::SideCrossIterator &operator++();
        MagicalContainer::SideCrossIterator begin() const;

        MagicalContainer::SideCrossIterator end() const;
    };

    class PrimeIterator
    {
    public:
        MagicalContainer *container;
        size_t currentPosition;

        static bool isPrime(int number)
        {
            if (number <= 1)
            {
                return false;
            }
            for (int i = 2; i * i <= number; ++i)
            {
                if (number % i == 0)
                {
                    return false;
                }
            }
            return true;
        }
        // constructors:
        PrimeIterator() : container(nullptr), currentPosition(0) {}
        PrimeIterator(MagicalContainer &container) : container(&container) ,currentPosition(0){
            while (currentPosition < container.size() && !isPrime(container.elements[currentPosition]))
             {++currentPosition;}
        }
        PrimeIterator(MagicalContainer &container, size_t idx) : container(&container), currentPosition(idx)
        {
            if (idx > container.size())
            {
                throw std::out_of_range("Invalid index");
            }
        }
        // Copy constructor
        PrimeIterator(const PrimeIterator &otherPI) : container(otherPI.container), currentPosition(otherPI.currentPosition) {}

        // Destructor (no additional cleanup needed)
        ~PrimeIterator() {}

        // Assignment operator
        MagicalContainer::PrimeIterator &operator=(const PrimeIterator &other);

        // Equality comparison (operator==)
        bool operator==(const PrimeIterator &other) const;

        // Inequality comparison (operator!=)
        bool operator!=(const PrimeIterator &other) const;

        // GT, LT comparison (operator>, operator<)
        bool operator>(const PrimeIterator &other) const;

        bool operator<(const PrimeIterator &other) const;

        // Dereference operator (operator*)
        int operator*() const;

        // Pre-increment operator (operator++)
        // this function uniqe to each iterator. here, it is doing ++ until it reach to the next prime number
        // such that we will ignore the oters and the iterator will go over only on the primes.
        PrimeIterator &operator++();

        // begin(type): Returns the appropriate iterator pointing to the first prime element.
        PrimeIterator begin();

        // end(type): Returns the appropriate iterator pointing one position past the last element.
        PrimeIterator end();
    };
};