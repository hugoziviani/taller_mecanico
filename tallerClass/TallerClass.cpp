//
// Created by Hugo Ziviani on 9/1/20.
//

#include "TallerClass.h"


TallerClass::TallerClass() {

}

void TallerClass::anadirEmpleado(Empleado* empleado) {
    empleado->setId(TallerClass::getQuantityEmpleados());
    TallerClass::empleadosList.emplace_front(TallerClass::getQuantityEmpleados(), empleado);
    TallerClass::setQuantityEmpleados(TallerClass::getQuantityEmpleados()+1);
}

void TallerClass::printListEmpleados() {
    for (auto& x: this->empleadosList)
        std::cout << " (" << x.first << "," << (x.second)->getNombre() << ")";
}

int TallerClass::getQuantityEmpleados() {
    return quantityEmpleados;
}
void TallerClass::setQuantityEmpleados(int quantityEmpleados) {
    TallerClass::quantityEmpleados = quantityEmpleados;
}
int TallerClass::getQuantityClientes() {
    return quantityClientes;
}
void TallerClass::setQuantityClientes(int quantityClientes) {
    TallerClass::quantityClientes = quantityClientes;
}
int TallerClass::getQuantityServicios() {
    return quantityServicios;
}
void TallerClass::setQuantityServicios(int quantityServicios) {
    TallerClass::quantityServicios = quantityServicios;
}
int TallerClass::getQuantityVehiculos() {
    return quantityVehiculos;
}
void TallerClass::setQuantityVehiculos(int quantityVehiculos) {
    TallerClass::quantityVehiculos = quantityVehiculos;
}
