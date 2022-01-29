#include <c++/mingw32/bits/stdc++.h>

int main(int argc, char const *argv[])
{
    // useful temp variables
    size_t size, i = 0;
    std::__cxx11::string temp;

    // main values
    std::vector<std::__cxx11::string> thingsToConvert;
    std::multimap<std::__cxx11::string, std::__cxx11::string> json;
    std::multimap<std::__cxx11::string, std::__cxx11::string>::iterator itr;
    std::fstream file(".\\data.json", std::fstream::in | std::fstream::out | std::fstream::app);

    std::cout << "Iterations : ";
    std::cin >> size;
    // cleaning cin buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (i++ < size)
    {
        getline(std::cin, temp);
        thingsToConvert.push_back(temp);
    }
    i = 0;
    for (auto &&i : thingsToConvert)
    {
        std::cout << i << '\t';
        json.insert(std::pair<std::__cxx11::string, std::__cxx11::string>("name", i));
    }
    file << '[';
    for (itr = json.begin(); itr != json.end(); itr++)
    {
        std::cout << '\t' << itr->first << " : " << itr->second << std::endl;
        file << "{\"" << itr->first << "\" : \"" << itr->second << "\"},";
    }
    file << ']';
    file.close();
    std::cout << "\nProgram end!.." << std::endl;
    return 0;
}
