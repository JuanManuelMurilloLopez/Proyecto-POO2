/**
 * 
 * Proyecto Gestor de Servicio Automotriz
 * Juan Manuel Murillo López
 * A01712218
 * 
 * Esta clase define el objeto de tipo Servicio
 * que contiene las operaciones para crear vehículos,
 * mostrar los datos de sus vehículos, mostrar su fecha,
 * actualizar su precio y duración e imprimir sus datos.
 * Esta clase se utiliza en el main y es parte del
 * proyecto de Gestor Automotriz
 */

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
        for(unsigned int i = 0; i < indice;i++){
            if(vehiculos[i]->getID() == ID){
                vehiculos[i]->mostrarDatos();
            }
        }
    };
    void mostrarFecha(){
        std::time_t fech = std::chrono::system_clock::to_time_t(this -> fecha);
        std::cout<<"Fecha Servicio: "<<std::ctime(& fech);
    };
    void updatePrecio(){
        float precioTotal = 0;
        for(unsigned int i = 0; i < indice; i++){
            precioTotal += vehiculos[i]->costoServicio();
        }
        this -> precio = precioTotal;
    };
    void updateDuracion(){
        float duracionTotal = 0;
        for(unsigned int i = 0; i < indice; i++){
            duracionTotal += vehiculos[i]->duracionServicio();
        }
        this ->  duracion = duracionTotal;
    };
    void imprimirDatos(){
        updateDuracion();
        updatePrecio();
        std::cout<<"Numero de Vehiculos: "<<indice;
        std::cout<<"\n";
        mostrarFecha();
        std::cout<<"Precio: "<<precio;
        std::cout<<"\nDuracion: "<<duracion;
    };
};

#endif
