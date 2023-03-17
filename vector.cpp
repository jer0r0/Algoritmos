// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>

using namespace std;

template<typename T>
class Vector{

private:
    int size;
    int capacidad;
    T* v;
    
public:
    
    Vector(int n){
        size = 0;
        capacidad = n;
        v =  new T[capacidad];
    }

    Vector(){
        size = 0;
        capacidad = 10;
        v =  new T[capacidad];
    }
    
    ~Vector(){
        delete[] v;
    }
    
    int get_size(){
        return size;
    }
    
    int get_capacidad(){
        return capacidad;
    }
    
    T get(int i){
        if(i >= 0 && i < size){
            return v[i];
        }else{
            return NULL;
        }
    }
    
    void incrementar_capacidad(){
        capacidad*=2;
        
        T* new_v = new T[capacidad];
        for(int i = 0; i < size; i++){
            new_v[i] = v[i];
        }
        T* old_v =  v;
        v =  new_v;
        
        delete[] old_v;
    }
    
    void add(T valor){
        if(size == capacidad){
            incrementar_capacidad();
        }
        v[size++] =  valor;
    
    }
    
    void mover(T* vector, int size, int posicion){  
        for (int i=size; i>posicion;i--){  
            vector[i]=vector[i-1];  
        } 
    }  

    void mover_atras(T* vector, int size, int posicion){  
        for (int i=posicion; i<size;i++){  
            vector[i]=vector[i+1];  
        } 
    }  

     

    void insert(int indice, int numero){ 
        if (indice>=size){ 
            cout<<"No se puede ingresar un elemento por fuera del vector"<<endl; 
        }else if (size<capacidad){ 
            mover(v,size,indice); 
            v[indice]=numero; 
            size++; 
        }else{ 
            incrementar_capacidad(); 
            mover(v,size,indice); 
            v[indice]=numero; 
            size++; 
        } 
    } 
     

    void eliminar_indi(int indice){ 
        if (indice>=size){ 
            cout<<"Indice invalido"<<endl; 
        }else{ 
            mover_atras(v,size,indice); 
            size--; 
        } 
    } 


    void eliminar_elem(int x){ 
        int indice=buscar_reto_indi(x); 
        if (indice>=size){ 
            cout<<"El elemento no está"<<endl; 
        }else{ 
            mover_atras(v,size,indice); 
            size--; 
        } 
    } 

     

    bool buscar( int x ){ 
        int i=0; 
        bool found =  false; 
        while(i<size && !found){ 
            if(v[i] == x){ 
                found =  true; 
            } 
            i++; 
        }
        return found; 
    } 


    int buscar_reto_indi( int x ){ 
        int i=0; 
        bool found =  false; 
        while(i<size && !found){ 
            if(v[i] == x){ 
                found =  true; 
            }
            i++;
        } 
        if (i<size) 
            return i-1; 
        else 
            return i; 
    } 
    
    
    void print(){
        for(int i = 0; i < size; i++){
            cout<<v[i]<<"\t";}
        cout<<"\n";
    }
    
    void bubble_sort() {
      
      for(int j = 0; j<size-1;j++ ){
        
        for(int i = 0; i < (size-1)-j; i++){
          if(v[i] > v[i+1]){
            
        	int dummy = v[i];
        	v[i] = v[i+1];
        	v[i+1] = dummy;
        	
          }
        }
      }
    }
    
    void select_sort() {
        int menor, menor_i, temp; 
        for(int j = 0; j<size-1;j++){
            menor = v[j];
            menor_i = j;
            for(int i = j+1; i< size;i++){
                if(v[i]< menor){
                    menor=v[i];
                    menor_i = i;
                    for(int i = 0; i < size; i++){
                    //
                    cout<<v[i]<<"\t";
                    }
                    cout<<"\n";
                    //
                }
            }
            if(j!=menor_i){
                temp = v[j];
                v[j] = v[menor_i];
                v[menor_i]= temp ;
            }
        }
    }
    
    void insert_sort(){
        for(int i = 1; i < size; ++i){
            int a = i;
            int b = i-1;
            while(v[b] > v[a]){
                //
                for(int i = 0; i < size; i++){
                cout<<v[i]<<"\t";
                }
                cout<<"\n";
                //
                int temp = v[a];
                v[a]=v[b];
                v[b]= temp; 
                a--;
                b = a-1;
            }
        }
    }
    
    void shell_sort(){
        for (int gap = size/2; gap > 0; gap /= 2){
            for (int i = gap; i < size; i += 1){
                int temp = v[i];
                int j;
                for (j = i; j >= gap && v[j - gap] > temp; j -= gap){
                    v[j] = v[j - gap];
                }
                
                v[j] = temp;
                }
            }
    }

    
};

int main()
{
    
    Vector<int> v = Vector<int>();
    v.add(5);
    v.add(3);
    v.add(19);
    v.add(12);
    v.add(21);
    v.add(4);
    v.add(1);
    v.add(7);
  

    v.print();
    cout<<"\n";
    
    
    cout<<"Usando shell Sort"<<endl;
    v.shell_sort();
    v.print();
    cout<<endl; 
        /*
    cout<<"Insertando los numeros 300,350,400,450"<<"\n"<<endl;
    v.insert(2,300);
    v.insert(4,350);
    v.insert(6,400);
    v.insert(8,450);
    v.print();
    cout<<endl;
    cout<<"Usando selection_sort "<<endl;
    v.selection_sort();
    v.print();
    cout<<endl;
    cout<<"Insertando los numeros 500,550,600,650"<<"\n"<<endl;
    v.insert(2,500);
    v.insert(4,550);
    v.insert(6,600);
    v.insert(8,650);
    v.print();
    cout<<"\n";
    cout<<"Usando insert_sort "<<endl;
    v.insertion_sort();
    v.print();
    cout<<endl;
    */
    
    /*
    v.add(17);
    v.add(4);
    v.add(15);
    v.add(9);
    v.add(22);
    v.add(21);
    v.add(52);
    v.add(2);
    v.add(19);
    v.print();
    v.shell_sort();
    v.print();*/
    /*
    Vector<char> l = Vector<char>();
    l.add('g');
    l.add('o');l.add('o');l.add('g');l.add('l');l.add('e');
    l.print();
    l.bubble_sort();
    l.print();*/
  
    
    
    return 0;
}
