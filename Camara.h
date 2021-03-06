#ifndef UNTITLED_CAMARA_H
#define UNTITLED_CAMARA_H

#include "Utils/Vector3D.h"
#include <string>

class Mundo;

class Camara {
public:
    Vector3D ojo, lookat;
    Vector3D u, v, w;

    Camara() {}

    void calcularUVW();

    void renderizarEscena(Mundo m, const std::string& path, int i);
    Vector3D getDireccion(Vector3D p);

    void setEye(double x, double y, double z) { ojo.set(x, y, z); }
    void setLookat(double x, double y, double z) { lookat.set(x, y, z); }
};


#endif //UNTITLED_CAMARA_H
