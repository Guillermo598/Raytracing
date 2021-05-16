#ifndef RAYTRACING_MATTE_H
#define RAYTRACING_MATTE_H

#include "Material.h"


class Matte : public Material{
public:
    double kd, ka;
    Vector3D c;

    Matte() : ka(0), kd(0), c(Vector3D(0,0,0)) {};
    Matte(double ka, double kd, const Vector3D& c) : ka(ka), kd(kd), c(c) {};

    Vector3D shade(ShadeRec& sr);
};


#endif //RAYTRACING_MATTE_H
