# pragma once

#include "utils.hpp"

namespace  ft {
    template <typename T>
    class random_access_iterator
    {
    public:
        typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category iterator_category;
        typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type        value_type;
        typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type   difference_type;
        typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer           pointer;
        typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference         reference;

        random_access_iterator(void) : _point(null_ptr) {};
        random_access_iterator(const random_access_iterator &other) : _point(other.base()) {};
        random_access_iterator(pointer point) : _point(point) {};

        random_access_iterator& operator=(const random_access_iterator& other){
            if (this == &other)
                return *this;
            _point = other.base();
            return *this;
        };

        virtual ~random_access_iterator() {};

        pointer base() const {return _point;}

        pointer operator->() const {return _point;}
        reference operator*() const {return *_point;}
        random_access_iterator& operator++() {
            ++_point;
            return *this;
        }

        random_access_iterator operator++(int) {
            random_access_iterator n(*this);
            ++_point;
            return n;
        }
        random_access_iterator& operator--() {
            --_point;
            return *this;
        }

        random_access_iterator operator--(int) {
            random_access_iterator n(*this);
            --_point;
            return n;
        }

        random_access_iterator operator+(difference_type n) const {
            return (_point + n);
        }

        random_access_iterator operator-(difference_type n) const{
            return (_point - n);
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
        return (first.base() == last.base());
    }

    template<typename F, typename L>
    typename ft::random_access_iterator<F>::difference_type
    operator==(const ft::random_access_iterator<F>& first,
               const ft::random_access_iterator<L>& last) {
        return (first.base() == last.base()) ;
    }

    template<typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator!=(const ft::random_access_iterator<T>& first,
               const ft::random_access_iterator<T>& last) {
        return (first.base() != last.base()) ;
    }

    template<typename F, typename L>
    typename ft::random_access_iterator<F>::difference_type
    operator!=(const ft::random_access_iterator<F>& first,
               const ft::random_access_iterator<L>& last) {
        return (first.base() != last.base()) ;
    }

    template<typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator>(const ft::random_access_iterator<T>& first,
              const ft::random_access_iterator<T>& last) {
        return (first.base() > last.base()) ;
    }

    template<typename F, typename L>
    typename ft::random_access_iterator<F>::difference_type
    operator>(const ft::random_access_iterator<F>& first,
              const ft::random_access_iterator<L>& last) {
        return (first.base() > last.base()) ;
    }

    template<typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator<(const ft::random_access_iterator<T>& first,
              const ft::random_access_iterator<T>& last) {
        return (first.base() < last.base()) ;
    }

    template<typename F, typename L>
    typename ft::random_access_iterator<F>::difference_type
    operator<(const ft::random_access_iterator<F>& first,
              const ft::random_access_iterator<L>& last) {
        return (first.base() < last.base()) ;
    }

    template<typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator>=(const ft::random_access_iterator<T>& first,
               const ft::random_access_iterator<T>& last) {
        return (first.base() >= last.base()) ;
    }

    template<typename F, typename L>
    typename ft::random_access_iterator<F>::difference_type
    operator>=(const ft::random_access_iterator<F>& first,
               const ft::random_access_iterator<L>& last) {
        return (first.base() >= last.base()) ;
    }

    template<typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator<=(const ft::random_access_iterator<T>& first,
               const ft::random_access_iterator<T>& last) {
        return (first.base() <= last.base()) ;
    }

    template<typename F, typename L>
    typename ft::random_access_iterator<F>::difference_type
    operator<=(const ft::random_access_iterator<F>& first,
               const ft::random_access_iterator<L>& last) {
        return (first.base() <= last.base()) ;
    }


    template<typename T>
    typename ft::random_access_iterator<T>
    operator+(typename ft::random_access_iterator<T>::difference_type n,
              const ft::random_access_iterator<T>& th) {
        return (th.base() + n);
    }

    template<typename F>
    typename ft::random_access_iterator<F>::difference_type
    operator-(const ft::random_access_iterator<F>& first,
              const ft::random_access_iterator<F>& last) {
        return (first.base() - last.base()) ;
    }

    template<typename F, typename L>
    typename ft::random_access_iterator<F>::difference_type
    operator-(const ft::random_access_iterator<F>& first,
              const ft::random_access_iterator<L>& last) {
        return (first.base() - last.base()) ;
    }

    template <class Iterator>
    class reverse_iterator {
    public:
        typedef Iterator                                                    iterator_type;
        typedef typename ft::iterator_traits<Iterator>::iterator_category   iterator_category;
        typedef typename ft::iterator_traits<Iterator>::value_type          value_type;
        typedef typename ft::iterator_traits<Iterator>::difference_type     difference_type;
        typedef typename ft::iterator_traits<Iterator>::pointer             pointer;
        typedef typename iterator_traits<Iterator>::reference               reference;

