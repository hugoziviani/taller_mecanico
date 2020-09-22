//
// Created by Hugo Ziviani on 9/1/20.
//

#ifndef TALLER_MECANICO_TALLERCLASS_H
#define TALLER_MECANICO_TALLERCLASS_H

#include <string>
#include <list>
#include "../empleado/Empleado.h"
#include "../empleado/atendiente/Atendiente.h"
#include "../empleado/mecanico/Mecanico.h"
#include "../clientes/Cliente.h"
#include "../servicio/Servicios.h"
#include "../vehiculo/Vehiculo.h"
#include "../UniqueId.h"

#define EMPLEADOS 1
#define MECANICO 2
#define ATEMDIENTE 3
#define CLIENTES 4
#define ORDENES_DE_SERVICIO 5


using namespace std;

class TallerClass {
private:
    static int quantityMecanicos;
    static int quantityAtendientes;
    static int quantityClientes;
    static int quantityServicios;

    list<pair<int, Empleado*>> empleadosList;
    list<pair<int, Cliente*>> clientesList;
    list<pair<int, Servicios*>> serviciosList;



public:

    TallerClass();

    virtual ~TallerClass();

    void anadirAtendiente(const string &nombre="", const string &setor="");
    void anadirMecanico(const string &nombre="", const string &setor="", const string &funcion="");
    void anadirCliente(const string &nombre, const string &telefono, string modelo, float kilometraje,
                       string placa);


    void crearOrdenServicio(Empleado *responsable = nullptr, Cliente *cliente = new Cliente(), int tipo = PRESSUPUESTO);
    void adicionarItemServicioEnOrden(int idOrdenServicio, const char *descripcion, float precio);
    void printListElements(int typeList);

    static int getQuantityEmpleados(int typeEmpleado);
    static void setQuantityEmpleados(int quantityEmpleados, int typeEmpleado);
    static int getQuantityClientes();
    static void setQuantityClientes(int quantityClientes);
    static int getQuantityServicios();
    static void setQuantityServicios(int quantityServicios);




};




#endif //TALLER_MECANICO_TALLERCLASS_H
