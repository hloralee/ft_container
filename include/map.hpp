# pragma once
#include <memory>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <cmath>
#include "utils/utils.hpp"
#include "utils/bidirectional_iterator.hpp"

namespace ft {
    template < class Key, class T, class Compare = ft::less<Key>,
            class Alloc = std::allocator<ft::pair<const Key,T> > >
    class map {
    public:
        typedef  Key                                                        key_type;
        typedef  T                                                          mapped_type;
        typedef  ft::pair<const key_type,mapped_type>                       value_type;
        typedef  Compare                                                    key_compare;
        typedef  Alloc                                                      allocator_type;
        typedef  typename allocator_type::reference                         reference;
        typedef  typename allocator_type::const_reference                   const_reference;
        typedef  typename allocator_type::pointer                           pointer;
        typedef  typename allocator_type::const_pointer                     const_pointer;
        typedef  ft::bidirectional_iterator<value_type, Compare>            iterator;
        typedef  ft::bidirectional_iterator<const value_type, Compare>      const_iterator;
        typedef  ft::reverse_iterator<iterator>                             reverse_iterator;
        typedef  ft::reverse_iterator<const_iterator>                       const_reverse_iterator;
        typedef  ptrdiff_t                                                  difference_type;
        typedef  size_t                                                     size_type;

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

        explicit map (const key_compare& comp = key_compare(),
                      const allocator_type& alloc = allocator_type()) :
                      _comp(comp), _alloc(alloc), _parent() {}

        template <class InputIterator>
        map (InputIterator first, InputIterator last,
             const key_compare& comp = key_compare(),
             const allocator_type& alloc = allocator_type(),
             typename ft::enable_if<!ft::is_integral<InputIterator>::value,
                     InputIterator>::type* = null_ptr) :
                _comp(comp), _alloc(alloc), _parent() {
//            insert(first, last);
        }

        map (const map& x) : _comp(x._comp), _alloc(x._alloc), _parent() {
            if (this == &x)
                return ;
//            insert(x.begin(), x.end());
        }

        ~map() {
//            clear();
        }

        map& operator= (const map& x) {
            if (this == &x)
                return *this;
//            clear();
//            insert(x.begin(), x.end());
            return *this;
        }

        iterator begin() {
            if (_parent.left == null_ptr)
                return _parent;
            tree tmp = _parent;
            while (tmp.left != null_ptr)
                tmp = tmp.left;
            return tmp.parent->left;
        }

        const_iterator begin() const {
            return begin();
        }

        iterator end() {
            if (_parent.right == null_ptr)
                return _parent;
            tree tmp = _parent;
            while (tmp.right != null_ptr)
                tmp = tmp.right;
            return tmp.parent->right;
        }

        const_iterator end() const {
            return end();
        }

        reverse_iterator rbegin() {
            return end();
        }

        const_reverse_iterator rbegin() const {
            return end();
        }

        reverse_iterator rend() {
            return begin();
        }

        const_reverse_iterator rend() const {
            return begin();
        }

        bool empty() const {
            return (_size == 0 ? true : false);
        }

        size_type size() const {
            return _size;
        }

        size_type   max_size() const {
            return (_alloc.max_size());
        }

        pair<iterator,bool> insert (const value_type& val) {

        }

        iterator insert (iterator position, const value_type& val) {

        }

        template <class InputIterator>
        void insert (InputIterator first, InputIterator last,
                     typename ft::enable_if<!ft::is_integral<InputIterator>::value,
                             InputIterator>::type* = null_ptr) {

        }
    private:
        typedef ft::Node<value_type>            tree;
        allocator_type                          _alloc;
        Compare                                 _comp;
        tree                                    _parent;
        size_type                               _size;
        std::allocator<tree>                    _allocNd;




    };
}