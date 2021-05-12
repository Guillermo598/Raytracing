#ifndef UNTITLED_SHADEREC_H
#define UNTITLED_SHADEREC_H

class Mundo;
class Material;

#include "Vector3D.h"
#include "Rayo.h"
#include "Materiales/Material.h"

class ShadeRec {
public:

    bool hit_objeto;
    Material* pMaterial;
    Vector3D hitPoint;
    Vector3D localHitPoint;
    Vector3D normal;
    Vector3D color;
    Rayo rayo;
    int depth;
    Vector3D dir;
    Mundo* mundo;
    double t;
    double u;
    double v;


    ShadeRec(Mundo* m);
    ShadeRec(const ShadeRec& sr);

};

#endif //UNTITLED_SHADEREC_H