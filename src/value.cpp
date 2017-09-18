#include <bua/value.h>

Value::Value(): value_double(NULL)
{
}

Value::Value(double value)
{
	value_double = value;
	value_string = "";
}

Value::Value(std::string value)
{
	value_string = value;
	value_double = NULL;
}