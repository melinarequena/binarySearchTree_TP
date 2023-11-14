#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Nodo{
    string palabra;
    int nivel;
    Nodo * izq;
    Nodo * der;
};

Nodo * nuevo(string palabra, int nivel);
Nodo * insertar(Nodo * nodo, Nodo * raiz);


Nodo * insertar(Nodo *nodo, Nodo *raiz) {
    if(!raiz){
        return nodo;
    }
    if(nodo->palabra > raiz->palabra){
        insertar(raiz->der, nodo);
    }

}

Nodo *nuevo(string palabra, int nivel) {
    Nodo * aux = nullptr;
    aux = new Nodo{palabra, nivel, nullptr, nullptr};
    return nuevo;
}


int main() {
    string parrafo;
    cout << "Ingrese un texto\n";
    getline(cin, parrafo);
    string palabra;

   istringstream stream(parrafo);

   while(stream >> palabra){
       insertar(nuevo(palabra, SDHFHNSDHF));
   }





    return 0;
}