
# include "include/vector.hpp"
# include <iostream>
# include <vector>
# include <iterator>


int main() {
    ft::vector<int> a;

    for (int i = 0; i < 10; i++){
        a.push_back(i);
        std::cout << "Size is " << a.size() << "\n";
        std::cout << "Capacity is " << a.capacity() << "\n";
    }

    ft::vector<int>::iterator beg = a.begin();
    ft::vector<int>::iterator end = a.end();

    while (beg != end)
        std::cout << *beg++ << "\n";


    ft::vector<int> b(a);
    ft::vector<int>::iterator bg = b.begin();
    ft::vector<int>::iterator ed = b.end();

    while (bg != ed)
        std::cout << *bg++ << "\n";


//    std::vector<int> a(10, 1);
//    std::vector<int>::iterator b = a.begin();
//    std::vector<int>::iterator e = a.end();
//
//    std::vector<int> nw(20, 1);
//
//    std::cout << "Size is " << nw.size() << "\n";
//    std::cout << "Capacity is " << nw.capacity() << "\n";
//
//    nw.clear();
//
//    std::cout << "Size is " << nw.size() << "\n";
//    std::cout << "Capacity is " << nw.capacity() << "\n";

   // a.reserve(10);
    //std::vector<int>::iterator b = a.begin();
    //std::vector<int>::iterator e = a.end();

    //std::cout << "Size is " << a.size() << "\n";
    //std::cout << "Capacity is " << a.capacity() << "\n";

    //while (b != e) {
    //    std::cout << e-b << ": " << *b++ << "\n";
}
