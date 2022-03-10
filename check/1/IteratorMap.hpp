#ifndef ITERATORMAP_HPP
#define ITERATORMAP_HPP
#include "Tags.hpp"
#include "Pair.hpp"
namespace ft
{
    template<class key, class val>
    struct Node
    {
        ft::pair<key, val> p;
        int hei;
        Node *parent, *left, *right;
        Node(const ft::pair<key, val>& value = ft::pair<key, val>(), Node* parent = NULL, Node* left = NULL, Node* right = NULL) : p(value), parent(parent), left(left), right(right), hei(0) {}
        void setP(const ft::pair<key, val> io)  { p = io;}
    };

	template <class Key, class T, class Category = bidirectional_iterator_tag>
	class IteratorMap
	{
        public:
            typedef Node< Key, T>	*NodPtr;
            typedef size_t  size_type;
            typedef std::ptrdiff_t		difference_type;
            typedef ft::pair<Key, T>*	pointer;
            typedef ft::pair<Key, T>&	reference;
        IteratorMap()
        {
            tree = NULL;
        }
        virtual ~IteratorMap(){}
        IteratorMap(NodPtr iter)
        {
            this->tree = iter;
        }
        IteratorMap(const IteratorMap& other)
        {
            *this = other;
        }
        IteratorMap& operator=(const IteratorMap& other)
        {
            this->tree = other.getCell();
            return *this;
        }
        IteratorMap &operator++()
        {
            NodPtr next = tree;
            if (tree->hei == -666)
            {
                tree = tree->right;
                return *this;
            }
            while (tree->hei != -666 && !(next->p.first < tree->p.first))
            {
                if (tree->right && (tree->right->hei == -666 ||
                next->p.first < tree->right->p.first))
                {
                    tree = tree->right;
                    NodPtr tmp = NULL;
                if (tree->hei != -666 && (tmp = searchMinNode(tree)))
                    tree = tmp;
                }
                else
                    tree = tree->parent;
            }
            return *this;
        }
        IteratorMap operator++(int)
        {
            IteratorMap tmp(*this);
            this->operator++();
            return tmp;
        }
        IteratorMap &operator--()
        {
            NodPtr next = tree;
            if (tree->hei == -666)
            {
                tree = tree->left;
                return *this;
            }
            while (tree->hei != -666 && !(tree->p.first < next->p.first))
            {
                if (tree->left && (tree->left->hei == -666 ||
                tree->left->p.first < next->p.first))
                {
                    tree = tree->left;
                    NodPtr tmp = NULL;
                    if (tree->hei != -666 && (tmp = searchMaxNode(tree)))
                        tree = tmp;
                }
                else
                    tree = tree->parent;
            }
            return *this;
        }
        IteratorMap operator--(int)
        {
            IteratorMap tmp(*this);
            this->operator--();
            return tmp;
        }
        pointer operator->()
        {
            return (&this->tree->p);
        }
        reference operator*()
        {
            return this->tree->p;
        }
        bool operator==(const IteratorMap&other)
        {
            return this->tree == other.tree;
        }
        bool operator!=(const IteratorMap&other)
        {
            return this->tree != other.tree;
        }
        NodPtr getCell() const
        {
            return tree;
        }
    protected:
	    NodPtr searchMaxNode(NodPtr root)
	    {
            if (root && root->hei != -666 && root->right && root->right->hei != -666)
                return searchMaxNode(root->right);
            return root;
	    }
	    NodPtr searchMinNode(NodPtr root)
	    {
	        if (root && root->hei != -666 && root->left && root->left->hei != -666)
	            return searchMinNode(root->left);
	        return root;
	    }
	    NodPtr tree;
    };

