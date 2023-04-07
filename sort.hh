#include "list.hh"
#ifndef SALIST_H
#define SALIST_H


class SAList: public UAList{
public:
SAList(int size);
//Destructor
~SAList();
//overriding
int search(int) const;
void insert(int);
void remove(int);
};
#endif

// Constructors
SAList::SAList(int size) : UAList(size) {
    
    cout << "\tInvoking SAList constructor" ;
}

    // Destructor

SAList::~SAList() {}

    // Overriding (redefining) functions

int SAList::search(int item) const {
    int index = -1 ;

    if(isEmpty()) {
        cout << "\tList is empty, cannot search.\n" ;
    }
    else { // List is not empty
       
        // Binary search

        bool isFound = false ;
        int first = 0 ;
        int last = length - 1 ;
        int middle ;

        while (first <= last && !isFound) {
            middle = (first + last) / 2 ;
            if(item == list[middle]) {
                isFound = true ;
                index = middle ;
            }
            else if (item < list[middle]) {
                last = middle -1 ;
            }
            else { // item > list[middle]
                first = middle + 1 ;
            }    
        } // End while
    }
    return index;
}
    
void SAList::insert(int item) {
  if(isFull())
    cout<< "\tList is full, cannot insert\n";
  else if(isEmpty()){
    list[length]= item;
    length++;
  }
  else if(search(item) != -1)
  cout<<"\tItem: "<<item<<" already in list.\n";
  else{
    //locate position for

    int position = 0;
    while (position < length && item <list[position]){
      position++;
    } 
    for (int i = length; i > position; i--){
      list[i]=list[i-1];
    }
    list[position] = item;
    length++;
  }
  

}

void SAList::remove(int item) {
  if(isEmpty())
  cout<<"\tList is Empty,can not remove. \n";
  else{
    int position =search(item);
    if(position == -1)
      cout<<"\t"<<item<< " is not on the list. \n";
      else{
        for (int i=position+1; i< length;i++){
          //cerrar el hueco
          list[i-1]=list[i];
          //decrementar el length
          length--;
        }
      }

  }

}
