//
// Created by Hugo Ziviani on 8/26/20.
//

#include "Atendiente.h"

Atendiente::Atendiente(int id,
                       const string &nombre,
                       const string &setor,
                       int ventasHechas) :
                       Empleado(id, nombre,setor), //sempre primeiro e a chamada da CB
                       ventasHechas(ventasHechas){}

int Atendiente::getVentasHechas() const {
    return ventasHechas;
}
void Atendiente::setVentasHechas(int ventasHechas) {
    Atendiente::ventasHechas = ventasHechas;
}

void Atendiente::salida(ostream &os) const {
     Empleado::salida(os);
     os << R"( "ventasHechas" : ")" << Atendiente::getVentasHechas()<<"\"}";
}
ostream &operator<<(ostream &os, const Atendiente &atendiente) {
    atendiente.salida(os);
    return os;
}

