#pragma once

#include <lua/lua.hpp>
#include <bua/value.h>
#include <map>

class Bua {
private:
	lua_State *m_state;
	std::map<std::string, Value> m_fields;
public:
	Bua(std::string lua_file, bool& error);
	void bind(std::string field_name);
	void update();
	Value get(std::string name);
	~Bua();
};
