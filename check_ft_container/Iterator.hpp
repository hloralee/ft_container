#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include "Tags.hpp"

namespace ft{
    template <class T>
        class ConstIterator;
    template <class T>
        class ConstReverseIterator;
    template <class T>
    class Iterator{
    public:
        typedef typename iterator_traits<T*>::iterator_category iterator_category;
        typedef typename iterator_traits<T*>::value_type value_type;
        typedef typename iterator_traits<T*>::difference_type difference_type;
        typedef typename iterator_traits<T*>::pointer pointer;
        typedef typename iterator_traits<T*>::reference reference;
        Iterator() : iter(NULL) { }
        ~Iterator() {}
        Iterator(pointer iter)
        {
            this->iter = iter;
        }
        Iterator(const Iterator & other)
        {
            iter = other.getCell();
        }
        Iterator(const ConstIterator<T> & other)
        {
            iter = other.getCell();
        }
        Iterator& operator=(const Iterator& other)
        {
            this->iter = other.getCell();
            return *this;
        }
        Iterator& operator=(const ConstIterator<T> & other)
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
        Iterator &operator++()
        {
            ++iter;
            return *this;
        }
        Iterator operator++(int)
        {
            Iterator tmp(*this);
            this->operator++();
            return tmp;
        }
        Iterator &operator--()
        {
            --iter;
            return *this;
        }
        Iterator operator--(int)
        {
            Iterator tmp(*this);
            this->operator--();
            return tmp;
        }
        Iterator operator+=(const difference_type & idx)
        {
            iter += idx;
            return *this;
        }
        Iterator operator-=(const difference_type & idx)
        {
            iter -= idx;
            return *this;
        }
        Iterator operator+(const  difference_type & idx)
        {

            return Iterator(iter + idx);
        }
//        Iterator operator+(const  size_t & idx)
//        {
//
//            return Iterator(iter + idx);
//        }
        difference_type operator+(const  Iterator & other)
        {

            return this->iter + other.iter;
        }
        Iterator operator-(const  difference_type & idx)
        {
            return Iterator(iter - idx);
        }
        difference_type operator-(const  Iterator & other)
        {
            return this->iter - other.iter;
        }
//        reference operator[](const size_t& idx)
//        {
//            return *(this->iter + idx);
//        }
        reference operator[](const difference_type & idx)
        {
            return *(this->iter + idx);
        }
        bool operator<(const Iterator&other)
        {
            return this->iter < other.iter;
        }
        bool operator>(const Iterator&other)
        {
            return this->iter > other.iter;
        }
        bool operator>=(const Iterator&other)
        {
            return this->iter >= other.iter;
        }
        bool operator<=(const Iterator&other)
        {
            return this->iter <= other.iter;
        }
        bool operator==(const Iterator&other)
        {
            return this->iter == other.iter;
        }
        bool operator!=(const Iterator&other)
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
class ReverseIterator
{
    public:
    typedef typename iterator_traits<T*>::iterator_category iterator_category;
    typedef typename iterator_traits<T*>::value_type value_type;
    typedef typename iterator_traits<T*>::difference_type difference_type;
    typedef typename iterator_traits<T*>::pointer pointer;
    typedef typename iterator_traits<T*>::reference reference;
		ReverseIterator()
        {
            this->iter = NULL;
        }
        ~ReverseIterator() {}
        ReverseIterator(pointer iter)
        {
            this->iter = iter;
        }
        ReverseIterator(const ReverseIterator& other)
        {
            this->iter = other.getCell();
        }
        ReverseIterator(const ConstReverseIterator<T> & other)
        {
		    this->iter = other.getCell();
        }
        ReverseIterator& operator=(const ReverseIterator& other)
        {
		    this->iter = other.getCell();
            return *this;
        }
        ReverseIterator& operator=(const ConstReverseIterator<T> & other)
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
        ReverseIterator &operator++()
        {
		    --iter;
		    return *this;
        }
        ReverseIterator operator++(int)
        {
		    ReverseIterator tmp(*this);
		    this->operator++();
		    return tmp;
        }
        ReverseIterator &operator--()
        {
		    ++iter;
		    return *this;
        }
        ReverseIterator operator--(int)
        {
		    ReverseIterator tmp(*this);
		    this->operator--();
		    return tmp;
        }
        ReverseIterator operator+=(const difference_type & idx)
                {
		    iter -= idx;
		    return *this;
                }
            ReverseIterator operator-=(const difference_type & idx)
                    {
		    iter += idx;
		    return *this;
                    }
                    ReverseIterator operator+(const  difference_type & idx)
                        {

		    return ReverseIterator(iter - idx);
                        }
//                        ReverseIterator operator+(const  size_t & idx)
//                        {
//
//		    return ReverseIterator(iter - idx);
//                        }
                        difference_type operator+(const  ReverseIterator & other)
                        {

		    return this->iter - other.iter;
                        }
                        ReverseIterator operator-(const  difference_type & idx)
                        {
		    return ReverseIterator(iter + idx);
                        }
                        difference_type operator-(const  ReverseIterator & other)
                        {
		    return this->iter + other.iter;
                        }
//                        reference operator[](const size_t & idx)
//                        {
//		    return *(this->iter + idx);
//                        }
                        reference operator[](const difference_type & idx)
                        {
		    return *(this->iter - idx);
                        }
                        bool operator<(const ReverseIterator& other)
                        {
		    return this->iter > other.iter;
                        }
                        bool operator>(const ReverseIterator& other)
                        {
		    return this->iter < other.iter;
                        }
                        bool operator>=(const ReverseIterator& other)
                        {
		    return this->iter <= other.iter;
                        }
                        bool operator<=(const ReverseIterator& other)
                        {
		    return this->iter >= other.iter;
                        }
                        bool operator==(const ReverseIterator& other)
                        {
		    return this->iter == other.iter;
                        }
                        bool operator!=(const ReverseIterator& other)
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
#endif // ITERATOR_HPP
