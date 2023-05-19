
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

template <typename T>
struct Node{
  T key;
  Node <T> *left;
  Node <T> *right;
  Node <T> *parent;  
};

template<typename T>
class Btree{
    private: 
        Node<T>* root;
        unsigned _size;
    public:
        Btree(){
          root = nullptr;
          _size = 0;
        }
        ~Btree(){
            destroy_rec(root);
        }
        void destroy_rec(Node<T> *n ){
            if(n != nullptr){
            destroy_rec(n -> left);
            destroy_rec(n -> right);
            delete n;
            }
        }
        int get_size(){return _size;}
        void insert(T k){
            insert_rec(k, root, nullptr);
        }
        void insert_rec(T k, Node<T>* &c, Node<T> *p){
            if(c == nullptr){
                c = new Node<T>;
                c->key = k;
                c->right = nullptr;
                c->left = nullptr;
                c->parent = p;
                _size += 1;
            }else if((c->key) > k){
                insert_rec(k, c->left, c);
            }else{
                insert_rec(k, c->right, c);
          }
        }
        void print_rec(Node<T> *n, int level){
            if(n != nullptr){
                print_rec(n->left, level + 1);
                std::cout << n->key << "(" << level << ")\t";
                print_rec(n->right, level + 1);
            }
        }
        void print(){
            print_rec(root, 0);
            cout<<endl;
        }
        Node<T>* find(T k, Node<T>* n){
            if(n == nullptr){
                return nullptr;
              }else{
                if(n -> key == k){
                  return n;
                }else if(n -> key > k){
                  return find(k, n -> left);
                }else{
                  return find(k, n -> right);
                }   
              } 
        }
        bool contains(T k){
          if(find(k, root) == nullptr){
            return false;
          }else{
            return true;
          }
        }
        void contains_2(T k){
          if(find(k, root) == nullptr){
            cout<<"El dato "<< k <<" NO está en el arbol."<<endl;
          }else{
            cout<<"El dato "<< k <<" está en el arbol."<<endl;
          }
        }
        void remove_rec(Node<T> *n){
         //Nodo sin hijos
          if(n-> left == nullptr && n->right == nullptr){
            Node<T> *p = n -> parent;
            if(p->right == n){
              p->right = nullptr;
              delete n;
            }else{
              p->left = nullptr;
              delete n;
            }
            
          }
        //Nodo con un hijo
          else if(n-> left == nullptr || n->right == nullptr){
            Node<T> *p = n -> parent;
            Node<T> *h;
            
            if(n->right != nullptr){
              h = n->right;
            }else{
              h = n->left;
            }
            
            if(p->right == n){
              p->right = h;
              delete n;
            }else{
              p->left = h;
              delete n;
            }
              
            }
        //Nodo con dos hijos
         else{
           Node<T> *s = successor(n);
           n->key = s->key;
           remove_rec(s);
         }
        }
        T maximum(){
            if(root == nullptr){
            throw std::runtime_error("maximum: Tree is empty.");
          }else{
            return max_rec(root) -> key;
          }
        }
        Node<T>* max_rec(Node <T> *n){
          if(n != nullptr){
            if(n -> right != nullptr){
              return max_rec(n -> right);
            }
          }
          return n;
        }
        Node<T>* min_rec(Node <T> *n){
          if(n != nullptr){
            if(n -> left != nullptr){
              return min_rec(n -> left);
            }
          }
          return n;
        }
        Node<T>* move_back(T k, Node<T> *n){
          if(n != nullptr){
            if(n -> key < k){
              return move_back(k, n -> parent);
            }
          }
          return n;
        }
        Node<T>* move_back_s(T k, Node<T> *n){
          if(n != nullptr){
            if(n -> key > k){
              return move_back_s(k, n -> parent);
            }
          }
          return n;
        }
        Node<T>* predecessor(Node<T> *n){
          if(n != nullptr){
            if(n -> left != nullptr){
              return max_rec(n -> left);
            }else{
              T k = n-> key;
              return move_back_s(k, n -> parent);
            }
          }
          return n;
        }
        Node<T>* successor(Node<T> *n){
          if(n != nullptr){
            if(n -> right != nullptr){
              return min_rec(n -> right);
            }else{
              T k = n-> key;
              return move_back(k, n -> parent);
            }
          }
          return n;
        }
        bool remove(T k){
          Node<T> *n = find(k, root);
          if(n == nullptr){
            return false;
          }else{
            remove_rec(n);
            return true;
          }
        }
        void test(){
          Node<T> *p = find(15, root);
          Node<T> *pp = successor(p);
          if(pp == nullptr){
            std::cout << "successor " << p->key <<  ": no successor.\n";
          }else{
            std::cout << "successor: " << pp -> key << "\n";
          }
        
          Node<T> *t = find(15, root);
          Node<T> *tt = predecessor(t);
          if(tt == nullptr){
            std::cout << "predecessor " << t->key <<  ": no predecessor.\n";
          }else{
            std::cout << "predecessor: " << tt -> key << "\n";
          } 
        }
        bool is_hoja(){
            return (left == nullptr && right == nullptr);
        }
        
        
        
        int altura(Node<T>* r){
            if(is_hoja()){
                return 0;
            }else{
                int max = -1;
                if(r->left != NULL){
                    max = altura(r->left);
                }
                if(r->right != NULL){
                    int temp = altura(r->right);
                    if(max < temp){
                        max = temp;
                    }
                }
                return max+1;
            }
        }
        
        int altura(){
            return altura(root); 
        }
        
        
};

int main()
{
    Btree<int> mytree;
    mytree.insert(18);
    mytree.insert(12);
    mytree.insert(15);
    mytree.insert(24);
    mytree.insert(21);
    mytree.insert(41);
    mytree.print();
    cout<<mytree.altura()<<endl;

    Btree<int> mytree2;
    
    return 0;
}
