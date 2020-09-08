//
// Created by Hugo Ziviani on 8/26/20.
//

#ifndef TALLER_MECANICO_SERVICIOS_H
#define TALLER_MECANICO_SERVICIOS_H

#include "../empleado/Empleado.h"
#include "ItemServicio.h"
#include <string>

#define PENDIENTE 0
#define CERRADO 1
#define PRESSUPUESTO 0
#define VENTA 1


using namespace std;


class Servicios {

private:
    int id;
    Empleado *responsable;
    int status = PENDIENTE;
    float precioTotal;
    int tipo;
    ItemServicio *itenServicios [];

public:
    Servicios(int id, Empleado *responsable, int status, float precioTotal, int tipo, ItemServicio **itenServicios);

    int getId() const;

    void setId(int id);

    Empleado *getResponsable() const;

    void setResponsable(Empleado *responsable);

    int getStatus() const;

    void setStatus(int status);

    float getPrecioTotal() const;

    void setPrecioTotal(float precioTotal);

    int getTipo() const;

    void setTipo(int tipo);

    ItemServicio *const *getItenServicios() const;
};


#endif //TALLER_MECANICO_SERVICIOS_H
