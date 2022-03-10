#ifndef STACK_HPP
#define STACK_HPP

# include <limits>
# include "Vector.hpp"
#include <iostream>

namespace ft{
    template <typename T, class Container = ft::Vector<T> >
    class Stack{
        public:
        typedef Container container_type;
        typedef typename container_type::value_type value_type;
        typedef typename container_type::size_type size_type;
        explicit Stack (const container_type& ctnr = container_type()) :
        c(ctnr) {}
        Stack( const Stack& other )
        {
            *this = other;
        }
        ~Stack() {}
        Stack& operator=( const Stack& other )
        {
            this->c = other.c;
            return *this;
        }
        value_type& top()
        {
            return c.back();
        }
        const value_type& top() const
        {
            return c.back();
        }
        bool empty() const
        {
            return c.empty();
        }
        size_type size() const
        {
            return c.size();
        }
        void push( const value_type& value )
        {
            c.push_back(value);
        }
        void pop()
        {
            c.pop_back();
        }
    friend bool operator==( const ft::Stack<T,Container>& lhs, const ft::Stack<T,Container>& rhs )
     {
         return lhs.c == rhs.c;
     }
    friend bool operator!=( const ft::Stack<T,Container>& lhs, const ft::Stack<T,Container>& rhs )
     {
         return lhs.c != rhs.c;
     }
    friend bool operator<( const ft::Stack<T,Container>& lhs, const ft::Stack<T,Container>& rhs )
     {
         return lhs.c < rhs.c;
     }
    friend bool operator<=( const ft::Stack<T,Container>& lhs, const ft::Stack<T,Container>& rhs )
     {
         return lhs.c <= rhs.c;
     }
    friend bool operator>( const ft::Stack<T,Container>& lhs, const ft::Stack<T,Container>& rhs )
     {
         return lhs.c > rhs.c;
     }
    friend bool operator>=( const ft::Stack<T,Container>& lhs, const ft::Stack<T,Container>& rhs )
     {
         return lhs.c >= rhs.c;
     }
        protected:
        Container c;

    };
    template< class T, class Container >
    bool operator==( const ft::Stack<T,Container>& lhs, const ft::Stack<T,Container>& rhs )
    {
        return lhs.c == rhs.c; 
    }
    template< class T, class Container >
    bool operator!=( const ft::Stack<T,Container>& lhs, const ft::Stack<T,Container>& rhs )
    {
        return lhs.c != rhs.c;
    }	
    template< class T, class Container >
    bool operator<( const ft::Stack<T,Container>& lhs, const ft::Stack<T,Container>& rhs )
    {
        return lhs.c < rhs.c;
    }
    template< class T, class Container >
    bool operator<=( const ft::Stack<T,Container>& lhs, const ft::Stack<T,Container>& rhs )
    {
        return lhs.c <= rhs.c;
    }	
    template< class T, class Container >
    bool operator>( const ft::Stack<T,Container>& lhs, const ft::Stack<T,Container>& rhs )
    {
        return lhs.c > rhs.c;
    }	
    template< class T, class Container >
    bool operator>=( const ft::Stack<T,Container>& lhs, const ft::Stack<T,Container>& rhs )
    {
        return lhs.c >= rhs.c;
    }
}
#endif // VECTOR_HPP