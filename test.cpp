
# include "include/vector.hpp"
# include <iostream>
# include <vector>
# include <iterator>


int main() {
    {
        std::cout << "Standart vector\n";
        std::vector<int> b;
        for (int i = 0; i < 10; i++)
            b.push_back(i);
        std::cout << "Max size is " << b.max_size() << "\n";
        std::cout << "Size is " << b.size() << "\n";
        std::cout << "Capacity is " << b.capacity() << "\n";
        std::vector<int>::iterator bg = b.begin();
        std::vector<int>::iterator ed = b.end();
        std::cout << *(bg + 5) << "\n";
        std::vector<int>::reverse_iterator red(bg);
        std::vector<int>::reverse_iterator rbg(red);
        if (rbg == red)
            std::cout << ed - bg  << "\n";
        else
            std::cout << "nonono\n";
        while (rbg != red)
            std::cout << *rbg++ << "\n";
    }

    std::cout << "MY vector\n";
    ft::vector<int> b;
    for (int i = 0; i < 10; i++)
        b.push_back(i);
    std::cout << "Max size is " << b.max_size() << "\n";
    std::cout << "Size is " << b.size() << "\n";
    std::cout << "Capacity is " << b.capacity() << "\n";
    ft::vector<int>::iterator bg = b.begin();
    ft::vector<int>::iterator ed = b.end();
    std::cout << *(bg + 5) << "\n";
    ft::vector<int>::reverse_iterator red(bg);
    ft::vector<int>::reverse_iterator rbg(red);
    if (rbg == red)
        std::cout << ed - bg  << "\n";
    else
        std::cout << "nonono\n";
    while (rbg != red)
        std::cout << *rbg++ << "\n";

}