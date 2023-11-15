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
Nodo * insertar(Nodo * nodo, Nodo *raiz);
void buscarPalabra(Nodo * raiz, string buscar);



Nodo * insertar(Nodo *nodo, Nodo *raiz) {
    if (!raiz) {
        return nodo;
    }
   nodo->nivel = raiz->nivel + 1;
    if (nodo->palabra > raiz->palabra) {
        raiz->der = insertar(nodo, raiz->der);
    } else {
        if (nodo->palabra < raiz->palabra) {
            raiz->izq = insertar(nodo, raiz->izq);
        }

    }
    return raiz;
}

Nodo *nuevo(string palabra) {
    Nodo * aux = new Nodo{palabra, 0, nullptr, nullptr};
    return aux;
}

void buscarPalabra(Nodo *raiz, string buscar) {
    if (!raiz) {
        cout << "No se encuentra la palabra\n";
        return;
    }
    if (raiz->palabra == buscar) {
        cout << "Palabra encontrada, nivel " << raiz->nivel;
        return;
    }
    if (raiz->palabra < buscar) {
        buscarPalabra(raiz->der, buscar);
    }

    if (raiz->palabra > buscar) {
        buscarPalabra(raiz->izq, buscar);
    }
}

int main() {
    Nodo * raiz = nullptr;

    string parrafo, buscar;
    cout << "Ingrese un texto\n";
    getline(cin, parrafo);

   istringstream stream(parrafo);
    string palabra;

   while(stream >> palabra){
       insertar(nuevo(palabra), raiz);
   }

    cout << "Ingrese palabra a buscar:\n";
    cin >> buscar;

    buscarPalabra(raiz, buscar);

    return 0;
}