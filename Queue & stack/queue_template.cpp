#include <math.h>

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

template<typename T>
class Nodo {
  T n;
  Nodo* next;

 public:
  Nodo(T d) {
    n = d;
    next = NULL;
  }

  T get() { return n; }

  Nodo* getNext() { return next; }

  void setNext(Nodo* p) { next = p; }
};


template<typename T>
class Cola {
  Nodo<T>* ptr;
  Nodo<T>* tail;
  int n_size;

 public:
  Cola() {
    ptr = NULL;
    tail = NULL;
    n_size = 0;
  }

  int size() { return n_size; }

  void push(T d) {
    if (n_size == 0) {
      ptr = new Nodo<T>(d);
      tail = ptr;
      n_size++;
    } else {
      Nodo<T>* n = new Nodo<T>(d);
      tail->setNext(n);
      tail = n;
      n_size++;
    }
  }
  
  int pop() {
      if(n_size == 0) throw invalid_argument("La cola esta vacia");
      
      Nodo<T>* n = ptr;
      if(n->getNext() != NULL) {
        ptr = n->getNext();
      } else {
          ptr = NULL;
      }
      n_size--;
      T value = n->get();
      delete n;
      
      return value;
  }
  
  int peek() {
      if(n_size == 0) throw invalid_argument("La cola esta vacia");
      
      Nodo<T>* n = ptr;
      if(n->getNext() != NULL) {
        ptr = n->getNext();
      } else {
          ptr = NULL;
      }

      T value = n->get();
      
      cout<<value;
      return value;
  }
  
  
  void print() {
    if (n_size == 0) {
      cout << "La lista está vacía" << endl;
    } else {
      Nodo<T>* t = ptr;
      do {
        cout << "" << (*t).get() ;
        t = t->getNext();

      } while (t != NULL);
      cout << endl;
    }
  }
};

int main() {
  Cola<char> c = Cola<char>();
  c.push('h');
  c.push('e');
  c.push('l');
  c.print();
  c.peek();

  return 0;
}
