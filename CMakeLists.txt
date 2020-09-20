cmake_minimum_required(VERSION 3.17)
project(taller_mecanico)

set(CMAKE_CXX_STANDARD 14)

add_executable(taller_mecanico main.cpp clientes/Cliente.cpp clientes/Cliente.h empleado/Empleado.cpp empleado/Empleado.h empleado/mecanico/Mecanico.cpp empleado/mecanico/Mecanico.h empleado/atendiente/Atendiente.cpp empleado/atendiente/Atendiente.h vehiculo/Vehiculo.cpp vehiculo/Vehiculo.h servicio/Servicios.cpp servicio/Servicios.h tallerClass/TallerClass.cpp tallerClass/TallerClass.h servicio/ItemServicio.cpp servicio/ItemServicio.h main.h UniqueId.cpp UniqueId.h)