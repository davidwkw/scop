#pragma once

#ifndef __MODEL_HPP__

#include <vector>
#include <string>
#include <map>

namespace Scop
{
    struct Vertex {
        float x;
        float y;
        float z;
        float w = 1.0f;

        Vertex(float x, float y, float z, float w = 1.0f): x(x), y(y), z(z), w(w) {}
    };

    struct FaceData {
        int vertex_index;
        int texture_vertex_index = 0;
        int vertex_normal_index = 0;

        FaceData(int vertex_index, int texture_vertex_index = 0, int vertex_normal_index = 0): vertex_index(vertex_index), texture_vertex_index(texture_vertex_index), vertex_normal_index(vertex_normal_index) {}
    };

    struct Face {
        std::vector<FaceData> face_data;
    };

    class Model
    {
        public:
            std::string             model_name;
            std::vector<Vertex>     vertices;
            bool                    smooth_shading;
            std::vector<Face>       faces;
            std::string             material_filename;
            std::string             material_name;
    };
}

#endif