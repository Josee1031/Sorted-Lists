//
// UAList specification and implementation
//

#include <iostream>
using namespace std;

// include guard

#ifndef UAList_H
#define UAList_H

class UAList {

    protected:  // Clase derivada tendra acceso 
                // a Los data members de la clase.

        int maxSize ;   // Tamaño fisico
        int length ; // Tamaño logico
        int* list ; // La lista

    public: 
        // parameters constructor
        UAList(int = 100) ;

        // Destructor
        ~UAList() ;

        // copy function to be used by the copy constructor
        // and OAO.

        void copy(const UAList& original) ;

        // Copy constructor
        UAList(const UAList& original) ;

        // OAO 
        const UAList& operator=(const UAList& original) ;

        // Getters (accessor, observer)

        bool isEmpty() const ;
        bool isFull() const ;
        int listLength() const ;
        int listSize() const ;
        int search(int item) const ;
        void print() const ;

        // Setters

        void insert(int item) ;
        void remove(int item) ;
        void clear() ;

};
#endif

// Class implementation

// Param. contructor

UAList::UAList(int size) {

    maxSize = (size > 0) ? size : 100 ;
    length = 0 ;
    list = new int[maxSize] ;
}

// Destructor

UAList::~UAList() {

    delete [] list ;
    list = nullptr ;
}

// Copy funcion for CC y

void UAList::copy(const UAList& original) {

    maxSize = original.maxSize ;
    length = original.length ;
    list = new int(maxSize) ;

    // Copy the list

    for(int k = 0; k < length; k++){
        list[k] = original.list[k] ;
    }
}

// Clear list

void UAList::clear() {
    length = 0 ;
}

// Copy Constructor
UAList::UAList(const UAList& original) {

    copy(original) ;
}

// OAO

const UAList& UAList::operator= (const UAList& original){

    if (this != &original) {
        delete [] list ;
        copy(original) ;
    }

    // Devolver la copia del objeto

    return *this ;
}

// isEmpty
bool UAList::isEmpty() const {
    return length == 0 ;
}

// isFull
bool UAList::isFull() const {
    return length == maxSize ;
}

// listLength
int UAList::listLength() const {
    return length ;
}

// listSize
int UAList::listSize() const {
    return maxSize ;
}

// print list

void UAList::print() const {

    if(isEmpty()) {

        cout << "EMPTY list, can not display.\n" ;
    }
    else {
        cout << "\nLos elementos de la lista son:\n" ;
        for (int k = 0; k < length ; k++)
            cout << "\t" << (k+1) << ") " <<
                list[k] << endl ;
    }
}    
// Linear or sequential search
int UAList::search(int item) const {

    int position = -1 ;
    bool found = false ;

    if (isEmpty()) {
        cout << "\tList is empty, can not search.\n" ;
    }
    else {
        for (int k = 0; k < length && !found ; k++){
            if (item == list[k]) {
                position = k ;
                found = true ;
            }
        }
    }
    return position ;
}    
// Insert item

void UAList:: insert(int item) {
     // Lista llena

    if (isFull()) {
        cout << "\tList is FULL, can not insert.\n" ;

    }
    else if(search(item) != -1){
        cout << "\tList doesnot allow duplicates.\n" ;
    }
    else {
        // Insertar al final
        list[length] = item ;
        length++ ;
    }   // End else

} // End of insert   

void UAList::remove(int item) {
    // Lista vacia no hay nada para remover 

    if (isEmpty()) {
        cout << "\tEMPTY list, can not remove.\n" ;
    }
    else{
        int location = search(item) ;
        if(location == -1){
            cout << item << " \tNOT in list, can not remove.\n" ;
        } 
        else { // item esta en la lista.

            // Proceder a remover
            list [location] = list[length - 1] ;
            // Decrementar length
            length-- ;
        }
    }
}       // End of function remove