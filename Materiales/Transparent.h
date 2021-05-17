#ifndef RAYTRACING_TRANSPARENT_H
#define RAYTRACING_TRANSPARENT_H

#include "Phong.h"

class Transparent : public Phong {
public:
    double kr, kt, ior;
    Vector3D c;

    virtual Vector3D shade(ShadeRec& sr);

private:
    bool tir(const ShadeRec& sr) const;
    Vector3D specular_f(const ShadeRec& sr, const Vector3D& wo, Vector3D& wt) const;
    Vector3D reflective_f(const ShadeRec& sr, const Vector3D& wo, Vector3D& wi) const;
};


#endif //RAYTRACING_TRANSPARENT_H
