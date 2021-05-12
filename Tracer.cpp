#include "Tracer.h"
#include "ShadeRec.h"

Tracer::Tracer() {
    mundo_ptr = nullptr;
}

Tracer::Tracer(Mundo *m_ptr) {
    mundo_ptr = m_ptr;
}

Vector3D Tracer::trace_ray(const Rayo& rayo, const int depth) const {
    ShadeRec sr(mundo_ptr->hitObjetos(rayo));

    if (sr.hit_objeto) {
        sr.rayo = rayo;
        return sr.pMaterial->shade(sr);
    }
    return Vector3D(0,0,0);
}
