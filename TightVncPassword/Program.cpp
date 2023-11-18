#include "inttypes.h"
#include "StringHelper.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include "CryptHelper.h"
#include "HelpWriter.h"
#include "RegistryWriter.h"
#include "TightVnc/VncPassCrypt.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 2 && argc != 3)
	{
		cout << "Incorrect number of arguments." << endl;
		WriteHelp();
		return 1;
	}

	string password = argv[1];
	int passwordLen = static_cast<int>(password.length());

	if (passwordLen > 8) {
		cout
			<< "Password exceeds the max length for VNC passwords. "
			<< "Only the first 8 characters will be used."
			<< endl;
	}
	TrimString(password);

	UINT8* encryptedPassword = EncryptVncPassword(password, VncPassCrypt::VNC_PASSWORD_SIZE);

	if (argc == 2) {
		int size = (std::min)(passwordLen, 8);

		cout << ToHexString(encryptedPassword, size);
		delete[] encryptedPassword;
		return 0;
	}

	string regTarget = argv[2];
	TrimString(regTarget);

	int result = WriteEncryptedPassword(regTarget, encryptedPassword, VncPassCrypt::VNC_PASSWORD_SIZE);

	delete[] encryptedPassword;

	if (result == 0)
	{
		cout << "Encrypted password successfully written to the registry.";
	}
	return result;
}