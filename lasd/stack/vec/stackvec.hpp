#ifndef STACKVEC_HPP
#define STACKVEC_HPP

#include "../stack.hpp"
#include "../../vector/vector.hpp"

namespace lasd {

template <typename Data>
class StackVec : public Stack<Data>, protected Vector<Data>{
private:
    
protected:
    using Vector<Data>::size;
    using Vector<Data>::Elements;
    unsigned long index = 0;
    
public:
    // Default constructor
    StackVec();
    
    StackVec(const LinearContainer<Data>&);
    
    // Copy constructor
    StackVec(const StackVec&);
    
    // Move constructor
    StackVec(StackVec&&) noexcept;
    
    // Destructor
    ~StackVec();
    
    // Copy assignment
    StackVec& operator =(const StackVec&);
    
    // Move assignment
    StackVec& operator =(StackVec&&) noexcept;
    
    // Comparison operators
    bool operator ==(const StackVec&) const noexcept;
    bool operator !=(const StackVec&) const noexcept;
    
    // Specific member functions (inherited from Stack)
    Data& Top() override; // Override Stack member (might throw std::length_error)
    void Pop() override; // Override Stack member (might throw std::length_error)
    Data TopNPop() override; // Override Stack member (might throw std::length_error)
    void Push(const Data&) override; // Override Stack member
    void Push(Data&&) noexcept override; // Override Stack member
    
    // Specific member functions (inherited from Container)
    bool Empty() const noexcept override; // Override Container member
    unsigned long Size() const noexcept override; // Override Container member
    void Clear() override; // Override Container member
    
protected:
    void Expand(); // Accessory function
    void Reduce(); // Accessory function
    
};

#include "stackvec.cpp"

}

#endif
