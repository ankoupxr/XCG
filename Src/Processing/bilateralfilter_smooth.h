#pragma once

#include "../Mesh/Core/surface_mesh.h"
#include "../System/per_vertex_normals.h"
#include "../System/vertex_triangle_adhacency.h"
#include <Eigen/Core>

namespace XCG{
    namespace Processing
    {
        namespace Smooth
        {
            double distance(Eigen::Vector3d a,Eigen::Vector3d b){
                return sqrt(pow(a.x()-b.x(),2)+pow(a.y()-b.y(),2)+pow(a.z()-b.z(),2));
            }

            void bilateral(XCG::Core::SurfaceMesh *mesh)
            {
                std::vector<std::vector<int>> neighbour_map;
                Eigen::MatrixXd V;
                Eigen::MatrixXi F;
                Eigen::MatrixXd N_vertices;

                V = mesh->get_verticesByMatrix();
                F = mesh->get_facesByMatrix();

                std::vector<std::vector<int>> VF;
                std::vector<std::vector<int>> VFi;

                XCG::vertex_triangle_adjacency(V.rows(),F,VF,VFi);
                for (uint i = 0; i < V.rows(); i++)
                {
                    std::vector<int> neigh;
                    std::vector<double> dist;

                    neigh.clear();
                    dist.clear();
                    for (int j = 0; j < VF[i].size(); ++j) {
                        int f = VF[i][j];
                        for (int k = 0; k < 3; ++k) {
                            int v_idx = F(f, k);
                            if (v_idx != i && std::find(neigh.begin(), neigh.end(), v_idx)
                             == neigh.end()) {
                                neigh.push_back(v_idx);
                            }
                        }
                    }

                    neighbour_map.push_back(neigh);
                }
                


                std::vector<std::vector<double>> dist_map;
                
                for (uint i = 0; i < 1; i++)
                {
                    dist_map.clear();
                    for (int i = 0; i < V.rows(); ++i) 
                    {
                        std::vector<double> dist;
                        dist.clear();
                        for (int j = 0; j < neighbour_map[i].size(); ++j) {
                            dist.push_back(distance(V.row(i),V.row(neighbour_map[i][j])));
                                }
                            
                        dist_map.push_back(dist);
                    }

                    for(int i = 0;i < V.rows();++i)
                    {
                        Eigen::Vector3d n = N_vertices.row(i);

                    }
                }
                
            } 
        }
    }
}