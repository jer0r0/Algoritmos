#include "sort.hpp"

void max_heapify(std::vector<int> &v,
		 unsigned i, unsigned size) {
  unsigned id = i + 1;
  unsigned l = (2*id) - 1;
  unsigned r = (2*id+1) - 1;
  unsigned max = i;
  if(l < size && v[i] < v[l])
    max = l;
  if(r < size && v[max] < v[r])
    max = r;
  if(max != i){
    int temp = v[max];
    v[max] = v[i];
    v[i] = temp;

    max_heapify(v, max, size);
  }
}

void heap_sort(std::vector<int> &v) {
  for(int i = v.size()/2; i >= 0; i--)
    max_heapify(v, i, v.size());

  for(int i = 0; i < v.size(); i++){
    //swap
    int tmp = v[v.size()-1-i];
    v[v.size()-1-i] = v[0];
    v[0] = tmp;

    //heapify
    max_heapify(v, 0, v.size()-1-i);
  }
}

//--------------------------------------------


void merge(std::vector<int> &v, std::vector<int> &aux,
	   unsigned left, unsigned right) {
  unsigned mid = (left + right) / 2;
  unsigned l = left;
  unsigned r = mid;
  unsigned h = l;
  while(l < mid && r < right){
    if(v[l] < v[r])
      aux[h++] = v[l++];
    else
      aux[h++] = v[r++];
  }
  while(l < mid)
    aux[h++] = v[l++];
  while(r < right)
    aux[h++] = v[r++];

  for(int i = left; i < right; i++)
    v[i] = aux[i];
}

void merge_sort(std::vector<int> &v, std::vector<int> &aux,
	       unsigned left, unsigned right) {
  if(left < right -1){
    unsigned mid = (left + right) / 2;
    merge_sort(v, aux, left, mid);
    merge_sort(v, aux, mid, right);
    merge(v, aux, left, right);
  }
}

void merge_sort(std::vector<int> &v) {
  std::vector<int> aux(v.size());
  merge_sort(v, aux, 0, v.size());
}

//--------------------------------------------

unsigned partition(std::vector<int> &v,
		   unsigned left, unsigned right) {
  int x = v[right-1];
  int i = left - 1;
  for(int j = left; j < right-1; j++){
    if(v[j] <= x){
      i++;
      int tmp = v[i];
      v[i] = v[j];
      v[j] = tmp;
    }
  }

  int tmp = x;
  v[right-1] = v[i+1];
  v[i+1] = tmp;
  return i+1;
}

void quick_sort(std::vector<int> &v,
		unsigned left, unsigned right) {
  if(left < right){
    int p = partition(v, left, right);
    quick_sort(v, left, p);
    quick_sort(v, p+1, right);
  }
}

void quick_sort(std::vector<int> &v) {
  quick_sort(v, 0, v.size());
}

//******************************************************************

void insertion_sort(std::vector<int> &v) {
  for(int i = 1; i < v.size(); i++){
    int a = i;
    while(v[a]<v[a-1] && a > 0){
      int dummy = v[a];
      v[a] = v[a-1];
      v[a-1] = dummy;
      a--;
    }
  }
}

void selection_sort(std::vector<int> &v) {
  for(int i = 0; i < v.size()-1; i++){
    
    //busca menor
    int min = v[i];
    int id = i;
    for(int j = i+1; j < v.size(); j++){
      if(v[j] < min){
	min = v[j];
	id = j;
      }
    }

    int dummy = v[i];
    v[i] = v[id];
    v[id] = dummy;
    
  }
}

void bubble_sort(std::vector<int> &v) {
  bool s = true;
  while(s){
    s = false;
    for(int i = 0; i < v.size()-1; i++){
      if(v[i] > v[i+1]){
	int dummy = v[i];
	v[i] = v[i+1];
	v[i+1] = dummy;
	s = true;
      }
    }
  }
}
