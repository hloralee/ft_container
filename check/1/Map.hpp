#ifndef MAP_HPP
#define MAP_HPP

# include <limits>
# include <memory>
# include <functional>
# include <stdexcept>
# include "IteratorMap.hpp"
# include <iostream>

namespace ft{

template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator <pair < Key, T> > >
class Map
{
    public:
        typedef Key key_type;
        typedef T mapped_type;
        typedef ft::pair< Key, T> value_type;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
        typedef Compare key_compare;
        typedef Alloc allocator_type;
        typedef value_type& reference;
        typedef const value_type& const_reference;
        typedef typename Alloc::pointer pointer;
        typedef typename Alloc::const_pointer const_pointer;
        typedef ft::IteratorMap<Key, T> iterator;
        typedef ft::ConstIteratorMap<Key, T> const_iterator;
        typedef ft::RevIteratorMap<Key, T> reverse_iterator;
        typedef ft::ConstRevIteratorMap<Key, T> const_reverse_iterator;
        typedef ft::Node< Key, T> tree;

        class value_compare
        {
            friend class Map;
            public:
            typedef bool result_type;
            typedef value_type first_argument_type;
            typedef value_type second_argument_type;
            bool operator()( const value_type& lhs, const value_type& rhs ) const
            {
                return comp(lhs.first, rhs.first);
            }
            protected:
                Compare comp;
                value_compare( Compare c ) : comp(c) {}
        };
        //-------------------------
        explicit Map( const Compare& comp = key_compare(), const Alloc& alloc = Alloc() )
        {
            this->comp = comp;
            this->alloc = alloc;
            length = 0;

            last = creatTree(ft::pair<key_type, mapped_type>());
            root = last;
            last->left = last;
            last->right = last;
        }
        template< class InputIt >
        Map( InputIt first, InputIt last, const Compare& comp = Compare(), const Alloc& alloc = Alloc(),
             typename ft::enable_if<!ft::is_integral<InputIt>::value >::type* = 0)
        {
            this->comp = comp;
            this->alloc = alloc;
            length = 0;
            this->last = creatTree(ft::pair<key_type, mapped_type>());
            root = this->last;
            this->last->left = this->last;
            this->last->right = this->last;
            insert(first, last);
        }
        size_type size() const
        {
            return length;
        }
        size_type max_size() const
		{
			return (std::numeric_limits<size_type>::max()/sizeof(root));
		}
        bool empty() const
		{
			return (!this->length);
		}
        Map( const Map& other ) :root(NULL), length(0)
        {
            if (this == &other)
                return;
            *this = other;
        }
        ~Map()
        {
             this->clear();
            destroy_tree(last);
        }
        Map& operator=( const Map& other )
        {
            this->comp = comp;
            this->alloc = alloc;
            this->alNod = other.alNod;
            length = 0;
            this->last = creatTree(ft::pair<key_type, mapped_type>());
            root = this->last;
            this->last->left = this->last;
            this->last->right = this->last;
            const_iterator h1 = other.begin();
            const_iterator h2 = other.end();
            insert(h1, h2);
            return *this;
        }
        //------------------------
         iterator begin()
         {
              return iterator(last->right);
         }
         iterator end()
         {
            return iterator(last);
         }
         const_iterator begin() const
         {
            return const_iterator(last->right);
         }
         const_iterator end() const
         {
              return const_iterator(last);
         }
         reverse_iterator rbegin()
         {
              return reverse_iterator(last->left);
         }
         reverse_iterator rend()
         {
              return reverse_iterator(last);
         }
         const_reverse_iterator rbegin() const
         {
              return const_reverse_iterator(last->left);
         }
         const_reverse_iterator rend() const
         {
              return const_reverse_iterator(last);
         }
         allocator_type get_allocator() const
         {
             return this->alloc;
         }
         size_type count( const Key& key ) const
         {
            tree* tmp = method_search(root, key);

            return tmp ? true: false;
         }
        ft::pair<iterator, bool> insert( const value_type& value )
        {
            tree* bb = method_search(root, value.first);
            if (bb)
                return (ft::pair<iterator, bool>(iterator(bb), false));
            length++;
            return(ft::pair<iterator, bool>(iterator(Insert(root, value)), true));
        }

