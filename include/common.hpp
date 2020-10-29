#ifndef COMMON_HPP
#define COMMON_HPP

#pragma once

#include <iostream>
#include <filesystem>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <tuple>

#include "file_manager.hpp"

using namespace std;

namespace me
{

class fIt
{
public:
    explicit fIt(const char* path ="");
    ~fIt();
    const FILE* ptr();
    bool opened();
    const fIt& load(const char* path) const;
private:
    void _load();
    FILE* _filePtr;
    mutable bool _opened;
};

    string filePath(const char* pFilename, fm::pokekit_type pType);

}

#endif
