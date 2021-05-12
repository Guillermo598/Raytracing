#ifndef RAYTRACING_PHONG_H
#define RAYTRACING_PHONG_H

#include "Material.h"

class Phong : public Material{
public:
    double ka, kd, ks, exp;
    Vector3D ca, cd, cs;

    Phong();
    Phong(double ka, double kd, double ks, double e, Vector3D c);
    Vector3D shade(ShadeRec& sr);
};


#endif //RAYTRACING_PHONG_H
