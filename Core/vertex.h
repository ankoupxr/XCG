#pragma once

#include <vector>
#include "element.h"
#include "vector"


class Vertex : public Element
{
private:
    /* data */
public:
    typedef struct 
    {
        unsigned int index;
        float x;
        float y;
        float z;
        float nx;
        float ny;
        float nz;
    }VertexInfo;
    


    Vertex(float p1 = 0.0f, float p2 = 0.0f, float p3 = 0.0f, float n1 = 0.0f, float n2 = 0.0f, float n3 = 0.0f);
    Vertex(const Vector &pos, const Vector &nor = Vector());

    VertexInfo getVertexInfo();

    public:
        ~Vertex(void);
};
