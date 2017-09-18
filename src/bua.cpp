#include <bua/bua.h>

Bua::Bua(std::string lua_file, bool &error)
{
	m_state = luaL_newstate();
	luaL_openlibs(m_state);
	if (luaL_loadfile(m_state, lua_file.data()) || lua_pcall(m_state, 0, 0, 0))
	{
		error = true;
		printf("error: %s", lua_tostring(m_state, -1));
	}
	else
	{
		error = false;
	}
}

void Bua::bind(std::string field_name)
{
	lua_getglobal(m_state, field_name.data());
	if (lua_isnumber(m_state, -1))
	{
		const double number = static_cast<double>(lua_tonumber(m_state, -1));
		m_fields[field_name] = Value(number);
	}
	else if(lua_isstring(m_state, -1))
	{
		const std::string string = static_cast<std::string>(lua_tostring(m_state, -1));
		m_fields[field_name] = Value(string);
	}
}

void Bua::update()
{
	for (std::map<std::string, Value>::iterator it = m_fields.begin(); it != m_fields.end(); ++it)
	{
		std::string name = it->first;
		Value value = it->second;
		lua_getglobal(m_state, name.data());
		if (lua_isnumber(m_state, -1))
		{
			const double number = static_cast<double>(lua_tonumber(m_state, -1));
			m_fields[name] = Value(number);
		}
		else if (lua_isstring(m_state, -1))
		{
			const std::string string = static_cast<std::string>(lua_tostring(m_state, -1));
			m_fields[name] = Value(string);
		}
	}
}

Value Bua::get(std::string name)
{
	Value value = m_fields[name];
	return value;
}

Bua::~Bua()
{
	lua_close(m_state);
}
