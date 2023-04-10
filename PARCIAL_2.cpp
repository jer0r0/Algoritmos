#include<iostream>

using namespace std;

template<typename T>
class Nodo{
private:
  T dato;
  Nodo* next;

public:

 Nodo(T d){
     dato = d;
     next =  NULL;
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
    
};

class Tarjeta{
private:
    //Definir atributos
    int color;
    int numero;
    
public:
    Tarjeta(){
        //Constructor con valores en 0
        color= 0; 
        numero = 0;
    }
    
    Tarjeta(int c, int n){
        //Constructor con parámetros de entrada
        color = c; 
        numero = n; 
    }
       
    int get_color(){
        return color;
    }

     int get_numero(){
        return numero;
    }
    void set_color(int c){
        color = c;
    }
    
    void set_numero(int n){
        numero = n;
    }

    
    string to_string(){
        return "("+std::to_string(color)+","+std::to_string(numero)+")";
    }
    
    Tarjeta& operator=(const Tarjeta& f) { 
		color = f.color;
		numero = f.numero;
		return *this;
	}
    
    void print(){
        cout<<to_string();
    }
    
    friend std::ostream& operator<<(std::ostream& os, Tarjeta& b) {
		return os << b.to_string();
	}
	
	friend std::ostream& operator<<(std::ostream& os, Tarjeta* b) {
		return os << b->to_string();
	}
    
};

class Jugador{
private:
    int id;
    Nodo<Tarjeta*>* ptrc;
    int size;
public:
    Jugador(){
        id = 0;
        ptrc = NULL;
        size = 0;
    }
    
    Jugador(int n){
        id = n;
        ptrc = NULL;
    }
    
    ~Jugador(){
        Nodo<Tarjeta*>* temp = ptrc;
        if(ptrc != NULL){
            Nodo<Tarjeta*>* temp_next = ptrc->get_next();
            while(temp_next != NULL){
                delete temp;
                temp = temp_next;
                temp_next = temp->get_next();
            }
            delete temp; //Borrar el último nodo
        }
    }
    
    void add(Tarjeta* c){
        //Método para añadir tarjeta
        Nodo<Tarjeta*>* nodo = new Nodo<Tarjeta*>(c); 
        if (ptrc==nullptr){//lista está vacia    
            ptrc = nodo;    
        }else{//lista no está vacia    
            Nodo<Tarjeta*>* temp = ptrc;    
            while(temp->get_next()!=nullptr){    
                temp = temp -> get_next();     
            }    
            temp->set_next(nodo);   
        }    
        size++;
    }
    int get_size(){
        return size;
    }
    
    int calc_points(){
        int sum = 0;
        //Recorra la lista de tarjetas y sume los números de las tarjetas
        Nodo<Tarjeta*>* temp = ptrc;
        if(ptrc != NULL){
            while(temp != NULL){
                sum  = sum + temp->get_dato()->get_numero();
                if(temp->get_dato()->get_numero() == 0){
                    sum = sum + 20; 
                }
                temp = temp->get_next();
            }
        }
        
        return sum;
    }
    
    
    int get_id(){
        return id;
    }
    
    
    Nodo<Tarjeta*>* get(int i){
        if(i>=0 && i<size){
          int j=0;
          Nodo<Tarjeta*>* temp = ptrc;
          while(j<i){
              temp = temp->get_next();
              j++;
          }
          return temp;
        }
        return NULL;
    }
    
    
    void sort(){
        int size = get_size();
        int index_m= 0; 
        int temp_m;
        int temp = 0;
        for(int i = 0;  i < size -1; i++){
            int temp = get(i)->get_dato()->get_color();
            index_m = i;
            for( int j = i+1 ; j< size;j++){
                temp_m = get(j)->get_dato()->get_color();
                if( temp > temp_m){
                   //cout<<"Tarjeta "<<get(j)->get_dato()->to_string()<<"Es mayor que: "<<get(index_m)->get_dato()->to_string()<<endl;
                    temp = temp_m;
                    index_m= j;
                }else if (temp == temp_m){
                    if(get(index_m)->get_dato()->get_numero() > get(j)->get_dato()->get_numero()){
                        temp = temp_m;
                        index_m= j;
                    }
                }
                cout<<" ";
            }
            if( index_m != i){
                 Tarjeta* tempj = get(index_m)->get_dato();
                 get(index_m)->set_dato(get(i)->get_dato());
                 get(i)->set_dato(tempj);
            }
        }
    }
	

