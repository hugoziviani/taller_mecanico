#include "Atendiente.h"

Atendiente::Atendiente(int id, const string &nombre, const string &setor, int ventasHechas) :
    Empleado(id, nombre,setor),
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

