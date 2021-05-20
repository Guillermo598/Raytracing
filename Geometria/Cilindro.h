#ifndef UNTITLED_CILINDRO_H
#define UNTITLED_CILINDRO_H

#include "Objeto.h"
#include "../Utils/Vector3D.h"
#include "../Utils/Rayo.h"

class Cilindro : public Objeto{
public:
    Vector3D centro;
    double altura;
    double radio;

    Cilindro(Vector3D c, double h, double r);

    virtual bool hit(const Rayo &rayo, double &tmin, ShadeRec &sr) const;
    virtual bool hit_sombra(const Rayo &rayo, double &tmin) const;
    virtual void move(const Vector3D& v);
};


#endif //UNTITLED_CILINDRO_H
