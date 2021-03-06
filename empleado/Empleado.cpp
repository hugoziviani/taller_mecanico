#include "Empleado.h"

Empleado::Empleado(int id, const string &nombre, const string &setor) :
    id(id),
    nombre(nombre),
    setor(setor) {}

Empleado::~Empleado() {
}

int Empleado::getId() const {
    return id;
}
void Empleado::setId(int id) {
    Empleado::id = id;
}

const string &Empleado::getNombre() const {
    return nombre;
}
void Empleado::setNombre(const string &nombre) {
    Empleado::nombre = nombre;
}

const string &Empleado::getSetor() const {
    return setor;
}
void Empleado::setSetor(const string &setor) {
    Empleado::setor = setor;
}


void Empleado::salida(ostream &os) const {
    os  <<"{"
        << R"( "idEmpleado" : ")" << Empleado::getId()<<"\","
        << R"( "nombre": ")" << Empleado::getNombre()<<"\","
        << R"( "setor" : ")" << Empleado::getSetor()<<"\",";
}
ostream &operator<<(ostream &os, const Empleado &empleado) {
    empleado.salida(os);
    return os;
}








