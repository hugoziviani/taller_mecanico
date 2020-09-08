//
// Created by Hugo Ziviani on 9/1/20.
//

#ifndef TALLER_MECANICO_TALLERCLASS_H
#define TALLER_MECANICO_TALLERCLASS_H

#include <string>
#include "../empleado/Empleado.h"
#include "../clientes/Cliente.h"
#include "../servicio/Servicios.h"

class TallerClass {
private:
    int quantityEmpleados;
    int quantityClientes;
    int quantityServicios;

private:
    Empleado empleados;
    Cliente clientes;
    Servicios servicios;


};


#endif //TALLER_MECANICO_TALLERCLASS_H
