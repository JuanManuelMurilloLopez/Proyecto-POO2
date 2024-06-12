/**
 * 
 * Proyecto Gestor de Servicio Automotriz
 * Juan Manuel Murillo López
 * A01712218
 * 
 * Esta clase definen los objetos de tipo Vehiculo, Auto,
 * Auto Eléctrico, Auto Gasolina, Van y Moto
 * que contiene las operaciones para calcular el costo
 * y duración del servicio e imprimir suu información
 * Esta clase se utiliza en el main y es parte del
 * proyecto de Gestor Automotriz
 */

#include<iostream>

#ifndef VEHICULO_H
#define VEHICULO_H

//Definimos las constantes a utilizar al calcular costos
const int LIMITE_VIDA_LLANTAS = 0.5;
const int COSTO_LLANTAS = 4500;
const int COSTO_SERVICIO_TRANSMISION_MANUAL = 300;
const int COSTO_SERVICIO_TRANSMISION_AUTOMATICA = 350;
const int COSTO_SERVICIO_FRENOS_TAMBOR = 150;
const int COSTO_SERVICIO_FRENOS_DISCO = 200;
const int MULTIPLICADOR_NUMERO_PUERTAS = 35;
const int MULTIPLICADOR_CAPACIDAD_BATERIA = 5;
const int MULTIPLICADOR_CILINDROS = 500;
const int COSTO_ACEITE_MINERAL = 100;
const int COSTO_ACEITE_SEMISINTETICO = 150;
const int COSTO_ACEITE_SINTETICO = 125;
const int COSTO_SERVICIO_DIESEL = 150;
const int COSTO_SERVICIO_GASOLINA = 100;

class Vehiculo {
    protected:
    int ID;
    int anio;
    int kilometraje;
    //Meses
    float tiempoAnteriorServicio;
    //Porcentaje
    float estadoLlantas;
    bool garantia;
    //Manual, Automatica
    std::string tipoTransmision;
    //Disco, Tambor
    std::string tipoFrenos;
    public:

    /**
     * Vehiculo constructor vacío
     * Inicializa el objeto con los atributos default
     * @param
     * @return
     */
    Vehiculo(){
        this-> ID = 0;
        this-> anio = 0;
        this-> kilometraje = 0;
        this-> tiempoAnteriorServicio = 0.0;
        this-> estadoLlantas = 0.0;
        this-> garantia = false;
        this-> tipoTransmision = "NA";
        this-> tipoFrenos = "NA";
    };

    /**
     * Vehiculo constructor con parámetros
     * Recibe los parámetos del usuario y los guarda en los respectivos
     * atributos
     * @param int ID, int año, int kilometraje, float tiempo desde anterior
     * servicio, float estado de llantas, bool garantía, string tipo de
     * transmisión, string tipo de frenos
     * @return
     */
    Vehiculo(int ID,int an,int km,float tas,float el,bool gar,
    std::string tt,std::string tf){
        this-> ID = ID;
        this-> anio = an;
        this-> kilometraje = km;
        this-> tiempoAnteriorServicio = tas;
        this-> estadoLlantas = el;
        this-> garantia = gar;
        this-> tipoTransmision = tt;
        this-> tipoFrenos = tf;
    };
    
    /**
     * setID setter de atributo ID
     * Recibe el ID y lo guarda en el atributo ID
     * @param int ID
     * @return 
     */
    void setID(int Id){this-> ID = Id;}

    /**
     * setAnio setter de atributo Anio
     * Recibe el Anio y lo guarda en el atributo Anio
     * @param int Anio
     * @return 
     */
    void setAnio(int an){this-> anio = an;};

    /**
     * setKilometraje setter de atributo Kilometraje
     * Recibe el Kilometraje y lo guarda en el atributo Kilometraje
     * @param int Kilometraje
     * @return 
     */
    void setKilometraje(int km){this-> kilometraje = km;};

