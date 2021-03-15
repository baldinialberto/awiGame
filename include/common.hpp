#ifndef COMMON_HPP
#define COMMON_HPP

#pragma once

#include <iostream>
#include <filesystem>
#include <fstream>
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
        explicit fIt(const char *path = "", const char *flags = "r");
        virtual ~fIt();
        bool opened() const;
        const fIt &load(const char *path, const char *flags);
        int write(const char *data, size_t len);
        int read(char *dest, size_t len);

    private:
        std::fstream _file;
    };

    string filePath(const char *pFilename, fm::pokekit_type pType);
}

#endif
