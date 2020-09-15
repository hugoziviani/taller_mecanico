//
// Created by Hugo Ziviani on 8/26/20.
//

#ifndef TALLER_MECANICO_EMPLEADO_H
#define TALLER_MECANICO_EMPLEADO_H

#include <string>
#include <ostream>

using namespace std;

class Empleado {
private:
    int id;
    string nombre;
    string setor;

public:

    Empleado(int id, const string &nombre, const string &setor);

    virtual ~Empleado();

    int getId() const;
    void setId(int id);

    const string &getNombre() const;
    void setNombre(const string &nombre);

    const string &getSetor() const;
    void setSetor(const string &setor);
};


#endif //TALLER_MECANICO_EMPLEADO_H
