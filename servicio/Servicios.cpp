//
// Created by Hugo Ziviani on 8/26/20.
//

#include "Servicios.h"

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

ItemServicio *const *Servicios::getItenServicios() const {
    return itenServicios;
}

