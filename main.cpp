#include <iostream>
#include<conio.h>

using namespace std;

struct nodo{
    int dato;
    nodo *siguiente;
};

void insertarLista(nodo *&, int);
void mostrarLista(nodo *);
void eliminarNodo(nodo *&, int);
void buscarLista(nodo *, int);
void eliminarListas(nodo *&, int);
void menu();

bool band;
int main()
{
    nodo *lista=NULL;
    int dato, dato3, dato4;

    int op;

    do{
            menu();
            scanf("%d",&op);



        switch(op)
        {
            case 1: printf("digite un dato \n");
            scanf("%d",&dato);
            insertarLista(lista, dato);

            printf("digite un dato \n");
            scanf("%d",&dato);
            insertarLista(lista, dato);
            break;

           case 2: printf("mostrando lista \n");
           mostrarLista(lista);
           break;

            case 3: printf("digite el dato a eliminar\n");
            scanf("%d",dato3);
            eliminarNodo(lista, dato3);
            mostrarLista(lista);
            break;

            case 4: printf("digite el numero a buscar\n");
            scanf("%d",dato4);
            buscarLista(lista,dato4);
            break;

            case 5:printf("elementos eliminados \n");
            eliminarListas(lista, dato);

            case 0: (exit);
            break;

        }
        printf("\n");
        system("pause");
        system("cls");
    }while(op!=0);

    return 0;
}

void menu(){
    printf("\t------------------------------------------\n");
    printf("\t|         MENU LISTA                     |\n");
    printf("\t-----------------------------------------|\n");
    printf("\t|                                        |\n");
    printf("\t|   1. INSERTAR LISTA                    |\n");
    printf("\t|   2. MOSTRAR LISTA                     |\n");
    printf("\t|   3. ELIMINAR NODO                     |\n");
    printf("\t|   4. BUSCAR LISTA                      |\n");
    printf("\t|   5. ELIMINAR TODA LA LISTA            |\n");
    printf("\t|   0. SALIR                             |\n");
    printf("\t|                                        |\n");
    printf("\t-----------------------------------------|\n");
    printf("\t ingrese opcion: ");

}

void insertarLista(nodo *&lista, int n){
    nodo *nuevo_nodo = new nodo();
    nuevo_nodo->dato=n;
    nodo *aux1=lista;
    nodo *aux2;
    while((aux1 != NULL)&&(aux1->dato<n)){
            aux2=aux1;
    aux1=aux1->siguiente=nuevo_nodo;

    }
    if(lista == aux1){
        lista= nuevo_nodo;
    }else{
        aux2->siguiente=nuevo_nodo;
    }
    nuevo_nodo->siguiente= aux1;
    printf("dato %d insertado con exito\n",n);
}

void mostrarLista(nodo *lista){
    nodo *actual = new nodo();
    actual=lista;
    while(actual != NULL){
        printf("%d\n",actual->dato);
        actual=actual->siguiente;
    }
}

void eliminarNodo(nodo *&lista, int n){
    if(lista !=NULL){
        nodo *aux_borrar;
        nodo *anterior = NULL;
        aux_borrar = lista;
        while((aux_borrar !=NULL)&&(aux_borrar->dato !=n)){
            anterior = aux_borrar;
            aux_borrar=aux_borrar->siguiente;
        }
        if(aux_borrar == NULL){
            printf("el elemento no existe\n");
        }else if(anterior == NULL){
            lista = lista->siguiente;
            printf("elemento %d eliminado \n",n);
            delete aux_borrar;

        }else{
            anterior->siguiente=aux_borrar->siguiente;
            printf("elemento %d eliminado\n",n);
            delete aux_borrar;
        }
    }
}

void buscarLista(nodo *lista, int n){
    nodo *actual = new nodo();
    actual = lista;

    while((actual != NULL)&&(actual->dato<=n)){
        if(actual->dato == n){
            band = true;
            actual = actual->siguiente;
        }
    }
}
void eliminarListas(nodo *&lista, int n){
    nodo *aux=lista;
    aux = lista;
    lista->dato= n;
    lista ->siguiente;
    delete aux;

}


