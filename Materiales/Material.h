#ifndef UNTITLED_MATERIAL_H
#define UNTITLED_MATERIAL_H

class ShadeRec;

#include "../Vector3D.h"
#include "../ShadeRec.h"
#include "../Mundo.h"

class Material {
public:
    virtual Vector3D shade(ShadeRec& sr) { return Vector3D(); }
    virtual Vector3D get_Le(ShadeRec& sr) const { return Vector3D(); }
};


#endif //UNTITLED_MATERIAL_H
