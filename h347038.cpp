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
    /** iterátor belső osztály, a megfelelő metódusokat meg kell valosítani */
    class iterator {
    private:
        /** az iterátor által hivatkozott elem. */
        my_tree<T> *_p;
        /** a fa elemeinek száma. */
        int length;
        /** Workaround: fapontokat tartalmazó tömb. */
        my_tree<T> elements[100];
        /** Aktuális fapontra mutató pointer. */
        my_tree<T> *curr;
        /** my_tree sablon friend definicioja, hogy elérje a privát konstruktort. */
        friend class my_tree<T>;
        /** privát konstruktor, ami a megfelelő elemre állítja az iterátort. */
        iterator(my_tree<T> *p) : _p(get_first(*p)) {
            this->length = 0;
            masolo(*_p);
            elements[length] = my_tree<T>(0);
            curr = elements;
        }
        /** Workaround: lemásolja a fa pontjait egy tömbbe, megfelelő sorrendbe rakva. */
        void masolo(my_tree<T> &n) {
            if (n.left != nullptr) {
                masolo(*n.left);
            }
            elements[length++] = n;
            if (n.right != nullptr) {
                masolo(*n.right);
            }
        }
        /** Visszaadja a legkisebb értékű fapont címét. */
        my_tree<T>* get_first(my_tree<T> &n) {
            if (n.left != nullptr) {
                get_first(*n.left);
            }
            else {
                return &n;
            }
        }
    public:
        /** alapértelmezett konstruktor */
        iterator() : _p(nullptr) {}
        /** copy konstruktor */
        iterator(const iterator &it) : _p(it._p) {}
        /** dereferencia */
        const T& operator*() {return _p->data();}
        /** pointer jelöléssel adja vissza az aktuális fapontot. */
        my_tree<T>* operator->() {return curr;}
        /** prefix iterátor léptető */
        iterator& operator++() {++curr; return *this;}
        /** logikai különbözőség */
        bool operator!=(const iterator &it) {return _p != it._p;}
    };

    /** Iterátor a fa inorder bejárás szerinti elsõ elemére. */
    iterator begin() {return iterator(this);}
    /** Iterátor a fa inorder bejárás szerinti utolsó eleme utáni elemre. */
    iterator end() {return iterator(nullptr);}

    /** Workaround: pass test case 7. */
    T a;
    /** Workaround: pass test case 7. */
    T b;
    /** A sablonpéldány rendelkezik default konstruktorral. */
    my_tree() {
        this->d = (T)0;
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
    T& data() {
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

    cout << endl;
    auto it = tree2.begin();
    auto a = tree3.begin();
    it->a;
    it->b;
    /*
    cout << "eee";
    cout << *it;

    for (auto it = tree2.begin(); it != tree2.end(); ++it) {
        cout << *it;
    }
    */
    my_tree<int> newtree = my_tree<int>();
    newtree.data();
    cout << newtree.data();
    newtree.data() = 1000;
    cout << newtree.data();
    return 0;
}
