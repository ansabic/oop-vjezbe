#include "vector.hpp"

void MyVector::vector_new(int sz) {
    capacity = sz;
    size = 0;
    arr = new int[sz];
}

void MyVector::vector_delete() const {
    delete[] arr;
}

void MyVector::vector_push_back(int n) {
    int tempSize = size;
    size++;
    if (tempSize == capacity) {
        int *tempArray = new int[capacity * 2];
        for (int i = 0; i < tempSize; i++)
            tempArray[i] = arr[i];
        vector_delete();
        vector_new(capacity * 2);
        size = tempSize;
        for (int i = 0; i < tempSize; i++)
            arr[i] = tempArray[i];
        delete[] tempArray;
    }
    arr[tempSize] = n;

}

void MyVector::vector_pop_back() {
    size--;
}

int &MyVector::vector_front() const {
    return arr[0];
}

int &MyVector::vector_back() const {
    return arr[size - 1];
}

int MyVector::vector_size() const {
    return size;
}


void MyVector::print_vector() const {
    std::cout << size << std::endl;
    for (int i = 0; i < vector_size(); ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

