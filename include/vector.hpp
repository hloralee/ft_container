#pragma once

#include <memory>
#include <algorithm>
#include <iostream>
#include <stdexcept>

namespace ft {

    template < class T, class Alloc = std::allocator<T> >
    class vector {

    public:
        typedef T                                               value_type;
        typedef Alloc                                           allocator_type;
        typedef typename Alloc::reference                       reference;
        typedef typename Alloc::const_reference                 const_reference;
        typedef typename Alloc::pointer                         pointer;
        typedef typename Alloc::const_pointer                   const_pointer;
    private:
        size_t                                                  _size;
        size_t                                                  _capacity;
        allocator_type                                          _alloc;
        value_type *                                            _buffer;
};