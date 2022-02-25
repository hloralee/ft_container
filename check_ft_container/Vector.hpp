#ifndef VECTOR_HPP
#define VECTOR_HPP

# include <limits>
# include <memory>
# include <stdexcept>
# include "Iterator.hpp"
#include <iostream>
#include "Pair.hpp"
# include "Const_Iter.hpp"
#include <cmath>
namespace ft{

template<class val, class Alloc = std::allocator<val> >
class Vector
{
    public:
        typedef size_t size_type;
        typedef val value_type;
        typedef ptrdiff_t difference_type;
        typedef Alloc allocator_type;
        typedef val& reference;
        typedef const value_type& const_reference;
        typedef typename Alloc::pointer pointer;
        typedef typename Alloc::const_pointer const_pointer;
        typedef ft::Iterator<val> iterator;
        typedef ft::ConstIterator<val> const_iterator;
        typedef ft::ReverseIterator<val> reverse_iterator;
        typedef ft::ConstReverseIterator<val> const_reverse_iterator;
        explicit Vector( const Alloc& alloc = Alloc() )
        {
            this->alloc = alloc;
            this->arr = this->alloc.allocate(0);
            length = 0;
            maxlen = 0;
        }
        explicit Vector( size_type count, const val& value = val(), const Alloc& alloc = Alloc())
        {
            this->alloc = alloc;
            this->arr = this->alloc.allocate(0);
            length = 0;
            maxlen = 0;
            this->assign(count, value);
        }
        template< class InputIt >
        Vector( InputIt first, InputIt last, const Alloc& alloc = Alloc(), typename ft::enable_if<!ft::is_integral<InputIt>::value >::type* = 0 )
        {
            this->alloc = alloc;
            this->arr = this->alloc.allocate(0);
            length = 0;
            maxlen = 0;
            this->assign(first, last);
        }
        ~Vector()
        {
            if (arr)
                this->clear();
            this->alloc.deallocate(arr, maxlen);
        }
        Vector(const Vector& other)
        {
            this->alloc = other.alloc;
            reallocate2(other.length, other.arr);
        }
        Vector& operator=(const Vector& other)
        {
            this->clear();
            this->alloc.deallocate(this->arr, this->maxlen);
            this->alloc = other.alloc;
//            this->arr = alloc.allocate(0);
            reallocate2(other.length, other.arr);
//            this->assign(other.begin(), other.end());
            return *this;
        }
        size_type size() const
        {
            return length;
        }
        size_type max_size() const
		{
//            if (sizeof(value_type) == 1)
//                return static_cast<size_type>(pow(2.0, 64.0) / 2.0) - 1;
//            return static_cast<size_type>(pow(2.0, 64.0) / static_cast<double>(sizeof(value_type))) - 1;
			return (std::numeric_limits<size_type>::max()/sizeof(value_type));
		}
		void reserve(const size_type len)
		{
            if (len > max_size())
                throw (std::length_error("max_size reached"));
            if (len > maxlen)
            {
                reallocate3(len);
            }
		}
        size_type capacity() const
		{
			return this->maxlen;
		}
        bool empty() const
		{
			return (!this->length);
		}
        reference operator[](size_type idx)
		{
//            if (idx > length || idx < 0)
//                return ();
			return arr[idx];
		}
		const_reference operator[](size_type idx) const
		{
//            if (idx > length || idx < 0)
//                return ();
			return arr[idx];
		}
		value_type *data()
		{
            if (length > 0)
                return arr;
            return NULL;
		}
        const value_type *data() const
		{
            if (length > 0)
                return arr;
            return NULL;
		}
        reference back()
		{
			return arr[length - 1];
		}

		const_reference back() const
		{
			return arr[length - 1];
		}
		reference front()
		{
			return *arr;
		}

		const_reference front() const
		{
			return *arr;
		}
        reference at(const size_type idx)
        {
            if(idx >= length)
                bad_index(idx);
            return arr[idx];
        }

        const_reference at(const size_type idx) const
        {
            if(idx >= length)
                bad_index(idx);
            return arr[idx];
        }
        allocator_type get_allocator() const
        {
            return alloc;
        }
        iterator begin()
        {
            return iterator(arr);
        }

        const_iterator begin() const
        {
            return const_iterator(arr);
        }

        iterator end()
        {
            return iterator(arr + length);
        }

        const_iterator end() const
        {
            return const_iterator(arr + length);
        }

        reverse_iterator rbegin()
        {
            return reverse_iterator(arr + length - 1);
        }

        reverse_iterator rend()
        {
            return reverse_iterator(arr - 1);
        }

        const_reverse_iterator rbegin() const
        {
            return const_reverse_iterator(arr + length - 1);
        }

