#ifndef TALLER_MECANICO_CLIENTE_H
#define TALLER_MECANICO_CLIENTE_H

#include "../vehiculo/Vehiculo.h"
#include <string>
#include <ostream>

using namespace std;

class Cliente{
    int id;
    string nombre;
    string telefono;
    list<Vehiculo*> vehiculosList;
public:


    Cliente(int id= 0, const string &nombre= "", const string &telefono="", const list<Vehiculo *> &vehiculosList={});
    virtual ~Cliente();

    void anadirVehiculo(Vehiculo *vehiculo = new Vehiculo());


    int getId() const;
    void setId(int id);

    const string &getNombre() const;
    void setNombre(const string &nombre);

    const string &getTelefono() const;
    void setTelefono(const string &telefono);

    virtual void salida(ostream&) const;
    friend ostream &operator<<(ostream &os, const Cliente &cliente);

};


#endif //TALLER_MECANICO_CLIENTE_H
