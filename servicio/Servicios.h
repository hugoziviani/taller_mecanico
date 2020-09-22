//
// Created by Hugo Ziviani on 8/26/20.
//

#ifndef TALLER_MECANICO_SERVICIOS_H
#define TALLER_MECANICO_SERVICIOS_H

#include "../empleado/Empleado.h"
#include "../clientes/Cliente.h"
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
    Empleado *responsable;
    Cliente *cliente;
    int status;
    float precioTotal;
    int tipo;
    list<pair<int, ItemServicio*>> serviciosList;

public:
    Servicios(int id=0, Empleado *responsable = nullptr, Cliente *cliente = nullptr, int status=PENDIENTE, float precioTotal=0.0, int tipo=PRESSUPUESTO);

    virtual ~Servicios();

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

    Cliente *getCliente() const;

    void setCliente(Cliente *cliente);

    void insertItemOnList(ItemServicio *itemServicio);

    void salida(ostream &os) const;
    friend ostream &operator<<(ostream &os, const Servicios &servicios);
};

#endif //TALLER_MECANICO_SERVICIOS_H