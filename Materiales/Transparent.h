#ifndef RAYTRACING_TRANSPARENT_H
#define RAYTRACING_TRANSPARENT_H

#include "Phong.h"

class Transparent : public Phong {
public:
    double kr, kt, ior;
    Vector3D c;

    virtual Vector3D shade(ShadeRec& sr);
};


#endif //RAYTRACING_TRANSPARENT_H
