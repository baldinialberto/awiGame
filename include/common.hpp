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
    template <typename T>
    class point
    {
    public:
        explicit point(T x, T y) : _x{x}, _y{y} {};
        explicit point(T x) : _x{x}, _y{x} {};
        virtual ~point(){};
        void x(T x) { _x = x; };
        void y(T y) { _y = y; };
        T x() const noexcept { return _x; };
        T y() const noexcept { return _y; };

    private:
        T _x;
        T _y;
    };

    class fIt
    {
    public:
        explicit fIt(const char *path = "");
        ~fIt();
        const FILE *ptr();
        bool opened();
        const fIt &load(const char *path) const;

    private:
        void _load();
        FILE *_filePtr;
        mutable bool _opened;
    };

    string filePath(const char *pFilename, fm::pokekit_type pType);
}

#endif
