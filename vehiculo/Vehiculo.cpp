//
// Created by Hugo Ziviani on 8/26/20.
//

#include "Vehiculo.h"


Vehiculo::Vehiculo(int id, const string &modelo, float kilometraje, const string &placa):
    id(id),
    modelo(modelo),
    kilometraje(kilometraje),
    placa(placa) {}

Vehiculo::~Vehiculo() {
}

int Vehiculo::getId() {
    return this->id;
}
void Vehiculo::setId(int id) {
    this->id = id;
}

const string &Vehiculo::getModelo() const {
    return modelo;
}
void Vehiculo::setModelo(const string &modelo) {
    Vehiculo::modelo = modelo;
}

float Vehiculo::getKilometraje() const {
    return kilometraje;
}
void Vehiculo::setKilometraje(float kilometraje) {
    Vehiculo::kilometraje = kilometraje;
}

const string &Vehiculo::getPlaca() const {
    return placa;
}
void Vehiculo::setPlaca(const string &placa) {
    Vehiculo::placa = placa;
}

Vehiculo& Vehiculo::operator=(const Vehiculo &vehiculo) {
    if(this == &vehiculo) return *this;
    this->id = vehiculo.id;
    this->modelo = vehiculo.getModelo();
    this->kilometraje = vehiculo.getKilometraje();
    this->placa = vehiculo.getPlaca();
    return *this;
}

bool operator==(const Vehiculo& vehiculo1, const Vehiculo& vehiculo2){
    return (vehiculo1.getPlaca() == vehiculo2.getPlaca());
}

void showlist(list<Vehiculo> g){
    std::list<Vehiculo>::iterator it;
    for(it = g.begin(); it != g.end(); ++it)
        cout << '\t' << it->getModelo();
    cout << '\n';
}

ostream &operator<<(ostream &os, const Vehiculo &vehiculo) {
    os
    << "\n{"
    << "\n \"id\": " << "\""<<vehiculo.id<<"\","
    << "\n \"modelo\": " << "\""<<vehiculo.modelo<<"\","
    << "\n \"kilometraje\": " << "\""<<vehiculo.kilometraje<<"\","
    << "\n \"placa\": " << "\""<<vehiculo.placa<<"\""
    << "\n}";
    return os;
}
istream &operator>>(istream &is,Vehiculo &vehiculo) {
    is >> vehiculo.id >> vehiculo.modelo >> vehiculo.kilometraje >> vehiculo.placa;
    return is;
}