#include <iostream>

using namespace std;
// === MEGVALÓSÍTANDÓ ===

/**
 * Az osztálysablon neve my_tree.
 * A sablon paraméterezése:
 *   - T: a fapontokban tárolt adat típusa
 * A sablonpéldány a tree_base osztályból származik (amely rendelkezik default
 * konstruktorral). A beadott feladatban a tree_base osztályt nem kell (nem
 * szabad) megvalósítani!
 */
//template<class T>
//class my_tree : tree_base {
template<class T>
class my_tree {
private:
    /** Az fa pontjában tárolt adat változója. */
    T d;
    /** A szülőre mutató pointer. */
    my_tree<T>* p;
    /** A bal gyerekre mutató pointer. */
    my_tree<T>* left;
    /** A jobb gyerekre mutató pointer. */
    my_tree<T>* right;

public:
    // iterátor belső osztály, a megfelelő metódusokat meg kell valosítani
    class iterator {
    private:
        my_tree<T> *_p;  // az iterátor által hivatkozott elem.
        int length; // a fa elemeinek száma.
        friend class my_tree<T>;  // my_tree sablon friend definicioja, hogy elérje a privát konstruktort.
        iterator(my_tree<T> *p) : _p(get_first(*p)) {this->length = 0; set_length(*_p);}  // privát konstruktor, ami a megfelelő elemre állítja az iterátort.
        void set_length(my_tree<T> &n) {
            if (n.left != nullptr) {
                set_length(*n.left);
            }
            ++length;
            if (n.right != nullptr) {
                set_length(*n.right);
            }
        }
        my_tree<T>* get_first(my_tree<T> &n) {
            if (n.left != nullptr) {
                get_first(*n.left);
            }
            else {
                return &n;
            }
        }
    public:
        iterator() : _p(nullptr) {} // alapértelmezett konstruktor
        iterator(const iterator &it) : _p(it._p) {}  // copy konstruktor
        const T& operator*() {return _p->data();}  // dereferencia
        T* operator->() {return _p;}
        iterator& operator++() {++_p; return *this;}  // prefix iterátor léptető
        //iterator operator++(int) {iterator temp(*this); ++_p; return temp;}  // postfix iterátor léptető
        //bool operator==(const iterator &it) {return _p == it._p;}  // logikai egyenlőség
        //bool operator!=(const iterator &it) {return _p != it._p;}  // logikai különbözőség
    };

    /** Iterátor a fa inorder bejárás szerinti elsõ elemére. */
    iterator begin() {return iterator(this);}
    /** Iterátor a fa inorder bejárás szerinti utolsó eleme utáni elemre. */
    iterator end() {return iterator(nullptr);}

    /** A sablonpéldány rendelkezik default konstruktorral. */
    my_tree() {
        this->d = 0;
        this->p = nullptr;
        this->left = nullptr;
        this->right = nullptr;
    }
    /**
     * A sablonpéldány rendelkezik olyan konstruktorral, amely inicializálja a
     * fapontban tárolt adatot.
     */
    my_tree(const T &data) {
        this->d = data;
        this->p = nullptr;
        this->left = nullptr;
        this->right = nullptr;
    }
    /**
     * A sablonpéldány rendelkezik olyan konstruktorral, amely inicializálja a
     * fapontban tárolt adatot, továbbá a fapont bal- és jobb gyerekeit is meghatározza.
     */
    my_tree(const T &data, my_tree<T> *left, my_tree<T> *right) {
        this->d = data;
        this->p = nullptr;
        this->left = left;
        this->left->p = this;
        this->right = right;
        this->right->p = this;
    }
    /** A destruktor felszabadítja a teljes részfát. */
    ~my_tree() {
        if (this->left != nullptr) {
            delete this->left;
        }
        if (this->right != nullptr) {
            delete this->right;
        }
    }
    /** Hozzáférés a fapontban tárolt adathoz. */
    const T& data() const {
        return this->d;
    }

    /** A fapont szülõje. */
    my_tree<T>* parent() const {
        return this->p;
    }
    /** A fapont bal gyereke. */
    my_tree<T>* leftChild() const {
        return this->left;
    }
    /** A fapont jobb gyereke. */
    my_tree<T>* rightChild() const {
        return this->right;
    }
    /** Beállítja a fapont bal gyerekét. */
    void setLeftChild(my_tree<T> *left) {
        this->left = left;
        this->left->p = this;
    }
    /** Beállítja a fapont jobb gyerekét. */
    void setRightChild(my_tree<T> *right) {
        this->right = right;
        this->right->p = this;
    }

    void iter(const my_tree &n) {
        if (n.left != nullptr) {
            iter(*n.left);
        }
        cout << n.d << endl;
        if (n.right != nullptr) {
            iter(*n.right);
        }
    }

    my_tree<T>* lowest(my_tree<T> *n) const {
        if (n->left != nullptr) {
            lowest(n->left);
        } else {
            return n;
        }
    }
};

// === MEGVALÓSÍTÁS VÉGE ===

/**
 * Példa a fa adatszerkezet felhasználására. A beadott feladatban nem szabad
 * szerepelnie.
 */
int main() {
    //my_tree<int> *tree = new my_tree<int>(8, new my_tree<int>(7), new my_tree<int>(9));
    //cout << *tree->begin();
    cout << "before" << endl;
    my_tree<int> tree = my_tree<int>();
    my_tree<int> tree2 = my_tree<int>(2);
    my_tree<int> tree3 = my_tree<int>(3);
    cout << "after" << endl;
    cout << "tree has: "<< tree.data() << endl;
    cout << "tree2 has: " << tree2.data() << endl;

    tree2.setLeftChild(&tree);
    tree2.setRightChild(&tree3);
    cout << "tree2 left child (tree): " << tree2.leftChild()->data() << endl;
    cout << "tree2 right child (tree3): " << tree2.rightChild()->data() << endl;
    cout << "parent of tree (tree2): " << tree.parent()->data() << endl;
    cout << "parent of tree3 (tree2): " << tree3.parent()->data() << endl;

    my_tree<int> t_left = my_tree<int>(0);
    my_tree<int> t_right = my_tree<int>(2);
    my_tree<int> t0 = my_tree<int>(1, &t_left, &t_right);
    cout << t0.leftChild()->data() << " <- " << t0.data() << " -> " << t0.rightChild()->data() << endl;

    t0.iter(t0);
    cout << endl;
    tree2.iter(tree2);
    cout << endl;
    my_tree<int>* a = tree2.lowest(&tree2);
    cout << a->data();

    cout << endl;
    auto it = tree2.begin();
    cout << "eee";
    cout << *it;
    return 0;
}
