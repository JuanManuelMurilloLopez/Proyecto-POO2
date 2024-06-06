#include<iostream>
#include<chrono>

//Biblioteca con las clases a utilizar
#include"Vehiculo.h"

#ifndef SERVICIO_H
#define SERVICIO_H

class Servicio {
    //Declaración de atributos privados
    private:
    //Arreglo de apuntadores para polimorfismo
    Vehiculo * vehiculos[100];
    //Indice a utilizar para recorrer el arreglo
    unsigned int indice;
    //Fecha del servicio
    std::chrono::time_point<std::chrono::system_clock> fecha;
    //Precio el servicio en pesos
    float precio;
    //Duración del servicio en horas
    float duracion;

    //Declaración de constructores, métodos y destructor
    public:
    //Constructor por default
    Servicio(){
        this -> indice = 0;
    };
    //Constructor con fecha
    Servicio(const std::chrono::time_point<std::chrono::system_clock>& fech){
        this -> fecha = fech;
        this -> indice = 0;
    }
    ~Servicio(){};
    /**
     * crearAutoElectrico crea un objeto AutoElectrico y lo agrega al arreglo de vehiculos
     * 
     * crea un objeo AutoElectrico y lo agrega al arreglo de empleados utilizando el aributo de índice para la posición
     * incrementándolo después en 1.
     * 
     * @param 
     * @return
    */
    void crearAutoElectrico(int ID, int anio, int kilometraje, float tiempoAnteriorServicio, float estadoLlantas, bool garantia, std::string tipoTransmision, std::string tipoFrenos, int numeroPuertas, std::string carroceria, float capacidadBateria){
        vehiculos[indice] = new AutoElectrico(ID, anio, kilometraje, tiempoAnteriorServicio, estadoLlantas, garantia, tipoTransmision, tipoFrenos, numeroPuertas, carroceria, capacidadBateria);
        indice++;
    };
        /**
     * crearAutoGasolina crea un objeto AutoGasolina y lo agrega al arreglo de vehiculos
     * 
     * crea un objeto AutoGasolina y lo agrega al arreglo de empleados utilizando el aributo de índice para la posición
     * incrementándolo después en 1.
     * 
     * @param 
     * @return
    */
    void crearAutoGasolina(int ID, int anio, int kilometraje, float tiempoAnteriorServicio, float estadoLlantas, bool garantia, std::string tipoTransmision, std::string tipoFrenos, int numeroPuertas, std::string carroceria, float cilindraje, int numeroCilindros, std::string tipoAceite){
        vehiculos[indice] = new AutoGasolina(ID, anio, kilometraje, tiempoAnteriorServicio, estadoLlantas, garantia, tipoTransmision, tipoFrenos, numeroPuertas, carroceria, cilindraje, numeroCilindros, tipoAceite);
        indice++;
    };
        /**
     * crearVan crea un objeto Van y lo agrega al arreglo de vehiculos
     * 
     * crea un objeto Van y lo agrega al arreglo de empleados utilizando el aributo de índice para la posición
     * incrementándolo después en 1.
     * 
     * @param 
     * @return
    */
    void crearVan(int ID, int anio, int kilometraje, float tiempoAnteriorServicio, float estadoLlantas, bool garantia, std::string tipoTransmision, std::string tipoFrenos, int numeroAsientos, std::string tipoCombustible){
        vehiculos[indice] = new Van(ID, anio, kilometraje, tiempoAnteriorServicio, estadoLlantas, garantia, tipoTransmision, tipoFrenos, numeroAsientos, tipoCombustible);
        indice++;
    };
        /**
     * crearMoto crea un objeto Moto y lo agrega al arreglo de vehiculos
     * 
     * crea un objeto Moto y lo agrega al arreglo de empleados utilizando el aributo de índice para la posición
     * incrementándolo después en 1.
     * 
     * @param 
     * @return
    */
    void crearMoto(int ID, int anio, int kilometraje, float tiempoAnteriorServicio, float estadoLlantas, bool garantia, std::string tipoTransmision, std::string tipoFrenos, int cilindrada){
        vehiculos[indice] = new Moto(ID, anio, kilometraje, tiempoAnteriorServicio, estadoLlantas, garantia, tipoTransmision, tipoFrenos, cilindrada);
        indice++;
    };
    void mostrarVehiculo_byID(int ID){
        for(unsigned int i = 0; i <= indice;i++){
            if(vehiculos[i]->getID() == ID){
                vehiculos[i]->mostrarDatos();
            }
        }
    };
    void mostrarFecha(){
        std::time_t fech = std::chrono::system_clock::to_time_t(this -> fecha);
        std::cout<<"Fecha Servicio: "<<std::ctime(& fech);
    };
    float getPrecio(){
        float precioTotal = 0;
        for(unsigned int i = 0; i <= indice; i++){
            precioTotal += vehiculos[i]->costoServicio();
        }
        return precioTotal;
    };
    float getDuracion(){
        float duracionTotal = 0;
        for(unsigned int i = 0; i <= indice; i++){
            duracionTotal += vehiculos[i]->costoServicio();
        }
        return duracionTotal;
    };
    void imprimirDatos(){
        mostrarFecha();
        std::cout<<"Numero de Vehiculos: "<<indice;
        mostrarFecha();
        std::cout<<"Precio: "<<precio;
        std::cout<<"Duración: "<<duracion;
    };
    //Revisar y probar método
    void eliminarVehiculo_byID(int ID){
        for(unsigned int i = 0; i <= indice; i++){
            if(vehiculos[i]->getID() == ID){
                delete vehiculos[i];
                //Recorrer los datos para no dejar espacios vacíos en el arreglo
                vehiculos[i] = vehiculos[indice];
                delete vehiculos[indice];
                indice--;
            }
        }
    }
    void eliminarVehiculos(){
        for(unsigned int i = 0; i <= indice; i++){
            delete vehiculos[i];
        }
    }
};

#endif
