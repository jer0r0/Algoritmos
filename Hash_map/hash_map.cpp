
#include <string>
#include <iostream>
#include <stdexcept>

const unsigned TABLE_SIZE = 5;

template <typename VT>
struct Cell {
  std::string key;
  VT val;
  Cell<VT> *next;
};

template <typename VT>
class HashMap {
private:
  Cell<VT> **table;
  unsigned table_size;
  unsigned _size;

  unsigned hash(std::string k);
  Cell<VT>* find_in_bucket(unsigned bucket, std::string k);
  void destroy_rec(unsigned bucket);
  //Cell<VT>* find(std::string k);
  
public:
  HashMap();
  ~HashMap();

  void insert(std::string k, VT v);
  void remove(std::string k);
  VT get(std::string k);

  void display();
};

//IMPLEMENTATION----------------------

template <typename VT>
unsigned HashMap<VT>::hash(std::string k) {
  unsigned int hashVal = 0;
  for(char c : k)
    hashVal += 64 * hashVal + c;
  return hashVal % table_size;
}

template <typename VT>
HashMap<VT>::HashMap() {
  table_size = TABLE_SIZE;
  _size = 0;
  table = new Cell<VT>*[table_size];
  for(int i = 0; i < table_size; i++)
    table[i] = nullptr;
}

template <typename VT>
HashMap<VT>::~HashMap() {
  for(int i = 0; i < table_size; i++){
    destroy_rec(i);
  }
  delete[] table;
}

template <typename VT>
void HashMap<VT>::destroy_rec(unsigned bucket) {
  if(table[bucket] != nullptr){
    Cell<VT> *n = table[bucket];
    table[bucket] = table[bucket]->next;
    delete n;
    destroy_rec(bucket);
  }
}

template <typename VT>
Cell<VT>* HashMap<VT>::find_in_bucket(unsigned bucket,
				      std::string k) {
  Cell<VT> *cursor = table[bucket];
  while(cursor != nullptr){
    if(cursor->key == k)
      return cursor;
    cursor = cursor->next;
  }
  return cursor;
}

template <typename VT>
void HashMap<VT>::insert(std::string k, VT v) {
  unsigned bucket = hash(k);
  Cell<VT> *c = find_in_bucket(bucket, k);
  if(c == nullptr){
    Cell<VT> *n = new Cell<VT>;
    n->key = k;
    n->val = v;
    n->next = table[bucket];
    table[bucket] = n;
    _size++;
  }else{
    c->val = v;
  }
}

template <typename VT>
void HashMap<VT>::display() {
  Cell<VT> *cursor;
  for(int i = 0; i < table_size; i++) {
    std::cout << i << ": ";
    cursor = table[i];
    while(cursor != nullptr){
      std::cout << "(" << cursor->key
		<< "," << cursor->val << ") ";
      cursor = cursor->next;
    }
    std::cout << "\n";
  }
}

template <typename VT>
void HashMap<VT>::remove(std::string k) {
  unsigned bucket = hash(k);
  Cell<VT> *c = find_in_bucket(bucket, k);
  if(c != nullptr){
    if(c == table[bucket]){
      table[bucket] = c->next;
    }else{
      Cell<VT> *p = table[bucket];
      while(p->next != c){
	p = p->next;
      }
      p->next = c->next;
    }
    delete c;
    _size--;
  }
}

int main() {
  HashMap<int> mymap;

  mymap.insert("Paco", 25);
  mymap.insert("Mariana", 32);
  mymap.insert("Luisa", 15);
  mymap.insert("Martin", 20);
  mymap.insert("Julio", 50);
  mymap.display();

  std::cout << "\n";
  mymap.remove("Mariana");
  mymap.display();

  std::cout << "\n";
  mymap.remove("Martin");
  mymap.display();
  
  return 0;
}