         iterator insert( iterator hint, const value_type& value )
         {
            if (comp(value.first, hint->first))
            {
                iterator prev(hint);
                --prev;
                while (prev != end() && prev->first >= value.first)
                {
                    --hint;
                    --prev;
                }
            }
            else if (comp(hint->first, value.first))
            {
                iterator next(hint);
                ++next;
                while (next != end() && next->first <= value.first)
                {
                    ++hint;
                    ++next;
                }
            }
            if (hint != end() && value.first == hint->first)
                return hint;
            ++length;
            return iterator(Insert(hint.getCell(), value));
         }

         template< class InputIt >
         void insert( InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value >::type* = 0 )
         {
             while (first != last)
             {
                 insert(*first);
                 first++;
             }
            
         }
		 iterator find( const Key& key )
		 {
            tree * buf = method_search(root, key);
            if (buf)
                return iterator(buf);
            return this->end();
		 }
         const_iterator find( const Key& key ) const
         {
            tree * buf = method_search(root, key);
            if (buf)
                return const_iterator(buf);
            return this->end();
         }
         T& operator[]( const Key& key )
		 {
//                std::cout << "grgrgr";
           value_type buf = ft::make_pair(key, mapped_type());
                iterator it = insert(buf).first;
             return ((*it).second);
		 }
         T& at( const Key& key )
         {
            iterator it = find(key);
            if (it == this->end())
                bad_index(1);
            return ((*it).second);
		 }
         const T& at( const Key& key ) const
         {
            const_iterator it = find(key);
            if (it == this->end())
                bad_index(1);
            return ((*it).second);
         }
         iterator lower_bound (const key_type& key) {
            iterator it = begin();
            for (iterator it1 = end(); it != it1 && comp(it->first, key); it++);
            return it;
        }

        const_iterator lower_bound(const key_type& key) const {
            const_iterator it = begin();
            for (iterator it1 = end(); it != it1 && comp(it->first, key); it++);
            return it;
        }

        iterator upper_bound(const key_type& key) {
            iterator it = lower_bound(key);
            if (it->first == key)
                ++it;
            return it;
        }

        const_iterator upper_bound(const key_type& key) const {
            const_iterator it = lower_bound(key);
            if (it->first == key)
                ++it;
            return it;
        }
        ft::pair<iterator,iterator> equal_range( const Key& key )
         {
            return ft::pair<iterator, iterator>(lower_bound(key), upper_bound(key));
         }
        ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const
        {
            return ft::pair<const_iterator, const_iterator>(lower_bound(key), upper_bound(key));
        }
        key_compare key_comp() const
        {
            return comp;
        }
        Map::value_compare value_comp() const
        {
            return value_compare(comp);
        }

        void swap( Map& other )
         {
            swap(root, other.root);
            swap(last, other.last);
            swap(length, other.length);
            swap(comp, other.comp);
            swap(alloc, other.alloc);
            swap(alNod, other.alNod);
         }
         void erase( iterator pos )
         {
            Remove(pos.getCell(), pos->first);
            length--;
         }
         void erase( iterator first, iterator last )
         {
            while (first != last)
            {
                erase(first);
                first++;
            }
         }
         size_type erase( const key_type& key )
         {
            size_type res = Remove(root, key);
            length -= res;
            return res;
         }

        void clear()
        {
            erase(this->begin(), this->end());
        }
    protected:

    private:
        allocator_type alloc;
        key_compare comp;
        tree *root;
        tree *last;
        size_type length;
        std::allocator<tree> alNod;

        void bad_index( size_type idx)
        {
//            assert(idx < length);
            idx = 0;
            throw std::out_of_range("key not found\n");
        }

        tree* creatTree(const value_type& par)
        {
            tree* nNode = alNod.allocate(1);

            this->alloc.construct(&nNode->p, par);
            nNode->parent = NULL;
            nNode->left = NULL;
            nNode->right = NULL;

            return nNode;
        }

