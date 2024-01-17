#include "utils.hpp"
#include <filesystem>
#include <algorithm> 
#include <cctype>
#include <locale>
#include <sstream>
#include <string>
#include <vector>

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

std::string remove_comment(const std::string &line)
{
    std::size_t comment_index = line.find_first_of('#');
    if (comment_index != std::string::npos)
        return line.substr(0, comment_index);
    else
        return line;
}

std::vector<std::string> tokenise_str(const std::string &line, char delim = ' ')
{
    std::stringstream           ss(line);
    std::vector<std::string>    result;
    std::string                 str;

    while (std::getline(ss, str, delim))
        result.push_back(str);
    return result;
}

}
