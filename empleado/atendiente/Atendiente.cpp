//
// Created by Hugo Ziviani on 8/26/20.
//

#include "Atendiente.h"

Atendiente::Atendiente(int id,
                       const string &nombre,
                       const string &setor,
                       int ventasHechas) :
                       Empleado(id, nombre,setor),
                       ventasHechas(ventasHechas){}

int Atendiente::getVentasHechas() const {
    return ventasHechas;
}
void Atendiente::setVentasHechas(int ventasHechas) {
    Atendiente::ventasHechas = ventasHechas;
}

