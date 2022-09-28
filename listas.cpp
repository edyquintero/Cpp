#include <iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};
void insertaLista(Nodo *&,int);
void mostrarLista(Nodo *);
char menu();

int main(){
    Nodo *lista = nullptr;
    int dato;
    char eleccion;

    while(true){
        eleccion = menu();

        if (eleccion==1){
            cout<<"Enter the data to add: ";
            cin>>dato;
            insertaLista(lista,dato);
        } else if (eleccion == 2){
            mostrarLista(lista);
        } else if (eleccion == 3) {
            break;
        } else {
        cout<<"Opcion no valida";
        }
    }
}

char menu(){
    char eleccion;
    cout<<"MENU DE OPCONES\n(1) Agregar elemento a la lista\n(2) Mostrar lista"<<endl;
    cin>>eleccion;
    return eleccion;
}

void insertaLista(Nodo *&lista,int n){
    Nodo *nuevo_nodo = new Nodo ();
    nuevo_nodo -> dato = n;

    Nodo *aux1 = lista;
    Nodo *aux2;
    while ((aux1 != nullptr)&&(aux1->dato <n)){
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }
    if(lista== aux1){
        lista= nuevo_nodo;

    }else{
        aux2-> siguiente = nuevo_nodo;
    }
    nuevo_nodo -> siguiente = aux1;
    cout<<"\nElemento "<<n<<" insertadoa a lista correctamente\n"<<endl;

}
void mostrarLista(Nodo *lista){
    Nodo *actual = lista;
    while (actual != nullptr){
        cout<<actual->dato<<endl;
        actual=actual->siguiente;
    }
}