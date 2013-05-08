#ifndef LOADER_H
#define LOADER_H

#include "yaml-cpp/yaml.h"

#include "Engine.h"

class Loader
{
public:
    Loader(void);
    ~Loader(void);

    static void load(std::string name, Engine *e);
};

#endif LOADER_H