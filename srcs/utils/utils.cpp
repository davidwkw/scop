#include "utils.hpp"

namespace Scop
{
    template <typename T>
    T string_to_type(const std::string str)
    {
        T result;
        std::stringstream stream;

        stream << str;
        stream >> result;
        return result;
    }

    std::string get_file_extension(const std::string& filename)
    {
        std::size_t index;

        index = filename.find_last_of('.');
        if (index == std::string::npos)
        {
            return "";
        }
        return filename.substr(index + 1);
    }
}
