#ifndef STEFFLIST_H
#define STEFFLIST_H

/*  Steffani Pfeifer
    HW5
    28 Mar 13
    CS419
    Spring 13

    This program enters a linked list from either the front or the back,
    checks to see if it is empty, and prints the data.*/

#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

class stefflist{

public:
    stefflist();
    bool empty();
    void pushfront(const int &val);
    void pushback(const int &val);
    void output();
    ~stefflist();
    stefflist & operator =(const stefflist &origlist);
    stefflist(const stefflist &origlist);

private:
    node *head, *tail;
};

// constructor to initialize the list with a head and a tail
stefflist::stefflist(){
    head = new node;
    tail = new node;
    head->next = tail;
    tail->next = 0;
}

// test to see if list is empty (head node points to tail)
bool stefflist::empty(){
    return (head->next == tail);
}

// add value to front of list and point the head to it and point it to the next value
void stefflist::pushfront(const int &val){
    node* np;
    np = new node;
    np->data = val;
    
    np->next = head->next;
    head->next = np;
}

// add value to the back of list and point the previous value to it and it to the tail
void stefflist::pushback(const int &val){
    node* np;
    np = new node;
    np->data = val;

    node* curr = head;
    while (curr->next != tail)
      curr = curr->next;
    np->next = tail;
    curr->next = np;
}

// print the values in the list one on each line
void stefflist::output(){
    node *temp = head->next;
    if (empty() )
      cout<<"The list is empty.";
    else{
      while (temp != tail){
        cout<<temp->data << endl;
        temp = temp->next;
      }
    }
    cout<<endl;
}

stefflist::~stefflist(){
    node *temp = head;
    while (temp->next != 0){
      head = temp->next;
      delete temp;
      temp = head;
    }
    delete head;
}

stefflist::stefflist(const stefflist& origlist){
    cout<<"made it to the first line";
    node *orig_pt, *new_pt, *this_pt;
    head = new node;
    tail = new node; 
    head->next = tail;
    tail->next = 0;
    orig_pt = origlist.head->next;
//    this_pt = head;
    while ( orig_pt != origlist.tail ){
      pushback(orig_pt->data);
      orig_pt = orig_pt->next;
    }
}

stefflist& stefflist::operator =(const stefflist &origlist){
    if ( &origlist != this ){
      node *this_pt = head->next;
      node *cur;
      while ( this_pt != tail){
        cur = this_pt->next;
        this_pt = this_pt->next;
        delete cur;
      }
      head->next = tail;

      node *orig_pt, *new_pt;

      orig_pt = origlist.head->next;
      this_pt = head;
      while ( orig_pt != origlist.tail ){
        pushback(orig_pt->data);
        orig_pt = orig_pt->next;
      }
    }
    return *this;
}
    

#endif
