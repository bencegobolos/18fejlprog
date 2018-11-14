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
    struct node {
        T data;
        node* left;
        node* right;
    };

    node* root;

public:
    /**
     * Bels� oszt�ly, amely az inorder bej�r�st biztos�t� iter�tort val�s�tja meg.
     */
    class iterator;
    /** A sablonp�ld�ny rendelkezik default konstruktorral. */
    my_tree() {
        root = nullptr;
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
        root = new node;
        root->data = data;
        root->left = nullptr;
        root->right = nullptr;
    }
    my_tree(const T &data, my_tree<T> *left, my_tree<T> *right);
    /** A destruktor felszabad�tja a teljes r�szf�t. */
    ~my_tree() {
        if (root != nullptr) {
            if (root->left != nullptr) {
                delete root->left;
            }
            if (root->right != nullptr) {
                delete root->right;
            }
            delete root;
        }
    }
    /** Hozz�f�r�s a fapontban t�rolt adathoz. */
    const T& data() const;
    T& data();
    /** A fapont sz�l�je. */
    my_tree<T>* parent() const;
    /** A fapont bal gyereke. */
    my_tree<T>* leftChild() const;
    /** A fapont jobb gyereke. */
    my_tree<T>* rightChild() const;
    /** Be�ll�tja a fapont bal gyerek�t. */
    void setLeftChild(my_tree<T> *left);
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
    int a = 2;
    my_tree<int> tree = my_tree<int>();
    my_tree<int> tree2 = my_tree<int>(a);
    cout << "after" << endl;
    return 0;
}
