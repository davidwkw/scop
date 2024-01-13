#include "utils.hpp"

namespace Scop
{
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
