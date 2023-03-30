
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>
#include <math.h>

using namespace std;

class Punto{
    public:
    int x;
    int y;
    Punto(){
        x=0;
        y=0;
    }
    
    Punto(int x1, int y1){
        x=x1;
        y=y1;
    }
    
    double calc_dist(Punto p){
        return sqrt(pow(x-p.x,2)+pow(y-p.y,2));
    }
    
    string to_string(){
        return "("+std::to_string(x)+", "+std::to_string(y)+")";
    }
    
};



class Ciudad{
private:
    string nombre;
    int poblacion;
public:
    Ciudad(){
        nombre = "";
        poblacion = 0;
    }
    
    Ciudad(string n, int p){
        nombre = n;
        poblacion = p;
    }
    
    string get_nombre(){
        return nombre;
    }
    
    int get_poblacion(){
        return poblacion;
    }
    
    string to_string(){
        return "("+nombre+","+std::to_string(poblacion)+")";
    }
    
    Ciudad& operator=(const Ciudad& f) { 
		nombre = f.nombre;
		poblacion = f.poblacion;
		return *this;
	}
    
    void print(){
        cout<<to_string();
    }
    
    friend std::ostream& operator<<(std::ostream& os, Ciudad& b) {
		return os << b.to_string();
	}
	
	friend std::ostream& operator<<(std::ostream& os, Ciudad* b) {
		return os << b->to_string();
	}
    
};


class Pais{
private:
    string nombre;
public:
    Pais(){
        nombre = "";
    }
    
    Pais(string n){
        nombre = n;
    }
    
    string get_nombre(){
        return nombre;
    }
    
    string to_string(){
        return nombre;
    }
    
    Pais& operator=(const Pais& f) { 
		nombre = f.nombre;
		return *this;
	}
    
    void print(){
        cout<<to_string();
    }
    
    friend std::ostream& operator<<(std::ostream& os, Pais& b) {
		return os << b.to_string();
	}
	
	friend std::ostream& operator<<(std::ostream& os, Pais* b) {
		return os << b->to_string();
	}
    
};


template<typename T>
class Nodosec{
private:
  T dato;
  Nodosec* next;

public:

 Nodosec(T d){
     dato = d;
     next =  NULL;
 }
 
 ~Nodosec(){
 }
 
 T get_dato(){
     return dato;
 }
 
 void set_dato(T d){
     dato = d;
 }
 
 Nodosec* get_next(){
     return next;
 }
 
 void set_next(Nodosec* n){
     next = n;
 }
 
 Nodosec<T>& operator=(const Nodosec<T>& f) { 
		dato = f.dato;
        next =  f.next;
		return *this;
	}
	
	string to_string() {
	    return dato.to_string(); //Si el dato es una clase con método to_string()
		//return std::to_string(dato); //Si el dato es un dato común
	}
    
    void print(){
        cout<<to_string();
    }
    
    friend std::ostream& operator<<(std::ostream& os, Nodosec<T>& b) {
		return os << b.to_string();
	}
	
	friend std::ostream& operator<<(std::ostream& os, Nodosec<T>* b) {
		return os << b->to_string();
	}

    //Aquí se incluirían los métodos especiales para País

};  

template<typename T, typename T2>
class Nodo{
private:
  T dato;
  Nodosec<T2>* ptrsec;
  Nodo* next;
  int size;

public:

 Nodo(T d){
     dato = d;
     next =  NULL;
     ptrsec =  NULL;
     size = 0;
 }
 
 ~Nodo(){
 }
 
 T get_dato(){
     return dato;
 }
 
 void set_dato(T d){
     dato = d;
 }
 
 Nodo* get_next(){
     return next;
 }
 
 void set_next(Nodo* n){
     next = n;
 }
 
  Nodosec<T2>* get_ptrsec(){
     return ptrsec;
 }
 
 void set_ptrsec(Nodosec<T2>* n){
     ptrsec = n;
 }

 void add(T2 d){
        Nodosec<T2>* nodo = new Nodosec<T2>(d);
        
        if(ptrsec == NULL){//La lista está vacía
            ptrsec  = nodo;
        }else{//La lista no está vacía
            Nodosec<T2>* temp =  ptrsec;
            while(temp->get_next() != NULL){
                temp = temp->get_next();
            }
            temp->set_next(nodo);
        }
        size++;
    }
    
    void print(){
        //Mostrar el dato del nodo principal y los elementos de la lista secundaria
        //Dato -> datosec1, datosec2, ...
        //Si no hay elementos: Dato -> La lista secundaria está vacía
        cout<<dato.to_string()<<" -> ";
        Nodosec<T2>* temp = ptrsec;
        while(temp != NULL){
            temp->print();
            cout<<" , ";
            temp = temp->get_next();
        }
        if(ptrsec == NULL){
            cout<<"La lista secundaria está vacía";
        }
        cout<<endl;
    }
    
