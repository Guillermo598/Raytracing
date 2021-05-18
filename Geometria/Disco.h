#ifndef RAYTRACING_DISCO_H
#define RAYTRACING_DISCO_H


#include "Objeto.h"

class Disco : public Objeto{
public:
    double radio;
    Vector3D centro, normal;

    Disco(Vector3D p, Vector3D n, double r);
    virtual bool hit(const Rayo& rayo, double& tmin, ShadeRec& sr) const;
    virtual bool hit_sombra(const Rayo& rayo, double& tmin) const;
    virtual void move(const Vector3D& v);
};


#endif //RAYTRACING_DISCO_H
