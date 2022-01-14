#include "Interface.h" 
#include <memory>

int main()
{
	std::unique_ptr<Interface> inter = std::make_unique<Interface>();
	inter->afficherInterface();
	return 0;
}