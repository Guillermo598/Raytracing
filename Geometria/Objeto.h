#ifndef UNTITLED_OBJETO_H
#define UNTITLED_OBJETO_H

#include "../Vector3D.h"
#include "../Rayo.h"
#include "../ShadeRec.h"

class Material;

class Objeto {
public:
    Material* pMaterial;
    Vector3D color;

    Objeto() : pMaterial(nullptr), color(Vector3D(0,0,0)){};

    void setColor(float r, float g, float b) { color.set(r, g, b); }
    Vector3D getColor() { return color; }

    void setMaterial(Material* pMat);

    virtual bool hit(const Rayo &rayo, double &tmin, ShadeRec &sr) const =0;
    virtual bool hit_sombra(const Rayo &rayo, double &tmin) const =0;
    virtual void move(const Vector3D& v) = 0;
};


#endif //UNTITLED_OBJETO_H
