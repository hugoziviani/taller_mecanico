//
// Created by Hugo Ziviani on 9/1/20.
//

#include "ItemServicio.h"

ItemServicio::ItemServicio(int id, const string &descripcion, bool finalizado, float precio) : id(id),
                                                                                               descripcion(descripcion),
                                                                                               finalizado(finalizado),
                                                                                               precio(precio) {}
int ItemServicio::getId() const {
    return id;
}

void ItemServicio::setId(int id) {
    ItemServicio::id = id;
}

const string &ItemServicio::getDescripcion() const {
    return descripcion;
}

void ItemServicio::setDescripcion(const string &descripcion) {
    ItemServicio::descripcion = descripcion;
}

bool ItemServicio::isFinalizado() const {
    return finalizado;
}

void ItemServicio::setFinalizado(bool finalizado) {
    ItemServicio::finalizado = finalizado;
}

float ItemServicio::getPrecio() const {
    return precio;
}

void ItemServicio::setPrecio(float precio) {
    ItemServicio::precio = precio;
}

ItemServicio::~ItemServicio() {}


