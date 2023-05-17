#ifndef BTREE_HPP
#define BTREE_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
struct Node{
  T key;
  Node <T> *left;
  Node <T> *right;
  Node <T> *parent;  
};

template <typename T>
class Btree{
private:
  Node <T> *root;
  unsigned _size;
  Node<T>* find(T k);
  void print_rec(Node<T> *n, int level);
  void destroy_rec(Node<T> *n);
  void insert_rec(T k, Node<T>* &c, Node<T> *p);
  Node<T>* find(T k, Node<T> *n);
  Node<T>* min_rec(Node<T> *n);
  Node<T>* max_rec(Node<T> *n);
  Node<T>* successor(Node<T> *n);
  Node<T>* move_back(T k, Node<T> *n);
  Node<T>* predecessor(Node<T> *n);
  Node<T>* move_back_s(T k, Node<T> *n);
  void remove_rec(Node<T> *n);
  void swap_recursive(Node<T> *p);



public:
  Btree();
  ~Btree();

  void insert(T k);
  bool remove(T k);
  bool contains(T k);

  T maximum();
  T minimum();
  unsigned size();

  void display();

  void test();
  void swap(T k, T j);
  
};


template<typename T>
void Btree<T>::swap( T k, T j){
Node<T>* p= find(k,root);
p ->key = j;
swap_recursive(p);
}

template<typename T>
void Btree<T>::swap_recursive(Node<T> *p){
if( p != nullptr){
  if(p->right != nullptr){
    if(p->right->key < p->key  ){
      int h = p->right->key;
      int r = p->key;
      p ->key = h;
      p->right->key = r;
      swap_recursive(p->right);
    }
  }
  if(p->left != nullptr){
    if(p->left->key > p->key){
      int h = p->left->key;
      int r = p->key;
      p ->key = h;
      p->left->key = r;
      swap_recursive(p->left);
      }
  }
}
}


//Implementation-----------------------------------------------------------------------
//constructor *****************************************************************
template <typename T>
Btree<T>::Btree(){
  root = nullptr;
  _size = 0;
}

//destructor ******************************************************************
template <typename T>
Btree<T>::~Btree(){
  destroy_rec(root);
}

template <typename T>
void Btree<T>::destroy_rec(Node<T> *n){
  if(n != nullptr){
    destroy_rec(n -> left);
    destroy_rec(n -> right);
    delete n;
  }
}

//insert *********************************************************************
template <typename T>
void Btree<T>::insert(T k){
  insert_rec(k, root, nullptr);
}

template <typename T>
void Btree<T>::insert_rec(T k, Node<T>* &c, Node<T> *p){ //pasar el apuntador por referencia, para no crear un apuntador copia, sino tomar el apuntador del nodo como tal. 
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

//metodos de busqueda *********************************************************
template <typename T>
Node<T>* Btree<T>::find(T k, Node<T> *n){
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

template <typename T>
bool Btree<T>::contains(T k){
  if(find(k, root) == nullptr){
    return false;
  }else{
    return true;
  }
}

//Remove *************************************************************************
template <typename T>
bool Btree<T>::remove(T k){
  Node<T> *n = find(k, root);
  if(n == nullptr){
    return false;
  }else{
    remove_rec(n);
    return true;
  }
}

template <typename T>
void Btree<T>::remove_rec(Node<T> *n){
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


//maximo *************************************************************************
template <typename T>
T Btree<T>::maximum(){
    if(root == nullptr){
    throw std::runtime_error("maximum: Tree is empty.");
  }else{
    return max_rec(root) -> key;
  }
}

template <typename T>
Node<T>* Btree<T>::max_rec(Node <T> *n){
  if(n != nullptr){
    if(n -> right != nullptr){
      return max_rec(n -> right);
    }
  }
  return n;
}

//mínimo *************************************************************************
template <typename T>
T Btree<T>::minimum(){
  if(root == nullptr){
    throw std::runtime_error("minimum: Tree is empty.");
  }else{
    return min_rec(root) -> key;
  }
}

template <typename T>
Node<T>* Btree<T>::min_rec(Node <T> *n){
  if(n != nullptr){
    if(n -> left != nullptr){
      return min_rec(n -> left);
    }
  }
  return n;
}

//Successor **********************************************************************
template <typename T>
Node<T>* Btree<T>::successor(Node<T> *n){
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

template <typename T>
Node<T>* Btree<T>::move_back(T k, Node<T> *n){
  if(n != nullptr){
    if(n -> key < k){
      return move_back(k, n -> parent);
    }
  }
  return n;
}

//Predecessor *******************************************************************
template <typename T>
Node<T>* Btree<T>::predecessor(Node<T> *n){
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


template <typename T>
Node<T>* Btree<T>::move_back_s(T k, Node<T> *n){
  if(n != nullptr){
    if(n -> key > k){
      return move_back_s(k, n -> parent);
    }
  }
  return n;
}

//métodos de apoyo **************************************************************
template <typename T>
unsigned Btree<T>::size(){
  return _size;
}

template <typename T>
void Btree<T>::print_rec(Node<T> *n, int level){
  if(n != nullptr){
    print_rec(n->left, level + 1);
    std::cout << n->key << "(" << level << ") ";
    print_rec(n->right, level + 1);
  }
}

template <typename T>
void Btree<T>::display(){
  print_rec(root, 0);
  std::cout << "\n";
}


template <typename T>
void Btree<T>::test(){
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




#endif
