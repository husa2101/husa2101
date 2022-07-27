#pragma once

#include <vector>

class linked_list {

public:
    /* CONSTRUCTORS and DESTRUCTOR: */
    linked_list();
    linked_list(const linked_list& src);
    ~linked_list();

    linked_list& operator = (const linked_list& rhs);

    // appaends elements from rhs
    linked_list& operator+=(const linked_list& rhs);

    //inserting elements
    void insert(double value, size_t pos);
    void push_front(double value);
    void push_back(double value);

    // accessing element
    double front() const;
    double back() const;
    double at(size_t pos) const;

    // removing elements
    void remove(size_t pos);
    double pop_front();
    double pop_back();

    // status
    size_t size() const;
    bool is_empthy() const;

    //output
    void print() const;
    void print_reverse() const; // fuction will validate wether revorselinke is created propoly or not. 

    private:
    struct node
    {
        node(double value);
        double value;
        node* Next;
        node* Prev;
    };

    node* head;
    node* tail;

};
