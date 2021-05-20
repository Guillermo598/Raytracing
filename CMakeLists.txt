cmake_minimum_required(VERSION 3.17)
project(Raytracing)

set(CMAKE_CXX_STANDARD 20)

add_executable(Raytracing
        main.cpp
        CImg.h
        Mundo.cpp Mundo.h
        Camara.cpp Camara.h
        Utils/Vector3D.cpp Utils/Vector3D.h
        Geometria/Objeto.cpp Geometria/Objeto.h
        Geometria/Esfera.cpp Geometria/Esfera.h
        Utils/Rayo.cpp Utils/Rayo.h
        Utils/ShadeRec.cpp Utils/ShadeRec.h
        Utils/PlanoVista.cpp Utils/PlanoVista.h
        Luces/Luz.cpp Luces/Luz.h
        Geometria/Plano.cpp Geometria/Plano.h
        Geometria/Cilindro.cpp Geometria/Cilindro.h
        Geometria/Caja.cpp Geometria/Caja.h
        Luces/LuzPunto.cpp Luces/LuzPunto.h
        Utils/Tracer.cpp Utils/Tracer.h
        Materiales/Material.cpp Materiales/Material.h
        Materiales/Matte.cpp Materiales/Matte.h
        Materiales/Phong.cpp Materiales/Phong.h
        Materiales/Transparent.cpp Materiales/Transparent.h
        Luces/LuzEsfera.cpp Luces/LuzEsfera.h
        Geometria/Disco.cpp Geometria/Disco.h
        Materiales/Reflective.cpp Materiales/Reflective.h)

