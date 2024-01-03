#pragma once

#include <string>
#include <iostream>
#include <stdexcept>
#include <utils.hpp>

namespace Scop
{
    class App
    {
        public:
            void run(const std::string model_filename);
        private:
            void _parse_object_file(const std::string& model_filename);
            void _check_valid_extension(const std::string& model_filename);
    };
}
