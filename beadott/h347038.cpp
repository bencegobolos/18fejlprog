// === MEGVALÓSÍTANDÓ ===

/**
 * Az osztálysablon neve my_tree.
 * A sablon paraméterezése:
 *   - T: a fapontokban tárolt adat típusa
 * A sablonpéldány a tree_base osztályból származik (amely rendelkezik default
 * konstruktorral). A beadott feladatban a tree_base osztályt nem kell (nem
 * szabad) megvalósítani!
 */
template<class T>
class my_tree : tree_base {
private:
    T d;
    my_tree<T>* p;
    my_tree<T>* left;
    my_tree<T>* right;

public:
    /**
     * Belso osztály, amely az inorder bejárást biztosító iterátort valósítja meg.
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

    /** A fapont szüloje. */
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
    /** Iterátor a fa inorder bejárás szerinti elso elemére. */
    iterator begin();
    /** Iterátor a fa inorder bejárás szerinti utolsó eleme utáni elemre. */
    iterator end();
};

// === MEGVALÓSÍTÁS VÉGE ===
