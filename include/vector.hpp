#pragma once

#include <memory>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include "utils/utils.hpp"
#include "utils/random_access_iterator.hpp"

namespace ft {

    template < class T, class Alloc = std::allocator<T> >
    class vector {

    public:
        typedef T                                                   value_type;
        typedef Alloc                                               allocator_type;
        typedef T&                                                  reference;
        typedef const T&                                            const_reference;
        typedef T*                                                  pointer;
        typedef const T*                                            const_pointer;
        typedef ft::random_access_iterator<T>                       iterator;
        typedef ft::random_access_iterator<const T>                 const_iterator;
        typedef ft::reverse_iterator<iterator>                      reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>                const_reverse_iterator;
        typedef size_t                                              size_type;
        typedef ptrdiff_t                                           difference_type;


        explicit vector(const allocator_type& alloc = allocator_type()) :
        _alloc(alloc), _size(0), _capacity(0), _buffer(_alloc.allocate(0))
        {}

        explicit vector (size_type n, const value_type& val = value_type(),
                         const allocator_type& alloc = allocator_type()) :
        _alloc(alloc), _size(0), _capacity(0), _buffer(_alloc.allocate(0))
        {
            this
        }
    }

    private:
        size_t                                                  _size;
        size_t                                                  _capacity;
        allocator_type                                          _alloc;
        value_type *                                            _buffer;
};