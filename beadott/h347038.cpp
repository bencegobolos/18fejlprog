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
    /** Az fa pontjában tárolt adat változója. */
    T d;
    /** A szülõre mutató pointer. */
    my_tree<T>* p;
    /** A bal gyerekre mutató pointer. */
    my_tree<T>* left;
    /** A jobb gyerekre mutató pointer. */
    my_tree<T>* right;

public:
    /** iterátor belsõ osztály, a megfelelõ metódusokat meg kell valosítani */
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
        /** privát konstruktor, ami a megfelelõ elemre állítja az iterátort. */
        iterator(my_tree<T> *p) : _p(get_first(*p)) {
            this->length = 0;
            masolo(*_p);
            elements[length] = my_tree<T>(0);
            curr = elements;
        }
        /** Workaround: lemásolja a fa pontjait egy tömbbe, megfelelõ sorrendbe rakva. */
        void masolo(my_tree<T> &n) {
            if (n.left != nullptr) {
                masolo(*n.left);
            }
            elements[length++] = n;
            if (n.right != nullptr) {
                masolo(*n.right);
            }
        }
        /** Visszaadja a legkisebb értékû fapont címét. */
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
        /** prefix iterátor léptetõ */
        iterator& operator++() {++curr; return *this;}
        /** logikai különbözõség */
        bool operator!=(const iterator &it) {return _p != it._p;}
    };

    /** Iterátor a fa inorder bejárás szerinti elso elemére. */
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
};

// === MEGVALÓSÍTÁS VÉGE ===