    string to_string(){
        string s = std::to_string(id)+" -> ";
        //Recorrer la lista y concatenar en la cadena s las información de las tarjetas, de acuerdo con     
        //la salida del programa
        Nodo<Tarjeta*>* temp = ptrc;
        while(temp != NULL){
            s.append(temp->get_dato()->to_string());
            s.append(",");
            temp = temp->get_next();
        }
        if(ptrc == NULL){
            s.append("La lista secundaria está vacía");
        }
        
        return s;
    }
    
    Jugador& operator=(const Jugador& f) { 
		id = f.id;
		ptrc = f.ptrc;
		return *this;
	}
    
    void print(){
        cout<<to_string();
    }
    
    friend std::ostream& operator<<(std::ostream& os, Jugador& b) {
		return os << b.to_string();
	}
	
	friend std::ostream& operator<<(std::ostream& os, Jugador* b) {
		return os << b->to_string();
	}
    
};

template<typename T>
class Lista{
private:
  Nodo<T>* ptr;
  int size;

public:

    Lista(){
        ptr = NULL;
        size = 0;
    }
  
    ~Lista(){
        Nodo<T>* temp = ptr;
        if(ptr != NULL){
            Nodo<T>* temp_next = ptr->get_next();
            while(temp_next != NULL){
                delete temp;
                temp = temp_next;
                temp_next = temp->get_next();
            }
            delete temp; //Borrar el último nodo
        }
    }
    
    void add(T d){
        Nodo<T>* nodo = new Nodo<T>(d);
        
        if(ptr == NULL){//La lista está vacía
            ptr  = nodo;
        }else{//La lista no está vacía
            Nodo<T>* temp =  ptr;
            while(temp->get_next() != NULL){
                temp = temp->get_next();
            }
            temp->set_next(nodo);
        }
        size++;
    }
    
    int get_size(){
        return size;
    }
    
