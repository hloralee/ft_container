#ifndef PAIR_HPP
#define PAIR_HPP
namespace ft{
    template< class T1, class T2 >
    struct pair
    {
        typedef T1 first_type;
        typedef T2 second_type;
        T1 first;
        T2 second;
        pair() : first(), second() {}
        pair( const T1& x, const T2& y )
        {
            first = x;
            second = y;
        }
        template< class U1, class U2 >
        pair( const pair<U1, U2>& p ) : first(p.first), second(p.second) {}
        pair& operator=(const pair& other)
        {
//            if (*this == other)
//                return (*this);
//this->first = std::remove_const<T1>(other.first);
this->first = static_cast<T1>(other.first);
            this->second = static_cast<T2>(other.second);
//            this->first = other.first;
//            this->second = other.second;
            return *this;
        }
    };

    template< class T1, class T2 >
    pair<T1,T2> make_pair( T1 t, T2 u )
    {
        pair<T1, T2> p1(t, u);
        return p1;
    }
    template< class T1, class T2 >
    bool operator==( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
    {
        return (lhs.first == rhs.first && lhs.second == rhs.second);
    }
    template< class T1, class T2 >
    bool operator!=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
    {
        return (!(lhs == rhs));
    }
    template< class T1, class T2 >
    bool operator<( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
    {
        if (lhs.first < rhs.first)
            return true;
        else if (rhs.first < lhs.first)
            return false;
        else if (lhs.second < rhs.second)
            return true;
        else
            return false;
    }
    template< class T1, class T2 >
    bool operator<=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
    {
        return (!(rhs < lhs));
    }
    template< class T1, class T2 >
    bool operator>( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
    {
        return rhs < lhs;
    }
    template< class T1, class T2 >
    bool operator>=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
    {
        return (!(lhs < rhs));
    }

    template <bool is_integ, class T>
    struct integral_const
    {
        static const bool value = is_integ;
    };
    template <typename>
        struct type_of_integral : public integral_const<false, bool> {};
    template <>
        struct type_of_integral<bool> : public integral_const<true, bool> {};
    template <>
        struct type_of_integral<char> : public integral_const<true, char> {};
    template <>
        struct type_of_integral<signed char> : public integral_const<true, signed char> {};
    template <>
        struct type_of_integral<short int> : public integral_const<true, short int> {};
    template <>
        struct type_of_integral<long int> : public integral_const<true, long int> {};
    template <>
        struct type_of_integral<int> : public integral_const<true, int> {};
    template <>
        struct type_of_integral<unsigned int> : public integral_const<true, unsigned int> {};
    template <>
        struct type_of_integral<long long int> : public integral_const<true, long long int> {};
    template <>
        struct type_of_integral<unsigned long int> : public integral_const<true, unsigned long int> {};
    template <>
        struct type_of_integral<unsigned short int> : public integral_const<true, unsigned short int> {};
    template <>
        struct type_of_integral<unsigned long long int> : public integral_const<true, unsigned long long int> {};
    template <>
        struct type_of_integral<unsigned char> : public integral_const<true, unsigned char> {};

    template<class T>
    struct is_integral : public type_of_integral<T> {};
}
#endif // PAIR_HPP
