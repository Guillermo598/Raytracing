#ifndef UNTITLED_ESFERA_H
#define UNTITLED_ESFERA_H

#include "Objeto.h"

class Esfera : public Objeto {
public:
    Vector3D centro;
    double radio;

    Esfera(Vector3D c, double r) : centro(c), radio(r) {}

    virtual bool hit(const Rayo &rayo, double &tmin, ShadeRec &sr) const;
    virtual bool hit_sombra(const Rayo &rayo, double &tmin) const;
    virtual void move(const Vector3D& v);
};


#endif //UNTITLED_ESFERA_H
