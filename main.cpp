/*
 * C++ Program to Implement Singly Linked List
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

/* Node Declaration */
struct node {
  int info;
  struct node *next;
}*start;

/* Class Declaration */
template <class T>
class SList {
  public:
    SList() {
      start = NULL;
    }

    node* create_node(T);
    void insert_begin();
    void insert_pos();
    void insert_last(); 
    void delete_pos();
    void print();
    struct iterator; 

    iterator begin();
    iterator end();
};
 
template <class T>
struct SList<T>::iterator {
  public:
    T& operator*() const;
    iterator& operator++();
    iterator operator++(int);

  private: 
    node* cur;
    iterator(node* other);

  friend class SList;
};
 
/*
 * Main :contains menu 
 */
int main() {
  int choice, nodes, element, position, i;
  string dataType;

  // while(!haveDataType) {
  //   cout << "What data type would you like? Enter: 'char' or 'int'" << endl;
  //   cin >> dataType;

  //   switch(dataType) {

  //   }
  // }
  
  SList<int> sl;
  start = NULL;

  while(1) {
    
    cout<<endl<<"---------------------------------"<<endl;
    cout<<endl<<"Operations on singly linked list"<<endl;
    cout<<endl<<"---------------------------------"<<endl;
    cout<<"1.Insert Node at beginning"<<endl;
    cout<<"2.Insert node at last"<<endl;
    cout<<"3.Insert node at position"<<endl;
    cout<<"5.Delete a Particular Node"<<endl;
    cout<<"8.Print Linked List"<<endl;
    cout<<"10.Exit "<<endl;
    cout<<"Enter your choice : ";
    
    cin>>choice;

    switch(choice) {
      case 1:
        cout<<"Inserting Node at Beginning: "<<endl;
        sl.insert_begin();
        cout<<endl;
        break;
      case 2:
        cout<<"Inserting Node at Last: "<<endl;
        sl.insert_last();
        cout<<endl;
        break;
      case 3:
        cout<<"Inserting Node at a given position:"<<endl;
        sl.insert_pos();
        cout<<endl;
        break;
      case 5:
        cout<<"Delete a particular node: "<<endl;
        sl.delete_pos();
        break;
      case 8:
        cout<<"Print elements of link list"<<endl;
        sl.print();
        cout<<endl;
        break;
      case 10:
        cout<<"Exiting..."<<endl;
        exit(1);
        break;  
      default:
        cout<<"Wrong choice"<<endl;
    }
  }
}
 
template <class T>
node *SList<T>::create_node(T value) {
  struct node *temp, *s;
  temp = new(struct node); 
  
  if(temp == NULL) {
    cout<<"Memory not allocated "<<endl;
    return 0;
  } else {
    temp->info = value;
    temp->next = NULL;     
    return temp;
  }
}
 
template <class T>
void SList<T>::insert_begin() {
  T value;
  
  cout << "Enter the value to be inserted: ";
  cin >> value;
  
  struct node *temp, *p;

  temp = create_node(value);

  if(start == NULL) {
    start = temp;
    start->next = NULL;          
  } else {
    p = start;
    start = temp;
    start->next = p;
  }

  cout << "Element Inserted at beginning" << endl;
}

template <class T>
void SList<T>::insert_last() {
  int value;
  cout << "Enter the value to be inserted: ";
  cin >> value;

  struct node *temp, *s;

  temp = create_node(value);

  if(start == NULL) {
    start = temp;
    start->next = NULL;          
  } else {
    s = start;

    while(s->next != NULL) {         
      s = s->next;        
    }

    temp->next = NULL;
    s->next = temp;
  }
  
  cout<<"Element Inserted at last"<<endl;  
}
 
template <class T>
void SList<T>::insert_pos() {
  int value, pos, counter = 0; 

  cout << "Enter the value to be inserted: ";
  cin >> value;

  struct node *temp, *s, *ptr;
  
  temp = create_node(value);
  
  cout<<"Enter the postion at which node to be inserted: ";
  cin>>pos;
  
  int i;
  s = start;
  while(s != NULL) {
    s = s->next;
    counter++;
  }

  if(pos == 1) {
    if (start == NULL) {
      start = temp;
      start->next = NULL;
    } else {
      ptr = start;
      start = temp;
      start->next = ptr;
    }
  } else if(pos > 1  && pos <= counter) {
    s = start;
    for (i = 1; i < pos; i++) {
      ptr = s;
      s = s->next;
    }

    ptr->next = temp;
    temp->next = s;
  } else {
    cout << "Positon out of range" << endl;
  }
}
 
template <class T>
void SList<T>::delete_pos()
{
  int pos, i, counter = 0;
  if(start == NULL) {
    cout << "List is empty" << endl;
    return;
  }
  
  cout << "Enter the position of value to be deleted: ";
  cin >> pos;
  
  struct node *s, *ptr;
  s = start;

  if(pos == 1) {
      start = s->next;
  } else {
    while (s != NULL)
    {
      s = s->next;
      counter++;  
    }

    if (pos > 0 && pos <= counter) {
      s = start;
      for (i = 1;i < pos;i++)
      {
          ptr = s;
          s = s->next;
      }
      ptr->next = s->next;
    } else {
      cout << "Position out of range" << endl;
    }

    free(s);
    cout << "Element Deleted" << endl;
  }
}
 
template <class T>
void SList<T>::print()
{
  struct node *temp;
  if(start == NULL) {
    cout<<"The List is Empty"<<endl;
    return;
  }

  temp = start;
  cout<<"Elements of list are: "<<endl;
  
  while(temp != NULL) {
    cout<<temp->info<<"->";
    temp = temp->next;
  }

  cout<<"NULL"<<endl;
}

 
template <class T>
SList<T>::iterator SList<T>::end() {
  return SList::iterator(fake);
}
 
template <class T>
SList<T>::iterator SList<T>::begin() {
  return SList::iterator(ptr);
}
 
template <class T>
T& SList<T>::iterator::operator*() const {
  return cur->key;
}
 
template <class T>
iterator SList<T>::iterator& SList<T>::iterator::operator++() {
  cur = cur->next;
  return *this; 
}
 
template <class T>
iterator SList<T>::iterator SList<T>::iterator::operator++(T) {
  iterator temp = *this;
  cur = cur->next;
  return temp;
}
