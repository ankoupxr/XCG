#pragma once

#include "surface_mesh.h"

namespace XCG{
    namespace Core{

        SurfaceMesh::SurfaceMesh() 
        { 
            clear(); 
        }

        SurfaceMesh::~SurfaceMesh() 
        { 
            clear(); 
        }

        Vertex* SurfaceMesh::add_vertex(Vertex *new_vertex)
        {
            uint return_handle;
            if(vertex_to_vertex_handle_map.find(new_vertex) == 
            vertex_to_vertex_handle_map.end())
            {
                uint new_vertex_handle;
                if (all_vertices.size() == 0) 
                {
                    new_vertex_handle = 0;
                } 
                else 
                {
                    new_vertex_handle = all_vertices.size();
                }
                all_vertices.push_back(new_vertex);
                new_vertex->set_handle(new_vertex_handle);
                vertex_to_vertex_handle_map[new_vertex] = new_vertex_handle;
                return_handle = new_vertex_handle;
                vertex_handle_to_vertex_map[new_vertex_handle] = new_vertex;
            }
            else
            {
                return_handle = vertex_to_vertex_handle_map[new_vertex];
            }
            return vertex_handle_to_vertex_map[return_handle];
        }

        Edge * SurfaceMesh::add_edge(Vertex *v1, Vertex *v2, Face *f1)
        {
            uint edge_handle;
            if(vertices_to)
            {

            }
        }
    }
}