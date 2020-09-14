//
// Created by Hugo Ziviani on 9/1/20.
//

#include "TallerClass.h"


TallerClass::TallerClass() {
    this->EmpleadosList.emplace_front(1, new Empleado("juca"));
}


void TallerClass::printListEmpleados() {
    for (auto& x: this->EmpleadosList)
        std::cout << " (" << x.first << "," << (x.second)->getNombre() << ")";
}
