#pragma once
#include <iostream> 
#include <string>
#include "Node.cpp"
using namespace std;

class List{
    private:
        Node* head;
    public :

        List(){
            this->head = NULL;
        };
        void push(Node* data);
        Node* pop();
        Node* peek();
        int size();
};

Node* List ::pop(){
    Node* tmp = this->head;
    this->head = this->head->next;
    return tmp;
}

void List :: push(Node* data){
    data->next = this->head;
    this->head = data;
}

Node* List::peek(){
    return this->head;
}

 int List::size(){
    int i = 0;
    Node* temp = this->head;
    while(temp){
        i++;
        temp = temp->next;
    }
    return i;
 }


