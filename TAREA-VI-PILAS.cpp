#include <iostream>
#include <string>

using namespace std;

// ==========================
// Estructura del nodo
// ==========================
struct Nodo {
    string accion;
    Nodo* siguiente;
};

// ==========================
// Función push
// Inserta una acción en la cima de la pila
// ==========================
void push(Nodo*& pila, string accion) {
    Nodo* nuevo = new Nodo;
    nuevo->accion = accion;
    nuevo->siguiente = pila;
    pila = nuevo;
}

// ==========================
// Función pop
// Saca una acción de la cima de la pila
// Devuelve true si pudo sacar elemento
// ==========================
bool pop(Nodo*& pila, string& accion) {
    if (pila == nullptr) {
        return false;
    }

    Nodo* temp = pila;
    accion = temp->accion;
    pila = pila->siguiente;
    delete temp;
    return true;
}

// ==========================
// Mostrar pila
// ==========================
void mostrar(Nodo* pila, string nombrePila) {
    cout << "\n===== " << nombrePila << " =====" << endl;

    if (pila == nullptr) {
        cout << "La pila esta vacia." << endl;
        return;
    }

    int contador = 1;
    Nodo* aux = pila;

    while (aux != nullptr) {
        cout << contador << ". " << aux->accion << endl;
        aux = aux->siguiente;
        contador++;
    }
}

// ==========================
// Limpiar pila completa
// Importante para rehacer
// ==========================
void limpiarPila(Nodo*& pila) {
    string accionEliminada;
    while (pop(pila, accionEliminada)) {
        // Solo se vacia la pila
    }
}

// ==========================
// Mostrar estado actual
// ==========================
void mostrarEstadoActual(Nodo* acciones) {
    cout << "\n===== ACCIONES ACTUALES =====" << endl;

    if (acciones == nullptr) {
        cout << "No hay acciones realizadas." << endl;
    } else {
        mostrar(acciones, "Pila de acciones");
    }
}

// ==========================
// Programa principal
// ==========================
int main() {
    Nodo* pilaAcciones = nullptr;
    Nodo* pilaRehacer = nullptr;

    int opcion;
    string accion;

    cout << "==============================================" << endl;
    cout << " Universidad Mariano Galvez de Guatemala" << endl;
    cout << " Ingenieria en Sistemas - 5to Semestre" << endl;
    cout << " Simulador de Deshacer / Rehacer con Pilas" << endl;
    cout << " Nombre: Erick Hernandez" << endl;
    cout << "==============================================" << endl;

    do {
        cout << "\n========== MENU ==========" << endl;
        cout << "1. Realizar accion" << endl;
        cout << "2. Deshacer ultima accion (UNDO)" << endl;
        cout << "3. Rehacer accion (REDO)" << endl;
        cout << "4. Mostrar acciones actuales" << endl;
        cout << "5. Mostrar pila de rehacer" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1:
            cout << "\nIngrese la accion realizada: ";
            getline(cin, accion);

            push(pilaAcciones, accion);

            // Cada nueva accion elimina la posibilidad de rehacer acciones anteriores
            limpiarPila(pilaRehacer);

            cout << "Accion guardada correctamente." << endl;
            break;

        case 2:
            if (pop(pilaAcciones, accion)) {
                push(pilaRehacer, accion);
                cout << "Accion deshecha: " << accion << endl;
            } else {
                cout << "No hay acciones para deshacer." << endl;
            }
            break;

        case 3:
            if (pop(pilaRehacer, accion)) {
                push(pilaAcciones, accion);
                cout << "Accion rehecha: " << accion << endl;
            } else {
                cout << "No hay acciones para rehacer." << endl;
            }
            break;

        case 4:
            mostrar(pilaAcciones, "Pila de acciones actuales");
            break;

        case 5:
            mostrar(pilaRehacer, "Pila de rehacer");
            break;

        case 6:
            cout << "\nSaliendo del programa..." << endl;
            break;

        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }

    } while (opcion != 6);

    // Liberar memoria antes de terminar
    limpiarPila(pilaAcciones);
    limpiarPila(pilaRehacer);

    cout << "Memoria liberada correctamente." << endl;

    return 0;
}