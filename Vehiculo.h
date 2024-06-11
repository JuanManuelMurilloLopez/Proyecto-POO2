#include<iostream>

#ifndef VEHICULO_H
#define VEHICULO_H

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
    Vehiculo(int ID, int anio, int kilometraje, float tiempoAnteriorServicio, float estadoLlantas, bool garantia, std::string tipoTransmision, std::string tipoFrenos){
        this-> ID = ID;
        this-> anio = anio;
        this-> kilometraje = kilometraje;
        this-> tiempoAnteriorServicio = tiempoAnteriorServicio;
        this-> estadoLlantas = estadoLlantas;
        this-> garantia = garantia;
        this-> tipoTransmision = tipoTransmision;
        this-> tipoFrenos = tipoFrenos;
    };
    
    void setID(int Id){this-> ID = Id;}
    void setAnio(int an){this-> anio = an;};
    void setKilometraje(int km){this-> kilometraje = km;};
    void setTiempoAnteriorServicio(float TAS){this-> tiempoAnteriorServicio = TAS;};
    void setEstadoLlantas(float EL){this-> estadoLlantas = EL;};
    void setTipoTransmision(std::string TT){this-> tipoTransmision = TT;};
    void setTipoFrenos(std::string TF){this-> tipoFrenos = TF;};

    int getID(){return ID;};
    int getAnio(){return anio;};
    int getKilometraje(){return kilometraje;};
    float getTiempoAnteriorServicio(){return tiempoAnteriorServicio;};
    float getEstadoLlantas(){return estadoLlantas;};
    bool tieneGarantia(){return garantia;};
    std::string getTipoTransmision(){return tipoTransmision;};
    std::string getTipoFrenos(){return tipoFrenos;};
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

    virtual float costoServicio() = 0;
    virtual float duracionServicio() = 0;
    virtual void mostrarDatos() = 0;
};

class Auto : public Vehiculo {
    protected:
    int numeroPuertas;
    //Hatckback, Sedan, Coupe
    std::string carroceria;

    public:
    Auto() : Vehiculo(){
        this-> numeroPuertas = 0;
        this-> carroceria = "NA";
    };
    Auto(int ID, int anio, int kilometraje, float tiempoAnteriorServicio, float estadoLlantas, bool garantia, std::string tipoTransmision, std::string tipoFrenos, int numeroPuertas, std::string carroceria) : Vehiculo(ID, anio, kilometraje, tiempoAnteriorServicio, estadoLlantas, garantia, tipoTransmision, tipoFrenos){
        this-> numeroPuertas = numeroPuertas;
        this-> carroceria = carroceria;
    };
    void setNumeroPuertas(int np){this-> numeroPuertas = np;};
    void setCarroceria(std::string cr){this-> carroceria = cr;};
    int getNumeroPuertas(){return numeroPuertas;};
    std::string getCarroceria(){return carroceria;};
    virtual float costoServicio() = 0;
    virtual float duracionServicio() = 0;
    virtual void mostrarDatos() = 0;
};

class AutoElectrico : public Auto {
    private:
    //kWh
    float capacidadBateria;
    public:
    AutoElectrico() : Auto(){
        this-> capacidadBateria = 0.0;
    };
    AutoElectrico(int ID, int anio, int kilometraje, float tiempoAnteriorServicio, float estadoLlantas, bool garantia, std::string tipoTransmision, std::string tipoFrenos, int numeroPuertas, std::string carroceria, float capacidadBateria) : Auto(ID, anio, kilometraje, tiempoAnteriorServicio, estadoLlantas, garantia, tipoTransmision, tipoFrenos, numeroPuertas, carroceria){
        this-> capacidadBateria = capacidadBateria;
    };
    void setCapacidadBateria(float cb){this-> capacidadBateria = cb;};
    float getCapacidadBateria(){return capacidadBateria;};
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
    float duracionServicio() override{
        return tiempoAnteriorServicio/2 + capacidadBateria*0.1;
    };
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
    AutoGasolina() : Auto(){
        this-> cilindraje = 0.0;
        this-> numeroCilindros = 0;
        this-> tipoAceite = "NA";
    };
    AutoGasolina(int ID, int anio, int kilometraje, float tiempoAnteriorServicio, float estadoLlantas, bool garantia, std::string tipoTransmision, std::string tipoFrenos, int numeroPuertas, std::string carroceria, float cilindraje, int numeroCilindros, std::string tipoAceite) : Auto(ID, anio, kilometraje, tiempoAnteriorServicio, estadoLlantas, garantia, tipoTransmision, tipoFrenos, numeroPuertas, carroceria){
        this-> cilindraje = cilindraje;
        this-> numeroCilindros = numeroCilindros;
        this-> tipoAceite = tipoAceite;
    };

    void setCilindraje(float cil){this-> cilindraje = cil;};
    void setNumeroCilindros(int numcil){this-> numeroCilindros = numcil;};
    void setTipoAceite(std::string ta){this-> tipoAceite = ta;};
    float getCilindraje(){return cilindraje;};
    int getNumerocilindros(){return numeroCilindros;};
    std::string getTipoAceite(){return tipoAceite;};
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
    float duracionServicio() override{
        return tiempoAnteriorServicio/2 + numeroCilindros*0.1;
    };
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
    Van() :Vehiculo(){
        this-> numeroAsientos = 0;
        this-> tipoCombustible = "NA";
    };
    Van(int ID, int anio, int kilometraje, float tiempoAnteriorServicio, float estadoLlantas, bool garantia, std::string tipoTransmision, std::string tipoFrenos, int numeroAsientos, std::string tipoCombustible) :  Vehiculo(ID, anio, kilometraje, tiempoAnteriorServicio, estadoLlantas, garantia, tipoTransmision, tipoFrenos){
        this-> numeroAsientos = numeroAsientos;
        this-> tipoCombustible = tipoCombustible;
    };

    void setNumeroAsientos(int numas){this-> numeroAsientos = numas;};
    void setTipoCombustible(std::string tc){this-> tipoCombustible = tc;};
    int getNumeroAsientos(){return numeroAsientos;};
    std::string getTipoCombustible(){return tipoCombustible;};
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
    float duracionServicio() override{
        return tiempoAnteriorServicio/2 + numeroAsientos*0.1;
    };
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
    Moto() : Vehiculo(){
        this-> cilindrada = 0;
    };
    Moto(int ID, int anio, int kilometraje, float tiempoAnteriorServicio, float estadoLlantas, bool garantia, std::string tipoTransmision, std::string tipoFrenos, int cilindrada) : Vehiculo(ID, anio, kilometraje, tiempoAnteriorServicio, estadoLlantas, garantia, tipoTransmision, tipoFrenos){
        this-> cilindrada = cilindrada;
    };

    void setCilindrada(int cil){this-> cilindrada = cil;};
    int getCilindrada(){return cilindrada;};
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
    float duracionServicio() override{
        return tiempoAnteriorServicio/2 + cilindrada*0.002;
    };
    void mostrarDatos() override{
        aux_Datos();
        std::cout<<"\nCilindrada"<<cilindrada;
    };
};

#endif
