#include <bua/bua.h>
#include <iostream>

int main(int argc, char *argv[]) 
{
	bool error;
	Bua *bua = new Bua("test.lua", error);
	if(error)
	{
		delete bua;
		return -1;
	}
	bua->bind("d");
	bua->bind("s");
	for(int i = 0; i < 10; i++)
	{
		bua->update();
		std::cout << "double: " << bua->get("d").value_double << std::endl;
		std::cout << "string: " << bua->get("s").value_string << std::endl;
	}
	delete bua;
	return 0;
}
