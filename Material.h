#ifndef UNTITLED_MATERIAL_H
#define UNTITLED_MATERIAL_H

class ShadeRec;

#include "Vector3D.h"
#include "ShadeRec.h"
#include "Mundo.h"

class Material {
public:
    double kd, ka;
    Vector3D cd, ca;

    Material() : ka(0), kd(0), cd(Vector3D(0,0,0)), ca(Vector3D(0,0,0)) {};
    Material(double ka, double kd, const Vector3D& c) : ka(ka), kd(kd), cd(c), ca(c) {};

    Vector3D shade(ShadeRec& sr);
};


#endif //UNTITLED_MATERIAL_H
