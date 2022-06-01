#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <utility>
#include <string>

using namespace std;

struct Nodo
{
    int dato;
    int contador;
    Nodo *der;
    Nodo *izq;
    Nodo *padre;
};

void Menu();
Nodo *CrearNodo(int, Nodo *);
void InsertarNodo(Nodo *&, int, Nodo *);
void MostrarArbol(Nodo *, int);
bool Busqueda(Nodo *, int);
void PreOrden(Nodo *);
void InOrden(Nodo *);
void PosOrden(Nodo *);
void Eliminar(Nodo *, int);
Nodo *Buscar(Nodo *&, int);
// funciones agregadas para fines practicos
void EliminarNodo(Nodo *);
bool EsHoja(Nodo *&);
Nodo *ObtenerMenor(Nodo *r);
Nodo *ObtenerMayor(Nodo *r);

// Arbol
Nodo *arbol = nullptr;

int main()
{
    Menu();

    return 0;
}

// FUNCIONES
// menu
void Menu()
{
    int dato, opcion, cont = 0;

    do
    {
        system("cls");
        cout << " MENU" << endl;
        cout << " 1) Insertar nodo" << endl;
        cout << " 2) Mostrar arbol" << endl;
        cout << " 3) Buscar nodo" << endl;
        cout << " 4) Recorrido preOrden" << endl;
        cout << " 5) Recorrido inOrden" << endl;
        cout << " 6) Recorrido posOrden" << endl;
        cout << " 7) Eliminar nodo" << endl;
        cout << " 8) Salir" << endl;
        cout << " Seleccione opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "\n Primer dato: ";
            cin >> dato;
            InsertarNodo(arbol, dato, nullptr);
            cout << "\n Se inserto correctamente el dato: " << dato << endl;
            cout << endl;
            system("pause");
            break;

        case 2:
            system("cls");
            cout << " Mostrar arbol" << endl;
            MostrarArbol(arbol, 0);
            system("pause");
            break;

        case 3:
            system("cls");
            cout << " Buscar nodo" << endl;
            cout << " Dato: ";
            cin >> dato;
            cout << endl;

            if (Busqueda(arbol, dato))
            {
                cout << " El nodo se encuentra en la lista" << endl;
            }
            else
            {
                cout << " El nodo NO se encuentra en la lista..." << endl;
            }
            cout << endl;
            system("pause");
            break;

        case 4:
            system("cls");
            cout << " Recorrido en preOrden" << endl;
            PreOrden(arbol);
            cout << endl;
            system("pause");
            break;

        case 5:
            system("cls");
            cout << " Recorrido en inOrden" << endl;
            InOrden(arbol);
            cout << endl;
            system("pause");
            break;

        case 6:
            system("cls");
            cout << " Recorrido en posOrden" << endl;
            PosOrden(arbol);
            cout << endl;
            system("pause");
            break;

        case 7:
            cout << endl
                 << " Nodo a eliminar: ";
            cin >> dato;
            Eliminar(arbol, dato);
            system("pause");
            break;

        case 8:
            cout << endl
                 << " Saliendo..." << endl;
            system("pause");
            break;

        default:
            cout << "Opcion no valida..." << endl;
        }

    } while (opcion != 8);
}

// Crear nodo
Nodo *CrearNodo(int n, Nodo *padre)
{
    Nodo *nuevo_nodo = new Nodo();

    nuevo_nodo->dato = n;
    nuevo_nodo->contador = 0;
    nuevo_nodo->der = nullptr;
    nuevo_nodo->izq = nullptr;
    nuevo_nodo->padre = padre;

    return nuevo_nodo;
}

// Insertar nodo
void InsertarNodo(Nodo *&arbol, int n, Nodo *padre)
{

    if (arbol == NULL)
    {
        Nodo *nuevo_nodo = CrearNodo(n, padre);
        arbol = nuevo_nodo;
    }

    else
    {
        int valorRaiz = arbol->dato;

        if (n < valorRaiz)
        {
            if (arbol->dato == n)
            {
                // insertar(arbol->izq,n, arbol,cant);
                arbol->contador++;
                cout << " Dato ya insertado en el arbol, por lo tanto, se aumentara el contador de veces repetido solamente " << endl;
            }
            else
            {
                InsertarNodo(arbol->izq, n, arbol);
            }
        }
        else
        {
            if (arbol->dato == n)
            {
                // insertar(arbol->izq,n, arbol,cant);
                arbol->contador++;
                cout << " Dato ya insertado en el arbol, por lo tanto, se aumentara el contador de veces repetido solamente " << endl;
            }
            else
            {
                InsertarNodo(arbol->der, n, arbol);
            }
        }
    }
    return;
}

