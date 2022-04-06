# pragma once
#include <memory>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <cmath>
# include "utils/utils.hpp"

namespace ft {
    template < class Key, class T, class Compare = ft::less<Key>,
            class Alloc = std::allocator<ft::pair<const Key,T> > >
    class map {
    public:
        typedef  Key                                                key_type;
        typedef  T                                                  mapped_type;
        typedef  ft::pair<const key_type,mapped_type>               value_type;
        typedef  Compare                                            key_compare;
        typedef  Alloc                                              allocator_type;
        typedef  typename allocator_type::reference                 reference;
        typedef  typename allocator_type::const_reference           const_reference;
        typedef  typename allocator_type::pointer                   pointer;
        typedef  typename allocator_type::const_pointer             const_pointer;
//        typedef  ft::bidirectional_iterator<const Key, T>           iterator;
//        typedef  ft::bidirectional_iterator<const Key, const T>     const_iterator;
//        typedef  reverse_iterator<iterator>                         reverse_iterator;
//        typedef  reverse_iterator<const_iterator>                   const_reverse_iterator;
        typedef  ptrdiff_t                                          difference_type;
        typedef  size_t                                             size_type;

        class value_compare {
            friend class map;
        protected:
            Compare comp;
            value_compare (Compare c) : comp(c) {}
        public:
            bool operator() (const value_type& x, const value_type& y) const
            {
                return comp(x.first, y.first);
            }
        };





    };
}