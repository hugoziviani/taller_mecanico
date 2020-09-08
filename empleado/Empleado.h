//
// Created by Hugo Ziviani on 8/26/20.
//

#ifndef TALLER_MECANICO_EMPLEADO_H
#define TALLER_MECANICO_EMPLEADO_H

#include <string>
using namespace std;

class Empleado {

    static int quantity; // variavel compartilhada por todos os objetos da classe.
    // tem que ser iniciada no main
    int id;
    string nombre;
    string setor;

};


#endif //TALLER_MECANICO_EMPLEADO_H
