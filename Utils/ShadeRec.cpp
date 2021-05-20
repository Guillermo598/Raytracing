#include "ShadeRec.h"

ShadeRec::ShadeRec(Mundo *m) :
        hit_objeto(false),
        pMaterial(nullptr),
        hitPoint(),
        localHitPoint(),
        normal(),
        rayo(),
        depth(0),
        color(Vector3D(0, 0, 0)),
        t(0.0),
        u(0.0),
        v(0.0),
        mundo(m) {}

ShadeRec::ShadeRec(const ShadeRec& sr) :
        hit_objeto(sr.hit_objeto),
        pMaterial(sr.pMaterial),
        hitPoint(sr.hitPoint),
        localHitPoint(sr.localHitPoint),
        normal(sr.normal),
        rayo(sr.rayo),
        depth(sr.depth),
        color(sr.color),
        t(sr.t),
        u(sr.u),
        v(sr.v),
        mundo(sr.mundo) {}
