# pragma once

# include <cstddef>
# include <limits>
# include <sstream>
# include <typeinfo>
# include <iostream>

static class
{
private:
    void operator&() const;
public:
    template<class T>
    operator T*() const { return (0); }
    template<class C, class T>
    operator T C::*() const { return (0); }
} null_ptr = {};

namespace ft {

    struct input_iterator_tag { };
    struct output_iterator_tag { };
    struct forward_iterator_tag { };
    struct bidirectional_iterator_tag { };
    struct random_access_iterator_tag { };

    template<bool B, class T = void>
    struct enable_if {};
    template<class T>
    struct enable_if<true, T>
    { typedef T type; };

    template <bool B, typename>
    struct is_integral_res{
        static const bool value = B;
    };

    template <typename T>
    struct is_integral : public is_integral_res<false, T> {};
    template <>
    struct is_integral<bool> : public is_integral_res<true, bool> {};
    template <>
    struct is_integral<char> : public is_integral_res<true, char> {};
    template <>
    struct is_integral<signed char> : public is_integral_res<true, signed char> {};
    template <>
    struct is_integral<short int> : public is_integral_res<true, short int> {};
    template <>
    struct is_integral<int> : public is_integral_res<true, int> {};
    template <>
    struct is_integral<long int> : public is_integral_res<true, long int> {};
    template <>
    struct is_integral<long long int> : public is_integral_res<true, long long int> {};
    template <>
    struct is_integral<unsigned char> : public is_integral_res<true, unsigned char> {};
    template <>
    struct is_integral<unsigned short int> : public is_integral_res<true, unsigned short int> {};
    template <>
    struct is_integral<unsigned int> : public is_integral_res<true, unsigned int> {};
    template <>
    struct is_integral<unsigned long int> : public is_integral_res<true, unsigned long int> {};
    template <>
    struct is_integral<unsigned long long int> : public is_integral_res<true, unsigned long long int> {};


    template<class InputIt1, class InputIt2>
    bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
    {
        while (first1 != last1 && first2 != last2)
        {
            if (*first1 < *first2)
                return true;
            if (*first2 < *first1)
                return false;
            ++first1;
            ++first2;
        }
        return (first1 == last1) && (first2 != last2);
    }

    template <class Iterator>
    struct iterator_traits
    {
        typedef typename Iterator::difference_type       difference_type;
        typedef typename Iterator::value_type            value_type;
        typedef typename Iterator::pointer               pointer;
        typedef typename Iterator::reference             reference;
        typedef typename Iterator::iterator_category     iterator_category;
    };
    template <class T>
    struct iterator_traits<T*>
    {
        typedef ptrdiff_t                       difference_type;
        typedef T                               value_type;
        typedef T*                              pointer;
        typedef T&                              reference;
        typedef ft::random_access_iterator_tag  iterator_category;
    };
    template <class T>
    struct iterator_traits<const T*>
    {
        typedef ptrdiff_t                       difference_type;
        typedef T                               value_type;
        typedef const T*                        pointer;
        typedef const T&                        reference;
        typedef ft::random_access_iterator_tag  iterator_category;
    };

    template <class C, class T, class D = std::ptrdiff_t, class Pt = T*, class Rf = T&>
    struct iterator{
        typedef  C  iterator_category;
        typedef  T  value_type;
        typedef  D  difference_type;
        typedef  Pt pointer;
        typedef  Rf reference;
    };
}