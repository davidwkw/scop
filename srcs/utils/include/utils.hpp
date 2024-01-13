#pragma once

#include <string>
#include <sstream>

namespace Scop
{
    std::string get_file_extension(const std::string& filename);

    template <typename T>
    T string_to_type(const std::string str)
    {
        T result;
        std::stringstream stream;

        stream << str;
        stream >> result;
        return result;
    }
}
