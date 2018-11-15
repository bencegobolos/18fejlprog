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
    T d;
    my_tree<T>* p;
    my_tree<T>* left;
    my_tree<T>* right;

public:
    /**
     * Belsõ osztály, amely az inorder bejárást biztosító iterátort valósítja meg.
     */
    class iterator;
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
    /**
     * A sablonpéldány rendelkezik olyan konstruktorral, amely inicializálja a
     * fapontban tárolt adatot, és a bal és jobb gyerekét.
     */
        this->d = data;
        this->p = nullptr;
        this->left = nullptr;
        this->right = nullptr;
    }
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
    /** Iterátor típus, amely inorder bejárást biztosít a fában. */
    class iterator;
    /** Iterátor a fa inorder bejárás szerinti elsõ elemére. */
    iterator begin();
    /** Iterátor a fa inorder bejárás szerinti utolsó eleme utáni elemre. */
    iterator end();
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

    return 0;
}
