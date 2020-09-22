#include "TallerClass.h"


TallerClass::TallerClass() {

}
TallerClass::~TallerClass() {
    if(!TallerClass::empleadosList.empty()){
        for (auto& x: TallerClass::empleadosList)
            delete x.second;
    }
}

void TallerClass::anadirAtendiente(const string &nombre, const string &setor){
    Atendiente *a = new Atendiente(UniqueId().id, nombre, setor, 0);

    TallerClass::empleadosList.emplace_front(UniqueId().id, a);
    TallerClass::setQuantityEmpleados(TallerClass::getQuantityEmpleados(ATEMDIENTE) + 1, ATEMDIENTE);
}
void TallerClass::anadirMecanico(const string &nombre, const string &setor, const string &funcion) {
    Mecanico *m = new Mecanico(UniqueId().id, nombre, setor, funcion);

    TallerClass::empleadosList.emplace_front(UniqueId().id, m);
    TallerClass::setQuantityEmpleados(TallerClass::getQuantityEmpleados(MECANICO) + 1, MECANICO);
}
void TallerClass::anadirCliente(const string &nombre, const string &telefono, string modelo, float kilometraje, string placa) {
    Vehiculo *v = new Vehiculo(UniqueId().id, modelo, kilometraje, placa);
    Cliente *c = new Cliente(UniqueId().id, nombre, telefono);
    c->anadirVehiculo(v);
    c->anadirVehiculo(v);
    TallerClass::clientesList.emplace_front(UniqueId().id, c);
    TallerClass::setQuantityClientes(TallerClass::getQuantityClientes()+ 1);
}

void TallerClass::crearOrdenServicio(Empleado *responsable, Cliente *cliente, int tipo,  const list<pair<int, ItemServicio *>> &serviciosList) {
    Servicios *s = new Servicios(UniqueId().id, responsable, cliente, PENDIENTE, 0.0, tipo, serviciosList);
    TallerClass::serviciosList.emplace_front(UniqueId().id, s);
    TallerClass::setQuantityClientes(TallerClass::getQuantityClientes()+ 1);
}

void TallerClass::adicionarItemServicioEnOrden(int idOrdenServicio, const char *descripcion, float precio) {
    auto * is = new ItemServicio(UniqueId().id, descripcion, false, precio);
    for (auto& x: TallerClass::serviciosList){
        if (x.first == idOrdenServicio){
            x.second->insertItemOnList(is);
            TallerClass::setQuantityServicios(TallerClass::getQuantityServicios()+1);
        }
    }
    //TODO desalocar memória
}

void TallerClass::printListElements(int typeList) {
    if (typeList == CLIENTES){
        for (auto& x: TallerClass::clientesList)
            cout << "{" << x.first << "," << *(x.second) << "\n";
    }
    if (typeList == ORDENES_DE_SERVICIO){
        for (auto& x: TallerClass::serviciosList)
            cout    << "{ \"ordenServiciosId\" : " << x.first << ",\n"
                    << "ordenes\" : " << *(x.second) << "\n}";
    }
    if (typeList == EMPLEADOS){
        for (auto it = TallerClass::empleadosList.begin(); it != TallerClass::empleadosList.end(); it++) {
            if (!((it) == TallerClass::empleadosList.end()) and ((it) != TallerClass::empleadosList.begin())){
                cout <<",\n";
            }
            cout <<"{\n"
                << R"( "empleadosListId" : ")" << (*it).first << ",\n"
                << R"( "empleados" : ")"<< *(*it).second << "\n}";
        }
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