        void destroy_tree(tree *rem)
        {
            this->alloc.destroy(&rem->p);
            alNod.deallocate(rem, 1);
        }
        template< class h>
        void swap(h& be, h& af)
        {
            h buf = be;
            be = af;
            af = buf;
        }
        tree* method_search(tree * pcur, key_type key) const
        {
            if (!pcur || pcur == last)
                return 0;
            if (!comp(pcur->p.first, key) && !comp(key, pcur->p.first))
                return pcur;

            if (comp(key, pcur->p.first) && pcur->left && pcur->left != last)
                return method_search(pcur->left, key);
            if (comp(pcur->p.first, key) && pcur->right && pcur->right != last)
                return method_search(pcur->right, key);

            return NULL;
        }
        tree* method_end(tree *buf)
        {
            tree* tmp = buf;
            for(;tmp && tmp->right; tmp = tmp->right);
            return tmp;
        }
        tree* method_begin(tree *buf)
        {
            tree* tmp = buf;
            for(;tmp && tmp->left; tmp = tmp->left);
            return tmp;
        }
         void RL_rotate(tree *pparent)
         {
            tree* subr = pparent->right;
            tree* subrl = subr->left;
            int bf = subrl->hei;

             right_rotate(pparent->right);
             left_rotate(pparent);
             if (bf == -1)
                 subr->hei = 1;
             else if (bf == 1)
                 pparent->hei = - 1;
         }
         void LR_rotate(tree *pparent)
         {
            tree* subl = pparent->left;
            tree* sublr = subl->right;
            int bf = sublr->hei;

            left_rotate(pparent->left);
            right_rotate(pparent);
            if (bf == -1)
                pparent->hei = 1;
            else if (bf == 1)
                subl->hei = - 1;
         }
         int Height(tree *p, int hri) {
            if (p == NULL || p == last)
                return hri - 1;
            int i = Height(p->left, hri + 1);
            int j = Height(p->right, hri + 1);
            return i > j ? i : j;
        }
        tree* LL_Rotation(tree *subRoot) {
            tree* temp = subRoot->left;
            subRoot->left = temp->right;
            if (subRoot->left != NULL)
                subRoot->left->parent = subRoot;
            temp->right = subRoot;
            tree *sparent = subRoot->parent;
            subRoot->parent = temp;
            temp->parent = sparent;
            if (sparent == NULL)
                return temp;
            else
            {
                if (sparent->left == subRoot)
                    sparent->left = temp;
                else
                    sparent->right = temp;
            }
            // После завершения операции вращения узел ветвления (ранее subRoot) изменился,
            // Итак, чтобы вернуть указатель нового узла ветвления для его родительского узла, чтобы обновить дочерний указатель
            return temp;
        }
        /// Вращение баланса RR (левое одинарное вращение)
        // Вставка в правое поддерево (R) правого дочернего (R) вызывает дисбаланс, и для достижения баланса необходимо повернуть влево один раз
        tree* RR_Rotation(tree *subRoot) {
            tree* temp = subRoot->right;
            subRoot->right = temp->left;
            if (subRoot->right != NULL)
                subRoot->right->parent = subRoot;
            temp->left = subRoot;
            tree *sparent = subRoot->parent;
            subRoot->parent = temp;
            temp->parent = sparent;
            if (sparent == NULL)
                return temp;
            else
            {
                if (sparent->left == subRoot)
                    sparent->left = temp;
                else
                    sparent->right = temp;
            }
            // После завершения операции вращения узел ветвления (ранее subRoot) изменился,
            // Итак, чтобы вернуть указатель нового узла ветвления для его родительского узла, чтобы обновить дочерний указатель
            return temp;
        }
        /// вращение баланса RL (сначала вправо, затем влево, двойное вращение)
        // Вставка в левое поддерево (L) правого потомка (R) приводит к дисбалансу, вам нужно сначала выполнить правое вращение (LL_Rotation) на правом потомке узла ветки,
        // Снова повернуть узел ветви влево (RR_Rotation)
        tree* RL_Rotation(tree *subRoot) {
            // После поворота правого дочернего узла LL subRoot обновляем указатель правого узла subRoot
            subRoot->right=LL_Rotation(subRoot->right);
            return RR_Rotation (subRoot); // Возвращаемся к новому узлу ветвления для родительского узла исходного узла ветвления, чтобы обновить дочерний указатель
        }
        /// Вращение баланса LR (сначала влево, а затем вправо, двойное вращение)
        // Вставка в правое поддерево (R) левого потомка (L) приводит к дисбалансу, вам нужно сначала выполнить левое вращение (RR_Rotation) левого потомка узла ветки,
        // Снова повернуть узел ветви вправо (LL_Rotation)
        tree* LR_Rotation(tree *subRoot) {
            // После поворота RR левого узла subRoot, обновляем указатель левого узла subRoot
            subRoot-> left = RR_Rotation(subRoot->left);
            return LL_Rotation (subRoot); // Возвращаемся к новому узлу ветвления для родительского узла исходного узла ветвления, чтобы обновить дочерний указатель
        }
        int BalanceFactor(tree *p) {
            if (!p)
                return 0;
            return Height(p->left, 1) - Height(p->right, 1);
        }

