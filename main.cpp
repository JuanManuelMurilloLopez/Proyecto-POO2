#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

#include "Servicio.h"
#include "Vehiculo.h"

int main(){
    unsigned int opcion = 1;
    while(opcion != 0){
        std::cout<<"MENU\n";
        std::cout<<"1. Cargar CSV\n";
        std::cout<<"2. Nuevo CSV\n";
        std::cout<<"\nIngresa la opcion: \n";
        std::cin>>opcion;
        if(opcion == 1){  
            std::string rutaDocumento;
            std::string linea;
            std::ifstream documento("pruebas.txt");
            std::getline(documento, linea);
            std::cout<<linea<<"\n";
        }
        else if(opcion == 2){
            
        }
        else if (opcion > 2)
        {
            std::cout<<"Entrada Incorrecta\n";
        }
        
    }
    return 0;
};
