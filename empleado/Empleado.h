//
// Created by Hugo Ziviani on 8/26/20.
//

#ifndef TALLER_MECANICO_EMPLEADO_H
#define TALLER_MECANICO_EMPLEADO_H

#include <string>
#include <ostream>
#include <ctime>

using namespace std;

class Empleado {
private:
    int id;
    string nombre;
    string setor;
public:
    Empleado(int id=0, const string &nombre="", const string &setor="");


    virtual ~Empleado();

    int getId() const;
    void setId(int id);

    const string &getNombre() const;
    void setNombre(const string &nombre);

    const string &getSetor() const;
    void setSetor(const string &setor);

    friend ostream &operator<<(ostream &os, const Empleado &empleado);

    time_t getAgregadoEn() const;
    void setAgregadoEn(time_t agregadoEn);

};


#endif //TALLER_MECANICO_EMPLEADO_H
