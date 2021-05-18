#ifndef RAYTRACING_LUZESFERA_H
#define RAYTRACING_LUZESFERA_H

#include <vector>


#include "LuzPunto.h"
#include "Materiales/Transparent.h"
#include "Geometria/Esfera.h"

class LuzEsfera {
public:
    LuzPunto* pLuz;
    Esfera* pEsfera;

    LuzEsfera(const Vector3D& centro, double radio, const Vector3D& color);
    void move(const Vector3D& v) const;
};


#endif //RAYTRACING_LUZESFERA_H
