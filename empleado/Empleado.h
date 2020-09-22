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

    //virtual string getResponsableIdentification();

    int getId() const;
    void setId(int id);

    const string &getNombre() const;
    void setNombre(const string &nombre);

    const string &getSetor() const;
    void setSetor(const string &setor);


    virtual void salida(ostream&) const = 0; //virtual puro
    friend ostream &operator<<(ostream &os, const Empleado &empleado);


};


#endif //TALLER_MECANICO_EMPLEADO_H
