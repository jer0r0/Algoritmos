
#include<iostream>

using namespace std;

class Node{
  int data;
  Node* izq;
  Node* der;
 
public:

  Node(){
      data=0;
      izq = NULL;
      der =  NULL;
  }

  Node(int d){
      data=d;
      izq = NULL;
      der =  NULL;
  }
 
  int getData(){
      return data;
  }
 
  Node* getIzq(){
      return izq;
  }
 
  Node* getDer(){
      return der;
  }
 
  void setIzq(Node* iz){
      izq =  iz;
  }
 
  void setDer(Node* de){
      der =  de;
  }
 
  bool hasIzq(){
      return izq!=NULL;
  }
 
  bool hasDer(){
      return der!=NULL;
  }
 
  bool isHoja(){
      if(izq == NULL && der == NULL)
        return true;
       
      return false;
  }
   
};

class Tree{
  Node* root;

public:
  Tree(){
      root = NULL;
  }
 
  Node* getRT(){
      return root;
  }
 
  void add(int d){
      Node* n = new Node(d);
      if(root == NULL){
          root = n;
      }else{
          Node* t = root;
          bool found = false;
          while(!found){
              if(t->getData() < n->getData()){
                if(t->hasDer()){
                    t =  t->getDer();
                }else{
                    t->setDer(n);
                    found=true;
                }  
              }else{
                if(t->hasIzq()){
                    t =  t->getIzq();
                }else{
                    t->setIzq(n);
                    found=true;
                }
              }
          }
      }
  }

  void preorder(){
      preorder(root);
      cout<<endl;
  }

  void preorder(Node* r){
      if(r != NULL){
          
          preorder(r->getIzq());
          cout<<r->getData()<<"\t";
          preorder(r->getDer());
      }
  }


   
  void addr(int d){
      if(root != NULL)
        addr(d, root, root);
      else
        root =  new Node(d);
    }

    void addr(int d, Node* t, Node* pt){
        if(t == NULL){
            Node* n = new Node(d);
            if(d < pt->getData()){
                pt->setIzq(n);
            }else{
                pt->setDer(n);
            }
        }else{
            if(d < t->getData()){
                addr(d, t->getIzq(), t);
            }else{
                addr(d, t->getDer(), t);
            }
        }
    }

  void addre(int d){
      if(root != NULL)
        addre(d, root, root);
      else
        root =  new Node(d);
    }

    void addre(int d, Node* t, Node* pt){
        if(t == NULL){
            Node* n = new Node(d);
            if(d > pt->getData()){
                pt->setIzq(n);
            }else{
                pt->setDer(n);
            }
        }else{
            if(d > t->getData()){
                addre(d, t->getIzq(), t);
            }else{
                addre(d, t->getDer(), t);
            }
        }
    }    
   
   
    void preorder2(Node* r, Tree* t){
      if(r != NULL){
          t->addre(r->getData());
          preorder2(r->getIzq(), t);
          preorder2(r->getDer(), t);
      }
    }
    
    void preorder_2(){
        preorder_2(root,0);
    }

     void preorder_2(Node* r, int level){
         if(r != NULL){
             if(level <= 2){
                 preorder_2(r->getIzq(), level+1);
                 cout<<r->getData()<<"("<<level<<")"<<"\t";
                 preorder_2(r->getDer(), level +1);
             }
         }
     }
     void preorderlevel(){
        preorderlevel(root,0);
        cout<<endl;
    }

     void preorderlevel(Node* r, int level){
         if(r != NULL){
                 preorderlevel(r->getIzq(), level+1);
                 cout<<r->getData()<<"("<<level<<")"<<"\t";
                 preorderlevel(r->getDer(), level +1);
         }
     }
     
     
   
};

Tree* espejo(Tree t){
    Tree*copy = new Tree();
    t.preorder2(t.getRT(),copy);
    return copy;
}




int main()
{
   
    Tree mytree;
    Tree* copy;
    mytree.add(18);
    mytree.add(12);
    mytree.add(15);
    mytree.add(24);
    mytree.add(21);
    mytree.add(41);
    mytree.add(13);
    mytree.add(16);
   cout<<"imprimiendo la version normal"<<endl;
    mytree.preorderlevel();
    
   cout<<"imprimiendo la version espejo"<<endl;
    
    copy = espejo(mytree);
    
    copy->preorder();

    
    
   
    return 0;
}