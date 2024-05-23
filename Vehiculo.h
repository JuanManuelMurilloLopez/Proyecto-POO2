#include<iostream>

#ifndef VEHICULO_H
#define VEHICULO_H

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
    //Manual, Automática
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

    virtual float costoServicio();
    virtual float duracionServicio();
};

class Auto : public Vehiculo {
    protected:
    int numeroPuertas;
    //Sedán, Hatckback, Coupe
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
};

class AutoElectrico : public Auto {
    private:
    //kWh
    float capacidadBateria;
    public:
    AutoElectrico() : Auto(){
        this-> capacidadBateria = 0.0;
    };
    AutoElectrico(int ID, int anio, int kilometraje, float tiempoAnteriorServicio, float estadoLlantas, bool garantia, std::string TipoTransmision, std::string tipoFrenos, int numeroPuertas, std::string carroceria, float capacidadBateria) : Auto(ID, anio, kilometraje, tiempoAnteriorServicio, estadoLlantas, garantia, tipoTransmision, tipoFrenos, numeroPuertas, carroceria){
        this-> capacidadBateria = capacidadBateria;
    };
    void setCapacidadBateria(float cb){this-> capacidadBateria = cb;};
    float getCapacidadBateria(){return capacidadBateria;};
    virtual float costoServicio() override;
    virtual float duracionServicio() override;
};

class AutoGasolina : public Auto {
    private:
    //Litros
    float cilindraje;
    int numeroCilindros;
    //Mineral, Semi-Sintético, Sintético
    std::string tipoAceite;
    public:
    AutoGasolina() : Auto(){
        this-> cilindraje = 0.0;
        this-> numeroCilindros = 0;
        this-> tipoAceite = "NA";
    };
    AutoGasolina(int ID, int anio, int kilometraje, float tiempoAnteriorServicio, float estadoLlantas, bool garantia, std::string TipoTransmision, std::string tipoFrenos, int numeroPuertas, std::string carroceria, float cilindraje, int numeroCilindros, std::string tipoAceite) : Auto(ID, anio, kilometraje, tiempoAnteriorServicio, estadoLlantas, garantia, tipoTransmision, tipoFrenos, numeroPuertas, carroceria){
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
    virtual float costoServicio() override;
    virtual float duracionServicio() override;
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
    virtual float costoServicio() override;
    virtual float duracionServicio() override;
};

class Moto : public Vehiculo {
    private:
    //cc
    int cilindrada;
    //Scooter, Turismo, Deportiva
    std::string tipo;
    public:
    Moto() : Vehiculo(){
        this-> cilindrada = 0;
        this-> tipo = "NA";
    };
    Moto(int ID, int anio, int kilometraje, float tiempoAnteriorServicio, float estadoLlantas, bool garantia, std::string tipoTransmision, std::string tipoFrenos, int cilindrada, std::string tipo) : Vehiculo(ID, anio, kilometraje, tiempoAnteriorServicio, estadoLlantas, garantia, tipoTransmision, tipoFrenos){
        this-> cilindrada = cilindrada;
        this-> tipo = tipo;
    };
    void setCilindrada(int cil){this-> cilindrada = cil;};
    void setTipo(std::string tip){this-> tipo = tip;};
    int getCilindrada(){return cilindrada;};
    std::string getTipo(){return tipo;};
    virtual float costoServicio() override;
    virtual float duracionServicio() override;
};

#endif
