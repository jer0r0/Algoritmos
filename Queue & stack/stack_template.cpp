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
class Pila {
  Nodo<T>* ptr;
  int n_size;

 public:
  Pila() {
    ptr = NULL;
    n_size = 0;
  }

  int size() { return n_size; }

  void push(T d) {
    Nodo<T>* nuevoNodo = new Nodo<T>(d);
    nuevoNodo->setNext(ptr);
    ptr = nuevoNodo;
    n_size++;
  }
  
  T pop(){
    if (n_size == 0) {
        throw std::invalid_argument("La cola esta vacia");
    }
 
    Nodo<T>* current = ptr ;
    ptr = ptr->getNext();
    T value = current->get();
    delete current;
    n_size--;

    return value;
}
  
  T peek() {
      if(n_size == 0) throw invalid_argument("La pila esta vacia");
      Nodo<T>* n = ptr;
      if(n->getNext() != NULL) {
        ptr = n->getNext();
      } else {
          ptr = NULL;
      }
      T value = n->get();
      return value;
  }
  
  void print() {
    if (n_size == 0) {
      cout << "La lista está vacía" << endl;
    } else {
      Nodo<T>* t = ptr;
      T* elementos  = new T[n_size];
      int i = 0;
      while( t !=nullptr){
          elementos[i++] = t->get();
          t = t->getNext();
      }
      for(int j = i-1; j>= 0; j--){
          cout<<elementos[j]<<" ";
      }
      cout<<endl;
      delete[] elementos;
      /*
      do {
        cout << "" << (*t).get() << "\t";
        t = t->getNext();

      } while (t != NULL);
      cout << endl;
      */
    }
  }
};

int main() {
  Pila<char> pila = Pila<char>();
  pila.push('h');
  pila.push('e');
  pila.push('l');
  pila.push('l');
  pila.push('o');
  pila.print(); 
  
  cout << pila.pop() << endl;
  
  pila.print();
  
  cout << "El numero que esta mas cerca de salir es: "<<pila.peek() << endl;
  
}
