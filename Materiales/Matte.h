#ifndef RAYTRACING_MATTE_H
#define RAYTRACING_MATTE_H

#include "Material.h"


class Matte : public Material{
public:
    double kd, ka;
    Vector3D cd, ca;

    Matte() : ka(0), kd(0), cd(Vector3D(0,0,0)), ca(Vector3D(0,0,0)) {};
    Matte(double ka, double kd, const Vector3D& c) : ka(ka), kd(kd), cd(c), ca(c) {};

    Vector3D shade(ShadeRec& sr);
};


#endif //RAYTRACING_MATTE_H
