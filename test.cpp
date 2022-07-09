
# include "include/vector.hpp"
# include <iostream>
# include <vector>
# include <stack>
# include <map>
# include <iterator>
# include "include/stack.hpp"
# include "include/map.hpp"



int main() {
    ft::map<char, int> a;
    std::map<char, int> b;

    b.insert(std::pair<char, int>('a', 100));
    std::map<char, int>::iterator it = b.begin();
    std::cout << "is first argument" << it->first << "is second argument" <<
    it->second << "\n";
}