    Nodo<T,T2>& operator=(const Nodo<T,T2>& f) { 
		dato = f.dato;
        next =  f.next;
        ptrsec = f.ptrsec;
        return *this;
	}
    
 
};  

template<typename T, typename T2>
class Lista{
private:
  Nodo<T,T2>* ptr;
  int size;

public:

    Lista(){
        ptr = NULL;
        size = 0;
    }
  
    ~Lista(){
        Nodo<T,T2>* temp = ptr;
        if(ptr != NULL){
            Nodo<T,T2>* temp_next = ptr->get_next();
            while(temp_next != NULL){
                delete temp;
                temp = temp_next;
                temp_next = temp->get_next();
            }
            delete temp; //Borrar el último nodo
        }
    }
    
    void add(T d){
        Nodo<T,T2>* nodo = new Nodo<T,T2>(d);
        
        if(ptr == NULL){//La lista está vacía
            ptr  = nodo;
        }else{//La lista no está vacía
            Nodo<T,T2>* temp =  ptr;
            while(temp->get_next() != NULL){
                temp = temp->get_next();
            }
            temp->set_next(nodo);
        }
        size++;
    }
    
    void add(int i, T2 d){
        //Añadir un dato d a la lista secundaria del nodo principal en la posición i de la lista
         get(i)->add(d);
    }
    
    void insert(T d, int i){
        if(i<=size && i>=0 && ptr != NULL){
            Nodo<T,T2>* nodo = new Nodo<T,T2>(d);
            if(i == 0){
                nodo->set_next(ptr);
                ptr = nodo;
            }else{
                int j = 0;
                Nodo<T,T2>* temp =  ptr;
                while(j<i-1){
                    temp = temp->get_next();
                    j++;
                }
                nodo->set_next(temp->get_next());
                temp->set_next(nodo);
            }
            size++;
        }else{//Si el índice es incorrecto o la lista está vacía, se añade al final
            add(d);
        }
        
    }
    int get_size(){
        return size;
    }
    
    void print(){
        if(ptr == NULL){//La lista está vacía
            cout<<"La lista está vacía"<<endl;
        }else{//La lista no está vacía
            Nodo<T,T2>* temp =  ptr;
            while(temp != NULL){
                //cout<<temp->get_dato()<<","<<temp->get_next()<<"\t";
                temp->print();
                cout<<endl;
                temp = temp->get_next();
            }
            cout<<endl;
        }
    }
    
    Nodo<T,T2>* get(int i){
        if(i>=0 && i<size){
          int j=0;
          Nodo<T,T2>* temp = ptr;
          while(j<i){
              temp = temp->get_next();
              j++;
          }
          return temp;
        }
        return NULL;
    }
    
    Nodo<T,T2>* get_last(){
        Nodo<T,T2>* temp = ptr;
        if(ptr != NULL){
            while(temp->get_next() != NULL){
                temp = temp->get_next();
            }
        }else{
            return NULL;
        }
        return temp;
    }
    
};


class Atlas{
private:
    Lista<Pais, Ciudad> l;

public:
    Atlas(){
        
    }
    
    ~Atlas(){
        
    }
    
    void addPais(Pais p, Ciudad c){
        l.add(p);
        Nodo<Pais,Ciudad>* t = l.get_last();
        t->add(c);
    }
    
    void addCiudad(Pais p, Ciudad c){
        int cont = 0; 
        for(int i = 0 ;  i< l.get_size();i++){
            
            cont++;
            if( p.get_nombre() == l.get(i)->get_dato().get_nombre()){
                Nodo<Pais,Ciudad>* t = l.get(i);
                t->add(c);
            }
            
            else if( p.get_nombre() != l.get(i)->get_dato().get_nombre() && cont == l.get_size()){
                l.add(p);
                Nodo<Pais,Ciudad>* t = l.get_last();
                t->add(c);
                
             }
        
        }      
        
    }
    
    
    void print(){
        l.print();
    }
    
};


int main()
{
    Atlas a = Atlas();
    
    a.addPais(Pais("Colombia"), Ciudad("Bogota",8000000));
    a.addPais(Pais("Peru"), Ciudad("Lima",7000000));
    a.addPais(Pais("Ecuador"), Ciudad("Quito",6000000));
    a.addCiudad(Pais("Ecuador"), Ciudad("ledok", 800000));
    a.addCiudad(Pais("Venezuela"), Ciudad("Caracas", 800000));
    
    
    a.print();
    
    return 0;
}
