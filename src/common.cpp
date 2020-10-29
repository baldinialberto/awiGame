#include "../include/common.hpp"

me::fIt::fIt(const char *path)
{

}

me::fIt::~fIt()
{

}

bool me::fIt::opened() { return _opened; }

const FILE * me::fIt::ptr() { return _filePtr; }

const me::fIt& me::fIt::load(const char *path) const
{
    return *this;
}

void me::fIt::_load()
{

}

string me::filePath(const char *pFilename, fm::pokekit_type pType)
{
    string currFilePath{ __FILE__ };
    currFilePath.resize(currFilePath.find("\\src"));
    currFilePath.append(fm::pokekit_relPaths[pType]).append(pFilename);

    return currFilePath;
}