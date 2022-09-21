#include <iostream> 
#include <string>
#include "Convert.cpp"
#include "List.cpp"


using namespace std;

int main(){
    cout << "Escriba la expresion" << endl;
    string expr = "";
    getline(cin, expr);
    string exprePolac = Convert::convertPre(expr);
    cout << "La expresion Polaca es: " << exprePolac << endl;
}

