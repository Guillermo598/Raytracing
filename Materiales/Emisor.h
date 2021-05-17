#ifndef RAYTRACING_EMISOR_H
#define RAYTRACING_EMISOR_H


#include "Material.h"

class Emisor : public Material{
public:
    double ls;
    Vector3D c;

    void escalar_rad(const double _ls);
    virtual Vector3D shade(ShadeRec& sr);
    //virtual Vector3D area_light_shade(ShadeRec& sr);
};


#endif //RAYTRACING_EMISOR_H
