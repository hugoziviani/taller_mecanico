#include "Cliente.h"


Cliente::Cliente(int id, const string &nombre, const string &telefono, const list<Vehiculo *> &vehiculosList) : id(id),
                                                                                                                nombre(nombre),
                                                                                                                telefono(telefono),
                                                                                                                vehiculosList(vehiculosList){}

Cliente::~Cliente() {
    if (!Cliente::vehiculosList.empty()) {
        for (auto &x: Cliente::vehiculosList) {
            delete x;
        }
    }
}

void Cliente::anadirVehiculo(Vehiculo *vehiculo) {
    Cliente::vehiculosList.push_back(vehiculo);
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
    os << "{"
       << R"( "clienteId" : ")" << Cliente::getId() << "\","
       << R"( "nombre" : ")" << Cliente::getNombre() << "\","
       << R"( "telefono" : ")" << Cliente::getTelefono() << "\","
       << R"( "vehicles" : )";
    if (!Cliente::vehiculosList.empty()){
        for (auto it = Cliente::vehiculosList.begin(); it != Cliente::vehiculosList.end(); it++) {
            if (!((it) == Cliente::vehiculosList.end()) and ((it) != Cliente::vehiculosList.begin())) {
                os << ",\n";
            }
            os <<*(*it);
        }
    }else{
        os << "{}";//(*it)->getPlaca();
    }
    os << "} ";
}


ostream &operator<<(ostream &os, const Cliente &cliente) {
    cliente.salida(os);
    return os;
}
