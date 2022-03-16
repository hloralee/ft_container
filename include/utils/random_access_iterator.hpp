# pragma once

#include "utils.hpp"

namespace  ft {
    template <typename T>
    class random_access_iterator : ft::iterator<ft::random_access_iterator_tag, T>
    {
    public:
        typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category iterator_category;
        typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type        value_type;
        typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type   difference_type;
        typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer           pointer;
        typedef typename ft::iterator<ft::random_access_iterator_tag, T>:: reference        reference;

        random_access_iterator(void) : _point(null_ptr) {};
        random_access_iterator(const random_access_iterator &other) : _point(other.get_pointer()) {};
        random_access_iterator(pointer point) : _point(point) {};

        random_access_iterator& operator=(const random_access_iterator& other){
            if (this == other)
                return ;
            _point = other.get_pointer();
            return *this;
        };

        virtual ~random_access_iterator() {};

        pointer get_pointer() const {return _point;}

        pointer operator->() const {return _point;}
        pointer operator*() const {return *(this->_point);}
        random_access_iterator& operator++() {
            _point++;
            return *this;
        }

        random_access_iterator& operator++(int) {
            random_access_iterator new(*this);
            _point++;
            return *new;
        }
        random_access_iterator& operator--() {
            _point--;
            return *this;
        }

        random_access_iterator& operator--(int) {
            random_access_iterator new(*this);
            _point--;
            return *this;
        }

        random_access_iterator& operator+(const difference_type& n) {
            _point += n;
            return *this;
        }

        random_access_iterator& operator-(const difference_type& n) {
            _point -= n;
            return *this;
        }

        random_access_iterator& operator+=(const difference_type& n) {
            _point += n;
            return *this;
        }

        random_access_iterator& operator-=(const difference_type& n) {
            _point -= n;
            return *this;
        }

        reference operator[](const difference_type& n) {
            return *(_point + n);
        }



    private:
        pointer  _point;

    };

};