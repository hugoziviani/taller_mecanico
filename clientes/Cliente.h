//
// Created by Hugo Ziviani on 8/26/20.
//

#ifndef TALLER_MECANICO_CLIENTE_H
#define TALLER_MECANICO_CLIENTE_H

#include "../vehiculo/Vehiculo.h"
#include <string>
#include <ostream>

using namespace std;

class Cliente{
    int id;
    string nombre;
    Vehiculo *vehicle; //TODO transformar em lista de veiculos
    string telefono;
public:
    Cliente(int id=0, const string &nombre="", const string &telefono="", Vehiculo &vehicle = *(new Vehiculo()));
    virtual ~Cliente();

    int getId() const;
    void setId(int id);

    const string &getNombre() const;
    void setNombre(const string &nombre);

    Vehiculo *getVehicle() const;
    void setVehicle(Vehiculo *vehicle);

    const string &getTelefono() const;
    void setTelefono(const string &telefono);

    friend ostream &operator<<(ostream &os, const Cliente &cliente);

};


#endif //TALLER_MECANICO_CLIENTE_H
