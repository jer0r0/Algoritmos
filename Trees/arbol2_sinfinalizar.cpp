#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>

using namespace std;

template <typename T>
struct Node {
    T key;
    Node<T> *left;
    Node<T> *right;
    Node<T> *parent;
};

template<typename T>
class Btree {
private:
    Node<T>* root;
    unsigned _size;
public:
    Btree() {
        root = nullptr;
        _size = 0;
    }

    ~Btree() {
        destroy_rec(root);
    }

    void destroy_rec(Node<T> *n) {
        if (n != nullptr) {
            destroy_rec(n->left);
            destroy_rec(n->right);
            delete n;
        }
    }

    int get_size() {
        return _size;
    }
    
    Node<T>* get_root() {
        return root;
    }

    void insert(T k) {
        insert_rec(k, root, nullptr);
    }

    void insert_rec(T k, Node<T>* &c, Node<T> *p) {
        if (c == nullptr) {
            c = new Node<T>;
            c->key = k;
            c->right = nullptr;
            c->left = nullptr;
            c->parent = p;
            _size += 1;
        } else if ((c->key) > k) {
            insert_rec(k, c->left, c);
        } else {
            insert_rec(k, c->right, c);
        }
    }

    void print_rec(Node<T> *n, int level) {
        if (n != nullptr) {
            print_rec(n->left, level + 1);
            std::cout << n->key << "(" << level << ")\t";
            print_rec(n->right, level + 1);
        }
    }

    void print() {
        print_rec(root, 0);
        cout << endl;
    }

    Node<T>* find(T k, Node<T>* n) {
        if (n == nullptr) {
            return nullptr;
        } else {
            if (n->key == k) {
                return n;
            } else if (n->key > k) {
                return find(k, n->left);
            } else {
                return find(k, n->right);
            }
        }
    }

    bool contains(T k) {
        if (find(k, root) == nullptr) {
            return false;
        } else {
            return true;
        }
    }

    void contains_2(T k) {
        if (find(k, root) == nullptr) {
            cout << "El dato " << k << " NO está en el árbol." << endl;
        } else {
            cout << "El dato " << k << " está en el árbol." << endl;
        }
    }

    void remove_rec(Node<T> *n) {
        if (n->left == nullptr && n->right == nullptr) {
            Node<T> *p = n->parent;
            if (p->right == n) {
                p->right = nullptr;
                delete n;
            } else {
                p->left = nullptr;
                delete n;
            }
        } else if (n->left == nullptr || n->right == nullptr) {
            Node<T> *p = n->parent;
            Node<T> *h;

            if (n->right != nullptr) {
                h = n->right;
            } else {
                h = n->left;
            }

            if (p->right == n) {
                p->right = h;
                delete n;
            } else {
                p->left = h;
                delete n;
            }
        } else {
            Node<T> *s = successor(n);
            n->key = s->key;
            remove_rec(s);
        }
    }

    T maximum() {
        if (root == nullptr) {
            throw std::runtime_error("maximum: Tree is empty.");
        } else {
            return max_rec(root)->key;
        }
    }

    Node<T>* max_rec(Node <T> *n) {
        if (n != nullptr) {
            if (n->right != nullptr) {
                return max_rec(n->right);
            }
        }
        return n;
    }

    Node<T>* min_rec(Node <T> *n) {
        if (n != nullptr) {
            if (n->left != nullptr) {
                return min_rec(n->left);
            }
        }
        return n;
    }

    Node<T>* move_back(T k, Node<T> *n) {
        if (n != nullptr) {
            if (n->key < k) {
                return move_back(k, n->parent);
            }
        }
        return n;
    }

    Node<T>* move_back_s(T k, Node<T> *n) {
        if (n != nullptr) {
            if (n->key > k) {
                return move_back_s(k, n->parent);
            }
        }
        return n;
    }

    Node<T>* predecessor(Node<T> *n) {
        if (n != nullptr) {
            if (n->left != nullptr) {
                return max_rec(n->left);
            } else {
                T k = n->key;
                return move_back_s(k, n->parent);
            }
        }
        return n;
    }

    Node<T>* successor(Node<T> *n) {
        if (n != nullptr) {
            if (n->right != nullptr) {
                return min_rec(n->right);
            } else {
                T k = n->key;
                return move_back(k, n->parent);
            }
        }
        return n;
    }

    bool remove(T k) {
        Node<T> *n = find(k, root);
        if (n == nullptr) {
            return false;
        } else {
            remove_rec(n);
            return true;
        }
    }

    bool is_hoja(Node<T>* r) {
        return (r->left == nullptr && r->right == nullptr);
    }

    int altura(Node<T>* n) {
        if (n->left == nullptr && n->right == nullptr) {
            return 0;
        } else {
            int max = -1;
            if (n->left != NULL) {
                max = altura(n->left);
            }
            if (n->right != NULL) {
                int temp = altura(n->right);
                if (max < temp) {
                    max = temp;
                }
            }
            return max + 1;
        }
    }

    int altura() {
        return altura(root);
    }

    void balancear() {
        balancearRec(root);
    }

    void balancearRec(Node<T>* n) {
        if (n == nullptr) {
            return;
        }
    
        balancearRec(n->left);
        balancearRec(n->right);
    
        int balance = altura(n->left) - altura(n->right);
    
        if (balance > 1) {
            if (altura(n->left->left) >= altura(n->left->right)) {
                rotateRight(n);
            } else {
                rotateLeft(n->left);
                rotateRight(n);
            }
        } else if (balance < -1) {
            if (altura(n->right->right) >= altura(n->right->left)) {
                rotateLeft(n);
            } else {
                rotateRight(n->right);
                rotateLeft(n);
            }
        }
    }



    void rotateRight(Node<T>* &n) {
        Node<T>* p = n;
        Node<T>* q = n->left;
        Node<T>* r = q->right;

        p->left = r;
        if (r != nullptr) {
            r->parent = p;
        }
        q->right = p;
        q->parent = p->parent;
        p->parent = q;

        if (q->parent == nullptr) {
            root = q;
        } else if (q->parent->left == p) {
            q->parent->left = q;
        } else {
            q->parent->right = q;
        }
    }

    void rotateLeft(Node<T>* &n) {
        Node<T>* p = n;
        Node<T>* q = n->right;
        Node<T>* r = q->left;

        p->right = r;
        if (r != nullptr) {
            r->parent = p;
        }
        q->left = p;
        q->parent = p->parent;
        p->parent = q;

        if (q->parent == nullptr) {
            root = q;
        } else if (q->parent->left == p) {
            q->parent->left = q;
        } else {
            q->parent->right = q;
        }
    }
};

int main() {
    Btree<int> tree;
    srand(1234);
    tree.print();
    for(int i=0; i<20;i++){
        tree.insert(rand()%100);
    }

    cout << "Árbol original:" << endl;
    tree.print();
    cout << "Tamaño del árbol: " << tree.get_size() << endl;

    cout << "Removiendo el elemento 3..." << endl;
    tree.remove(81);
    tree.print();
    cout << "Tamaño del árbol: " << tree.get_size() << endl;

    cout << "¿Contiene el número 7? ";
    tree.contains_2(7);
    cout << "¿Contiene el número 10? ";
    tree.contains_2(77);

    cout << "El máximo elemento es: " << tree.maximum() << endl;

    cout << "La altura del árbol es: " << tree.altura() << endl;

    cout << "Balanceando el árbol..." << endl;
    tree.balancearRec(tree.find(78,tree.get_root()));
    tree.print();

    return 0;
}
