#ifndef UNTITLED_LUZ_H
#define UNTITLED_LUZ_H

#include "Vector3D.h"
#include "Rayo.h"

class ShadeRec;

class Luz {
public:
    bool sombras;

    virtual Vector3D get_direccion(ShadeRec& sr) = 0;
    virtual Vector3D L(ShadeRec& sr) = 0;
};


#endif //UNTITLED_LUZ_H
