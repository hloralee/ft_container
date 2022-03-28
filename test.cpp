
# include "include/vector.hpp"
# include <iostream>
# include <vector>
# include <iterator>


int main() {
    {
        std::cout << "Standart vector\n";
        std::vector<int> b(10, 1);
        std::cout << "Size is " << b.size() << "\n";
        std::cout << "Capacity is " << b.capacity() << "\n";
        std::vector<int>::iterator bg = b.begin();
        std::vector<int>::iterator ed = b.end();

        while (bg != ed)
            std::cout << *bg++ << "\n";
       b.reserve(12);
        b.insert(b.begin()+2, 3, 5);
        std::cout << "Empty is " << b.empty() << "\n";
        std::cout << "Size is " << b.size() << "\n";
        std::cout << "Capacity is " << b.capacity() << "\n";
        std::vector<int>::iterator beg = b.begin();
        std::vector<int>::iterator end = b.end();

        while (beg != end)
            std::cout << *beg++ << "\n";
    }
    std::cout << "MY vector\n";
    ft::vector<int> b(10, 1);
    std::cout << "Size is " << b.size() << "\n";
    std::cout << "Capacity is " << b.capacity() << "\n";
    ft::vector<int>::iterator bg = b.begin();
    ft::vector<int>::iterator ed = b.end();

    while (bg != ed)
        std::cout << *bg++ << "\n";
   b.reserve(12);
    b.insert(b.begin()+2, 3, 5 );
    std::cout << "Empty is " << b.empty() << "\n";
    std::cout << "Size is " << b.size() << "\n";
    std::cout << "Capacity is " << b.capacity() << "\n";
    ft::vector<int>::iterator beg = b.begin();
    ft::vector<int>::iterator end = b.end();

    while (beg != end)
        std::cout << *beg++ << "\n";

}