    /**
     * setTiempoAnteriorServicio setter de atributo TiempoAnteriorServicio
     * Recibe el TiempoAnteriorServicio y lo guarda en el atributo 
     * TiempoAnteriorServicio
     * @param float TiempoAnteriorServicio
     * @return 
     */
    void setTiempoAnteriorServicio(float TAS){
        this-> tiempoAnteriorServicio = TAS;};

        /**
     * setEstadoLlantas setter de atributo EstadoLlantas
     * Recibe el EstadoLlantas y lo guarda en el atributo EstadoLlantas
     * @param float EstadoLlantas
     * @return 
     */
    void setEstadoLlantas(float EL){this-> estadoLlantas = EL;};

    /**
     * setTimpoTransmision setter de atributo TimpoTransmision
     * Recibe el TimpoTransmision y lo guarda en el atributo TimpoTransmision
     * @param string TimpoTransmision
     * @return 
     */
    void setTipoTransmision(std::string TT){this-> tipoTransmision = TT;};

    /**
     * setTipoFrenos setter de atributo TipoFrenos
     * Recibe el TipoFrenos y lo guarda en el atributo TipoFrenos
     * @param string TipoFrenos
     * @return 
     */
    void setTipoFrenos(std::string TF){this-> tipoFrenos = TF;};

    /**
     * getID retorna el valor del atriuto ID
     * Regresa el valor del atributo ID
     * @param
     * @return int ID
     */
    int getID(){return ID;};

    /**
     * getanio retorna el valor del atriuto anio
     * Regresa el valor del atributo anio
     * @param
     * @return int anio
     */
    int getAnio(){return anio;};

    /**
     * getKilometraje retorna el valor del atriuto Kilometraje
     * Regresa el valor del atributo Kilometraje
     * @param
     * @return int Kilometraje
     */
    int getKilometraje(){return kilometraje;};

    /**
     * getTiempoAnteriorServicio retorna el valor del atriuto TiempoAnteriorServicio
     * Regresa el valor del atributo TiempoAnteriorServicio
     * @param
     * @return float TiempoAnteriorServicio
     */
    float getTiempoAnteriorServicio(){return tiempoAnteriorServicio;};

    /**
     * ge EstadoLlantas retorna el valor del atriuto EstadoLlantas
     * Regresa el valor del atributo EstadoLlantas
     * @param
     * @return float EstadoLlantas
     */
    float getEstadoLlantas(){return estadoLlantas;};

    /**
     * tieneGarantia retorna el valor del atriuto garantia
     * Regresa el valor del atributo garantia
     * @param
     * @return bool garantia
     */
    bool tieneGarantia(){return garantia;};

    /**
     * getTipoTransmision retorna el valor del atriuto TipoTransmision
     * Regresa el valor del atributo TipoTransmision
     * @param
     * @return string TipoTransmision
     */
    std::string getTipoTransmision(){return tipoTransmision;};

    /**
     * getTipoFrenos retorna el valor del atriuto TipoFrenos
     * Regresa el valor del atributo TipoFrenos
     * @param
     * @return string TipoFrenos
     */
    std::string getTipoFrenos(){return tipoFrenos;};

    /**
     * aux_Datos imprime los atributos
     * Método auxiliar para imprimir los atributos
     * generales de la clase padre
     * @param
     * @return
     */
    void aux_Datos(){
        std::cout<<"\nID: "<<ID;
        std::cout<<"\nAnio: "<<anio;
        std::cout<<"\nKilometraje: "<<kilometraje;
        std::cout<<"\nTiempo Anterior Servicio: "<<tiempoAnteriorServicio;
        std::cout<<"\nEstado Llantas: "<<estadoLlantas;
        std::cout<<"\nGarantia: "<<garantia;
        std::cout<<"\nTipo Transmision: "<<tipoTransmision;
        std::cout<<"\nTipo Frenos: "<<tipoFrenos;
        std::cout <<"\nCosto Servicio: "<<costoServicio();
        std::cout <<"\nDuracion Servicio: "<<duracionServicio();
    }

