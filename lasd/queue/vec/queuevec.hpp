#ifndef QUEUEVEC_HPP
#define QUEUEVEC_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueVec: public Queue<Data>, protected Vector<Data> {
    
private:
    
protected:
    using Vector<Data>::size;
    using Vector<Data>::Elements;
    unsigned long head = 0;
    unsigned long tail = 0;
    unsigned long length = 0;
    
public:
    
    // Default constructor
    QueueVec();
    
    /* ************************************************************************ */
    
    // Specific constructor
    QueueVec(const LinearContainer<Data>&);
    
    /* ************************************************************************ */
    
    // Copy constructor
    QueueVec(const QueueVec&);
    
    // Move constructor
    QueueVec(QueueVec&&) noexcept;
    
    /* ************************************************************************ */
    
    // Destructor
    virtual ~QueueVec();
    
    /* ************************************************************************ */
    
    // Copy assignment
    QueueVec& operator=(const QueueVec&);
    
    // Move assignment
    QueueVec& operator=(QueueVec&&) noexcept;
    
    /* ************************************************************************ */
    
    // Comparison operators
    bool operator==(const QueueVec&) const noexcept;
    inline bool operator!=(const QueueVec&) const noexcept;
    
    /* ************************************************************************ */
    
    // Specific member functions (inherited from Queue)
    
    void Enqueue(const Data&) override;
    void Enqueue(Data&&) noexcept override;
    
    Data& Head() override;
    
    void Dequeue() override;
    Data HeadNDequeue() override;
    
    /* ************************************************************************ */
    
    // Specific member functions (inherited from Container)
    
    bool Empty() const noexcept override;
    
    unsigned long Size() const noexcept override;
    
    void Clear() override;
    
protected:
    
    // Auxiliary member functions
    
    void Expand();
    void Reduce();
    void SwapVectors(unsigned long);
    
};

/* ************************************************************************** */

}

#include "queuevec.cpp"

#endif

