
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>

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
                std::cout << n->key << "(" << level << ") ";
                print_rec(n->right, level + 1);
            }
        }
        
        void print(){
            print_rec(root, 0);
            cout<<endl;
        }
        
        
        
};
      
