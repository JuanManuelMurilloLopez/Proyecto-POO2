#include<iostream>
#include<chrono>
#include "Vehiculo.h"
#include"Servicio.h"

int main(){
    //Recuperamos la fecha actual del sistema
    auto fecha = std::chrono::system_clock::now();
    unsigned int opcion;
    //Creamos el objeto de servicio
    Servicio servicio(fecha);
    unsigned int numEmp;
    std::cout<<"Ingrese la cantidad de empleados: ";
    std::cin>>numEmp;
    servicio.setNumeroEmpleados(numEmp);
    //Menú ciclado
    do{
        std::cout<<"\nMENU\n";
        //Opciones de funcionalidades para el usuario
        std::cout<<"1. Aniadir Vehiculo\n";
        std::cout<<"2. Consultar datos de Vehiculo\n";
        std::cout<<"3. Informacion del servicio\n";
        std::cout<<"4. Cargar ejemplos predeterminados\n";
        std::cout<<"0. SALIR\n";
        std::cout<<"Ingresa la opcion: \n";
        std::cin>>opcion; 
        if(opcion == 1){
            unsigned int tipo;
            std::cout<<"1. Auto Electrico\n";
            std::cout<<"2. Auto Gasolina\n";
            std::cout<<"3. Van\n";
            std::cout<<"4. Moto\n";
            std::cin>>tipo;
            if(tipo == 1){
                //Pedimos los datos del Auto Eléctrico al usuario

                //Atributos Generales de clase Vehículo
                int ID;
                std::cout<<"Ingrese el ID del Vehiculo: ";
                std::cin>>ID;
                int kilometraje;
                std::cout<<"Ingrese el kilometraje: ";
                std::cin>>kilometraje;
                int anio;
                std::cout<<"Ingrese el anio: ";
                std::cin>>anio;
                float tiempoAnteriorServicio;
                std::cout<<"Ingrese el tiempo desde el anterior";
                std::cout<<"servicio (meses): ";
                std::cin>>tiempoAnteriorServicio;
                float estadoLlantas;
                std::cout<<"Ingrese el estado de llantas (porcentaje): ";
                std::cin>>estadoLlantas;
                bool garantia;
                std::cout<<"El Vehiculo tiene garantia? (Si->1, No->0): ";
                std::cin>>garantia;
                std::string tipoTransmision;
                int opTransmision;
                std::cout<<"Ingrese la opcion de tipo de transmision";
                std::cout<<"1. Manual";
                std::cout<<"2. Automática";
                std::cin>>opTransmision;
                if(opTransmision == 1){
                    tipoTransmision = "Manual";
                }
                if(opTransmision == 2){
                    tipoTransmision = "Automática";
                }
                std::string tipoFrenos;
                int opFrenos;
                std::cout<<"Ingrese la opcion del tipo de Frenos";
                std::cout<<"1. Disco";
                std::cout<<"2. Tambor";
                std::cin>>opFrenos;
                if(opFrenos == 1){
                    tipoFrenos = "Disco";
                }
                if(opFrenos == 2){
                    tipoFrenos = "Tambor";
                }

                //Atributos específicos de la clase Auto
                int numeroPuertas;
                std::cout<<"Ingrese el numero de puertas: ";
                std::cin>>numeroPuertas;
                std::string carroceria;
                int opCarroceria;
                std::cout<<"Ingrese la opcion del tipo de carroceria: ";
                //Hatckback, Sedán, Coupe
                std::cout<<"1. Hatchback";
                std::cout<<"2. Sedan";
                std::cout<<"3. Coupe";
                std::cin>>opCarroceria;
                if(opCarroceria == 1){
                    carroceria = "Hatchback";
                }
                if(opCarroceria == 2){
                    carroceria = "Sedan";
                }
                if(opCarroceria == 3){
                    carroceria = "Coupe";
                }

                //Atributos específicos de la clase AutoEletrico
                float capacidadBateria;
                std::cout<<"Ingrese la capacidad de la bateria";
                std::cin>>capacidadBateria;

                //Creamos el objeto con los valores recibidos
                servicio.crearAutoElectrico(ID,anio,kilometraje,
                tiempoAnteriorServicio,estadoLlantas,garantia,
                tipoTransmision,tipoFrenos,numeroPuertas,
                carroceria,capacidadBateria);

            } 
            if(tipo == 2){
                //Pedimos los datos del Auto de Gasolina al usuario

                //Atributos Generales de clase Vehículo
                int ID;
                std::cout<<"Ingrese el ID del Vehiculo: ";
                std::cin>>ID;
                int anio;
                std::cout<<"Ingrese el anio: ";
                std::cin>>anio;
                int kilometraje;
                std::cout<<"Ingrese el kilometraje: ";
                std::cin>>kilometraje;
                float tiempoAnteriorServicio;
                std::cout<<"Ingrese el tiempo desde el anterior ";
                std::cout<<"servicio (meses): ";
                std::cin>>tiempoAnteriorServicio;
                float estadoLlantas;
                std::cout<<"Ingrese el estado de llantas (porcentaje): ";
                std::cin>>estadoLlantas;
                bool garantia;
                std::cout<<"El Vehiculo tiene garantia? (Si->1, No->0): ";
                std::cin>>garantia;
                std::string tipoTransmision;
                int opTransmision;
                std::cout<<"Ingrese la opcion de tipo de transmision";
                std::cout<<"1. Manual";
                std::cout<<"2. Automatica";
                std::cin>>opTransmision;
                if(opTransmision == 1){
                    tipoTransmision = "Manual";
                }
                if(opTransmision == 2){
                    tipoTransmision = "Automatica";
                }
                std::string tipoFrenos;
                int opFrenos;
                std::cout<<"Ingrese la opción del tipo de Frenos";
                std::cout<<"1. Disco";
                std::cout<<"2. Cambor";
                std::cin>>opFrenos;
                if(opFrenos == 1){
                    tipoFrenos = "Disco";
                }
                if(opFrenos == 2){
                    tipoFrenos = "Tambor";
                }

                //Atributos específicos de la clase Auto
                int numeroPuertas;
                std::cout<<"Ingrese el numero de puertas: ";
                std::cin>>numeroPuertas;
                std::string carroceria;
                int opCarroceria;
                std::cout<<"Ingrese la opcion del tipo de carroceria: ";
                //Hatckback, Sedán, Coupe
                std::cout<<"1. Hatchback";
                std::cout<<"2. Seden";
                std::cout<<"3. Coupe";
                std::cin>>opCarroceria;
                if(opCarroceria == 1){
                    carroceria = "Hatchback";
                }
                if(opCarroceria == 2){
                    carroceria = "Seden";
                }
                if(opCarroceria == 3){
                    carroceria = "Coupe";
                }

                //Atributos específicos de la clase Auo Gasolina
                float cilindraje;
                std::cout<<"Ingrese el cilindraje: ";
                std::cin>>cilindraje;
                int numeroCilindros;
                std::cout<<"Ingrese el número de cilindros: ";
                std::cin>>numeroCilindros;
                std::string tipoAceite;
                int opAceite;
                std::cout<<"Ingrese la opcion del tipo de Aceite: ";
                //Mineral, Semi-Sintetico, Sintetico
                std::cout<<"1. Mineral";
                std::cout<<"2. Semi-Sintetico";
                std::cout<<"3. Sintetico";
                std::cin>>opAceite;
                if(opAceite == 1){
                    tipoAceite = "Mineral";
                }
                if(opAceite == 2){
                    tipoAceite = "Semi-Sintetico";
                }
                if(opAceite == 3){
                    tipoAceite = "Sintetico";
                }

                //Creamos el objeto con los valores recibidos
                servicio.crearAutoGasolina(ID,anio,kilometraje,
                tiempoAnteriorServicio,estadoLlantas,garantia,
                tipoTransmision,tipoFrenos,numeroPuertas,carroceria
                ,cilindraje,numeroCilindros,tipoAceite);
            }
            if(tipo == 3){
                //Pedimos los datos de la Van al usuario

                //Atributos Generales de clase Vehículo
                int ID;
                std::cout<<"Ingrese el ID del Vehiculo: ";
                std::cin>>ID;
                int kilometraje;
                std::cout<<"Ingrese el kilometraje: ";
                std::cin>>kilometraje;
                int anio;
                std::cout<<"Ingrese el año: ";
                std::cin>>anio;
                float tiempoAnteriorServicio;
                std::cout<<"Ingrese el tiempo desde el anterior";
                std::cout<<"servicio (meses): ";
                std::cin>>tiempoAnteriorServicio;
                float estadoLlantas;
                std::cout<<"Ingrese el estado de llantas (porcentaje): ";
                std::cin>>estadoLlantas;
                bool garantia;
                std::cout<<"El Vehiculo tiene garantia? (Si->1, No->0): ";
                std::cin>>garantia;
                std::string tipoTransmision;
                int opTransmision;
                std::cout<<"Ingrese la opcion de tipo de transmision";
                std::cout<<"1. Manual";
                std::cout<<"2. Automatica";
                std::cin>>opTransmision;
                if(opTransmision == 1){
                    tipoTransmision = "Manual";
                }
                if(opTransmision == 2){
                    tipoTransmision = "Automatica";
                }
                std::string tipoFrenos;
                int opFrenos;
                std::cout<<"Ingrese la opcion del tipo de Frenos";
                std::cout<<"1. Disco";
                std::cout<<"2. Tambor";
                std::cin>>opFrenos;
                if(opFrenos == 1){
                    tipoFrenos = "Disco";
                }
                if(opFrenos == 2){
                    tipoFrenos = "Tambor";
                }

                //Atributos específicos de la clase Van
                int numeroAsientos;
                std::cout<<"Ingrese el numero de asientos: ";
                std::cin>>numeroAsientos;
                std::string tipoCombustible;
                int opCombustible;
                std::cout<<"Ingrese la opcion del tipo de combustible: ";
                std::cout<<"1. Gasolina";
                std::cout<<"2. Diesel";
                std::cin>>opCombustible;
                if(opCombustible == 1){
                    tipoCombustible = "Gasolina";
                }
                if(opCombustible == 2){
                    tipoCombustible = "Diesel";
                }
                
                //Creamos el objeto con los valores recibidos
                servicio.crearVan(ID,anio,kilometraje,tiempoAnteriorServicio
                ,estadoLlantas,garantia,tipoTransmision,tipoFrenos,
                numeroAsientos,tipoCombustible);
            }
            if(tipo == 4){
                //Pedimos los datos de la Moto al usuario

                //Atributos Generales de clase Vehículo
                int ID;
                std::cout<<"Ingrese el ID del Vehiculo: ";
                std::cin>>ID;
                int kilometraje;
                std::cout<<"Ingrese el kilometraje: ";
                std::cin>>kilometraje;
                int anio;
                std::cout<<"Ingrese el anio: ";
                std::cin>>anio;
                float tiempoAnteriorServicio;
                std::cout<<"Ingrese el tiempo desde el anterior";
                std::cout<<"servicio (meses): ";
                std::cin>>tiempoAnteriorServicio;
                float estadoLlantas;
                std::cout<<"Ingrese el estado de llantas (porcentaje): ";
                std::cin>>estadoLlantas;
                bool garantia;
                std::cout<<"El Vehiculo tiene garantia? (Si->1, No->0): ";
                std::cin>>garantia;
                std::string tipoTransmision;
                int opTransmision;
                std::cout<<"Ingrese la opción de tipo de transmision";
                std::cout<<"1. Manual";
                std::cout<<"2. Automatica";
                std::cin>>opTransmision;
                if(opTransmision == 1){
                    tipoTransmision = "Manual";
                }
                if(opTransmision == 2){
                    tipoTransmision = "Automatica";
                }
                std::string tipoFrenos;
                int opFrenos;
                std::cout<<"Ingrese la opcion del tipo de Frenos";
                std::cout<<"1. Disco";
                std::cout<<"2. Tambor";
                std::cin>>opFrenos;
                if(opFrenos == 1){
                    tipoFrenos = "Disco";
                }
                if(opFrenos == 2){
                    tipoFrenos = "Tambor";
                }

                //Atributos específicos de la clase Moto
                int cilindrada;
                std::cout<<"Ingrese la cilindrada: ";
                std::cin>>cilindrada;

                //Creamos el objeto con los valores recibidos
                servicio.crearMoto(ID,anio,kilometraje,tiempoAnteriorServicio,
                estadoLlantas,garantia,tipoTransmision,tipoFrenos,cilindrada);
            }
        } 
        if(opcion == 2){
            int id;
            std::cout<<"Ingrese el ID del Vehiculo: ";
            std::cin>>id;
            servicio.mostrarVehiculo_byID(id);
        }
        if(opcion == 3){
            servicio.imprimirDatos();
        }
        if(opcion == 4){
            servicio.crearAutoElectrico(1001,2015,200000,3,0.8,1,"Automatica"
            ,"Disco",4,"Hatckback",40);
            servicio.crearAutoGasolina(1002,2005,450000,4,0.3,0,"Manual"
            ,"Tambor",4,"Sedan",2.0,4,"Mineral");
            servicio.crearMoto(1003,2020,40000,2,0.8,1,"Manual","Disco",125);
            servicio.crearVan(1004,1990,500000,4,0.3,1,"Manual","Tambor",14,
            "Diesel");
            std::cout<<"\n **Ejemplos Cargados**\n";
            }
        if(opcion > 4){
            std::cout<<"\nEntrada Incorrecta.\n";
        }
    }
    while(opcion != 0);
    return 0;
};
