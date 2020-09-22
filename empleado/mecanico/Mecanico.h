//
// Created by Hugo Ziviani on 8/26/20.
//

#ifndef TALLER_MECANICO_MECANICO_H
#define TALLER_MECANICO_MECANICO_H

#include "../Empleado.h"
#include <iostream>

class Mecanico: public Empleado {
private:
    string funcion;
    bool disponible;
public:

    Mecanico(int id=0, const string &nombre="", const string &setor="", const string &funcion="", bool disponible=true);

    virtual ~Mecanico();

    const string &getFuncion() const;
    void setFuncion(const string &funcion);

    bool isDisponible() const;
    void setDisponible(bool disponible);

    void salida(ostream &) const;

    friend ostream &operator<<(ostream &os, const Mecanico &mecanico);
    /*TODO: -ver OS abertas e autorizadas para pegar uma e fazer
        -cadastrar serviço e peças utilizadas
    */
};


#endif //TALLER_MECANICO_MECANICO_H
