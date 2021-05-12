#ifndef UNTITLED_LUZPUNTO_H
#define UNTITLED_LUZPUNTO_H

#include "Luz.h"
#include "ShadeRec.h"
#include "Vector3D.h"

class LuzPunto : public Luz{
public:
    double ls;
    Vector3D color;
    Vector3D posicion;

    LuzPunto(Vector3D pos);
    virtual Vector3D get_direccion(ShadeRec& sr);
    virtual Vector3D L(ShadeRec& sr);
};


#endif //UNTITLED_LUZPUNTO_H
