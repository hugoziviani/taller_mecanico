//
// Created by Hugo Ziviani on 9/1/20.
//

#include "TallerClass.h"


TallerClass::TallerClass() {

}


void TallerClass::printListEmpleados() {
    for (auto& x: this->empleadosList)
        std::cout << " (" << x.first << "," << (x.second)->getNombre() << ")";
}
