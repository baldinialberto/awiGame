#include "../include/common.hpp"

me::fIt::fIt(const char *path, const char *flags)
    : _file{path, flags[0] == 'r' ? std::ios_base::in : std::ios_base::out}
{
}

me::fIt::~fIt()
{
    if (_file.is_open())
        _file.close();
}

bool me::fIt::opened() const { return _file.is_open(); }

const me::fIt &me::fIt::load(const char *path, const char *flags)
{
    _file.open(path, flags[0] == 'r' ? std::ios_base::in : std::ios_base::out);
    return *this;
}

int me::fIt::write(const char *data, size_t size)
{
    if (data == nullptr || size == 0)
        return 1;
    _file.write(data, size);
    return _file.eof() | _file.fail() | _file.bad();
}
int me::fIt::read(char *dest, size_t size)
{
    if (dest == nullptr || size == 0)
        return 1;
    _file.read(dest, size);
    return _file.eof() | _file.fail() | _file.bad();
}

string me::filePath(const char *pFilename, fm::pokekit_type pType)
{
    //string currFilePath{std::__fs::filesystem::current_path()};
    string currFilePath{"/Users/albertobaldini/source/repos/awigame/"};
    currFilePath.append(fm::pokekit_relPaths[pType]).append(pFilename);

    return currFilePath;
}