        const_reverse_iterator rend() const
        {
            return const_reverse_iterator(arr - 1);
        }
        void push_back (const value_type& vali)
        {
            if (length + 1 > maxlen)
                reallocate3(!maxlen ? 1 : maxlen * 2);
            alloc.construct(&arr[length++], vali);
        }
        void pop_back()
		{
			if (length)
			    alloc.destroy(&arr[length-- - 1]);
		}
        void resize( size_type count, val value = val() )
        {
            if (arr == NULL)
                this->arr = this->alloc.allocate(0);
            if (count < maxlen)
            {
                if  (length > count)
                {
                    while  (length > count)
                        this->pop_back();

                }
                else
                {
                    while(length < count)
                    {
                        this->push_back(value);
                    }
                }
            }
            else{
                this->my_push_back(value, count);
            }
        }
        void swap(  Vector& other )
        {
            swap(arr, other.arr);
            swap(length, other.length);
            swap(maxlen, other.maxlen);
            swap(alloc, other.alloc);
        }
        iterator erase( iterator pos )
        {
            difference_type dif = distance(begin(), pos);
            moveElementsToTheLeft( dif);
            return iterator(arr + dif);
        }
        iterator erase( iterator first, iterator last )
        {
            while (first != last)
            {
                if (last == end())
                    last--;
                this->erase(last);
                last--;
            }
            this->erase(last);
            return last;
        }
        void clear()
        {
            resize(0);
        }
        iterator insert( iterator pos, const val& value )
        {
            if (pos < this->begin())
                bad_start(pos);
            else if(pos > this->end())
                bad_end(pos);
            size_type dis = distance(begin(), pos);
            reallocate(1, dis, value);
            return iterator(arr + dis);
        }
        void insert( iterator pos, size_type n, const val& value )
        {
            if (pos < this->begin())
                bad_start(pos);
            else if(pos > this->end())
                bad_end(pos);
            size_type dis = distance(begin(), pos);
            reallocate(n, dis, value);
        }
        template< class InputIt >
        void insert( iterator pos, InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value >::type* = 0)
        {
            if (first == last)
                return ;
            if (pos < this->begin())
                bad_start(pos);
            else if(pos > this->end())
                bad_end(pos);
            size_type dis = distance(begin(), pos);
            difference_type sz = last - first;
            reallocate(sz, dis, 0, first, last);

//			while (first != last)
//			{
//				pos = this->insert1(pos, *first);
//				pos++;
//				first++;
//			}
        }
        void assign( size_type count, const val& value )
        {
            this->clear();
            this->resize(count, value);
        }
        template< class InputIt >
        void assign( InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value >::type* = 0 )
        {
            this->clear();
			this->insert(this->begin(), first, last);
        }
    protected:

    private:
        allocator_type alloc;
        value_type *arr;
        size_type length;
        size_type maxlen;

        void bad_index(const size_type idx)
        {
            assert(idx < length);
            throw std::out_of_range("Error! Idx is more than Vector.Size\n");
        }
        void my_push_back(const value_type& el, const size_type cn)
        {
            if (cn <= maxlen * 2)
                reserve(maxlen * 2);
            else
                reserve(cn);
            while (length < cn)
            {
                arr[length] = el;
                length++;
            }
        }
        pointer my_resize(const size_type cn)
        {
            pointer mu = NULL;
            if (cn > maxlen)
                my_reserve(mu, maxlen * 2);
            else
                my_reserve(mu, maxlen);
            return mu;
        }
        pointer my_resize1(const size_type cn)
        {
            pointer mu = NULL;
            if (cn > maxlen)
                my_reserve(mu, cn);
            else
                my_reserve(mu, maxlen);
            return mu;
        }
        void my_reserve(pointer &mu, const size_type len)
        {
            if (len > max_size())
                throw (std::length_error("max_size reached"));
            mu = alloc.allocate(len);
            maxlen = len;
        }
        void my_pop_back()
        {
            size_type mi = length;
            while (mi > 0)
                alloc.destroy(&arr[mi-- - 1]);
        }
        template <typename U>
        void swap(U& a, U&b)
        {
            U tmp = a;
            a = b;
            b = tmp;
        }
        void bad_end(iterator adx)
        {
            assert(!(end() < adx));
            throw std::out_of_range("Error! Iterator is greater than end()\n");
        }

