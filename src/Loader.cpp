#include "Loader.h"

#include <iostream>
#include <fstream>
#include <string>
#include "System.h"

Loader::Loader(void) {}

Loader::~Loader(void) {}

void Loader::load(std::string name, Engine *e) {
    std::ifstream fin(name);
    YAML::Parser parser(fin);
    YAML::Node doc;
    if(!parser.GetNextDocument(doc)) std::cout << "file does not have a YAML Sequence" << std::endl;
    for(YAML::Iterator it=doc.begin();it!=doc.end();++it) {
        int EntityID = Engine::instance().createEntity();
        for(YAML::Iterator j = it->begin(); j != it->end(); ++j) {
            std::string key;
            j.first() >> key;
            Engine::instance().getSystem(key)->loadEntity(EntityID, j.second() );
        }
    }
}