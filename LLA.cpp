
#include "sort.hh"
using namespace std;

int DisplayMenu();
void ExecuteOption(int option, SAList& myList);

int main(){

  //menu
int option;
int max;

  cout<<"\n\tChoose the max size for your list: ";
  cin>>max;
  SAList myList(max);
  do{
    option = DisplayMenu();
    ExecuteOption(option, myList);

  }while (option!=8);
    return 0;
} // end of main


int DisplayMenu(){
  int option;
  do{
    cout<<"\n\t<<<LIST OPTIONS>>>"<<"\n"
    <<"\t1. Insert an item to the list.\n"
    <<"\t2. Search the list for an item.\n"
    <<"\t3. Remove an item from the list.\n"
    <<"\t4.Display the list\n"
    <<"\t5. Capacity of the list.\n"
    <<"\t6. Length of the list.\n"
    <<"\t7. Clear the list.\n"
    <<"\t8. Exit the program.\n"
    <<"\n\tEnter your selection: ";
    cin>>option;
    if(option<1 || option >8){
      cout<<"\n\tInvalid option must be between 1-8"<<endl;
    }
  } while (option <1 || option>8);
    return option;
  }

  void ExecuteOption(int option,SAList& myList){
    int item;
    int index;
    switch (option){
      case 1: cout<<"\n\tInserting an item to the list.\n";
              cout<<"\tWhich integer would you like to insert: ";
              cin>>item;
              myList.insert(item);
              break;

      case 2: cout<<"\n\tSearching an item from the list.\n";
               cout<<"\tWhich integer would you like to search: ";
              cin>>item;
              index=myList.search(item);
              if (index == -1){
                cout<<"\t"<<item<<" is not in the list.\n";
              }
              else{
                cout << "\t" << item << " in position: " << index + 1 << endl;
              }
              
              break;

      case 3: cout<<"\n\tRemoving an item in the list.\n";
              cout<<"\tWhich integer would you like to remove: ";
              cin>>item;
              myList.remove(item);
              break;

       case 4: cout << "\n\tDisplaying the list. \n" ;
                myList.print() ;
                break;

        case 5: cout << "\n\tDisplaying the capacity of the list. \n" ;
                cout << "\tList capacity: " 
                    << myList.listSize() << endl ;
                break;

        case 6: cout << "\n\tDisplaying the length of the list. \n" ;
                cout << "\tList length: " 
                    << myList.listLength() << endl ;
                break;

        case 7: cout << "\n\tClearing the list. \n" ;
                myList.clear() ;
                break;

        case 8: cout << "\n\tExit the program. \n" ;
                break;    
  }
  }


