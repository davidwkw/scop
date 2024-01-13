#pragma once

#include <string>
#include <sstream>

namespace Scop
{
    T string_to_type(const std::string str);
    std::string get_file_extension(const std::string& filename);
}