    /**
     * costoServicio calcula costo de servicio
     * función virtual que calcula el costo del servicio 
     * según los atributos del vehículo
     * @param
     * @return
     */
    virtual float costoServicio() = 0;

    /**
     * duracionServicio calcula duracion de servicio
     * función virtual que calcula la duracion del servicio 
     * según los atributos del vehículo
     * @param
     * @return
     */
    virtual float duracionServicio() = 0;

    /**
     * mostrarDatos imprime los atributos
     * función virtual que imprime los atributos del objeto
     * con sus respectivas etiquetas
     * @param
     * @return
     */
    virtual void mostrarDatos() = 0;
};

class Auto : public Vehiculo {
    protected:
    int numeroPuertas;
    //Hatckback, Sedan, Coupe
    std::string carroceria;

    public:

    /**
     * Auto constructor vacío
     * Inicializa el objeto con los atributos default
     * @param
     * @return
     */
    Auto() : Vehiculo(){
        this-> numeroPuertas = 0;
        this-> carroceria = "NA";
    };

    /**
     * Auto constructor con parámetros
     * Recibe los parámetos del usuario y los guarda en los respectivos
     * atributos
     * @param int ID, int año, int kilometraje, float tiempo desde anterior
     * servicio, float estado de llantas, bool garantía, string tipo de
     * transmisión, string tipo de frenos, int numero de puertas,
     * string carrocería
     * @return
     */
    Auto(int ID,int an,int km,float tas,float el,bool gar,std::string tt,
    std::string tf,int np,std::string carr):
    Vehiculo(ID, an, km, tas, el, gar, tt, tf){
        this-> numeroPuertas = np;
        this-> carroceria = carr;
    };

    /**
     * setNumeroPuertas setter de atributo NumeroPuertas
     * Recibe el NumeroPuertas y lo guarda en el atributo NumeroPuertas
     * @param int NumeroPuertas
     * @return
     */
    void setNumeroPuertas(int np){this-> numeroPuertas = np;};

    /**
     * setCarroceria setter de atributo Carroceria
     * Recibe el Carroceria y lo guarda en el atributo Carroceria
     * @param string Carroceria
     * @return 
     */
    void setCarroceria(std::string cr){this-> carroceria = cr;};

    /**
     * getNumeroPuertas retorna el valor del atriuto NumeroPuertas
     * Regresa el valor del atributo NumeroPuertas
     * @param
     * @return int NumeroPuertas
     */
    int getNumeroPuertas(){return numeroPuertas;};

    /**
     * getCarroceria retorna el valor del atriuto Carroceria
     * Regresa el valor del atributo Carroceria
     * @param
     * @return int Carroceria
     */
    std::string getCarroceria(){return carroceria;};

    /**
     * costoServicio calcula costo de servicio
     * función virtual que calcula el costo del servicio 
     * según los atributos del vehículo
     * @param
     * @return
     */
    virtual float costoServicio() = 0;

    /**
     * duracionServicio calcula duracion de servicio
     * función virtual que calcula la duracion del servicio 
     * según los atributos del vehículo
     * @param
     * @return
     */
    virtual float duracionServicio() = 0;

    /**
     * mostrarDatos imprime los atributos
     * función virtual que imprime los atributos del objeto
     * con sus respectivas etiquetas
     * @param
     * @return
     */
    virtual void mostrarDatos() = 0;
};

class AutoElectrico : public Auto {
    private:
    //kWh
    float capacidadBateria;
    public:

    /**
     * AutoElectrico constructor vacío
     * Inicializa el objeto con los atributos default
     * @param
     * @return
     */
    AutoElectrico() : Auto(){
        this-> capacidadBateria = 0.0;
    };

    /**
     * AutoElectrico constructor con parámetros
     * Recibe los parámetos del usuario y los guarda en los respectivos
     * atributos
     * @param int ID, int año, int kilometraje, float tiempo desde anterior
     * servicio, float estado de llantas, bool garantía, string tipo de
     * transmisión, string tipo de frenos, string numero de puertas,
     * string carroceria, float capacidad de batería
     * @return
     */
    AutoElectrico(int ID,int an,int km,float tas,float el,bool gar,
    std::string tt,std::string tf,int np,std::string carr,float cb):
    Auto(ID, an, km, tas, el, gar, tt, tf, np, carr){
        this-> capacidadBateria = cb;
    };

