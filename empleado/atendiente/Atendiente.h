#ifndef TALLER_MECANICO_ATENDIENTE_H
#define TALLER_MECANICO_ATENDIENTE_H

#include <ostream>
#include "../Empleado.h"

class Atendiente: public Empleado {
    int ventasHechas;
    /* TODO Gerar OS
     *      Autorizar OS
     *      Fechar OS
     */
public:
    Atendiente(int id=0, const string &nombre="", const string &setor="", int ventasHechas=0);

    int getVentasHechas() const;
    void setVentasHechas(int ventasHechas);

    friend ostream &operator<<(ostream &os, const Atendiente &atendiente);
};


#endif //TALLER_MECANICO_ATENDIENTE_H
