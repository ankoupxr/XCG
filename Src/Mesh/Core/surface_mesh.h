#pragma once

#include <cstddef>

#include "../../Core/vertex.h"
#include "../../Core/edge.h"
#include "../../Core/halfedge.h"
#include "../../Core/face.h"

namespace XCG{
    namespace Core{
        std::nullptr_t NULL_VALUE;

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

            typedef std::unordered_map<const twin_type_t, unsigned int, twin_key_hash, twin_key_equal> special_map_twin;
            typedef std::unordered_map<const twin_type_t, HalfEdge *, twin_key_hash, twin_key_equal> twin_map_he_special;
            special_map_three vertices_to_face_handle_map;
            special_map_twin vertices_to_edge_handle_map;
            twin_map_he_special vertex_to_half_edge_map;


        public:
            SurfaceMesh(){};
            ~SurfaceMesh(){};

            Vertex *add_vertex(Vertex *new_vertex);
            HalfEdge *add_half_edge(Vertex *v1, Vertex *v2, Face *f1);
            Edge *add_edge(Vertex *v1,Vertex *v2,Face *f1);
            Face *add_face(Vertex *v1, Vertex *v2, Vertex *v3);

            std::vector<Face *> get_faces() {
            return all_faces;
            }

            std::vector<Edge *> get_edges() {
                return all_edges;
            }

            std::vector<HalfEdge *> get_half_edges() {
                return all_half_edges;
            }

            std::vector<Vertex *> get_vertices() {
                return all_vertices;
            }


            HalfEdge *get_half_edge(uint _i);

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