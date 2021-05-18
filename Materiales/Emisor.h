#ifndef RAYTRACING_EMISOR_H
#define RAYTRACING_EMISOR_H


#include "Material.h"
#include "../Geometria/Esfera.h"

class Emisor : public Material{
public:
    double ls;
    Vector3D c;
    Esfera* pEsfera;
    LuzPunto* pLuz;

    Emisor(Vector3D color, double _ls, Esfera* esfera, LuzPunto* luz);
    virtual Vector3D shade(ShadeRec& sr);
    virtual Vector3D get_Le(ShadeRec& sr) const;
};


#endif //RAYTRACING_EMISOR_H
