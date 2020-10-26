#ifndef COMMON_HPP
#define COMMON_HPP

#pragma once

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <tuple>

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

    const char* filePath(const char* pFilename, const char* pRelPath);

}

#endif