    void insert(T d, int i){
        if(i<=size && i>=0 && ptr != NULL){
            Nodo<T>* nodo = new Nodo<T>(d);
            if(i == 0){
                nodo->set_next(ptr);
                ptr = nodo;
            }else{
                int j = 0;
                Nodo<T>* temp =  ptr;
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
    
    void print(){
        if(ptr == NULL){//La lista está vacía
            cout<<"La lista está vacía"<<endl;
        }else{//La lista no está vacía
            Nodo<T>* temp =  ptr;
            while(temp != NULL){
                //cout<<temp->get_dato()<<","<<temp->get_next()<<"\t";
                cout<<temp->get_dato()->to_string()<<endl;
                temp = temp->get_next();
            }
            cout<<endl;
        }
    }
    
    Nodo<T>* get(int i){
        if(i>=0 && i<size){
          int j=0;
          Nodo<T>* temp = ptr;
          while(j<i){
              temp = temp->get_next();
              j++;
          }
          return temp;
        }
        return NULL;
    }
    
    Nodo<T>* get_last(){
        Nodo<T>* temp = ptr;
        if(ptr != NULL){
            while(temp->get_next() != NULL){
                temp = temp->get_next();
            }
        }else{
            return NULL;
        }
        return temp;
    }
    
    Lista& operator=(const Lista& f) { 
	    size = f.size;
		ptr = f.ptr;
		return *this;
    }
    
};

class Uno{
private:
    //Declarar la lista de jugadores
    Lista<Jugador*> l; 

public:
    Uno(){
        
    }
    
    ~Uno(){
        
    }
    
    void addJugador(Jugador* p){
        //Añadir un jugador
        l.add(p);
    }
    
    Jugador* getJugador(int i){
        //Obtener un jugador de la lista
        return l.get(i)->get_dato();
    }
    
    void addTarjeta(int jugador, Tarjeta* t){
        //Añadir una tarjeta a un jugador
        l.get(jugador)->get_dato()->add(t);
        
    }
    
    
    
    void print(){
        l.print();
    }
    
    void sort(){
        int size = l.get_size();
        int index_may= 0; 
       int temp_m;
       int temp = 0;
        for(int i = 0;  i < size -1; i++){
            int temp = l.get(i)->get_dato()->calc_points();
            index_may = i;
            for( int j = i+1 ; j< size;j++){
                temp_m = l.get(j)->get_dato()->calc_points();
                if( temp > temp_m){
                    temp = temp_m;
                    index_may= j;
                }
            }
            if( index_may != i){
                 Jugador* tempj = l.get(index_may)->get_dato();
                 l.get(index_may)->set_dato(l.get(i)->get_dato());
                 l.get(i)->set_dato(tempj);
                
            }
        }
        
    }
        
        
        
        /*
        for(int i = 1; i < l.get_size(); i++){
            int a = i;
            int b = i-1;
            int c =l.get(b)->get_dato()->calc_points();
            int d = l.get(a)->get_dato()->calc_points();
            //cout<<"Elemento b: "<<l.get(b)->get_dato()->calc_points()<<endl;
            //cout<<"Elemento a: "<<l.get(a)->get_dato()->calc_points()<<endl;
            while(c > d){
                //
                
                for(int i = 0; i < l.get_size(); i++){
                cout<<l.get(i)->get_dato()->get_id()<<"\t";
                }
                cout<<"\n";
                
                //
                cout<<"Elemento b: "<<l.get(b)->get_dato()->calc_points()<<endl;
                cout<<"Elemento a: "<<l.get(a)->get_dato()->calc_points()<<endl;
            
                Nodo<Jugador*>* temp = l.get(a);
                l.get(a)==l.get(b);
                l.get(b)==temp; 
                a--;
                b = a-1;
                cout<<"zzz"<<endl;
            }
        }
        
        int menor, menor_i; 
        for(int j = 0; j<l.get_size()-1;j++){
            menor = l.get(j)->get_dato()->calc_points();
            menor_i = j;
            for(int i = j+1; i< l.get_size();i++){
                if(l.get(i)->get_dato()->calc_points()< menor){
                    menor=l.get(i)->get_dato()->calc_points();
                    menor_i = i;
                }
            }
            
            if(j!=menor_i){
                Nodo<Jugador*>* temp= l.get(j);
                l.get(j) == l.get(menor_i);
                l.get(menor_i) == temp ;
            }
        }
        
        */
    
    
};

int main()
{
    
    srand(1234);
    int num_jugadores = 0;
    int num_colores = 4;
    int num_tarjetas = 10;
    
    //Lea el número de jugadores, hasta que cumpla con la condición
    do{
        cout<< "Ingrese el numero de jugadores"<<endl; 
        cin>>num_jugadores;
        cout<< endl; 
    }while(num_jugadores<2 || num_jugadores >= 5 );



    int winner = rand()%num_jugadores;
    Uno u = Uno();
    
    //Añada num_jugadores jugadores a la lista
    
    for(int i = 0 ; i <  num_jugadores;  i++){
        u.addJugador(new Jugador(i));
        
    }
   
    
    int temp=0;
    for(int i = 0; i<num_colores; i++){
        for(int j = 0; j< num_tarjetas; j++){
            temp = rand()%num_jugadores;
            if(temp != winner){
                u.addTarjeta(temp, new Tarjeta(rand()%num_colores,rand()%num_tarjetas));
            }
        }
    }
    
    u.print();
    
    //Muestre el puntaje de los jugadores, en orden de id
    
    for( int i = 0 ; i < num_jugadores; i++){
        cout<<"Jugador "<< std::to_string(u.getJugador(i)->get_id())<< " tiene: "<< u.getJugador(i)->calc_points()<<" puntos."<<endl ;
        
    }
    

   u.sort(); //Ordena a jugadores y sus cartas internamente

   cout<<"\n"<<endl;
   
   for( int i = 0 ; i < num_jugadores; i++){
        cout<<"Jugador "<< std::to_string(u.getJugador(i)->get_id())<< " tiene: "<< u.getJugador(i)->calc_points()<<" puntos."<<endl ;
        
    }
    
    
    for( int i = 0 ; i < num_jugadores; i++){
        u.getJugador(i)->sort();
        
    }
    u.getJugador(0)->sort();
   cout<<"\n"<<endl;

   u.print();
    
    return 0;
}
