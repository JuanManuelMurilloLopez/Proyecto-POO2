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
    unsigned int numeroEmpleados;

    //Declaración de constructores, métodos y destructor
    public:
    /**
     * Servicio constructor vacío
     * Inicializa el objeto con los atributos default
     * @param
     * @return
     */
    Servicio(){
        this -> indice = 0;
        this -> numeroEmpleados = 0;
    };

    /**
     * Servicio constructor con parámetro de fecha
     * Recibe la fecha del usuario
     * además de inicializar el índice
     * @param const std::chrono::time_point<std::chrono::system_clock>&
     * @return
     */
    Servicio(const std::chrono::time_point<std::chrono::system_clock>& fech){
        this -> fecha = fech;
        this -> indice = 0;
        this -> numeroEmpleados = 0;
    }

    /**
     * setNumeroEmpleados setter de atributo NumeroEmpleados
     * Recibe el NumeroEmpleados y lo guarda en el atributo NumeroEmpleados
     * @param unsigned int NumeroEmpleados
     * @return 
     */
    void setNumeroEmpleados(int numEmp){
        this -> numeroEmpleados = numEmp;
    }

    /**
     * crearAutoElectrico crea un objeto AutoElectrico y lo agrega al arreglo
     * de vehiculos
     * 
     * crea un objeo AutoElectrico y lo agrega al arreglo de empleados
     * utilizando el aributo de índice para la posición
     * incrementándolo después en 1.
     * 
     * @param int ID, int año, int kilometraje, float tiempo anterior
     * servicio, float estado llantas, bool garantia,
     * string tipo transmisión, string tipo frenos, int numero puertas,
     * string carrocería, float capacidad batería
     * @return
    */
    void crearAutoElectrico(int ID,int an,int km,float tas,float el,bool gar,
    std::string tt,std::string tf,int np,std::string car,float cb){
        vehiculos[indice] = new AutoElectrico(ID,an,km,tas,el,gar,tt,
        tf,np,car,cb);
        indice++;
    };

    /**
     * crearAutoGasolina crea un objeto AutoGasolina y lo agrega al arreglo
     * de vehiculos
     * 
     * crea un objeto AutoGasolina y lo agrega al arreglo de empleados
     * utilizando el aributo de índice para la posición
     * incrementándolo después en 1.
     * 
     * @param int ID, int año, int kilometraje, float tiempo anterior
     * servicio, float estado llantas, bool garantia,
     * string tipo transmisión, string tipo frenos, int numero puertas,
     * string carrocería, float cilindraje, int numero cilindros,
     * string tipo aceite
     * @return
    */
    void crearAutoGasolina(int ID,int an,int km,float tas,float el,bool gar,
    std::string tt,std::string tf,int np,std::string carr,float cil,int nc,
    std::string ta){
        vehiculos[indice] = new AutoGasolina(ID, an, km, tas, el, gar, tt, tf,
         np, carr, cil, nc, ta);
        indice++;
    };

        /**
     * crearVan crea un objeto Van y lo agrega al arreglo de vehiculos
     * 
     * crea un objeto Van y lo agrega al arreglo de empleados utilizando
     * el aributo de índice para la posición
     * incrementándolo después en 1.
     * 
     *@param int ID, int año, int kilometraje, float tiempo anterior
     * servicio, float estado llantas, bool garantia,
     * string tipo transmisión, string tipo frenos,
     * int numero asientos, string tipo combustible
     * @return
    */
    void crearVan(int ID, int an, int km, float tas, float el, bool gar,
     std::string tt, std::string tf, int na, std::string tc){
        vehiculos[indice] = new Van(ID, an, km, tas, el, gar, tt, tf, na, tc);
        indice++;
    };

    /**
     * crearMoto crea un objeto Moto y lo agrega al arreglo de vehiculos
     * 
     * crea un objeto Moto y lo agrega al arreglo de empleados utilizando
     * el aributo de índice para la posición
     * incrementándolo después en 1.
     * 
     * @param int ID, int año, int kilometraje, float tiempo anterior
     * servicio, float estado llantas, bool garantia,
     * string tipo transmisión, string tipo frenos, int cilindraje
     * @return
    */
    void crearMoto(int ID, int an, int km, float tas, float el, bool gar,
     std::string tt, std::string tf, int cil){
        vehiculos[indice] = new Moto(ID, an, km, tas, el, gar, tt, tf, cil);
        indice++;
    };

    /**
     * mostrarVehiculo_byID imprime el dato del vehiculo deseado
     * Recorre la lista de vehiculos buscando la coindicencia de ID
     * al encontrar el valor, si no se encuentra ningún vehiculo con
     * el ID proporcionado imprime el aviso que el vehiculo no existe
     */
    void mostrarVehiculo_byID(int ID){
        bool found = false;
        for(unsigned int i = 0; i < indice;i++){
            if(vehiculos[i]->getID() == ID){
                vehiculos[i]->mostrarDatos();
                found = true;
            }
        }
        if(!found){
            std::cout<<"El Vehículo con ID "<<ID<<" no existe";
        }
    };

    /**
     * mostrarFecha imprime la fecha en la que se creó el objeto
     * Transforma a un formato compatible con cout el atributo de fecha
     * para imprimirlo
     * @param
     * @return
     */
    void mostrarFecha(){
        std::time_t fech = std::chrono::system_clock::to_time_t(this -> fecha);
        std::cout<<"Fecha Servicio: "<<std::ctime(& fech);
    };

    /**
     * updatePrecio calcula el precio total del servicio
     * Calcula el precio total de los Vehículos dentro del objeto
     * para actualizar el atributo de precio
     * @param
     * @return
     */
    void updatePrecio(){
        float precioTotal = 0;
        for(unsigned int i = 0; i < indice; i++){
            precioTotal += vehiculos[i]->costoServicio();
        }
        this -> precio = precioTotal;
    };

    /**
     * updateDuracion calcula la duración total del servicio
     * Calcular la duración total de los Vehículos dentro del objeto
     * para actualizar el atributo de duración
     * @param
     * @return
     */
    void updateDuracion(){
        float duracionTotal = 0;
        for(unsigned int i = 0; i < indice; i++){
            duracionTotal += vehiculos[i]->duracionServicio();
        }
        this ->  duracion = duracionTotal/numeroEmpleados;
    };

    /**
     * imprimirDatos imprime los datos del objeto
     * Recupera los atributos del objeto y los imprime
     * junto con sus etiquetas
     * @param
     * @return
     */
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
