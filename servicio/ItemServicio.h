//
// Created by Hugo Ziviani on 9/1/20.
//

#ifndef TALLER_MECANICO_ITEMSERVICIO_H
#define TALLER_MECANICO_ITEMSERVICIO_H

#include <string>
using namespace std;

class ItemServicio {

private:
    int id;
    string descripcion;
    bool finalizado;
    float precio;


public:
    ItemServicio(int id, const string &descripcion, bool finalizado, float precio);

    virtual ~ItemServicio();

public:
    int getId() const;

    void setId(int id);

    const string &getDescripcion() const;

    void setDescripcion(const string &descripcion);

    bool isFinalizado() const;

    void setFinalizado(bool finalizado);

    float getPrecio() const;

    void setPrecio(float precio);


};


#endif //TALLER_MECANICO_ITEMSERVICIO_H
