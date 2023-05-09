#include <iostream>
using namespace std;

template <class T>
class Nodo {
public:
  T dato;
  Nodo<T>* siguiente;
};

template <class T>
class Pila {
private:
  Nodo<T>* cima;
  int tamano;
public:
  Pila() { cima = nullptr; tamano = 0; }

  bool estaVacia() {
    return (cima == nullptr);
  }

  int size() {
    return tamano;
  }

  void push(T x) {
    Nodo<T>* nuevoNodo = new Nodo<T>();
    nuevoNodo->dato = x;
    nuevoNodo->siguiente = cima;
    cima = nuevoNodo;
    tamano++;
  }

  T pop() {
    if (estaVacia()) {
      cout << "La pila está vacía. No se puede eliminar ningún elemento." << endl;
      return T();
    } else {
      T temp = cima->dato;
      Nodo<T>* tempPtr = cima;
      cima = cima->siguiente;
      delete tempPtr;
      tamano--;
      return temp;
    }
  }

  T peek() {
    if (estaVacia()) {
      cout << "La pila está vacía. No hay elementos para mostrar." << endl;
      return T();
    } else {
      return cima->dato;
    }
  }

  void imprimir() {
  if (estaVacia()) {
    cout << "La pila está vacía. No hay elementos para mostrar." << endl;
  } else {
    Nodo<T>* actual = cima;
    T* elementos = new T[tamano];
    int i = 0;
    while (actual != nullptr) {
      elementos[i++] = actual->dato;
      actual = actual->siguiente;
    }
    for (int j = i - 1; j >= 0; j--) {
      cout << elementos[j] << " ";
    }
    cout << endl;
    delete[] elementos;
  }
}
};

int main() {
Pila<string> s;

  s.push("hola");
  s.push("mundo");
  s.push("Te");
  s.push("Amo");

  s.imprimir(); // Imprime "mundo hola"
  cout << s.pop() << endl; // Imprime "mundo"
  cout << s.pop() << endl; // Imprime "hola"
  cout << s.pop() << endl;
  cout << s.pop() << endl;// Imprime "La pila está vacía. No se puede eliminar ningún elemento."
  s.imprimir(); // Imprime "La pila está vacía. No hay elementos para mostrar."

  return 0;
}
