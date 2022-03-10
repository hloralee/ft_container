//
// Created by Luci Atkins on 9/5/21.
//

#ifndef VECTOR_CONST_ITER_HPP
#define VECTOR_CONST_ITER_HPP
#include "Iterator.hpp"
#include "Tags.hpp"
namespace ft{
    template <typename T>
    class ConstIterator{
    public:
        typedef typename iterator_traits<const T*>::iterator_category iterator_category;
        typedef typename iterator_traits<const T*>::value_type value_type;
        typedef typename iterator_traits<const T*>::difference_type difference_type;
        typedef typename iterator_traits<const T*>::pointer pointer;
        typedef typename iterator_traits<const T*>::reference reference;
        ConstIterator() : iter(NULL) { }
        ~ConstIterator() {}
        ConstIterator(pointer iter)
        {
            this->iter = iter;
        }
        ConstIterator(const ConstIterator & other)
        {
            iter = other.getCell();
        }
        ConstIterator(const Iterator<T> & other)
        {
            iter = other.getCell();
        }
        ConstIterator& operator=(const Iterator<T>& other)
                {
            this->iter = other.getCell();
            return *this;
                }
                ConstIterator& operator=(const ConstIterator & other)
                        {
            this->iter = other.getCell();
            return *this;
                        }
                        pointer operator->() const
                        {
            return this->iter;
                        }
                        reference operator*() const
                        {
            return (*(this->iter));
                        }
                        ConstIterator &operator++()
                        {
            ++iter;
            return *this;
                        }
                        ConstIterator operator++(int)
                        {
            ConstIterator tmp(*this);
            this->operator++();
            return tmp;
                        }
                        ConstIterator &operator--()
                        {
            --iter;
            return *this;
                        }
                        ConstIterator operator--(int)
                        {
            ConstIterator tmp(*this);
            this->operator--();
            return tmp;
                        }
                        ConstIterator operator+=(const difference_type & idx)
                                {
            iter += idx;
            return *this;
                                }
                                ConstIterator operator-=(const difference_type & idx)
                                        {
            iter -= idx;
            return *this;
                                        }
                                        ConstIterator operator+(const  difference_type & idx)
                                        {

            return ConstIterator(iter + idx);
                                        }
//                                        ConstIterator operator+(const  size_t & idx)
//                                        {
//
//            return ConstIterator(iter + idx);
//                                        }
                                        difference_type operator+(const  ConstIterator & other)
                                        {

            return this->iter + other.iter;
                                        }
                                        ConstIterator operator-(const  difference_type & idx)
                                        {
            return ConstIterator(iter - idx);
                                        }
                                        difference_type operator-(const  ConstIterator & other)
                                        {
            return this->iter - other.iter;
                                        }
//                                        reference operator[](const size_t& idx)
//                                        {
//            return *(this->iter + idx);
//                                        }
                                        reference operator[](const difference_type & idx)
                                        {
            return *(this->iter + idx);
                                        }
                                        bool operator<(const ConstIterator &other)
                                        {
            return this->iter < other.iter;
                                        }
                                        bool operator>(const ConstIterator &other)
                                        {
            return this->iter > other.iter;
                                        }
                                        bool operator>=(const ConstIterator &other)
                                        {
            return this->iter >= other.iter;
                                        }
                                        bool operator<=(const ConstIterator &other)
                                        {
            return this->iter <= other.iter;
                                        }
                                        bool operator==(const ConstIterator &other)
                                        {
            return this->iter == other.iter;
                                        }
                                        bool operator!=(const ConstIterator &other)
                                        {
            return this->iter != other.iter;
                                        }
                                        pointer getCell() const
                                        {
            return iter;
                                        }
    protected:
        pointer iter;
    };
    template <class T>
            class ConstReverseIterator
                    {
                    public:
                        typedef typename iterator_traits<const T*>::iterator_category iterator_category;
                        typedef typename iterator_traits<const T*>::value_type value_type;
                        typedef typename iterator_traits<const T*>::difference_type difference_type;
                        typedef typename iterator_traits<const T*>::pointer pointer;
                        typedef typename iterator_traits<const T*>::reference reference;
                        ConstReverseIterator()
                        {
                            this->iter = NULL;
                        }
                        ~ConstReverseIterator() {}
                        ConstReverseIterator(pointer iter)
                        {
                            this->iter = iter;
                        }
                        ConstReverseIterator(const ConstReverseIterator& other)
                        {
                            this->iter = other.getCell();
                        }
                        ConstReverseIterator(const ReverseIterator<T> & other)
                        {
                            this->iter = other.getCell();
                        }
                        ConstReverseIterator& operator=(const ConstReverseIterator& other)
                                {
                            this->iter = other.getCell();
                            return *this;
                                }
                                ConstReverseIterator& operator=(const ReverseIterator<T> & other)
                                        {
                            this->iter = other.getCell();
                            return *this;
                                        }
                                        pointer operator->()
                                        {
                            return this->iter;
                                        }
                                        reference operator*()
                                        {
                            return (*(this->iter));
                                        }
                                        ConstReverseIterator &operator++()
                                        {
                            --iter;
                            return *this;
                                        }
                                        ConstReverseIterator operator++(int)
                                        {
                            ConstReverseIterator tmp(*this);
                            this->operator++();
                            return tmp;
                                        }
                                        ConstReverseIterator &operator--()
                                        {
                            ++iter;
                            return *this;
                                        }
                                        ConstReverseIterator operator--(int)
                                        {
                            ConstReverseIterator tmp(*this);
                            this->operator--();
                            return tmp;
                                        }
                                        ConstReverseIterator operator+=(const difference_type & idx)
                                                {
                            iter -= idx;
                            return *this;
                                                }
                                                ConstReverseIterator operator-=(const difference_type & idx)
                                                        {
                            iter += idx;
                            return *this;
                                                        }
                                                        ConstReverseIterator operator+(const  difference_type & idx)
                                                        {

                            return ConstReverseIterator(iter - idx);
                                                        }
//                                                        ConstReverseIterator operator+(const  size_t & idx)
//                                                        {
//
//                            return ConstReverseIterator(iter - idx);
//                                                        }
                                                        difference_type operator+(const  ConstReverseIterator & other)
                                                        {

                            return this->iter - other.iter;
                                                        }
                                                        ConstReverseIterator operator-(const  difference_type & idx)
                                                        {
                            return ConstReverseIterator(iter + idx);
                                                        }
                                                        difference_type operator-(const  ConstReverseIterator & other)
                                                        {
                            return this->iter + other.iter;
                                                        }
//                                                        reference operator[](const size_t & idx)
//                                                        {
//                            return *(this->iter + idx);
//                                                        }
                                                        reference operator[](const difference_type & idx)
                                                        {
                            return *(this->iter - idx);
                                                        }
                                                        bool operator<(const ConstReverseIterator& other)
                                                        {
                            return this->iter > other.iter;
                                                        }
                                                        bool operator>(const ConstReverseIterator& other)
                                                        {
                            return this->iter < other.iter;
                                                        }
                                                        bool operator>=(const ConstReverseIterator& other)
                                                        {
                            return this->iter <= other.iter;
                                                        }
                                                        bool operator<=(const ConstReverseIterator& other)
                                                        {
                            return this->iter >= other.iter;
                                                        }
                                                        bool operator==(const ConstReverseIterator& other)
                                                        {
                            return this->iter == other.iter;
                                                        }
                                                        bool operator!=(const ConstReverseIterator& other)
                                                        {
                            return this->iter != other.iter;
                                                        }
                                                        pointer getCell() const
                                                        {
                            return iter;
                                                        }

                    protected:
                        pointer iter;
                    };
}

#endif //VECTOR_CONST_ITER_H
