//
// Created by Hugo Ziviani on 8/26/20.
//

#include "Empleado.h"
Empleado::Empleado(const string &nombre) : nombre(nombre) {}

const string &Empleado::getNombre() const {
    return nombre;
}
