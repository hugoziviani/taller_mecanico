//
// Created by Hugo Ziviani on 8/26/20.
//

#ifndef TALLER_MECANICO_ATENDIENTE_H
#define TALLER_MECANICO_ATENDIENTE_H

#include "../Empleado.h"

class Atendiente: public Empleado {
    int ventasHechas;
    /* TODO Gerar OS
     *      Autorizar OS
     *      Fechar OS
     */
public:
    Atendiente(int id, const string &nombre, const string &setor, int ventasHechas);

    int getVentasHechas() const;
    void setVentasHechas(int ventasHechas);
};


#endif //TALLER_MECANICO_ATENDIENTE_H
