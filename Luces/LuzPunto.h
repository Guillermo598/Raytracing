#ifndef UNTITLED_LUZPUNTO_H
#define UNTITLED_LUZPUNTO_H

#include "Luz.h"
#include "../Utils/ShadeRec.h"
#include "../Utils/Vector3D.h"

class LuzPunto : public Luz{
public:
    double ls;
    Vector3D color;
    Vector3D posicion;

    LuzPunto(Vector3D pos);
    void set_color(Vector3D c);
    virtual Vector3D get_direccion(ShadeRec& sr);
    virtual Vector3D L(ShadeRec& sr);
    virtual bool en_sombra(const Rayo& rayo, const ShadeRec& sr) const;
};


#endif //UNTITLED_LUZPUNTO_H
