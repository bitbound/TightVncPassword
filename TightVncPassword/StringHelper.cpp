#include "StringHelper.h"
#include <iomanip>
#include <sstream>
#include <string>
#include "inttypes.h"

using namespace std;

void TrimString(string& str)
{
	size_t index = 0;
	while (isspace(str[index]))
	{
		str.erase(index, 1);
	}

	index = str.length() - 1;
	while (isspace(str[index]))
	{
		str.erase(index, 1);
		index--;
	}
}

std::string ToHexString(UINT8* encryptedPassword, int size)
{
	std::stringstream ss;
	ss << std::hex;

	for (int i(0); i < size; ++i)
		ss << std::setw(2) << std::setfill('0') << (int)encryptedPassword[i];

	return ss.str();
}