        /// Выполните операцию балансировки на узле (вызовите четыре разные операции вращения в соответствии с коэффициентом балансировки)
        tree* Balance(tree* subRoot) {
            int bf = BalanceFactor(subRoot);
            if (bf> 1) // Левое поддерево выше
                {
                if (BalanceFactor(subRoot->left) > 0)
                    // Коэффициент баланса левого дочернего узла> 0 означает, что новые узлы в основном находятся в левом поддереве, поэтому вызовите LL_Rotation
                    subRoot = LL_Rotation(subRoot);
                else
                    // Коэффициент баланса левого дочернего узла <0 означает, что новые узлы в основном находятся в правом поддереве, поэтому вызовите LR_Rotation
                    subRoot = LR_Rotation(subRoot);
                }
            else if (bf <-1) // Правое поддерево выше
                {
                if (BalanceFactor(subRoot->right) > 0)
                    // Коэффициент баланса правого дочернего узла> 0 означает, что новые узлы в основном находятся в левом поддереве, поэтому вызовите RL_Rotation
                    subRoot = RL_Rotation(subRoot);
                else
                    // Коэффициент баланса правого дочернего узла <0 означает, что новые узлы в основном находятся в правом поддереве, поэтому вызовите RR_Rotation
                    subRoot = RR_Rotation(subRoot);
                }
            // После балансировки узла ветвления, узел ветвления может быть обновлен, поэтому новый узел ветвления возвращается исходному родительскому узлу для обновления дочернего указателя
            return subRoot;
        }
        bool Remove(tree* subRoot, const key_type& key) {
            tree* balancTree = NULL;
            tree* tmp = method_search(subRoot, key);

            if (!tmp)
                return false;

            if (!tmp->parent)
            {
                if (tmp->left == last && tmp->right == last)
                {
                    root = last;
                    last->left = last;
                    last->right = last;
                }
                else if (tmp->left && tmp->right == last)
                {
                    balancTree = tmp->parent;
                    root = tmp->left;
                    tmp->left->parent = NULL;
                    last->left = tmp->left;
                    tmp->left->right = last;
                }
                else if (tmp->left == last && tmp->right)
                {
                    balancTree = tmp->parent;
                    root = tmp->right;
                    tmp->right->parent = NULL;
                    last->right = tmp->right;
                    tmp->right->left = last;
                } else{
                    tree* topTree = method_end(tmp->left);

                    this->alloc.destroy(&tmp->p);
                    this->alloc.construct(&tmp->p, topTree->p);

                    return Remove(tmp->left, topTree->p.first);
                }
            }
            else if ((!tmp->left || tmp->left == last) && (!tmp->right || tmp->right == last))
            {
                balancTree = tmp->parent;

                tree* conn = NULL;
                if (tmp->left == last || tmp->right == last)
                {
                    conn = last;
                    if (tmp->p.first <= tmp->parent->p.first)
                        last->right = tmp->parent;
                    else
                        last->left = tmp->parent;
                }
                if (tmp->p.first <= tmp->parent->p.first)
                    tmp->parent->left = conn;
                else
                    tmp->parent->right = conn;
            }
            else if ((tmp->left && tmp->left != last) && (!tmp->right || tmp->right == last))
            {
                balancTree = tmp->parent;
                if (tmp->p.first <= tmp->parent->p.first)
                    tmp->parent->left = tmp->left;
                else
                    tmp->parent->right = tmp->left;
                tmp->left->parent = tmp->parent;

                if (tmp->right == last)
                {
                    last->left = tmp->left;
                    tmp->left->right = last;
                }
            }
            else if ((!tmp->left || tmp->left == last) && tmp->right && tmp->right != last)
            {
                balancTree = tmp->parent;
                if (tmp->p.first <= tmp->parent->p.first)
                    tmp->parent->left = tmp->right;
                else
                    tmp->parent->right = tmp->right;
                tmp->right->parent = tmp->parent;

                if (tmp->left == last)
                {
                    last->right = tmp->right;
                    tmp->right->left = last;
                }
            } else{
                tree *conn = method_end(tmp->left);
                this->alloc.destroy(&tmp->p);
                this->alloc.construct(&tmp->p, conn->p);
                return Remove(tmp->left, conn->p.first);
            }
            root = Balance(root);
            destroy_tree(tmp);
            return true;
        }
        tree* Insert(tree* subRoot, const value_type& value) {
            if (root == last)
            {
                root = creatTree(value);
                root->left = last;
                root->right = last;
                last->left = root;
                last->right = root;
                return root;
            }
            if (subRoot->p.first == value.first)
                return NULL;
            if (comp(value.first, subRoot->p.first) && subRoot->left && subRoot->left != last)
                return Insert(subRoot->left, value);
            else if (comp(subRoot->p.first, value.first) && subRoot->right && subRoot->right != last)
                return Insert(subRoot->right, value);
            tree* pcur = creatTree(value);
            if (comp(pcur->p.first, subRoot->p.first) && !subRoot->left)
                subRoot->left = pcur;
            else if (comp(subRoot->p.first, pcur->p.first) && !subRoot->right)
                subRoot->right = pcur;
            else if (subRoot->left && comp(pcur->p.first, subRoot->p.first))
            {
                pcur->left = last;
                last->right = pcur;
                subRoot->left = pcur;
            }
            else if (subRoot->right && comp(subRoot->p.first, pcur->p.first))
            {
                pcur->right = last;
                last->left = pcur;
                subRoot->right = pcur;
            }
            pcur->parent = subRoot;
            root = Balance(root);
            last->hei = -666;
            return pcur;
        }
};
    template< class Key, class T, class Compare, class Alloc >
        bool operator==( const ft::Map<Key,T,Compare,Alloc>& lhs,
                const ft::Map<Key,T,Compare,Alloc>& rhs )
                {
                    return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
                }
    template< class Key, class T, class Compare, class Alloc >
            bool operator!=( const ft::Map<Key,T,Compare,Alloc>& lhs,
                    const ft::Map<Key,T,Compare,Alloc>& rhs )
                    {
                        return (!(lhs == rhs));
                    }
    template< class Key, class T, class Compare, class Alloc >
            bool operator<( const ft::Map<Key,T,Compare,Alloc>& lhs,
                    const ft::Map<Key,T,Compare,Alloc>& rhs )
                    {
                        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
                    }

    template< class Key, class T, class Compare, class Alloc >
            bool operator<=( const ft::Map<Key,T,Compare,Alloc>& lhs,
                    const ft::Map<Key,T,Compare,Alloc>& rhs )
                    {
                        return (!(lhs > rhs));
                    }

    template< class Key, class T, class Compare, class Alloc >
        bool operator>( const ft::Map<Key,T,Compare,Alloc>& lhs,
                        const ft::Map<Key,T,Compare,Alloc>& rhs )
                        {
                            return rhs < lhs;
                        }
    template< class Key, class T, class Compare, class Alloc >
        bool operator>=( const ft::Map<Key,T,Compare,Alloc>& lhs,
                const ft::Map<Key,T,Compare,Alloc>& rhs )
                {
            return (!(lhs < rhs));
                }
    template< class Key, class T, class Compare, class Alloc >
    void swap( ft::Map<Key,T,Compare,Alloc>& lhs, ft::Map<Key,T,Compare,Alloc>& rhs )
    {
        lhs.swap(rhs);
    }

}

#endif // MAP_HPP
