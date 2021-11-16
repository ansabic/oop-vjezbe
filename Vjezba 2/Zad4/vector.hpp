#include <cstddef>
#include <iostream>

struct MyVector {

    int *arr;
    int size, capacity;

    // member functions
    void vector_new(int sz = 0);

    void vector_delete() const;

    void vector_push_back(int n);/* adds a new element at the end of the vector */
    void vector_pop_back();/* removes the last element in the vector */
    int &vector_front() const;/* returns a reference to the first element in the vector*/
    int &vector_back() const; /* returns a reference to the last element in the vector */
    int vector_size() const; /* returns the number of the elements in the vector */

    void print_vector() const;
};

