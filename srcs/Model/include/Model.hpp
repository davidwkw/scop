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
        std::vector<FaceData> data;
    };

    // https://paulbourke.net/dataformats/obj/
    class Model
    {
        public:
            std::string             model_name; // o
            std::vector<Vertex>     vertices; // v
            bool                    smooth_shading; // s
            std::vector<Face>       faces; // f
            std::string             material_filename; // mtllib
            std::string             material_name; // usemtl

            Model() = delete;
            Model(const std::string &filename);
            ~Model();
        
        private:
            void parse_object_file(const std::string& model_filename);
            void check_valid_extension(const std::string& model_filename);
            void parse_obj_file_to_model_instance(const std::string& model_filename);
            void parse_file(const std::string &line);
            void parse_obj_file_line(const std::string &line);
            void parse_vertex(const std::vector<std::string> &line_tokens);
            void parse_face(const std::vector<std::string> &line_tokens);
    };
}

#endif