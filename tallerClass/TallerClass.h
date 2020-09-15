//
// Created by Hugo Ziviani on 9/1/20.
//

#ifndef TALLER_MECANICO_TALLERCLASS_H
#define TALLER_MECANICO_TALLERCLASS_H

#include <string>
#include <list>
#include "../empleado/Empleado.h"
#include "../clientes/Cliente.h"
#include "../servicio/Servicios.h"
#include "../vehiculo/Vehiculo.h"

using namespace std;

class TallerClass {
private:
    static int quantityEmpleados;
    static int quantityClientes;
    static int quantityServicios;
    static int quantityVehiculos;

    list<pair<int, Empleado*>> empleadosList;
    list<pair<int, Cliente*>> clientesList;
    list<pair<int, Servicios*>> serviciosList;
    list<pair<int, Vehiculo*>> vehiculosList;
public:

    TallerClass();


    void printListEmpleados();

};




#endif //TALLER_MECANICO_TALLERCLASS_H
