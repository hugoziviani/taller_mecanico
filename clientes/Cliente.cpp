//
// Created by Hugo Ziviani on 8/26/20.
//

#include "Cliente.h"




Cliente::~Cliente() {
    //Desalocar o veículo, por uma função da classe de Vehiculo TODO

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

const string &Cliente::getTelefono() const {
    return telefono;
}
void Cliente::setTelefono(const string &telefono) {
    Cliente::telefono = telefono;
}

void Cliente::salida(ostream &os) const {
    os  <<"{"
        << R"( "clienteId" : ")" << Cliente::getId() <<"\","
        << R"( "nombre" : ")" << Cliente::getNombre() <<"\","
        << R"( "telefono" : ")" << Cliente::getTelefono() <<"\","
        << R"( "vehicle" : )";

    for (auto it = Cliente::vehiculosList.begin(); it != Cliente::vehiculosList.end(); it++) {
        if (!((it) == Cliente::vehiculosList.end()) and ((it) != Cliente::vehiculosList.begin())) {
            cout << ",\n";
        }
        os<<*(*it);
    }
    os <<"} ";
}


ostream &operator<<(ostream &os, const Cliente &cliente) {
    cliente.salida(os);
    return os;
}


Cliente::Cliente(int id, const string &nombre, const string &telefono)
        : id(id), nombre(nombre), telefono(telefono){}

void Cliente::anadirVehiculo(Vehiculo *vehiculo) {
    Cliente::vehiculosList.push_front(vehiculo);
}
