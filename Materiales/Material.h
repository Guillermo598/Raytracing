#ifndef UNTITLED_MATERIAL_H
#define UNTITLED_MATERIAL_H

class ShadeRec;

#include "../Vector3D.h"
#include "../ShadeRec.h"
#include "../Mundo.h"

class Material {
public:
    virtual Vector3D shade(ShadeRec& sr) { return Vector3D(0,0,0); }
};


#endif //UNTITLED_MATERIAL_H
