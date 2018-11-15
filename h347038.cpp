#include <iostream>

using namespace std;
// === MEGVAL�S�TAND� ===

/**
 * Az oszt�lysablon neve my_tree.
 * A sablon param�terez�se:
 *   - T: a fapontokban t�rolt adat t�pusa
 * A sablonp�ld�ny a tree_base oszt�lyb�l sz�rmazik (amely rendelkezik default
 * konstruktorral). A beadott feladatban a tree_base oszt�lyt nem kell (nem
 * szabad) megval�s�tani!
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
     * Bels� oszt�ly, amely az inorder bej�r�st biztos�t� iter�tort val�s�tja meg.
     */
    class iterator;
    /** A sablonp�ld�ny rendelkezik default konstruktorral. */
    my_tree() {
        this->d = 0;
        this->left = nullptr;
        this->right = nullptr;
    }
    /**
     * A sablonp�ld�ny rendelkezik olyan konstruktorral, amely inicializ�lja a
     * fapontban t�rolt adatot.
     */
    my_tree(const T &data) {
    /**
     * A sablonp�ld�ny rendelkezik olyan konstruktorral, amely inicializ�lja a
     * fapontban t�rolt adatot, �s a bal �s jobb gyerek�t.
     */
        this->d = data;
        this->left = nullptr;
        this->right = nullptr;
    }
    my_tree(const T &data, my_tree<T> *left, my_tree<T> *right);
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

    /** A fapont sz�l�je. */
    my_tree<T>* parent() const;
    /** A fapont bal gyereke. */
    my_tree<T>* leftChild() const {
        return this->left;
    }
    /** A fapont jobb gyereke. */
    my_tree<T>* rightChild() const;
    /** Be�ll�tja a fapont bal gyerek�t. */
    void setLeftChild(my_tree<T> *left) {
        this->left = left;
    }
    /** Be�ll�tja a fapont jobb gyerek�t. */
    void setRightChild(my_tree<T> *right);
    /** Iter�tor t�pus, amely inorder bej�r�st biztos�t a f�ban. */
    class iterator;
    /** Iter�tor a fa inorder bej�r�s szerinti els� elem�re. */
    iterator begin();
    /** Iter�tor a fa inorder bej�r�s szerinti utols� eleme ut�ni elemre. */
    iterator end();
};

// === MEGVAL�S�T�S V�GE ===

/**
 * P�lda a fa adatszerkezet felhaszn�l�s�ra. A beadott feladatban nem szabad
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
