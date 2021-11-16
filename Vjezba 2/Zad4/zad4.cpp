#include "vector.hpp"

using namespace std;

int main() {
    int init = 10;
    MyVector mv{};
    mv.vector_new(init);

    int m;
    cout << "Unesi element, -999 za kraj unosa" << endl;
    while (m != -999) {
        cin >> m;
        if (m != -999)
            mv.vector_push_back(m);
    }

    cout << "first element " << mv.vector_front() << endl;
    cout << "last element " << mv.vector_back() << endl;
    mv.print_vector();

    cout << "removing last element" << endl;
    mv.vector_pop_back();
    mv.print_vector();

    cout << "size " << mv.vector_size() << endl;
    cout << "capacity " << mv.capacity << endl;

    mv.vector_delete();
}
