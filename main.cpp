#include <iostream>
using namespace std;


struct Nodo {
    int dato;
    Nodo* sig;
};


Nodo* pila = NULL;


Nodo* frente = NULL;
Nodo* fin = NULL;


Nodo* lista = NULL;


void push(int x) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = x;
    nuevo->sig = pila;
    pila = nuevo;
}

void pop() {
    if (pila == NULL) {
        cout << "Pila vacia\n";
        return;
    }
    Nodo* temp = pila;
    pila = pila->sig;
    delete temp;
}

void mostrarPila() {
    Nodo* aux = pila;
    cout << "Pila (impares): ";
    while (aux != NULL) {
        cout << aux->dato << " -> ";
        aux = aux->sig;
    }
    cout << "NULL\n";
}

void enqueue(int x) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = x;
    nuevo->sig = NULL;

    if (frente == NULL) {
        frente = fin = nuevo;
    } else {
        fin->sig = nuevo;
        fin = nuevo;
    }
}

void dequeue() {
    if (frente == NULL) {
        cout << "Cola vacia\n";
        return;
    }
    Nodo* temp = frente;
    frente = frente->sig;

    if (frente == NULL) {
        fin = NULL;
    }

    delete temp;
}

void mostrarCola() {
    Nodo* aux = frente;
    cout << "Cola (pares): ";
    while (aux != NULL) {
        cout << aux->dato << " -> ";
        aux = aux->sig;
    }
    cout << "NULL\n";
}

void insertarLista(int x) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = x;
    nuevo->sig = lista;
    lista = nuevo;
}

void mostrarLista() {
    Nodo* aux = lista;
    cout << "Lista (negativos): ";
    while (aux != NULL) {
        cout << aux->dato << " -> ";
        aux = aux->sig;
    }
    cout << "NULL\n";
}

void liberar(Nodo*& estructura) {
    while (estructura != NULL) {
        Nodo* temp = estructura;
        estructura = estructura->sig;
        delete temp;
    }
}


int main() {
    int opcion, num;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Ingresar numero\n";
        cout << "2. Mostrar pila\n";
        cout << "3. Mostrar cola\n";
        cout << "4. Mostrar lista\n";
        cout << "5. Eliminar de pila\n";
        cout << "6. Eliminar de cola\n";
        cout << "7. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Entrada invalida\n";
            continue;
        }

        switch (opcion) {
            case 1:
                cout << "Ingrese numero (-1 para terminar): ";
                cin >> num;

                if (num == -1) break;

                if (num < 0) {
                    insertarLista(num);
                } else if (num % 2 == 0) {
                    enqueue(num);
                } else {
                    push(num);
                }
                break;

            case 2:
                mostrarPila();
                break;

            case 3:
                mostrarCola();
                break;

            case 4:
                mostrarLista();
                break;

            case 5:
                pop();
                break;

            case 6:
                dequeue();
                break;

            case 7:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opcion invalida\n";
        }

    } while (opcion != 7);

    liberar(pila);
    liberar(lista);
    liberar(frente);

    return 0;
}