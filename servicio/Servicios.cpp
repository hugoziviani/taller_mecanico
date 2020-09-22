//
// Created by Hugo Ziviani on 8/26/20.
//

#include "Servicios.h"


Servicios::Servicios(int id, Empleado *responsable, Cliente *cliente, int status, float precioTotal, int tipo,
                     const list<pair<int, ItemServicio *>> &serviciosList) : id(id), responsable(responsable),
                                                                             cliente(cliente), status(status),
                                                                             precioTotal(precioTotal), tipo(tipo),
                                                                             serviciosList(serviciosList) {}

int Servicios::getId() const {
    return id;
}
void Servicios::setId(int id) {
    Servicios::id = id;
}

Empleado *Servicios::getResponsable() const {
    return responsable;
}
void Servicios::setResponsable(Empleado *responsable) {
    Servicios::responsable = responsable;
}

int Servicios::getStatus() const {
    return status;
}
void Servicios::setStatus(int status) {
    Servicios::status = status;
}

float Servicios::getPrecioTotal() const {
    return precioTotal;
}
void Servicios::setPrecioTotal(float precioTotal) {
    Servicios::precioTotal = precioTotal;
}

int Servicios::getTipo() const {
    return tipo;
}
void Servicios::setTipo(int tipo) {
    Servicios::tipo = tipo;
}

const list<pair<int, ItemServicio *>> &Servicios::getServiciosList() const {
    return serviciosList;
}


void Servicios::insertItemOnList(ItemServicio *itemServicio){
    Servicios::serviciosList.push_front(make_pair(serviciosList.size(), itemServicio));
}

ostream &operator<<(ostream &os, const Servicios &servicios) {

    os
        << "\n{"
        << "\n\"serviciosId\" : \"" << servicios.id <<"\","
        << "\n\"responsable\" : \"" << *servicios.responsable<<"\","
        << "\n\"cliente\" : " << *servicios.cliente<<","
        << "\n\"precioTotal\" : \"" << servicios.precioTotal <<"\","
        << "\n\"tipo\" : \"" << servicios.tipo <<"\","
        << "\n\"serviciosList\" : ";
        for (auto& x: servicios.serviciosList){
            os  << *x.second
                << ",";
        }
        os << "\n}";

    return os;
}