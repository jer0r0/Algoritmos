#include "functions.hpp"

double gettime(){
  struct timeval tp;
  gettimeofday(&tp, NULL);
  return tp.tv_sec + tp.tv_usec/(double)1.0e6;
}

void generate_vector(int size, vector<int>& v, minstd_rand0& rng){
  v.clear();
  const int max_num = size;
  //Generation of a sequence of (pseudo)random numbers
  rng();
  for(int i = 0; i < size; ++i){
    int num = int(max_num * ( double(rng()) / rng.max() ));
    v.push_back(num);
  }
}

void generate_ordered_vector(int size, vector<int>& v, minstd_rand0& rng, bool inv){
  v.clear();
  //Generation of an ordered sequence of (pseudo)random numbers
  rng();
  if(!inv){
    int current = 0;
    for(int i = 0; i < size; ++i){
      //number between 0 and 1
      int bin = int(2 * ( double(rng()) / rng.max() ));
      int num;
      if(bin == 1){
	num = i;
	current = i;
      }else
	num = current;
      v.push_back(num);
    }
  }else{
    int current = size-1;
    for(int i = size-1; i >= 0; --i){
      //number between 0 and 1
      int bin = int(2 * ( double(rng()) / rng.max() ));
      int num;
      if(bin == 1){
	num = i;
	current = i;
      }else
	num = current;
      v.push_back(num);
    }
  }
}

void generate_norepeat_vector(int size, vector<int>& v, minstd_rand0& rng){
  v.clear();
  const int max_num = 3*size;
  //use set to profit from the count method
  set<int> numbers;
  //Generation of a sequence of (pseudo)random numbers
  rng();
  int count = 0;
  while(count < size){
    int num = int(max_num * ( double(rng()) / rng.max() ));
    if(numbers.count(num) == 0){ //if number not in set
      numbers.insert(num);
      v.push_back(num);
      count++;
    }
  }
}

void swap(int i, int j, vector<int>& v){
  int temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

void print_vector(vector<int>& v){
  for(int i = 0; i < v.size(); ++i)
    cout << v[i] << " ";
  cout << "\n";
}
