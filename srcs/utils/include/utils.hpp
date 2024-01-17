#pragma once

#include <string>
#include <vector>
#include <sstream>

namespace Scop
{
    std::string get_file_extension(const std::string& filename);
    std::vector<std::string> tokenise_str(const std::string &line, char delim);
    std::string remove_comment(const std::string &line);

    template <typename T>
    T string_to_type(const std::string str)
    {
        T result;
        std::stringstream stream;

        stream << str;
        stream >> result;
        return result;
    }

    std::string ltrim_ws(std::string s);
    std::string rtrim_ws(std::string s);
    std::string trim_ws(std::string str);
}
