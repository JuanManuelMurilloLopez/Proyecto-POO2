#include<iostream>
#include<chrono>
#include "Vehiculo.h"
#include"Servicio.h"

int main(){
    auto fecha = std::chrono::system_clock::now();
    unsigned int opcion = 1;
    Servicio servicio(fecha);
    servicio.mostrarFecha();
    while (opcion != 0)
    {
        std::cout<<"\nMENU\n";
        std::cout<<"1. Añadir Vehiculo\n";
        std::cout<<"2. Consultar datos de Vehiculo\n";
        std::cout<<"3. Información\n";
        std::cout<<"4. Cargar ejemplos predeterminados\n";
        std::cout<<"Ingresa la opción: \n";
        std::cin>>opcion;
        if(opcion == 1){
            unsigned int tipo = 0;
            std::cout<<"1. Auto Gasolina\n";
            std::cout<<"2. Auto Eléctrico\n";
            std::cout<<"3. Van\n";
            std::cout<<"4. Moto\n";
            if(tipo == 1){

                //servicio.agregarVehiculo();
                //Después de pedir todos los atributos, crear el objeto dentro de la clase servicio.
                
            };
        };
    }
    return 0;
};
