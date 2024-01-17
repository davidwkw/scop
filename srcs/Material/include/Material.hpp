#pragma once

#ifndef __MATERIAL_HPP__

#include <vector>
#include <string>
#include <map>

namespace Scop
{
    struct RGB {
        float red; // 0 - 1.0
        float green;
        float blue;

        RGB(float r, float g = 0, float b = 0) : red(r), green(g ? g : r), blue(b ? b : r) {}
    };

    // https://paulbourke.net/dataformats/mtl/
    class Material
    {   
        public:
            std::string material_name; // if no newmtl name define in file it is invalid; NO BLANKS
            RGB ambient_reflectivity; // 0 - 1.0 Ka // color // other formats include Ka spectral file.rfl factor // Ka xyz x y z
            RGB diffuse_reflectivity; // 0 - 1.0 Kd // transparency
            RGB specular_reflectivity; // 0 - 1.0 Ks // reflectivity
            float specular_exponent; // 0 - 1000 // Ns
            int illumination_model; // 1 - 10 need illum_ prepended?? // illum
            float dissolve; // 0 - 1.0 // d
            float optical_density; // 0.001 to 10 // Ni

            Material() = delete;
            Material(const std::string &filename);
            ~Material();

        private:
            void parse_material_file(const std::string &filename);
            void check_valid_extension(const std::string& filename);
            void parse_mtl_file_to_instance(const std::string& filename);
            void parse_obj_file_line(const std::string &line);
            void parse_reflectivity(const std::vector<std::string> &line_tokens, RGB &reflectivity);
    };
}

#endif