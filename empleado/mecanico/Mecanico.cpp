//
// Created by Hugo Ziviani on 8/26/20.
//

#include "Mecanico.h"

Mecanico::Mecanico(int id, const string &nombre, const string &setor, const string &funcion, bool disponible) :
    Empleado(id, nombre, setor),
    funcion(funcion),
    disponible(disponible) {}

Mecanico::~Mecanico() {}

const string &Mecanico::getFuncion() const {
    return funcion;
}
void Mecanico::setFuncion(const string &funcion) {
    Mecanico::funcion = funcion;
}

bool Mecanico::isDisponible() const {
    return disponible;
}
void Mecanico::setDisponible(bool disponible) {
    Mecanico::disponible = disponible;
}

void Mecanico::salida(ostream &os) const {
    Empleado::salida(os);
    os  << R"( "funcion" : ")" << Mecanico::getFuncion() <<"\","
        << R"( "disponible" : ")" << Mecanico::isDisponible() <<"\"}\n";
}

ostream &operator<<(ostream &os, const Mecanico &mecanico) {
    mecanico.salida(os);
    return os;
}