        reverse_iterator() : _base(null_ptr) {};
        explicit reverse_iterator (iterator_type it) : _base(it) {}
        template <class Iter>
        reverse_iterator (const reverse_iterator<Iter>& rev_it) : _base(rev_it.base()) {};
        reverse_iterator(pointer point) : _base(point) {};

        reverse_iterator& operator=(const reverse_iterator& other){
            if (this == &other)
                return *this;
            _base = other.base();
            return *this;
        };

        virtual ~reverse_iterator() {};
        iterator_type base() const {
            return _base;
        }

        pointer operator->() const {
            return &(operator*());
        }

        reference operator*() const {
            return *(_base - 1);
        }

        reverse_iterator operator+(difference_type n) const {
            return (reverse_iterator(_base - n));
        }
        reverse_iterator& operator++() {
            --_base;
            return *this;
        }

        reverse_iterator  operator++(int){
            reverse_iterator tmp(*this);
            --_base;
            return tmp;
        }

        reverse_iterator& operator+=(difference_type n) {
            _base -= n;
            return *this;
        }

        reverse_iterator operator-(difference_type n) const{
            return (reverse_iterator(_base + n));
        }

        reverse_iterator& operator--(){
            ++_base;
            return *this;
        }

        reverse_iterator  operator--(int){
            reverse_iterator tmp(*this);
            ++_base;
            return tmp;
        }

        reverse_iterator& operator-=(difference_type n){
            _base += n;
            return *this;
        }

        reference operator[](difference_type n) const{
            return _base[n - 1];
        }

    private:
        iterator_type _base;
    };

    template<typename T>
    typename ft::reverse_iterator<T>::difference_type
    operator==(const ft::reverse_iterator<T>& first,
            const ft::reverse_iterator<T>& last) {
        return (first.base() == last.base());
    }

    template<typename F, typename L>
    typename ft::reverse_iterator<F>::difference_type
    operator==(const ft::reverse_iterator<F>& first,
               const ft::reverse_iterator<L>& last) {
        return (first.base() == last.base()) ;
    }

    template<typename T>
    typename ft::reverse_iterator<T>::difference_type
    operator!=(const ft::reverse_iterator<T>& first,
               const ft::reverse_iterator<T>& last) {
        return (first.base() != last.base()) ;
    }

    template<typename F, typename L>
    typename ft::reverse_iterator<F>::difference_type
    operator!=(const ft::reverse_iterator<F>& first,
               const ft::reverse_iterator<L>& last) {
        return (first.base() != last.base()) ;
    }

    template<typename T>
    typename ft::reverse_iterator<T>::difference_type
    operator>(const ft::reverse_iterator<T>& first,
               const ft::reverse_iterator<T>& last) {
        return (first.base() < last.base()) ;
    }

    template<typename F, typename L>
    typename ft::reverse_iterator<F>::difference_type
    operator>(const ft::reverse_iterator<F>& first,
               const ft::reverse_iterator<L>& last) {
        return (first.base() < last.base()) ;
    }

    template<typename T>
    typename ft::reverse_iterator<T>::difference_type
    operator<(const ft::reverse_iterator<T>& first,
               const ft::reverse_iterator<T>& last) {
        return (first.base() > last.base()) ;
    }

    template<typename F, typename L>
    typename ft::reverse_iterator<F>::difference_type
    operator<(const ft::reverse_iterator<F>& first,
               const ft::reverse_iterator<L>& last) {
        return (first.base() > last.base()) ;
    }

    template<typename T>
    typename ft::reverse_iterator<T>::difference_type
    operator>=(const ft::reverse_iterator<T>& first,
               const ft::reverse_iterator<T>& last) {
        return (first.base() <= last.base()) ;
    }

    template<typename F, typename L>
    typename ft::reverse_iterator<F>::difference_type
    operator>=(const ft::reverse_iterator<F>& first,
               const ft::reverse_iterator<L>& last) {
        return (first.base() <= last.base()) ;
    }

    template<typename T>
    typename ft::reverse_iterator<T>::difference_type
    operator<=(const ft::reverse_iterator<T>& first,
               const ft::reverse_iterator<T>& last) {
        return (first.base() >= last.base()) ;
    }

    template<typename F, typename L>
    typename ft::reverse_iterator<F>::difference_type
    operator<=(const ft::reverse_iterator<F>& first,
               const ft::reverse_iterator<L>& last) {
        return (first.base() >= last.base()) ;
    }


    template<typename T>
    typename ft::reverse_iterator<T>
    operator+(typename ft::reverse_iterator<T>::difference_type n,
               const ft::reverse_iterator<T>& th) {
        return (th + n);
    }

    template<typename F>
    typename ft::reverse_iterator<F>::difference_type
    operator-(const ft::reverse_iterator<F>& first,
              const ft::reverse_iterator<F>& last) {
        return (last.base() - first.base()) ;
    }

    template<typename F, typename L>
    typename ft::reverse_iterator<F>::difference_type
    operator-(const ft::reverse_iterator<F>& first,
               const ft::reverse_iterator<L>& last) {
        return (last.base() - first.base()) ;
    }
};