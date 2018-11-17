// === MEGVAL�S�TAND� ===

/**
 * Az oszt�lysablon neve my_tree.
 * A sablon param�terez�se:
 *   - T: a fapontokban t�rolt adat t�pusa
 * A sablonp�ld�ny a tree_base oszt�lyb�l sz�rmazik (amely rendelkezik default
 * konstruktorral). A beadott feladatban a tree_base oszt�lyt nem kell (nem
 * szabad) megval�s�tani!
 */
template<class T>
class my_tree : tree_base {
private:
    /** Az fa pontj�ban t�rolt adat v�ltoz�ja. */
    T d;
    /** A sz�l�re mutat� pointer. */
    my_tree<T>* p;
    /** A bal gyerekre mutat� pointer. */
    my_tree<T>* left;
    /** A jobb gyerekre mutat� pointer. */
    my_tree<T>* right;

public:
    /** iter�tor bels� oszt�ly, a megfelel� met�dusokat meg kell valos�tani */
    class iterator {
    private:
        /** az iter�tor �ltal hivatkozott elem. */
        my_tree<T> *_p;
        /** a fa elemeinek sz�ma. */
        int length;
        /** Workaround: fapontokat tartalmaz� t�mb. */
        my_tree<T> elements[100];
        /** Aktu�lis fapontra mutat� pointer. */
        my_tree<T> *curr;
        /** my_tree sablon friend definicioja, hogy el�rje a priv�t konstruktort. */
        friend class my_tree<T>;
        /** priv�t konstruktor, ami a megfelel� elemre �ll�tja az iter�tort. */
        iterator(my_tree<T> *p) : _p(get_first(*p)) {
            this->length = 0;
            masolo(*_p);
            elements[length] = my_tree<T>(0);
            curr = elements;
        }
        /** Workaround: lem�solja a fa pontjait egy t�mbbe, megfelel� sorrendbe rakva. */
        void masolo(my_tree<T> &n) {
            if (n.left != nullptr) {
                masolo(*n.left);
            }
            elements[length++] = n;
            if (n.right != nullptr) {
                masolo(*n.right);
            }
        }
        /** Visszaadja a legkisebb �rt�k� fapont c�m�t. */
        my_tree<T>* get_first(my_tree<T> &n) {
            if (n.left != nullptr) {
                get_first(*n.left);
            }
            else {
                return &n;
            }
        }
    public:
        /** alap�rtelmezett konstruktor */
        iterator() : _p(nullptr) {}
        /** copy konstruktor */
        iterator(const iterator &it) : _p(it._p) {}
        /** dereferencia */
        const T& operator*() {return _p->data();}
        /** prefix iter�tor l�ptet� */
        iterator& operator++() {++curr; return *this;}
        /** logikai k�l�nb�z�s�g */
        bool operator!=(const iterator &it) {return _p != it._p;}
    };

    /** Iter�tor a fa inorder bej�r�s szerinti elso elem�re. */
    iterator begin() {return iterator(this);}
    /** Iter�tor a fa inorder bej�r�s szerinti utols� eleme ut�ni elemre. */
    iterator end() {return iterator(nullptr);}

    /** A sablonp�ld�ny rendelkezik default konstruktorral. */
    my_tree() {
        this->d = 0;
        this->p = nullptr;
        this->left = nullptr;
        this->right = nullptr;
    }
    /**
     * A sablonp�ld�ny rendelkezik olyan konstruktorral, amely inicializ�lja a
     * fapontban t�rolt adatot.
     */
    my_tree(const T &data) {
        this->d = data;
        this->p = nullptr;
        this->left = nullptr;
        this->right = nullptr;
    }
    /**
     * A sablonp�ld�ny rendelkezik olyan konstruktorral, amely inicializ�lja a
     * fapontban t�rolt adatot, tov�bb� a fapont bal- �s jobb gyerekeit is meghat�rozza.
     */
    my_tree(const T &data, my_tree<T> *left, my_tree<T> *right) {
        this->d = data;
        this->p = nullptr;
        this->left = left;
        this->left->p = this;
        this->right = right;
        this->right->p = this;
    }
    /** A destruktor felszabad�tja a teljes r�szf�t. */
    ~my_tree() {
        if (this->left != nullptr) {
            delete this->left;
        }
        if (this->right != nullptr) {
            delete this->right;
        }
    }
    /** Hozz�f�r�s a fapontban t�rolt adathoz. */
    const T& data() const {
        return this->d;
    }

    /** A fapont sz�loje. */
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
    /** Be�ll�tja a fapont bal gyerek�t. */
    void setLeftChild(my_tree<T> *left) {
        this->left = left;
        this->left->p = this;
    }
    /** Be�ll�tja a fapont jobb gyerek�t. */
    void setRightChild(my_tree<T> *right) {
        this->right = right;
        this->right->p = this;
    }
};

// === MEGVAL�S�T�S V�GE ===
