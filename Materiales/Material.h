#ifndef UNTITLED_MATERIAL_H
#define UNTITLED_MATERIAL_H

class ShadeRec;

#include "../Utils/Vector3D.h"
#include "../Utils/ShadeRec.h"
#include "../Mundo.h"

class Material {
public:
    virtual Vector3D shade(ShadeRec& sr) { return Vector3D(); }
};


#endif //UNTITLED_MATERIAL_H
