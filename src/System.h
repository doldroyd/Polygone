#ifndef SYSTEM_H
#define SYSTEM_H

class Component {
};

class System {
	public:
        System(const int& p, const std::string& n): priority(p), name(n) {}
        ~System() {}

		virtual bool init() = 0;
		virtual void update(unsigned int delay) = 0;
		virtual void cleanup() = 0;

		virtual Component* getEntity(int EntityID) = 0;
		virtual bool removeEntity(int EntityID) = 0;

        const std::string name;
        const int priority;

};

#endif //SYSTEM_H
