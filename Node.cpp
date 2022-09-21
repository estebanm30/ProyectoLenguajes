#pragma once
#include <iostream> 
#include <string>
using namespace std;

class Node{
    private:
        char token;
    public:
        Node(char token){
            this->token = token;
            this->next = NULL;
        }
        Node* next;
        char getToken();
};

char Node::getToken(){
    return this->token;
}
