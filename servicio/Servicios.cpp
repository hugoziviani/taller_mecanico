#include "Servicios.h"

Servicios::Servicios(int id, Empleado *responsable, Cliente *cliente, int status, float precioTotal, int tipo) :
    id(id), responsable(responsable),
    cliente(cliente), status(status),
    precioTotal(precioTotal), tipo(tipo){}

Servicios::~Servicios() {
    if(!Servicios::serviciosList.empty()){
        for (auto& x: Servicios::serviciosList){
            delete x.second;
        }
    }
}

float Servicios::calculatePrecioTotal() {
    auto precio = 0;
    for( auto &s : Servicios::serviciosList){
        precio+= s.second->getPrecio();
    }
    Servicios::setPrecioTotal(precio);
    return precioTotal;
}
void Servicios::insertItemOnList(ItemServicio *itemServicio){
    Servicios::serviciosList.push_front(make_pair(serviciosList.size(), itemServicio));
}

int Servicios::getId() const {
    return id;
}
void Servicios::setId(int id) {
    Servicios::id = id;
}

Empleado *Servicios::getResponsable() const {
    return responsable;
}
void Servicios::setResponsable(Empleado *responsable) {
    Servicios::responsable = responsable;
}

int Servicios::getStatus() const {
    return status;
}
void Servicios::setStatus(int status) {
    Servicios::status = status;
}

float Servicios::getPrecioTotal() const {
    return precioTotal;
}
void Servicios::setPrecioTotal(float precioTotal) {
    Servicios::precioTotal = precioTotal;
}

int Servicios::getTipo() const {
    return tipo;
}
void Servicios::setTipo(int tipo) {
    Servicios::tipo = tipo;
}

const list<pair<int, ItemServicio *>> &Servicios::getServiciosList() const {
    return serviciosList;
}

Cliente *Servicios::getCliente() const {
    return cliente;
}

void Servicios::setCliente(Cliente *cliente) {
    Servicios::cliente = cliente;
}


void Servicios::salida(ostream &os) const {
    os  <<"{"
        << R"( "serviciosId" : ")" << Servicios::getId() <<"\","
        << R"( "precioTotal" : ")" << Servicios::getPrecioTotal() <<"\","
        << R"( "tipo" : ")" << Servicios::getTipo() <<"\","
        << R"( "cliente" : )" << *Servicios::getCliente() <<","
        << R"( "responsable" : )" << *Servicios::getResponsable() <<","
        << R"( "serviciosList" : )";
        for (auto it = Servicios::serviciosList.begin(); it != Servicios::serviciosList.end(); it++) {
            if (!((it) == Servicios::serviciosList.end()) and ((it) != Servicios::serviciosList.begin())) {
                cout << ",\n";
            }
            os<<(*it->second);
        }
    os <<"} ";
}

ostream &operator<<(ostream &os, const Servicios &servicios) {
    servicios.salida(os);
    return os;
}