    /**
     * setCapacidadBateria setter de atributo CapacidadBateria
     * Recibe el CapacidadBateria y lo guarda en el atributo CapacidadBateria
     * @param float CapacidadBateria
     * @return 
     */
    void setCapacidadBateria(float cb){this-> capacidadBateria = cb;};

   /**
     * getCapacidadBateria retorna el valor del atriuto CapacidadBateria
     * Regresa el valor del atributo CapacidadBateria
     * @param
     * @return float CapacidadBateria
     */
    float getCapacidadBateria(){return capacidadBateria;};

    /**
     * costoServicio calcula costo de servicio
     * sobreescritura de la función virtual que calcula el costo del servicio
     * según los atributos del vehículo
     * @param
     * @return
     */    
    float costoServicio() override{
        float servicio = (anio - 1980)*10 + (kilometraje/10000);
        if (estadoLlantas <= LIMITE_VIDA_LLANTAS && garantia){
            servicio += COSTO_LLANTAS/2;
        }
        else if (estadoLlantas <= LIMITE_VIDA_LLANTAS)
        {
            servicio += COSTO_LLANTAS;
        }
        if(tipoTransmision == "Manual"){
            servicio += COSTO_SERVICIO_TRANSMISION_MANUAL;
        }
        if(tipoTransmision == "Automatica"){
            servicio += COSTO_SERVICIO_TRANSMISION_AUTOMATICA;
        }
        if(tipoFrenos == "Disco"){
            servicio += COSTO_SERVICIO_FRENOS_DISCO;
        }
        if(tipoFrenos == "Tambor"){
            servicio += COSTO_SERVICIO_FRENOS_TAMBOR;
        }
        servicio += numeroPuertas*MULTIPLICADOR_NUMERO_PUERTAS;

        if(garantia){
            servicio += capacidadBateria*MULTIPLICADOR_CAPACIDAD_BATERIA/2;
        }
        else{
            servicio += capacidadBateria*MULTIPLICADOR_CAPACIDAD_BATERIA;
        }

        return servicio;
    };

    /**
     * 
     * duracionServicio calcula duracion de servicio
     * sobreescritura de la función virtual que calcula la duracion del servicio
     * según los atributos del vehículo
     * @param
     * @return
     */
    float duracionServicio() override{
        return tiempoAnteriorServicio/2 + capacidadBateria*0.1;
    };

    /**
     * mostrarDatos imprime los atributos
     * sobreescritura de la función virtual que imprime los atributos del objeto
     * con sus respectivas etiquetas
     * @param
     * @return
     */
    void mostrarDatos() override{
        aux_Datos();
        std::cout<<"\nNumero Puertas: "<<numeroPuertas;
        std::cout<<"\nTipo Carroceria: "<<carroceria;
        std::cout<<"\nCapacidad Bateria: "<<capacidadBateria;
    }
};

class AutoGasolina : public Auto {
    private:
    //Litros
    float cilindraje;
    int numeroCilindros;
    //Mineral, Semi-Sintetico, Sintetico
    std::string tipoAceite;
    public:

    /**
     * AutoGasolina constructor vacío
     * Inicializa el objeto con los atributos default
     * @param
     * @return
     */
    AutoGasolina() : Auto(){
        this-> cilindraje = 0.0;
        this-> numeroCilindros = 0;
        this-> tipoAceite = "NA";
    };

