#ifndef SYSTEM_H
#define SYSTEM_H

class Component;

class System {
  public:
		System(Engine* e);
		virtual ~System();

		virtual bool init() = 0;
		virtual void update(time) = 0;
		virtual void cleanup() = 0;

		virtual bool addEntity(int EntityID) = 0;
		virtual Component* getEntity(int EntityID) = 0;
		virtual bool removeEntity(int EntityID) = 0;

		bool operator<(const System& other) const {
			return priority < other.priority;
		}

		const std::string name;
		const int priority;

	protected:
		Engine* e;
};

#endif //SYSTEM_H
