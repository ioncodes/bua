#pragma once

#include <string>

struct Value
{
	double value_double;
	std::string value_string;
	Value();
	Value(double value);
	Value(std::string value);
};