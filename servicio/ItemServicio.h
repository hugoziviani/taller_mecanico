#ifndef TALLER_MECANICO_ITEMSERVICIO_H
#define TALLER_MECANICO_ITEMSERVICIO_H


#include <string>
#include <ostream>


using namespace std;

class ItemServicio {

private:
    int id;
    string descripcion;
    bool finalizado;
    float precio;

public:
    ItemServicio(int id=0, const string &descripcion="", bool finalizado=false, float precio=0.0);

    virtual ~ItemServicio();

    int getId() const;
    void setId(int id);

    const string &getDescripcion() const;
    void setDescripcion(const string &descripcion);

    bool isFinalizado() const;
    void setFinalizado(bool finalizado);

    float getPrecio() const;
    void setPrecio(float precio);

    void salida(ostream &os) const;
    friend ostream &operator<<(ostream &os, const ItemServicio &servicio);

    friend class Servicio;
};


#endif //TALLER_MECANICO_ITEMSERVICIO_H
