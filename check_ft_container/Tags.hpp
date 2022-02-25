#ifndef TAGS_HPP_INCLUDED
#define TAGS_HPP_INCLUDED

# include <cstddef>

namespace ft{

    struct input_iterator_tag { };
    struct output_iterator_tag { };
    struct forward_iterator_tag : public input_iterator_tag { };
    struct bidirectional_iterator_tag : public forward_iterator_tag { };
    struct random_access_iterator_tag : public bidirectional_iterator_tag { };

    template<bool B, class T = void>
    struct enable_if {};

    template<class T>
    struct enable_if<true, T> { typedef T type; };

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

    template<class InputIt1, class InputIt2>
    bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
    {
        while (first1 != last1)
        {
            if (!(*first1 == *first2))
                return false;
            ++first1;
            ++first2;
        }
        return true;
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
    template <class C, class T, class D = std::ptrdiff_t, class Pt = T*, class Rt = T&>
    struct aiterator{
        typedef   C iterator_category;
        typedef  T value_type;
        typedef  D difference_type;
        typedef  Pt pointer;
        typedef  Rt reference;
    };
}
#endif // TAGS_HPP_INCLUDED
