#pragma once

#include "utils.hpp"

namespace ft {
    template<typename Value, typename Compare>
    class bidirectional_iterator{
    public:
        typedef Value                                                                        value_type;
        typedef typename ft::iterator<ft::bidirectional_iterator_tag, Value>::iterator_category iterator_category;
        typedef typename ft::iterator<ft::bidirectional_iterator_tag, Value>::difference_type   difference_type;
        typedef typename ft::iterator<ft::bidirectional_iterator_tag, Value>::pointer           pointer;
        typedef typename ft::iterator<ft::bidirectional_iterator_tag, Value>::reference         reference;
    };
}

