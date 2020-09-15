//
// Created by Hugo Ziviani on 8/26/20.
//

#ifndef TALLER_MECANICO_SERVICIOS_H
#define TALLER_MECANICO_SERVICIOS_H

#include "../empleado/Empleado.h"
#include "./ItemServicio.h"
#include <string>
#include <list>
#include <ostream>

#define PENDIENTE 0
#define CERRADO 1
#define PRESSUPUESTO 0
#define VENTA 1


using namespace std;


class Servicios {

private:
    int id;
    Empleado *responsable;  //fazer cast para atendente ou mecanico
    int status = PENDIENTE;
    float precioTotal;
    int tipo;
    list<pair<int, ItemServicio*>> serviciosList;

public:
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

    const list<pair<int, ItemServicio *>> &getServiciosList() const;
    void setServiciosList(const list<pair<int, ItemServicio *>> &serviciosList);


    friend ostream &operator<<(ostream &os, const Servicios &servicios);

    friend ostream &operator<<(ostream &os, const list<pair<int, ItemServicio *>> &serviciosList);


};


#endif //TALLER_MECANICO_SERVICIOS_H
