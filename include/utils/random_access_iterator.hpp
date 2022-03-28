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
                return *this;
            _point = other.get_pointer();
            return *this;
        };

        virtual ~random_access_iterator() {};

        pointer get_pointer() const {return _point;}

        pointer operator->() const {return _point;}
        reference operator*() const {return *_point;}
        random_access_iterator& operator++() {
            _point++;
            return *this;
        }

        random_access_iterator operator++(int) {
            random_access_iterator n(*this);
            _point++;
            return n;
        }
        random_access_iterator& operator--() {
            _point--;
            return *this;
        }

        random_access_iterator operator--(int) {
            random_access_iterator n(this);
            _point--;
            return n;
        }

        random_access_iterator& operator+(difference_type n) {
            _point += n;
            return *this;
        }

        random_access_iterator& operator-(difference_type n) {
            _point -= n;
            return *this;
        }

        difference_type operator-(const random_access_iterator& other) {
            return (this->get_pointer() - other.get_pointer());
        }

        random_access_iterator& operator+=(difference_type n) {
            _point += n;
            return *this;
        }

        random_access_iterator& operator-=(difference_type n) {
            _point -= n;
            return *this;
        }

        reference operator[](difference_type n) {
            return *(_point + n);
        }



    private:
        pointer  _point;

    };

    template<typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator==(const ft::random_access_iterator<T>& first,
            const ft::random_access_iterator<T>& last) {
        return (first.get_pointer() == last.get_pointer());
    }

    template<typename F, typename L>
    typename ft::random_access_iterator<F>::difference_type
    operator==(const ft::random_access_iterator<F>& first,
               const ft::random_access_iterator<L>& last) {
        return (first.get_pointer() == last.get_pointer()) ;
    }

    template<typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator!=(const ft::random_access_iterator<T>& first,
               const ft::random_access_iterator<T>& last) {
        return (first.get_pointer() != last.get_pointer()) ;
    }

    template<typename F, typename L>
    typename ft::random_access_iterator<F>::difference_type
    operator!=(const ft::random_access_iterator<F>& first,
               const ft::random_access_iterator<L>& last) {
        return (first.get_pointer() != last.get_pointer()) ;
    }

    template<typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator>(const ft::random_access_iterator<T>& first,
               const ft::random_access_iterator<T>& last) {
        return (first.get_pointer() > last.get_pointer()) ;
    }

    template<typename F, typename L>
    typename ft::random_access_iterator<F>::difference_type
    operator>(const ft::random_access_iterator<F>& first,
               const ft::random_access_iterator<L>& last) {
        return (first.get_pointer() > last.get_pointer()) ;
    }

    template<typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator<(const ft::random_access_iterator<T>& first,
               const ft::random_access_iterator<T>& last) {
        return (first.get_pointer() < last.get_pointer()) ;
    }

    template<typename F, typename L>
    typename ft::random_access_iterator<F>::difference_type
    operator<(const ft::random_access_iterator<F>& first,
               const ft::random_access_iterator<L>& last) {
        return (first.get_pointer() < last.get_pointer()) ;
    }

    template<typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator>=(const ft::random_access_iterator<T>& first,
               const ft::random_access_iterator<T>& last) {
        return (first.get_pointer() >= last.get_pointer()) ;
    }

    template<typename F, typename L>
    typename ft::random_access_iterator<F>::difference_type
    operator>=(const ft::random_access_iterator<F>& first,
               const ft::random_access_iterator<L>& last) {
        return (first.get_pointer() >= last.get_pointer()) ;
    }

    template<typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator<=(const ft::random_access_iterator<T>& first,
               const ft::random_access_iterator<T>& last) {
        return (first.get_pointer() <= last.get_pointer()) ;
    }

    template<typename F, typename L>
    typename ft::random_access_iterator<F>::difference_type
    operator<=(const ft::random_access_iterator<F>& first,
               const ft::random_access_iterator<L>& last) {
        return (first.get_pointer() <= last.get_pointer()) ;
    }


    template<typename T>
    typename ft::random_access_iterator<T>&
    operator+(typename ft::random_access_iterator<T>::difference_type n,
               const ft::random_access_iterator<T>& th) {
        th.get_pointer() += n;
        return *th ;
    }

    template<typename F, typename L>
    typename ft::random_access_iterator<F>::difference_type
    operator-(const ft::random_access_iterator<F>& first,
               const ft::random_access_iterator<L>& last) {
        return (last.get_pointer() - first.get_pointer()) ;
    }
};