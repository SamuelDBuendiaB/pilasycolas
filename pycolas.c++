#include<iostream>
#include<conio.h>
using namespace std;

struct lista
{
    int numero;
    lista *next;
    lista *atras;
};

lista *orden = NULL ;
lista*cola;
void eleccion(int x);
void agregaralista(lista*&,int);
void show(lista*);

int main() {
    int x;
    //ciclo para elejir la opcion de usar en modo pila o cola
    do {
        cout << "Elejir" << endl;
        cout << "1. Pilas" << endl;
        cout << "2. Colas" << endl;
        cin >> x;
        
        if (x != 1 && x != 2) {
            cout << "Elija una opcion valida" << endl;
        }
    } while (x != 1 && x != 2); 
    //mandarle al menu de eleccion el dato de x 
    eleccion(x);
    getch;
    return 0;
}

//modo pila- Agrega a la cola normal 1-2-2
void agregaralista(lista *&orden,int i){

    lista * nuevo_nodo = new lista();

    nuevo_nodo->numero = i;

    lista * nodo1 = orden;
    lista * nodo2;

while((nodo1 !=NULL )&&(nodo1->numero < i)){
    nodo2 = nodo1;
    nodo1 = nodo1->next;    
}

if(orden == nodo1 ){

orden = nuevo_nodo;

}
else {
    nodo2->next = nuevo_nodo;
}
nuevo_nodo->next = nodo1;

cout<<"\ndato ingresado\n";

}


void show(lista *orden){

    lista * mostrar = new lista();
    mostrar = orden;

    while(mostrar != NULL){
        cout<<mostrar->numero<<" -- ";
        mostrar = mostrar->next;
    }

}

// modo de pila-Borra siempre el ultimo dato ingresado
void borrar(lista *&orden) {
    if (orden != NULL) {
        lista *borr = orden;
        orden = orden->next;
        delete borr;
        cout << "\nDato eliminado\n";
    } else {
        cout << "Pila vacia" << endl;
    }
}

//modo cola-Agrega a la izquierda moviendo hacia al frente 3-2-1
void agregarinicio(lista *&orden,int n){

lista * nuevo = new lista();
nuevo->numero = n;

if (orden==NULL)
{
    orden = nuevo;
    orden->next = NULL;
    orden->atras = NULL;
    cola = orden;
}
else{
    nuevo->next = orden;
    orden = nuevo;
    nuevo->atras = cola;
    cola = nuevo;

}

cout<<"\nDato ingresado"<<endl;

}

void borrarcabeza(lista *&orden) {
    if (orden != NULL) {
        if (orden->next == NULL) {
            // Si solo hay un nodo
            delete orden;
            orden = NULL;
            cout << "\nDato eliminado\n";
        } else {
            //crear nuevos espacios de memoria darle la lista a actual
            lista *actual = orden;
            lista *prev = NULL;
            //ciclo para mover actual hasta el ultimo punto
            while (actual->next != NULL) {
                prev = actual;
                actual = actual->next;
            }

            // actual ya esta en el ultimo nodo
            // previo apunto al penultimo
            prev->next = NULL;
            delete actual;
            cout << "\nDato eliminado\n";
        }
    } else {
        cout << "Pila vacia" << endl;
    }
}





void eleccion(int x){
    int opcion,numero;

    do
    {
    
        cout<<"\n 1. Agregar numeros:  "<<endl;
        cout<<"2. Agregar ver lista "<<endl;
        cout<<"3. Extraer numero"<<endl;
        cout<<"4. salir"<<endl;
        cin>>opcion;

        switch (opcion)
        {
        case 1 : cout<<"Numero a digitar:   ";
        cin>>numero;
        if (x==1)
        {
            agregaralista(orden,numero);
            system("pause");
            break;
        }
        else
        {
            agregarinicio(orden,numero);
            system("pause");
            break;
        }
        
    

        case 2 : show(orden);
        cout<<"   "<<endl;
        system("pause");
            break;


         case 3:
         if (x==1)
         {
            borrar(orden);
            system("pause");
         break;
         }else
         {
            borrarcabeza(orden);
            system("pause");
         break;
         }
    
        }
        system("cls");
    } while (opcion !=4);
    
}