    /**
     * AutoGasolina constructor con parámetros
     * Recibe los parámetos del usuario y los guarda en los respectivos
     * atributos
     * @param int ID, int año, int kilometraje, float tiempo desde anterior
     * servicio, float estado de llantas, bool garantía, string tipo de
     * transmisión, string tipo de frenos, int numero de puertas,
     * string carrocería, float cilindraje, int numero cilindros,
     * string tipo de aceite
     * @return
     */
    AutoGasolina(int ID,int an,int km,float tas,float el,bool gar,
    std::string tt,std::string tf,int np,std::string carr,float cil,
    int nc,std::string ta):
    Auto(ID, an, km, tas, el, gar, tt, tf, np, carr){
        this-> cilindraje = cil;
        this-> numeroCilindros = nc;
        this-> tipoAceite = ta;
    };

    /**
     * setCilindraje setter de atributo Cilindraje
     * Recibe el Cilindraje y lo guarda en el atributo Cilindraje
     * @param float Cilindraje
     * @return 
     */
    void setCilindraje(float cil){this-> cilindraje = cil;};

    /**
     * setNumeroCilindros setter de atributo NumeroCilindros
     * Recibe el NumeroCilindros y lo guarda en el atributo NumeroCilindros
     * @param int NumeroCilindros
     * @return 
     */
    void setNumeroCilindros(int numcil){this-> numeroCilindros = numcil;};

    /**
     * setTipoAceite setter de atributo TipoAceite
     * Recibe el TipoAceite y lo guarda en el atributo TipoAceite
     * @param string TipoAceite
     * @return 
     */
    void setTipoAceite(std::string ta){this-> tipoAceite = ta;};
    
    /**
     * getCilindraje retorna el valor del atriuto Cilindraje
     * Regresa el valor del atributo Cilindraje
     * @param
     * @return float Cilindraje
     */
    float getCilindraje(){return cilindraje;};
    
    /**
     * getNumeroCilindros retorna el valor del atriuto NumeroCilindros
     * Regresa el valor del atributo NumeroCilindros
     * @param
     * @return int NumeroCilindros
     */
    int getNumerocilindros(){return numeroCilindros;};
    
    /**
     * getTipoAceite retorna el valor del atriuto TipoAceite
     * Regresa el valor del atributo TipoAceite
     * @param
     * @return string TipoAceite
     */
    std::string getTipoAceite(){return tipoAceite;};
    
    /**
     * costoServicio calcula costo de servicio
     * sobreescritura de la función virtual que calcula el costo del servicio
     * según los atributos del vehículo
     * @param
     * @return
     */ 
    float costoServicio() override{
        float servicio = (anio - 1980)*10 + (kilometraje/10000);
        if (estadoLlantas <= LIMITE_VIDA_LLANTAS && garantia){
            servicio += COSTO_LLANTAS/2;
        }
        else if (estadoLlantas <= LIMITE_VIDA_LLANTAS)
        {
            servicio += COSTO_LLANTAS;
        }
        if(tipoTransmision == "Manual"){
            servicio += COSTO_SERVICIO_TRANSMISION_MANUAL;
        }
        if(tipoTransmision == "Automatica"){
            servicio += COSTO_SERVICIO_TRANSMISION_AUTOMATICA;
        }
        if(tipoFrenos == "Disco"){
            servicio += COSTO_SERVICIO_FRENOS_DISCO;
        }
        if(tipoFrenos == "Tambor"){
            servicio += COSTO_SERVICIO_FRENOS_TAMBOR;
        }
        servicio += numeroPuertas*MULTIPLICADOR_NUMERO_PUERTAS;

        servicio += cilindraje/numeroCilindros*MULTIPLICADOR_CILINDROS;
        if(tipoAceite == "Mineral"){
            servicio += COSTO_ACEITE_MINERAL;
        }
        if(tipoAceite == "Semi-Sintetico"){
            servicio += COSTO_ACEITE_SEMISINTETICO;
        }
        if(tipoAceite == "Sintetico"){
            servicio += COSTO_ACEITE_SINTETICO;
        }
        return servicio;
    };

    /**
     * 
     * duracionServicio calcula duracion de servicio
     * sobreescritura de la función virtual que calcula la duracion del servicio
     * según los atributos del vehículo
     * @param
     * @return
     */
    float duracionServicio() override{
        return tiempoAnteriorServicio/2 + numeroCilindros*0.1;
    };

