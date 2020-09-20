//
// Created by Hugo Ziviani on 8/26/20.
//

#include "Cliente.h"


Cliente::Cliente(int id, const string &nombre, const string &telefono, Vehiculo &vehicle) :
                 id(id), nombre(nombre),
                 vehicle(&vehicle),
                 telefono(telefono) {}

Cliente::~Cliente() {
    //Desalocar o veículo, por uma função da classe de Vehiculo
    delete this->vehicle;
}

int Cliente::getId() const {
    return id;
}
void Cliente::setId(int id) {
    Cliente::id = id;
}

const string &Cliente::getNombre() const {
    return nombre;
}
void Cliente::setNombre(const string &nombre) {
    Cliente::nombre = nombre;
}

Vehiculo *Cliente::getVehicle() const {
    return vehicle;
}
void Cliente::setVehicle(Vehiculo *vehicle) {
    Cliente::vehicle = vehicle;
}

const string &Cliente::getTelefono() const {
    return telefono;
}
void Cliente::setTelefono(const string &telefono) {
    Cliente::telefono = telefono;
}

ostream &operator<<(ostream &os, const Cliente &cliente) {
    os
    << "\n{"
    << "\n\"id\" : \"" << cliente.id <<"\","
    << "\n\"nombre\" : \"" << cliente.nombre<<"\","
    << "\n\"telefono\" : \"" << cliente.telefono <<"\","
    << "\n\"vehicle\" : " << *cliente.vehicle
    << "\n}";
    return os;
}
