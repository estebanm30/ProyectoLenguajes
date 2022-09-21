#pragma once
#include <iostream> 
#include <string>
#include <sstream>
#include "List.cpp"
using namespace std;

class Convert{
    
    public:
    static string convertPre(string expresion);
    static int hierarchy(char character);
    
};

string Convert::convertPre(string expresion){
        string exprOriginal = "";
        string exprNew = expresion;
        reverse(exprNew.begin(),exprNew.end());
        List* stack = new List();
        char arr[exprNew.length() + 1];
        for (int i = 0; i < sizeof(arr); i++){
            arr[i] = exprNew[i];
        }
        
        for (int i = 0; i < sizeof(arr); i++) {
            if(arr[i] == '(') { 
                arr[i] = ')';
                i++;
            }
            else if(arr[i] == ')') {
                arr[i] = '(';
                i++;
            }
        }
        
        for (int i = 0; i <= sizeof(arr); i++) {
            char character = arr[i];

            if(hierarchy(character) > 0){
               while(stack->peek() && hierarchy(stack->peek()->getToken()) >= hierarchy(character) ){  
                exprOriginal += stack->pop()->getToken();
               }
               stack->push(new Node(character));
            }
                
            else if(character == ')') {
                char temp = stack->pop()->getToken();
                while (temp != '(') {
                    exprOriginal += temp;
                    temp = stack->pop()->getToken();
                }
            }

            else if(character == '('){
                stack->push(new Node(character));
            }
            else {
                exprOriginal += character;
            }
        }
       cout << stack->size() << endl;

        for (int i = 0; i <= stack->size(); i++) {
            exprOriginal += stack->pop()->getToken();
        }
//7*4+6/3+2
        reverse(exprOriginal.begin(),exprOriginal.end());
        return exprOriginal;
    } 
 

 int Convert::hierarchy(char character){
        switch(character){
            case '+':
                return 1;
            case '-':
                return 1;
            
            case '*':
                return 2;
            case '/':
                return 2;
            case '^':
                return 3;
        }
        return -1;
    }


