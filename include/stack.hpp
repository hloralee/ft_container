#pragma once

#include "vector.hpp"

namespace ft {
    template <class T, class Container = ft::vector<T> >
    class stack {
    public:
        typedef T           value_type;
        typedef Container   container_type;
        typedef size_t      size_type;

        explicit stack (const container_type& ctnr = container_type()) : c(ctnr) {}

        ~stack()
        {}

        bool empty() const {
            return (c.empty());
        }

        size_type size() const {
            return (c.size());
        }

        value_type& top() {
            return (c.back());
        }

        const value_type& top() const {
            return (c.back());
        }

        void push (const value_type& val) {
            return (c.push_back(val));
        }

        void pop() {
            return (c.pop_back());
        }


        template <class Tn, class ContainerN>
        friend bool operator== (const ft::stack<Tn, ContainerN>& lhs, const ft::stack<Tn, ContainerN>& rhs);
        template <class Tn, class ContainerN>
        friend bool operator!= (const ft::stack<Tn, ContainerN>& lhs, const ft::stack<Tn, ContainerN>& rhs);
        template <class Tn, class ContainerN>
        friend bool operator< (const ft::stack<Tn, ContainerN>& lhs, const ft::stack<Tn, ContainerN>& rhs);
        template <class Tn, class ContainerN>
        friend bool operator<= (const ft::stack<Tn, ContainerN>& lhs, const ft::stack<Tn, ContainerN>& rhs);
        template <class Tn, class ContainerN>
        friend bool operator> (const ft::stack<Tn, ContainerN>& lhs, const ft::stack<Tn, ContainerN>& rhs);
        template <class Tn, class ContainerN>
        friend bool operator>= (const ft::stack<Tn, ContainerN>& lhs, const ft::stack<Tn, ContainerN>& rhs);

    private:
        container_type c;
    };

    template <class T, class Container>
    bool operator==(const ft::stack<T,Container>& first, const ft::stack<T,Container>& last) {
        return (first.c == last.c);
    }

    template <class T, class Container>
    bool operator!=(const ft::stack<T,Container>& first, const ft::stack<T,Container>& last){
        return (first.c != last.c);
    }

    template <class T, class Container>
    bool operator<(const ft::stack<T,Container>& first, const ft::stack<T,Container>& last){
        return(first.c < last.c);
    }

    template <class T, class Container>
    bool operator<=(const ft::stack<T,Container>& first, const ft::stack<T,Container>& last){
        return(first.c <= last.c);
    }

    template <class T, class Container>
    bool operator>(const ft::stack<T,Container>& first, const ft::stack<T,Container>& last){
        return(first.c > last.c);
    }

    template <class T, class Container>
    bool operator>=(const ft::stack<T,Container>& first, const ft::stack<T,Container>& last){
        return(first.c >= last.c);
    }

    template <class T, class Container>
    void swap (ft::stack<T,Container>& x, stack<T,Container>& y) {
        noexcept(noexcept(x.swap(y)));
    }
}