    /**
     * mostrarDatos imprime los atributos
     * sobreescritura de la función virtual que imprime los atributos del objeto
     * con sus respectivas etiquetas
     * @param
     * @return
     */
    void mostrarDatos() override{
        aux_Datos();
        std::cout<<"\nNumero de puertas: "<<numeroPuertas;
        std::cout<<"\nCarroceria: "<<carroceria;
        std::cout<<"\nCilindraje: "<<cilindraje;
        std::cout<<"\nNumero cilindros: "<<numeroCilindros;
        std::cout<<"\nTipo de aceite: "<<tipoAceite;
    };
};

class Van : public Vehiculo {
    private:
    int numeroAsientos;
    //Gasolina, Diesel
    std::string tipoCombustible;
    public:

    /**
     * Van constructor vacío
     * Inicializa el objeto con los atributos default
     * @param
     * @return
     */
    Van() :Vehiculo(){
        this-> numeroAsientos = 0;
        this-> tipoCombustible = "NA";
    };

    /**
     * Van constructor con parámetros
     * Recibe los parámetos del usuario y los guarda en los respectivos
     * atributos
     * @param int ID, int año, int kilometraje, float tiempo desde anterior
     * servicio, float estado de llantas, bool garantía, string tipo de
     * transmisión, string tipo de frenos, int numero de asientos,
     * string tipo de combustible
     * @return
     */
    Van(int ID,int an,int km,float tas,float el,bool gar,
    std::string tt,std::string tf,int na,std::string tc):
    Vehiculo(ID, an, km, tas, el, gar, tt, tf){
        this-> numeroAsientos = na;
        this-> tipoCombustible = tc;
    };

    /**
     * setNumeroAsientos setter de atributo NumeroAsientos
     * Recibe el NumeroAsientos y lo guarda en el atributo NumeroAsientos
     * @param int NumeroAsientos
     * @return 
     */
    void setNumeroAsientos(int numas){this-> numeroAsientos = numas;};

    /**
     * setTipoCombustible setter de atributo TipoCombustible
     * Recibe el TipoCombustible y lo guarda en el atributo TipoCombustible
     * @param string TipoCombustible
     * @return 
     */
    void setTipoCombustible(std::string tc){this-> tipoCombustible = tc;};

    /**
     * getNumeroAsientos retorna el valor del atriuto NumeroAsientos
     * Regresa el valor del atributo NumeroAsientos
     * @param
     * @return int NumeroAsientos
     */
    int getNumeroAsientos(){return numeroAsientos;};

    /**
     * getTipoCombustible retorna el valor del atriuto TipoCombustible
     * Regresa el valor del atributo TipoCombustible
     * @param
     * @return int TipoCombustible
     */
    std::string getTipoCombustible(){return tipoCombustible;};

    /**
     * costoServicio calcula costo de servicio
     * sobreescritura de la función virtual que calcula el costo del servicio
     * según los atributos del vehículo
     * @param
     * @return
     */    
    float costoServicio() override{
        float servicio = (anio - 1980)*10 + (kilometraje/10000);
        if (estadoLlantas <= LIMITE_VIDA_LLANTAS && garantia){
            servicio += COSTO_LLANTAS/2;
        }
        else if (estadoLlantas <= LIMITE_VIDA_LLANTAS)
        {
            servicio += COSTO_LLANTAS;
        }
        if(tipoTransmision == "Manual"){
            servicio += COSTO_SERVICIO_TRANSMISION_MANUAL;
        }
        if(tipoTransmision == "Automatica"){
            servicio += COSTO_SERVICIO_TRANSMISION_AUTOMATICA;
        }
        if(tipoFrenos == "Disco"){
            servicio += COSTO_SERVICIO_FRENOS_DISCO;
        }
        if(tipoFrenos == "Tambor"){
            servicio += COSTO_SERVICIO_FRENOS_TAMBOR;
        }
        if(tipoCombustible == "Diesel"){
            servicio += COSTO_SERVICIO_DIESEL;
        }
        if(tipoCombustible == "Gasolina"){
            servicio += COSTO_SERVICIO_GASOLINA;
        }
        return servicio;
    };

