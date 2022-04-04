
# include "include/vector.hpp"
# include <iostream>
# include <vector>
# include <stack>
# include <iterator>
# include "include/stack.hpp"


int main() {
    {
        std::stack<float> p;
        std::stack<float> pic;
        float *begin;
        float *end;
        for (int i = 0; i <= 10; i++) {
                p.push(i);
            if (i < 10)
                pic.push(i);
            if (i == 9)
                begin = &(p.top()) - 9;
        }
        pic.push(7);
        std::cout << "Size pic is " << pic.size() << "\n";
        end = &(p.top()) + 1;
        if (p > pic)
            std::cout << "Yesyes\n";
        else
            std::cout << "nono\n";
        while (begin != end)
            std::cout << *begin++ << "\n";
        std::cout << p.size() << "\n\n";
    }

    ft::stack<float> p;
    ft::stack<float> pic;
    float *begin;
    float *end;
    for (int i = 0; i <= 10; i++) {
        p.push(i);
        if (i < 10)
            pic.push(i);
        if (i == 9)
            begin = &(p.top()) - 9;
    }
    pic.push(7);
    std::cout << "Size pic is " << pic.size() << "\n";
    end = &(p.top()) + 1;
    if (p > pic)
        std::cout << "Yesyes\n";
    else
        std::cout << "nono\n";
    while (begin != end)
        std::cout << *begin++ << "\n";
    std::cout << p.size() << "\n\n";
}