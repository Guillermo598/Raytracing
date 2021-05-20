#ifndef RAYTRACING_LUZESFERA_H
#define RAYTRACING_LUZESFERA_H

#include <vector>


#include "LuzPunto.h"
#include "../Geometria/Esfera.h"
#include "../Materiales/Reflective.h"

class LuzEsfera {
public:
    std::vector<LuzPunto*> luces;
    Esfera* pEsfera;

    LuzEsfera(const Vector3D& centro, double radio, const Vector3D& color);
    void move(const Vector3D& v) const;
};


#endif //RAYTRACING_LUZESFERA_H