    /**
     * 
     * duracionServicio calcula duracion de servicio
     * sobreescritura de la función virtual que calcula la duracion del servicio
     * según los atributos del vehículo
     * @param
     * @return
     */
    float duracionServicio() override{
        return tiempoAnteriorServicio/2 + numeroAsientos*0.1;
    };

    /**
     * mostrarDatos imprime los atributos
     * sobreescritura de la función virtual que imprime los atributos del objeto
     * con sus respectivas etiquetas
     * @param
     * @return
     */
    void mostrarDatos() override{
        aux_Datos();
        std::cout<<"\nNumero asientos: "<<numeroAsientos;
        std::cout<<"\nTipo combustible: "<<tipoCombustible;
    };
};

class Moto : public Vehiculo {
    private:
    //cc
    int cilindrada;
    public:

    /**
     * Moto constructor vacío
     * Inicializa el objeto con los atributos default
     * @param
     * @return
     */
    Moto() : Vehiculo(){
        this-> cilindrada = 0;
    };

    /**
     * Moto constructor con parámetros
     * Recibe los parámetos del usuario y los guarda en los respectivos
     * atributos
     * @param int ID, int año, int kilometraje, float tiempo desde anterior
     * servicio, float estado de llantas, bool garantía, string tipo de
     * transmisión, string tipo de frenos, int cilindrada
     * @return
     */
    Moto(int ID,int an,int km,float tas,float el,bool gar,
    std::string tt,std::string tf,int cil):
    Vehiculo(ID, an, km, tas, el, gar, tt, tf){
        this-> cilindrada = cil;
    };

    /**
     * setCilindrada setter de atributo Cilindrada
     * Recibe el Cilindrada y lo guarda en el atributo Cilindrada
     * @param int Cilindrada
     * @return 
     */
    void setCilindrada(int cil){this-> cilindrada = cil;};

    /**
     * getCilindrada retorna el valor del atriuto Cilindrada
     * Regresa el valor del atributo Cilindrada
     * @param
     * @return int Cilindrada
     */
    int getCilindrada(){return cilindrada;};

    /**
     * costoServicio calcula costo de servicio
     * sobreescritura de la función virtual que calcula el costo del servicio
     * según los atributos del vehículo
     * @param
     * @return
     */  
    float costoServicio() override{
                float servicio = (anio - 1980)*10 + (kilometraje/10000);
        if (estadoLlantas <= LIMITE_VIDA_LLANTAS && garantia){
            servicio += COSTO_LLANTAS/2;
        }
        else if (estadoLlantas <= LIMITE_VIDA_LLANTAS)
        {
            servicio += COSTO_LLANTAS;
        }
        if(tipoTransmision == "Manual"){
            servicio += COSTO_SERVICIO_TRANSMISION_MANUAL;
        }
        if(tipoTransmision == "Automatica"){
            servicio += COSTO_SERVICIO_TRANSMISION_AUTOMATICA;
        }
        if(tipoFrenos == "Disco"){
            servicio += COSTO_SERVICIO_FRENOS_DISCO;
        }
        if(tipoFrenos == "Tambor"){
            servicio += COSTO_SERVICIO_FRENOS_TAMBOR;
        }
        return servicio;
    };

    /**
     * 
     * duracionServicio calcula duracion de servicio
     * sobreescritura de la función virtual que calcula la duracion del servicio
     * según los atributos del vehículo
     * @param
     * @return
     */
    float duracionServicio() override{
        return tiempoAnteriorServicio/2 + cilindrada*0.002;
    };

    /**
     * mostrarDatos imprime los atributos
     * sobreescritura de la función virtual que imprime los atributos del objeto
     * con sus respectivas etiquetas
     * @param
     * @return
     */
    void mostrarDatos() override{
        aux_Datos();
        std::cout<<"\nCilindrada"<<cilindrada;
    };
};

#endif