// Mostrar arbol
void MostrarArbol(Nodo *arbol, int cont)
{
    if (arbol == NULL)
    {

        return;
    }
    else
    {
        MostrarArbol(arbol->der, cont + 1);
        for (int i = 0; i < cont; i++)
        {
            cout << "    ";
        }
        cout << arbol->dato << "(" << arbol->contador << ")" << endl;
        MostrarArbol(arbol->izq, cont + 1);
    }
}

// Buscar
bool Busqueda(Nodo *arbol, int n)
{
    if (arbol == nullptr)
    {
        return false;
    }
    else if (arbol->dato == n)
    {
        cout << " Este numero se repite " << arbol->contador << " veces, por lo tanto... " << endl;
        return true;
    }
    else if (n < arbol->dato)
    {
        return Busqueda(arbol->izq, n);
    }
    else
    {
        return Busqueda(arbol->der, n);
    }
}

// Recorrido preorden
void PreOrden(Nodo *arbol)
{
    if (arbol == nullptr)
    {
        return;
    }
    else
    {
        cout << arbol->dato << " - ";
        PreOrden(arbol->izq);
        PreOrden(arbol->der);
    }
}

// Recorrido inorden
void InOrden(Nodo *arbol)
{
    if (arbol == nullptr)
    {
        return;
    }
    else
    {
        InOrden(arbol->izq);
        cout << arbol->dato << " - ";
        InOrden(arbol->der);
    }
}

// Recorrido posorden
void PosOrden(Nodo *arbol)
{
    if (arbol == nullptr)
    {
        return;
    }
    else
    {
        PosOrden(arbol->izq);
        PosOrden(arbol->der);
        cout << arbol->dato << " - ";
    }
}

// confrimamos que el nodo sea hoja si nuestra raiz es diferente a null y los hijos derecho e izquierdo tienene el mismo valor osea null

// esta funcion nos regresará el menor elemento de la raiz seleccionada el cual nos ayudará para eliminar
Nodo *ObtenerMenor(Nodo *r)
{
    if (r == NULL || r->izq == nullptr)
    {
        return r;
    }

    return ObtenerMenor(r->izq);
}

// lo mismo que la anterior pero esta vez obtenemos el mayor de la raiz indicada
Nodo *ObtenerMayor(Nodo *r)
{
    if (r == NULL || r->der == nullptr)
    {
        return r;
    }

    return ObtenerMayor(r->der);
}

// Eliminar
// aqui se remplaza el nodo por el mayor del hijo izquierdo o el menor del hijo derecho
void Eliminar(Nodo *r, int n)
{
    if (r == NULL || r->dato == n)
    {
        EliminarNodo(r);
    }
    else if (n < arbol->dato)
    {
        Eliminar(r->izq, n);
    }
    else
    {
        Eliminar(r->der, n);
    }
}

void EliminarNodo(Nodo *r)
{
    Nodo *reemplazo;
    if (r == nullptr)
    {
        cout << "No se ecnuentra el nodo, estupido XD" << endl;
        return;
    }
    // en caso de tener mas de un elemento se disminuye el contador
    if (r->contador > 0)
    {
        r->contador--;
        cout << " Este dato se repite varias veces, asi que se redujo el contador en -1 " << endl;
        return;
    }
    // comprobamos is es hoja, y solamente eliminamos
    if (r->izq == r->der)
    {
        if (r->padre->izq == r)
        {
            r->padre->izq = nullptr;
        }
        else if (r->padre->der == r)
        {
            r->padre->der = nullptr;
        }
        delete r;
    }
    else
    {
        if (r->izq != nullptr) // comprobamos si tiene hiho izquierdo
        {
            reemplazo = ObtenerMayor(r->izq);
            if (reemplazo == r->izq)
            {
                r->izq = reemplazo->izq;
            }
            else
            {
                reemplazo->padre->der = reemplazo->izq;
            }
        }
        else if(r->der != nullptr)
        {
            reemplazo = ObtenerMenor(r->der);
            if (reemplazo == r->der)
            {
                r->der = reemplazo->der;
            }
            else
            {
                reemplazo->padre->izq = reemplazo->der;
            }

        }
        r->dato = reemplazo->dato;
        delete reemplazo;
        //Raiz en hijos
    }
}
