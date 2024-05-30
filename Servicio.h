#include<iostream>
#include<chrono>
#include"Vehiculo.h"

#ifndef SERVICIO_H
#define SERVICIO_H

class Servicio {
    private:
    Vehiculo * vehiculos[100];
    unsigned int indice = 0;
    std::chrono::time_point<std::chrono::system_clock> fecha;
    //Pesos
    float precio;
    //Horas
    float duracion;
    public:
    Servicio(){};
    Servicio(const std::chrono::time_point<std::chrono::system_clock>& fech){
        this -> fecha = fech;
    }
    void agregarAutoElectrico(int ID, int anio, int kilometraje, float tiempoAnteriorServicio, float estadoLlantas, bool garantia, std::string tipoTransmision, std::string tipoFrenos, int numeroPuertas, std::string carroceria, float capacidadBateria){
        vehiculos[indice] = new AutoElectrico(ID, anio, kilometraje, tiempoAnteriorServicio, estadoLlantas, garantia, tipoTransmision, tipoFrenos, numeroPuertas, carroceria, capacidadBateria);
        indice++;
    };
    void agregarAutoGasolina(int ID, int anio, int kilometraje, float tiempoAnteriorServicio, float estadoLlantas, bool garantia, std::string tipoTransmision, std::string tipoFrenos, int numeroPuertas, std::string carroceria, float cilindraje, int numeroCilindros, std::string tipoAceite){
        vehiculos[indice] = new AutoGasolina(ID, anio, kilometraje, tiempoAnteriorServicio, estadoLlantas, garantia, tipoTransmision, tipoFrenos, numeroPuertas, carroceria, cilindraje, numeroCilindros, tipoAceite);
        indice++;
    };
    void agregarVan(int ID, int anio, int kilometraje, float tiempoAnteriorServicio, float estadoLlantas, bool garantia, std::string tipoTransmision, std::string tipoFrenos, int numeroAsientos, std::string tipoCombustible){
        vehiculos[indice] = new Van(ID, anio, kilometraje, tiempoAnteriorServicio, estadoLlantas, garantia, tipoTransmision, tipoFrenos, numeroAsientos, tipoCombustible);
        indice++;
    };
    void agregarMoto(int ID, int anio, int kilometraje, float tiempoAnteriorServicio, float estadoLlantas, bool garantia, std::string tipoTransmision, std::string tipoFrenos, int cilindrada){
        vehiculos[indice] = new Moto(ID, anio, kilometraje, tiempoAnteriorServicio, estadoLlantas, garantia, tipoTransmision, tipoFrenos, cilindrada);
        indice++;
    };
    Vehiculo getVehiculo_byID(int ID){
        for(unsigned int i = 0; i < indice + 1;i++){
            if(vehiculos[i]->getID() == ID){
                return *vehiculos[i];
            }
        }
    };
    void mostrarFecha(){
        std::time_t fech = std::chrono::system_clock::to_time_t(this -> fecha);
        std::cout<<"Fecha Servicio: "<<std::ctime(& fech);
    };
    float getPrecio(){
        float precioTotal = 0;
        for(unsigned int i = 0; i < indice + 1; i++){
            precioTotal += vehiculos[i]->costoServicio();
        }
        return precioTotal;
    };
    float getDuracion(){
        float duracionTotal = 0;
        for(unsigned int i = 0; i < indice + 1; i++){
            duracionTotal += vehiculos[i]->costoServicio();
        }
        return duracionTotal;
    };
};

#endif

