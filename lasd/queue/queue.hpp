
#ifndef QUEUE_HPP
#define QUEUE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Queue: public virtual Container {
    
private:
    
protected:
    
public:
    
    // Destructor
    virtual ~Queue() = default;
    
    /* ************************************************************************ */
    
    // Copy assignment
    Queue& operator=(const Queue&) = delete;
    
    // Move assignment
    Queue& operator=(const Queue&&) noexcept = delete;
    
    /* ************************************************************************ */
    
    // Comparison operators
    bool operator==(const Queue&) const noexcept = delete;
    inline bool operator!=(const Queue&) const noexcept = delete;
    
    /* ************************************************************************ */
    
    // Specific member functions
    
    virtual void Enqueue(const Data&) = 0;
    virtual void Enqueue(Data&&) noexcept = 0;
    
    virtual Data& Head() = 0; // (concrete function must throw std::length_error when empty)
    
    virtual void Dequeue() = 0; // (concrete function must throw std::length_error when empty)
    virtual Data HeadNDequeue() = 0; // (concrete function must throw std::length_error when empty)
    
};

/* ************************************************************************** */

}

#endif
