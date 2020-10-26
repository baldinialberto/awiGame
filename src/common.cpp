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

const char * me::filePath(const char *pFilename, const char *pRelPath)
{
    return "";
}