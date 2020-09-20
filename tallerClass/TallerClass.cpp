#include "TallerClass.h"


TallerClass::TallerClass() {

}
TallerClass::~TallerClass() {
    if (getQuantityEmpleados(ATEMDIENTE) > 0) {
        for (auto &x: TallerClass::mecanicoList)
            delete x.second;
    }
    if(getQuantityEmpleados(MECANICO) > 0){
        for (auto& x: TallerClass::atendienteList)
            delete x.second;
    }
}

void TallerClass::anadirAtendiente(const string &nombre, const string &setor){
    Atendiente *a = new Atendiente(UniqueId().id, nombre, setor, 0);

    TallerClass::atendienteList.emplace_front(UniqueId().id, a);
    TallerClass::setQuantityEmpleados(TallerClass::getQuantityEmpleados(ATEMDIENTE) + 1, ATEMDIENTE);
}
void TallerClass::anadirMecanico(const string &nombre, const string &setor, const string &funcion) {
    Mecanico *m = new Mecanico(UniqueId().id, nombre, setor, funcion);

    TallerClass::mecanicoList.emplace_front(UniqueId().id, m);
    TallerClass::setQuantityEmpleados(TallerClass::getQuantityEmpleados(MECANICO) + 1, MECANICO);
}
void TallerClass::anadirCliente(const string &nombre, const string &telefono, string modelo, float kilometraje, string placa) {
    Vehiculo *v = new Vehiculo(UniqueId().id, modelo, kilometraje, placa);
    Cliente *c = new Cliente(UniqueId().id, nombre, telefono, *v);

    TallerClass::clientesList.emplace_front(UniqueId().id, c);
    TallerClass::setQuantityClientes(TallerClass::getQuantityClientes()+ 1);
}

void TallerClass::crearOrdenServicio(Empleado *responsable, Cliente *cliente, int tipo,  const list<pair<int, ItemServicio *>> &serviciosList) {
    Servicios *s = new Servicios(UniqueId().id, responsable, cliente, PENDIENTE, 0.0, tipo, serviciosList);
    TallerClass::serviciosList.emplace_front(UniqueId().id, s);
    TallerClass::setQuantityClientes(TallerClass::getQuantityClientes()+ 1);
}



void TallerClass::printListElements(int typeList) {
    if (typeList == ATEMDIENTE){
        for (auto& x: TallerClass::atendienteList)
            cout << " (\n" << x.first << "," << *(x.second) << "\n)";
    }
    if (typeList == MECANICO){
        for (auto& x: TallerClass::mecanicoList)
            cout << " (\n" << x.first << "," << *(x.second) << "\n)";
    }
    if (typeList == CLIENTES){
        for (auto& x: TallerClass::clientesList)
            cout << " (\n" << x.first << "," << *(x.second) << "\n)";
    }
    if (typeList == ORDENES_DE_SERVICIO){
        for (auto& x: TallerClass::serviciosList)
            cout << " (\n" << x.first << "," << *(x.second) << "\n)";
    }

}

int TallerClass::getQuantityEmpleados(int typeEmpleado) {
    if (typeEmpleado == ATEMDIENTE){
        return quantityAtendientes;
    }
    if (typeEmpleado == MECANICO){
        return quantityMecanicos;
    }
    return -1;
}
void TallerClass::setQuantityEmpleados(int quantityEmpleados, int typeEmpleado) {
    if (typeEmpleado == ATEMDIENTE){
        TallerClass:: quantityAtendientes = quantityEmpleados;
    }
    if (typeEmpleado == MECANICO){
        TallerClass:: quantityMecanicos = quantityEmpleados;
    }
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
