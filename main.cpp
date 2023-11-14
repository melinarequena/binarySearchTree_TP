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

Nodo * nuevo(string palabra);
Nodo * insertar(Nodo * nodo, Nodo * raiz);
void buscar(Nodo * raiz, string buscar);



Nodo * insertar(Nodo *nodo, Nodo *raiz) {
    if(!raiz){
        return nodo;
    }
    if(nodo->palabra > raiz->palabra){
        nodo->nivel = raiz->nivel+1;
        insertar(raiz->der, nodo);
    }

    if(nodo->palabra < raiz->palabra){
        nodo->nivel = raiz->nivel+1;
        insertar(raiz->izq, nodo);
    }

}

Nodo *nuevo(string palabra) {
    Nodo * aux = nullptr;
    aux = new Nodo{palabra, 0, nullptr, nullptr};
    return aux;
}

void buscar(Nodo *raiz, string buscar) {
    if(!raiz){
        cout << "Arbol vacio, no se encuentra la palabra\n";
        return;
    }
    if(raiz->palabra == buscar){
        cout << "Palabra encontrada, nivel " << raiz->nivel;
        return;
    }
}
    if(raiz->palabra < buscar){
        buscar(raiz->der, buscar);
    }

    if(raiz->palabra > buscar){
        buscar(raiz->izq, buscar);
    }

int main() {
    Nodo * raiz = nullptr;

    string parrafo, buscar;
    cout << "Ingrese un texto\n";
    getline(cin, parrafo);
    string palabra;

   istringstream stream(parrafo);

   while(stream >> palabra){
       insertar(nuevo(palabra, SDHFHNSDHF));
   }

    cout << "Ingrese palabra a buscar:\n";
    cin >> buscar;



    return 0;
}