#ifndef SYSTEM_H
#define SYSTEM_H

class Component;

class System {
	public:
		System(Engine* e);
		~System();

		virtual void init() = 0;
		virtual void update(unsigned int delay) = 0;
		virtual void cleanup() = 0;

		virtual Component* addEntity(int EntityID) = 0;
		virtual Component* getEntity(int EntityID) = 0;
		virtual bool removeEntity(int EntityID) = 0;

		bool operator<(const System& other) const {
			return priority < other.priority;
		}

        static const std::string name;

	protected:
		int priority;
		Engine* e;
};

#endif //SYSTEM_H
