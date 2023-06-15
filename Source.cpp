#include <string.h>
#include <iostream>
#include "chat.h"

using namespace std;

int main()
{
	Name u1 = "Vasia";
	Name u2 = "Petia";
	chat che;
	uint a = 123;
	uint b = 456;
	che.add(u1, a);
	che.add(u2, b);
	return 0;
}