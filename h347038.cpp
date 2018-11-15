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
        this->left = nullptr;
        this->right = nullptr;
    }
    my_tree(const T &data, my_tree<T> *left, my_tree<T> *right);
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
    my_tree<T>* parent() const;
    /** A fapont bal gyereke. */
    my_tree<T>* leftChild() const {
        return this->left;
    }
    /** A fapont jobb gyereke. */
    my_tree<T>* rightChild() const;
    /** Beállítja a fapont bal gyerekét. */
    void setLeftChild(my_tree<T> *left) {
        this->left = left;
    }
    /** Beállítja a fapont jobb gyerekét. */
    void setRightChild(my_tree<T> *right);
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
    cout << "after" << endl;
    cout << "tree has: "<< tree.data() << endl;
    cout << "tree2 has: " << tree2.data() << endl;

    tree2.setLeftChild(&tree);
    my_tree<int> *val = tree2.leftChild();
    cout << "tree2 left child (tree): " << val->data() << endl;

    return 0;
}
