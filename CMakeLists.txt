cmake_minimum_required(VERSION 3.17)
project(Raytracing)

set(CMAKE_CXX_STANDARD 20)

add_executable(Raytracing
        main.cpp
        CImg.h
        Mundo.cpp Mundo.h
        Camara.cpp Camara.h
        Vector3D.cpp Vector3D.h
        Geometria/Objeto.cpp Geometria/Objeto.h
        Geometria/Esfera.cpp Geometria/Esfera.h
        Rayo.cpp Rayo.h
        ShadeRec.cpp ShadeRec.h
        PlanoVista.cpp PlanoVista.h
        Luz.cpp Luz.h
        Geometria/Plano.cpp Geometria/Plano.h
        Geometria/Cilindro.cpp Geometria/Cilindro.h
        Geometria/Caja.cpp Geometria/Caja.h
        LuzPunto.cpp LuzPunto.h
        Tracer.cpp Tracer.h
        Materiales/Material.cpp Materiales/Material.h
        Materiales/Matte.cpp Materiales/Matte.h
        Materiales/Phong.cpp Materiales/Phong.h
        Materiales/Transparent.cpp Materiales/Transparent.h
        Materiales/Emisor.cpp Materiales/Emisor.h)

