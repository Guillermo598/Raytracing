#ifndef RAYTRACING_REFLECTIVE_H
#define RAYTRACING_REFLECTIVE_H


#include "Phong.h"

class Reflective : public Phong{
public:
    double kr;
    Vector3D cr;

    virtual Vector3D shade(ShadeRec& sr);
};


#endif //RAYTRACING_REFLECTIVE_H
