#ifndef UNTITLED_TRACER_H
#define UNTITLED_TRACER_H

#include "Vector3D.h"
#include "Rayo.h"

class Mundo;

class Tracer {
public:
    Mundo* mundo_ptr;

    Tracer();
    Tracer(Mundo* m_ptr);
    Vector3D trace_ray(const Rayo& rayo, const int depth) const;
};


#endif //UNTITLED_TRACER_H
