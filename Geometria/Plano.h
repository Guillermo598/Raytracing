#ifndef UNTITLED_PLANO_H
#define UNTITLED_PLANO_H

#include "Objeto.h"
#include "../Vector3D.h"
#include "../Rayo.h"

class Plano : public Objeto{
public:
    Vector3D punto;
    Vector3D normal;

    Plano(Vector3D p, Vector3D n);

    virtual bool hit(const Rayo& rayo, double& tmin, ShadeRec& sr) const;
    virtual bool hit_sombra(const Rayo &rayo, double &tmin) const;
    virtual void move(const Vector3D& v);
};


#endif //UNTITLED_PLANO_H
