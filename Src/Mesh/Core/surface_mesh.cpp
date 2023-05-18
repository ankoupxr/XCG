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

        HalfEdge* SurfaceMesh::add_half_edge(Vertex *v1,Vertex *v2,Face *f1)
        {
            uint half_edge_handle;
            if (vertex_to_half_edge_map.find(std::make_tuple(v1->handle(), v2->handle())) ==
                vertex_to_half_edge_map.end()) 
            {
                if(all_half_edges.size() == 0)
                {
                    half_edge_handle = 0;
                }
                else
                {
                    half_edge_handle = all_half_edges.size();
                }
                HalfEdge *new_half_edge = new HalfEdge(v1, v2);
                new_half_edge->set_handle(half_edge_handle);
                new_half_edge->set_parent_face(f1->handle());
                if (vertex_to_half_edge_map.find(std::make_tuple(v2->handle(), v1->handle())) !=
                    vertex_to_half_edge_map.end()) {
                    unsigned int existing_half_edge = vertex_to_half_edge_map[std::make_tuple(v2->handle(),
                                                                                              v1->handle())]->handle();
                    new_half_edge->set_opposing_half_edge(existing_half_edge);
                    get_half_edge(existing_half_edge)->set_opposing_half_edge(new_half_edge->handle());
                }
                v1->add_outgoing_half_edge(half_edge_handle);
                v2->add_incoming_half_edge(half_edge_handle);
                all_half_edges.push_back(new_half_edge);
                half_edge_handle_to_half_edge_map[half_edge_handle] = new_half_edge;
                face_to_one_half_edge_map[f1] = new_half_edge;
                vertex_to_half_edge_map[std::make_tuple(v1->handle(), v2->handle())] = new_half_edge;
            }
            else
            {
                half_edge_handle = vertex_to_half_edge_map[std::make_tuple(v1->handle(), v2->handle())]->handle();
            }
            return half_edge_handle_to_half_edge_map[half_edge_handle];
        }

        Edge * SurfaceMesh::add_edge(Vertex *v1, Vertex *v2, Face *f1)
        {
            uint edge_handle;
            if (vertices_to_edge_handle_map.find(std::make_tuple(v1->handle(), v2->handle())) ==
                vertices_to_edge_handle_map.end())
            {
                if (vertices_to_edge_handle_map.find(std::make_tuple(v2->handle(), v1->handle())) ==
                    vertices_to_edge_handle_map.end()) 
                {
                    if(all_edges.size() == 0)
                    {
                        edge_handle = 0;
                    }
                    else
                    {
                        edge_handle = all_edges.size();
                    }
                    Edge* new_edge = new Edge(v1,v2);
                    new_edge->set_handle(edge_handle);
                    all_edges.push_back(new_edge);
                    vertices_to_edge_handle_map[std::make_tuple(v1->handle(), 
                    v2->handle())] = edge_handle;
                    edge_handle_to_edge_map[edge_handle] = new_edge;
                    HalfEdge *he = add_half_edge(v1, v2, f1);
                    he->set_parent_edge(edge_handle);
                    edge_to_one_half_edge_map[new_edge] = he;
                }
                else
                {
                    edge_handle = vertices_to_edge_handle_map[std::make_tuple(v2->handle(), v1->handle())];
                    Edge *existing_edge = edge_handle_to_edge_map[edge_handle];
                    HalfEdge *he = add_half_edge(v1, v2, f1);
                    he->set_parent_edge(edge_handle);
                    edge_to_one_half_edge_map[existing_edge] = he;
                }
            }
            else
            {
                edge_handle = vertices_to_edge_handle_map[std::make_tuple(v1->handle(), v2->handle())];
            }
            return edge_handle_to_edge_map[edge_handle];
        }
    
        Face * SurfaceMesh::add_face(Vertex *v1, Vertex *v2, Vertex *v3)
        {
            uint face_handle;
            if (vertices_to_face_handle_map.find(std::make_tuple(v1->handle(), v2->handle(), v3->handle())) ==
                vertices_to_face_handle_map.end()) {
                if (all_faces.size() == 0) {
                    face_handle = 0;
                } else {
                    face_handle = all_faces.size();
                }
                Face *new_face = new Face(v1, v2, v3);
                new_face->set_handle(face_handle);
                all_faces.push_back(new_face);
                vertices_to_face_handle_map[std::make_tuple(v1->handle(), v2->handle(), v3->handle())] = face_handle;
                face_handle_to_face_map[face_handle] = new_face;
                Edge *e1 = add_edge(v1, v2, new_face);
                Edge *e2 = add_edge(v2, v3, new_face);
                Edge *e3 = add_edge(v3, v1, new_face);
            } else {
                face_handle = vertices_to_face_handle_map[std::make_tuple(v1->handle(), v2->handle(), v3->handle())];
            }
            return face_handle_to_face_map[face_handle];
        }

        HalfEdge * SurfaceMesh::get_half_edge(uint _i) {
            HalfEdge *new_half_edge = NULL_VALUE;
            if (half_edge_handle_to_half_edge_map.find(_i) != 
            half_edge_handle_to_half_edge_map.end()) {
                return half_edge_handle_to_half_edge_map[_i];
            } else {
                return new_half_edge;
            }
        }
    
    }
}