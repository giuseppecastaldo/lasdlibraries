#ifndef QUEUEVEC_HPP
#define QUEUEVEC_HPP

#include "../queue.hpp"
#include "../../vector/vector.hpp"

namespace lasd {

template <typename Data>
class QueueVec : public Queue<Data>, protected Vector<Data>{
private:
    
protected:
    using Vector<Data>::size;
    using Vector<Data>::Elements;
    unsigned long top = 0;
    unsigned long back = 0;
    unsigned long lunghezza = 0;
    
public:
    // Default constructor
    QueueVec();
    
    // Copy constructor
    QueueVec(const QueueVec&);
    
    QueueVec(const LinearContainer<Data>&);
    
    // Move constructor
    QueueVec(QueueVec&&) noexcept;
    
    // Destructor
    ~QueueVec();
    
    // Copy assignment
    QueueVec& operator =(const QueueVec&);
    
    // Move assignment
    QueueVec& operator =(QueueVec&&) noexcept;
    
    // Comparison operators
    bool operator ==(const QueueVec&) const noexcept;
    bool operator !=(const QueueVec&) const noexcept;
    
    // Specific member functions (inherited from Queue)
    Data& Head() override; // Override Queue member (might throw std::length_error)
    void Dequeue() override; // Override Queue member (might throw std::length_error)
    Data HeadNDequeue() override ; // Override Queue member (might throw std::length_error)
    void Enqueue(const Data&) override; // Override Queue member
    void Enqueue(Data&&) noexcept override; // Override Queue member
    
    // Specific member functions (inherited from Container)
    bool Empty() const noexcept override; // Override Container member
    unsigned long Size() const noexcept override; // Override Container member
    void Clear() override; // Override Container member
    
protected:
    void Expand(); // Accessory function
    void Reduce(); // Accessory function

};

#include "queuevec.cpp"

}

#endif
