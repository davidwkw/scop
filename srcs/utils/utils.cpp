#include "utils.hpp"
#include <filesystem>
#include <algorithm> 
#include <cctype>
#include <locale>

namespace Scop
{

std::string get_file_extension(const std::string& filename)
{
    std::filesystem::path file_path(filename);
    return file_path.extension().string();
}

std::string ltrim_ws(std::string s)
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    return s;
}

std::string rtrim_ws(std::string s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
    return s;
}

std::string trim_ws(std::string str)
{
    str = rtrim(str);
    str = ltrim(str);
    return str;
}

}
