//
// Created by Hugo Ziviani on 8/26/20.
//

#ifndef TALLER_MECANICO_VEHICULO_H
#define TALLER_MECANICO_VEHICULO_H

#include <iostream>
#include <string>
#include <list>
using namespace std;

class Vehiculo {

    int id;
    string modelo;
    float kilometraje;
    string placa;

public:

    Vehiculo(int id=0, const string &modelo="", float kilometraje=0.0, const string &placa="");

    virtual ~Vehiculo();

    int getId();
    void setId(int id);

    const string &getModelo() const;
    void setModelo(const string &modelo);

    float getKilometraje() const;
    void setKilometraje(float kilometraje);

    const string &getPlaca() const;
    void setPlaca(const string &placa);

    static int getContador();

    Vehiculo& operator=(const Vehiculo&);
    friend bool operator==(const Vehiculo& vehiculo1, const Vehiculo& vehiculo2);
    friend void showlist(list<Vehiculo>);

    friend ostream &operator<<(ostream &os, const Vehiculo &vehiculo);
    friend istream &operator>>(istream &is, Vehiculo &vehiculo);
    //só da pra ser implementada como funções amigas, a sobrecarga de ostream e istream

};


#endif //TALLER_MECANICO_VEHICULO_H
