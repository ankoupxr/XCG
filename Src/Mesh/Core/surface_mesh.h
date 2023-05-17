#pragma once

#include "../../Core/vertex.h"
#include "../../Core/edge.h"
#include "../../Core/halfedge.h"
#include "../../Core/face.h"

namespace XCG{
    namespace Core{
        class SurfaceMesh
        {
        private:
            std::vector<Face*> all_faces;
            std::vector<Edge*> all_edges;
            std::vector<HalfEdge*> all_half_edges;
            std::vector<Vertex *> all_vertices;

            std::unordered_map<Vertex *, uint> vertex_to_vertex_handle_map;
            std::unordered_map<uint, Vertex *> vertex_handle_to_vertex_map;
            std::unordered_map<uint, Edge *> edge_handle_to_edge_map;
            std::unordered_map<uint, HalfEdge *> half_edge_handle_to_half_edge_map;
            std::unordered_map<uint, Face *> face_handle_to_face_map;
            std::unordered_map<Face *, HalfEdge *> face_to_one_half_edge_map;
            std::unordered_map<Edge *, HalfEdge *> edge_to_one_half_edge_map;


        public:
            SurfaceMesh(){};
            ~SurfaceMesh(){};

            Vertex *add_vertex(Vertex *new_vertex);
            HalfEdge *add_half_edge(Vertex *v1, Vertex *v2, Face *f1);
            Edge *add_edge(Vertex *v1,Vertex *v2,Face *f1);
            Face *add_face(Vertex *v1, Vertex *v2, Vertex *v3);
        private:
            void clear()
            {
                all_faces.clear();
                all_edges.clear();
                all_half_edges.clear();
                all_vertices.clear();
            }
        
        };
    }

}