#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
struct{
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
}typedef Producto;

struct{
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable
    // “CantidadProductosAPedir”
}typedef Cliente;

void cargarProductos(Producto *prod, int n);
void cargarnombre(char *k);
void cargarclientes(Cliente *cli, int num);
float costoProducto(Producto *producto);
void mostrarprod(Producto *prod, int num, float *total);
void mostrar(Cliente *cli, int num);
int main()
{
    srand(time(NULL));
    Cliente *clientes;

    int cant;
    puts("Ingrese cantidad de clientes:");
    scanf("%d", &cant);
    fflush(stdin);

    clientes = malloc(sizeof(Cliente)*cant);
    cargarclientes(clientes, cant);
    mostrar(clientes,cant);

    for (int i = 0; i < cant; i++){
        free(clientes[i].Productos);
    }
    free(clientes);
    
    return 0;
}
void cargarclientes(Cliente *cli, int num)
{
    int cantp;
    char *buff = malloc(sizeof(char)*100); 
    puts("***CARGAR CLIENTES***");
    for (int i = 0; i < num; i++){
        cli[i].ClienteID = i+1;
        puts("Ingrese nombre del cliente");
        gets(buff);
        cli[i].NombreCliente = malloc(sizeof(char)*(strlen(buff)+1));
        strcpy(cli[i].NombreCliente, buff);
        cli[i].CantidadProductosAPedir = rand()%5+1;
        cli[i].Productos = malloc(sizeof(Producto)*(cli[i].CantidadProductosAPedir));
        cargarProductos(cli[i].Productos, cli[i].CantidadProductosAPedir);
    }
    free(buff);
    
}
void cargarProductos(Producto *prod, int n)
{
    for(int i = 0; i < n; i++){
        prod[i].ProductoID = i+1;
        prod[i].Cantidad = rand()%10 + 1;
        prod[i].TipoProducto = TiposProductos[i];
        prod[i].PrecioUnitario = (rand()%991+100)/10.0;
    }
}
float costoProducto(Producto *producto)
{
    return((producto->Cantidad)*(producto->PrecioUnitario));
}
void mostrar(Cliente *cli, int num)
{   
    float total;
    puts("*****MOSTRAR CLIENTES*****");
    for (int i = 0; i < num; i++){
        total=0;
        printf("\n****CLIENTE ID %d****\n", cli[i].ClienteID);
        puts(cli[i].NombreCliente);
        printf("Cantidad de productos a pedir: %d\n", cli[i].CantidadProductosAPedir);
        mostrarprod(cli[i].Productos, cli[i].CantidadProductosAPedir, &total);
        printf("TOTAL A PAGAR: %.2f\n", total);
    }
    
}
void mostrarprod(Producto *prod, int num, float *total)
{
    puts("**PRODUCTOS**");
    for (int i = 0; i < num; i++){
        printf("*Producto ID %d\n", prod[i].ProductoID);
        printf("Cantidad: %d\n", prod[i].Cantidad);
        printf("Tipo de producto: ");
        puts(prod[i].TipoProducto);
        printf("Precio unitario: %.2f\n", prod[i].PrecioUnitario);
        (*total) += costoProducto(&(prod[i]));
    }
    
}