    template <class Key, class T>
    class ConstIteratorMap : public IteratorMap<Key, T>
    {
    public:
        typedef Node< Key, T>	*NodPtr;
        typedef size_t  size_type;
        typedef std::ptrdiff_t		difference_type;
        typedef const ft::pair<Key, T>*	pointer;
        typedef const ft::pair<Key, T>&	reference;
        ConstIteratorMap()
        {
            this->tree = NULL;
        }
        ~ConstIteratorMap() {}
        ConstIteratorMap(NodPtr iter)
        {
            this->tree = iter;
        }
        ConstIteratorMap(const ConstIteratorMap& other)
        {
            *this = other;
        }
        ConstIteratorMap(const IteratorMap<Key, T>& other)
        {
            *this = other;
        }
        ConstIteratorMap& operator=(const ConstIteratorMap& other)
        {
            this->tree = other.getCell();
//            this->tree = std::remove_const<ConstIteratorMap>(other);
            return *this;
        }
        ConstIteratorMap &operator=(const IteratorMap<Key, T> &other)
                {
            this->tree = other.getCell();
            return (*this);
                }
        reference operator*()
        {
            return this->tree->p;
        }
        pointer operator->()
        {
            return (&this->tree->p);
        }
    };
    template <class Key, class T>
	class RevIteratorMap : public IteratorMap<Key, T>
	{
        public:
	    typedef Node< Key, T>	*NodPtr;
	    typedef size_t  size_type;
	    typedef std::ptrdiff_t		difference_type;
	    typedef ft::pair<Key, T>*	pointer;
	    typedef ft::pair<Key, T>&	reference;
        RevIteratorMap()
        {
            this->tree = NULL;
        }
        virtual ~RevIteratorMap() {}
        RevIteratorMap(NodPtr iter)
        {
            this->tree = iter;
        }
        RevIteratorMap(const RevIteratorMap& other)
        {
            *this = other;
        }
        RevIteratorMap& operator=(const RevIteratorMap& other)
        {
            this->tree = other.tree;
            return *this;
        }
        RevIteratorMap &operator++()
        {
            NodPtr next = this->tree;
            if (this->tree->hei == -666)
            {
                this->tree = this->tree->left;
                return *this;
            }
            while (this->tree->hei != -666 && !(this->tree->p.first < next->p.first))
            {
                if (this->tree->left && (this->tree->left->hei == -666 ||
                this->tree->left->p.first < next->p.first))
                {
                    this->tree = this->tree->left;
                    NodPtr tmp = NULL;
                    if (this->tree->hei != -666 && (tmp = this->searchMaxNode(this->tree)))
                        this->tree = tmp;
                }
                else
                    this->tree = this->tree->parent;
            }
            return *this;
        }
        RevIteratorMap operator++(int)
        {
            RevIteratorMap tmp(*this);
            this->operator++();
            return tmp;
        }
        RevIteratorMap &operator--()
        {
            NodPtr next = this->tree;
            if (this->tree->hei == -666)
            {
                this->tree = this->tree->right;
                return *this;
            }
            while (this->tree->hei != -666 && !(next->p.first < this->tree->p.first))
            {
                if (this->tree->right && (this->tree->right->hei == -666 ||
                next->p.first < this->tree->right->p.first))
                {
                    this->tree = this->tree->right;
                    NodPtr tmp = NULL;
                    if (this->tree->hei != -666 && (tmp = this->searchMinNode(this->tree)))
                        this->tree = tmp;
                }
                else
                    this->tree = this->tree->parent;
            }
            return *this;
        }
        NodPtr getCell() const
        {
            return this->tree;
        }
        RevIteratorMap operator--(int)
        {
            RevIteratorMap tmp(*this);
            this->operator--();
            return tmp;
        }
    };

    template <class Key, class T>
    class ConstRevIteratorMap : public RevIteratorMap<Key, T>
    {
    public:
        typedef Node< Key, T>	*NodPtr;
        typedef size_t  size_type;
        typedef std::ptrdiff_t		difference_type;
        typedef const ft::pair<Key, T>*	pointer;
        typedef const ft::pair<Key, T>&	reference;
        ConstRevIteratorMap()
        {
            this->tree = NULL;
        }
        ~ConstRevIteratorMap() {}
        ConstRevIteratorMap(NodPtr iter)
        {
            this->tree = iter;
        }
        ConstRevIteratorMap(const ConstRevIteratorMap& other)
        {
            *this = other;
        }
        ConstRevIteratorMap(const RevIteratorMap<Key, T>& other)
        {
            *this = other;
        }
        ConstRevIteratorMap& operator=(const ConstRevIteratorMap& other)
        {
            this->tree = other.getCell();
            return *this;
        }
        ConstRevIteratorMap& operator=(const RevIteratorMap<Key, T>& other)
                {
            this->tree = other.getCell();
            return (*this);
                }
                reference operator*()
                {
            return this->tree->p;
                }
                pointer operator->()
                {
            return (&this->tree->p);
                }
    };
}
#endif // ITERATORMAP_HPP_INCLUDED
