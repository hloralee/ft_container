#pragma once

#include <memory>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <cmath>
#include "utils/utils.hpp"
#include "utils/random_access_iterator.hpp"

namespace ft {

    template < class T, class Alloc = std::allocator<T> >
    class vector {

    public:
        typedef T value_type;
        typedef Alloc allocator_type;
        typedef T & reference;
        typedef const T & const_reference;
        typedef T * pointer;
        typedef const T * const_pointer;
        typedef ft::random_access_iterator<T> iterator;
        typedef ft::random_access_iterator<const T> const_iterator;
        typedef std::reverse_iterator<iterator> reverse_iterator;
        typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;


        explicit vector(const allocator_type &alloc = allocator_type()) :
                _alloc(alloc), _size(0), _capacity(0), _buffer(_alloc.allocate(0)) {}

        explicit vector(size_type n, const value_type &val = value_type(),
                        const allocator_type &alloc = allocator_type()) :
                _alloc(alloc), _size(0), _capacity(0), _buffer(_alloc.allocate(0)) {
            assign(n, val);
        }

        template <class InputIterator>
        vector (InputIterator first, InputIterator last,
                const allocator_type& alloc = allocator_type(),
                typename ft::enable_if<!ft::is_integral<InputIterator>::value,
                InputIterator>::type* = null_ptr) :
                _alloc(alloc), _size(0), _capacity(0), _buffer(_alloc.allocate(0)){
            assign(first, last);
        }

        vector (const vector& x) :
        _alloc(x._alloc), _size(0), _capacity(0), _buffer(_alloc.allocate(0)){
            assign(x.begin(), x.end());
        }

        ~vector() {
            clear();
            _alloc.deallocate(_buffer, _capacity);
        }

        vector& operator=(const vector& x) {
            if (this == &x)
                return *this;
            assign(x.begin(), x.end());
            return *this;
        }

        iterator begin() {
            return (_buffer);
        }

        const_iterator begin() const {
            return (_buffer);
        }

        iterator end() {
            return (_buffer + _size);
        }

        const_iterator end() const {
            return (_buffer + _size);
        }

        reverse_iterator rbegin() {
            return (_buffer + _size);
        }

        const_reverse_iterator rbegin() const {
            return (_buffer + _size);
        }

        reverse_iterator rend() {
            return (_buffer);
        }

        const_reverse_iterator rend() const {
            return (_buffer);
        }

        void push_back(const value_type & val)
        {
            if (_size == _capacity){
                int new_capacity = (_size == 0) ? 1 : _size * 2;
                reserve(new_capacity);
            }
            _alloc.construct(_buffer + _size, val);
            _size++;
        }

        void clear() {
            while (_size)
                _alloc.destroy(_buffer + --_size);
        }

        template <class InputIterator>
        void assign (InputIterator first, InputIterator last,
                     typename ft::enable_if<!ft::is_integral<InputIterator>::value,
                     InputIterator>::type* = null_ptr) {
            difference_type n = last - first;
            if (n <= 0)
                return;
            clear();
            _size = n;
            if (n > _capacity) {
                _alloc.deallocate(_buffer, _capacity);
                _buffer = _alloc.allocate(n);
                _capacity = n;
            }
            while (n) {
                _alloc.construct(_buffer + _size - n, *first++);
                n--;
            }
        }

        void assign (size_type n, const value_type& val) {
            if (n <= 0)
                return;
            if (n > max_size())
                throw (std::length_error("max_size reached"));
            clear();
            _size = n;
            if (n > _capacity) {
                _alloc.deallocate(_buffer, _capacity);
                _buffer = _alloc.allocate(n);
                _capacity = n;
            }
            while (n > 0)
                _alloc.construct(_buffer + --n, val);
        }

        void reserve (size_type n) {
            if (n > max_size())
                throw (std::length_error("max_size reached"));
            else if (n > _capacity) {
                pointer beg = _buffer;

                _buffer = _alloc.allocate(n);
                size_type len = 0;
                while (len < _size) {
                    _alloc.construct(_buffer + len, *(beg + len));
                    len++;
                }
                _alloc.deallocate(beg, _capacity);
                _capacity = n;
            }
        }

        size_type   max_size() const {
            return (_alloc.max_size());
        }

        size_type capacity() const {
            return _capacity;
        }

        size_type size() const {
            return _size;
        }

        bool empty() const {
            return (_size == 0 ? true : false);
        }

        void resize (size_type n, value_type val = value_type()) {
            if (n < _size) {
                while (_size != n)
                    _alloc.destroy(_buffer + --_size);
            }
            else if (n > _capacity) {
                size_type nw = (n > _capacity * 2) ? n : _capacity * 2;
                reserve(nw);
                while (_size != n) {
                    _alloc.construct(_buffer + _size++, val);
                }
            }
        }

        void pop_back() {
            _alloc.destroy(_buffer + --_size);
        }

        iterator insert (iterator position, const value_type& val) {
            difference_type n = &(*position) - _buffer;
            insert(position, 1, val);
            return (_buffer + n);
        }

        void insert (iterator position, size_type n, const value_type& val) {
            pointer tmp = _alloc.allocate(n);
            size_type nw = n;
            while (nw)
                _alloc.construct(tmp + --nw, val);
            insert(position, tmp, tmp + n);
            _alloc.deallocate(tmp, n);
        }

        template <class InputIterator>
        void insert (iterator position, InputIterator first, InputIterator last,
                     typename ft::enable_if<!ft::is_integral<InputIterator>::value,
                             InputIterator>::type* = null_ptr) {
            difference_type dif = &(*position) - _buffer;
            difference_type n = last - first;
            if (_size + n > _capacity) {
                size_type nw = (_size + n > _capacity * 2) ? _size + n : _capacity * 2;
                pointer tmp = _buffer;
                _buffer = _alloc.allocate(nw);
                _size += n;
                for (int i = 0; i < _size; i++) {
                    if (i >= dif && i < dif + n)
                        _alloc.construct(_buffer + i, *first++);
                    else if (i >= _size - n)
                        _alloc.construct(_buffer + i, *(tmp + i - n));
                    else
                        _alloc.construct(_buffer + i, *(tmp + i));
                }
                _alloc.deallocate(tmp, _capacity);
                _capacity = nw;
            }
            else {
                for (int i = _size + n; i >= dif + n; i--)
                    _alloc.construct(_buffer + i, *(_buffer + i - n));
                for (int i = dif; i < dif + n; i ++)
                    _alloc.construct(_buffer + i, *first++);
                _size += n;
            }
        }
    private:
        size_t _size;
        size_t _capacity;
        allocator_type _alloc;
        value_type *_buffer;

    };
}