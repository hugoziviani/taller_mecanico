//
// Created by Hugo Ziviani on 9/1/20.
//

#ifndef TALLER_MECANICO_TALLERCLASS_H
#define TALLER_MECANICO_TALLERCLASS_H

#include <string>
#include "../empleado/Empleado.h"
#include "../clientes/Cliente.h"
#include "../servicio/Servicios.h"

using namespace std;

class TallerClass {
private:
    static int quantityEmpleados;
    static int quantityClientes;
    static int quantityServicios;

    Empleado empleados;
    Cliente clientes;
    Servicios servicios;

};




#endif //TALLER_MECANICO_TALLERCLASS_H
