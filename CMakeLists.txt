cmake_minimum_required(VERSION 3.17)
project(taller_mecanico)

set(CMAKE_CXX_STANDARD 14)

add_executable(taller_mecanico main.cpp clientes/Cliente.cpp clientes/Cliente.h empleado/Empleado.cpp empleado/Empleado.h empleado/mecanico/Mecanico.cpp empleado/mecanico/Mecanico.h empleado/atendiente/Atendiente.cpp empleado/atendiente/Atendiente.h productos/Producto.cpp productos/Producto.h vehiculo/Vehiculos.cpp vehiculo/Vehiculos.h servicio/Servicio.cpp servicio/Servicio.h tallerClass/tallerClass.cpp tallerClass/tallerClass.h)