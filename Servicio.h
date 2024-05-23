#include<iostream>
#include"Vehiculo.h"

#ifndef SERVICIO_H
#define SERVICIO_H

class Servicio {
    private:
    Vehiculo * vehiculos[100];
    std::string fecha;
    //Pesos
    float precio;
    //Horas
    float duracion;
    Servicio();
    void agregarVehiculo(Vehiculo);
    void eliminarVehiculo(int);
    void setFecha(std::string);
    Vehiculo getVehiculo_byID(int ID);
    std::string getFecha();
    float getPrecio();
    float getDuracion();
};

#endif

