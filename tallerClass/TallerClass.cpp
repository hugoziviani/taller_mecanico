#include "TallerClass.h"


TallerClass::TallerClass() {

}
TallerClass::~TallerClass() {
    if(!TallerClass::empleadosList.empty()){
        for (auto& x: TallerClass::empleadosList){
            delete x.second;
        }
    }
    if(!TallerClass::clientesList.empty()){
        for (auto& x: TallerClass::clientesList){
            delete x.second;
        }
    }
    if(!TallerClass::serviciosList.empty()){
        for (auto& x: TallerClass::serviciosList){
            delete x.second;
        }
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
    auto *vehiculo = new Vehiculo(UniqueId().id, modelo, kilometraje, placa);
    auto *cliente = new Cliente(UniqueId().id, nombre, telefono);
    cliente->anadirVehiculo(vehiculo);
    TallerClass::clientesList.emplace_front(UniqueId().id, cliente);
    TallerClass::setQuantityClientes(TallerClass::getQuantityClientes()+ 1);
}

void TallerClass::crearOrdenServicio(Empleado *responsable, Cliente *cliente, int tipo) {
    Servicios *s = new Servicios(UniqueId().id, responsable, cliente, PENDIENTE, 0.0, tipo);
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
}
void TallerClass::printListElements(int typeList) {
    if (typeList == CLIENTES and !TallerClass::clientesList.empty()){
        for (auto it = TallerClass::clientesList.begin(); it != TallerClass::clientesList.end(); it++) {
            if (!((it) == TallerClass::clientesList.end()) and ((it) != TallerClass::clientesList.begin())) {
                cout << ",\n";
            }
            cout << "{\n"
                 << R"( "clientesListId" : ")" << (*it).first << "\",\n"
                 << R"( "clientes" : )" << *((*it).second) << "\n}";
        }
    }
    if (typeList == ORDENES_DE_SERVICIO and !TallerClass::serviciosList.empty()){
        for (auto it = TallerClass::serviciosList.begin(); it != TallerClass::serviciosList.end(); it++) {
            if (!((it) == TallerClass::serviciosList.end()) and ((it) != TallerClass::serviciosList.begin())) {
                cout << ",\n";
            }
            cout << "{\n"
                 << R"("ordenServiciosId" : ")" << (*it).first << "\",\n"
                 << R"( "ordenes" : )" << *((*it).second) << "\n}";
        }
    }
    if (typeList == EMPLEADOS and !TallerClass::empleadosList.empty()){
        for (auto it = TallerClass::empleadosList.begin(); it != TallerClass::empleadosList.end(); it++) {
            if (!((it) == TallerClass::empleadosList.end()) and ((it) != TallerClass::empleadosList.begin())){
                cout <<",\n";
            }
            cout    <<"{\n"
                    << R"( "empleadosListId" : ")" << (*it).first << ",\n"
                    << R"( "empleados" : ")"<< *(*it).second << "\n}";
        }
    }
}

list<pair<int, string>> TallerClass::buscaPersona(int typeList, const string nombre) {
    list<pair<int, string>> listReturn;
    if (typeList == CLIENTES and !TallerClass::clientesList.empty()){
        for (auto & it : TallerClass::clientesList) {
            auto nombreRegistrado = (it.second->getNombre());
            if (nombreRegistrado.find(nombre) != string::npos) {
                 listReturn.emplace_back(it.second->getId(), it.second->getNombre());
            }

        }
    }
    if (typeList == EMPLEADOS and !TallerClass::empleadosList.empty()){
        for (auto & it : TallerClass::empleadosList) {
            auto nombreRegistrado = (it.second->getNombre());
            if (nombreRegistrado.find(nombre) != string::npos) {
                listReturn.emplace_back(it.second->getId(), it.second->getNombre());
            }
        }
    }
    return listReturn;
}
list<pair<int, string>> TallerClass::buscaOrdenDeServicio(int typeList, string nombre) {
    list<pair<int, string>> listReturn;
    if (typeList == ORDENES_DE_SERVICIO and !TallerClass::serviciosList.empty()){
        for (auto it = TallerClass::serviciosList.begin(); it != TallerClass::serviciosList.end(); it++) {
            auto nombreRegistrado = it->second->getCliente()->getNombre();
            if (nombreRegistrado.find(nombre) != string::npos) {
                listReturn.emplace_back(it->second->getId(), it->second->getCliente()->getNombre());
                //TODO adaptar para retornar as OS
            }
        }
    }
    return listReturn;
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

