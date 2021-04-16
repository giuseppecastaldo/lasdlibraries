
#ifndef QUEUELST_HPP
#define QUEUELST_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueLst: public Queue<Data>, protected List<Data> {
    
private:
    
protected:
    
    using List<Data>::size;
    
public:
    
    // Default constructor
    QueueLst() = default;
    
    /* ************************************************************************ */
    
    // Specific constructor
    QueueLst(const LinearContainer<Data>&);
    
    /* ************************************************************************ */
    
    // Copy constructor
    QueueLst(const QueueLst&);
    
    // Move constructor
    QueueLst(QueueLst&&) noexcept;
    
    /* ************************************************************************ */
    
    // Destructor
    virtual ~QueueLst();
    
    /* ************************************************************************ */
    
    // Copy assignment
    QueueLst& operator = (const QueueLst&);
    
    // Move assignment
    QueueLst& operator = (QueueLst&&) noexcept;
    
    /* ************************************************************************ */
    
    // Comparison operators
    bool operator==(const QueueLst&) const noexcept;
    inline bool operator!=(const QueueLst&) const noexcept;
    
    /* ************************************************************************ */
    
    // Specific member functions (inherited from Queue)
    
    void Enqueue(const Data&) override;
    void Enqueue(Data&&) noexcept override;
    
    Data& Head() override;
    
    void Dequeue() override;
    Data HeadNDequeue() override;
    
    /* ************************************************************************ */
    
    // Specific member functions (inherited from Container)
    
    void Clear() override;
    
};

/* ************************************************************************** */

}

#include "queuelst.cpp"

#endif
