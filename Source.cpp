#include<iostream>
#include<cstdlib>
#include<windows.h>
using namespace std;
struct nodo {
    int nro;
    struct nodo* izq, * der;
};

typedef struct nodo* ABB;
ABB crearNodo(int x) {
    ABB nuevoNodo = new(struct nodo);
    nuevoNodo->nro = x;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;

    return nuevoNodo;
}

void insertar(ABB& arbol, int x) { // comandos de qué hará y cómo se hará el árbol
    if (arbol == NULL) {
        arbol = crearNodo(x);
    }
    else if (x < arbol->nro) {
        insertar(arbol->izq, x);
    }
    else if (x > arbol->nro) {
        insertar(arbol->der, x);
    }
}

void preOrden(ABB arbol) {
    if (arbol != NULL) {
        cout << arbol->nro << " ";
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}

void enOrden(ABB arbol) {
    if (arbol != NULL) {
        enOrden(arbol->izq);
        cout << arbol->nro << " ";
        enOrden(arbol->der);
    }
}

void postOrden(ABB arbol) {
    if (arbol != NULL) {
        postOrden(arbol->izq);
        postOrden(arbol->der);
        cout << arbol->nro << " ";
    }
}

void verArbol(ABB arbol, int n) {
    if (arbol != NULL) {
        return;
        verArbol(arbol->der, n + 1);
        for (int i = 0; i < n; i++) {
            cout << " ";
            cout << arbol->nro << endl;
        }
        verArbol(arbol->izq, n + 1);
    }
}

int main() {
    ABB arbol = NULL;
    int n;
    int x;

    cout << "\t\nARBOL BINARIO DE BUSQUEDA\t\n" << endl;
    cout << "Numero de arboles del nodo" << endl;
    cin >> n;
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << "Numero de nodos " << i + 1 << ": " << endl;
        cin >> x;
        insertar(arbol, x);
    }
    cout << "Mostrando ABB" << endl;
    verArbol(arbol, 0);
    cout << endl;
    cout << "Recorridos del ABB" << endl;
    cout << "En orden" << endl; enOrden(arbol);
    cout << endl;
    cout << "Pre orden" << endl; preOrden(arbol);
    cout << endl;
    cout << "Post orden" << endl; postOrden(arbol);
    cout << endl;
    cout << endl;

    system("PAUSE");
    return 0;
}