        void bad_start(iterator adx)
        {
            assert(!(begin() > adx));
            throw std::out_of_range("Error! Iterator is less than begin()\n");
        }
        size_type distance(iterator first, iterator last) {
            size_type dst = 0;
            for (;first != last; first++, dst++);
            return dst;
        };
        template< class InputIt >
                void reallocate(const size_type& count, const difference_type& dif,
                                const value_type& el=0, InputIt first=0, InputIt last=0, typename ft::enable_if<!ft::is_integral<InputIt>::value >::type* = 0)
                                {
                    //                size_type got = (maxlen > length + count) ? length :
                    //                pointer Buf = my_resize(length + count);
                    pointer Buf = NULL;
                    if (first != 0 && last != 0)
                        Buf = my_resize1(length + count);
                    else
                        Buf = my_resize(length + count);

                    for(size_type i = 0; i < length + count; ++i)
                    {
                        alloc.construct(&Buf[i], arr[i]);
                    }
                    my_pop_back();
                    alloc.deallocate(arr, maxlen);
                    //                std::cout << Buf[12] << "------------------";
                    for(pointer t = Buf + length + count - 1;t >= Buf + dif; --t)
                    {
                        if(count > 1)
                            *(t + 1) =*(t - count + 1);
                        else
                            *(t + 1) = *t;
                    }
                    for(pointer t = Buf + dif; t != Buf + dif + count; t++)
                    {
                        if(first == 0 && last == 0)
                            alloc.construct(t, el);
                        else
                        {
                            alloc.construct(t, *first);
                            *first++;
                        }

                    }
                    pointer kot = alloc.allocate(1);
                    alloc.construct(&kot[0], Buf[0]);
                    arr = Buf;
                    alloc.deallocate(kot, 1);
                    length += count;
                                }

        void reallocate(const size_type& count, const difference_type& dif,
                        const value_type& el=0, iterator first=0, iterator last=0)
            {
//                size_type got = (maxlen > length + count) ? length :
//                pointer Buf = my_resize(length + count);
pointer Buf = NULL;
if (first != 0 && last != 0)
                     Buf = my_resize1(length + count);
                else
                     Buf = my_resize(length + count);
                for(size_type i = 0; i < length + count; ++i)
                {
                    alloc.construct(&Buf[i], arr[i]);
                }
                my_pop_back();
                alloc.deallocate(arr, maxlen);
//                std::cout << Buf[12] << "------------------";
                for(pointer t = Buf + length + count - 1;t >= Buf + dif; --t)
                {
                    if(count > 1)
                        *(t + 1) =*(t - count + 1);
                    else
                        *(t + 1) = *t;
                }
                for(pointer t = Buf + dif; t != Buf + dif + count; t++)
                {
                    if(first == 0 && last == 0)
                        alloc.construct(t, el);
                    else
                        alloc.construct(t, *first++);
                }
                arr = Buf;
                length += count;
            }
            void moveElementsToTheLeft(const difference_type& dif)
            {
//                pointer h;
                pointer buf = alloc.allocate(length - dif - 1);
                size_type u = dif + 1;
                int i = 0;
                while (u < length)
                {
                    alloc.construct(&buf[i], arr[u]);
                    u++;
                    i++;
                }
                u = dif;
                size_type io = u;
                while(u < length)
                {
//                    h[0] = arr[u];
                    alloc.destroy(&arr[u++]);
                }
                int y = 0;
                while(io < length - 1)
                {
//                    h[0] = buf[y];
//                    h[0] = arr[io];
                    alloc.construct(&arr[io], buf[y]);
                    io++;
                    y++;
                }
                length--;
                alloc.deallocate(buf, i);

            }
            void reallocate2(const size_type& count, const pointer other)
            {
                pointer buf = alloc.allocate(count);
                size_type i = 0;
                while(i < count)
                {
                    alloc.construct(&buf[i], other[i]);
                    i++;
                }
                arr = buf;
                length = maxlen = count;
            }
            void reallocate3(const size_type& count)
            {
                pointer buf = alloc.allocate(count);
                size_type i = 0;
                while(i < length)
                {
                    alloc.construct(&buf[i], arr[i]);
                    i++;
                }
                my_pop_back();
                alloc.deallocate(arr, maxlen);
                arr = buf;
                maxlen = count;
            }


};
    template< class T, class Alloc >
    bool operator==( const ft::Vector<T,Alloc>& lhs, const ft::Vector<T,Alloc>& rhs )
    {
        if (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()))
            return true;
        return false;
    }

    template< class T, class Alloc >
    bool operator!=( const ft::Vector<T,Alloc>& lhs, const ft::Vector<T,Alloc>& rhs )
    {
        return (!(lhs == rhs));
    }

    template< class T, class Alloc >
    bool operator<( const ft::Vector<T,Alloc>& lhs, const ft::Vector<T,Alloc>& rhs )
    {
        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

    template< class T, class Alloc >
    bool operator<=( const ft::Vector<T,Alloc>& lhs, const ft::Vector<T,Alloc>& rhs )
    {
        return (!(rhs < lhs));
    }

    template< class T, class Alloc >
    bool operator>( const ft::Vector<T,Alloc>& lhs, const ft::Vector<T,Alloc>& rhs )
    {
        return rhs < lhs;
    }
    template< class T, class Alloc >
    bool operator>=( const ft::Vector<T,Alloc>& lhs, const ft::Vector<T,Alloc>& rhs )
    {
        return (!(lhs < rhs));
    }
    template< class T, class Alloc >
    void swap( ft::Vector<T,Alloc>& lhs, ft::Vector<T,Alloc>& rhs )
    {
        lhs.swap(rhs);
    }

}
#endif // VECTOR_HPP
