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
	if (argc != 3)
	{
		cout << "Incorrect number of arguments." << endl;
		WriteHelp();
		return 1;
	}

	string regTarget = argv[2];
	TrimString(regTarget);

	string password = argv[1];
	if (password.length() > 8) {
		cout
			<< "Password exceeds the max length for VNC passwords. "
			<< "Only the first 8 characters will be used."
			<< endl;
	}
	TrimString(password);

	UINT8* encryptedPassword = EncryptVncPassword(password, VncPassCrypt::VNC_PASSWORD_SIZE);

	int result = WriteEncryptedPassword(regTarget, encryptedPassword, VncPassCrypt::VNC_PASSWORD_SIZE);

	delete[] encryptedPassword;

	if (result == 0)
	{
		cout << "Encrypted password successfully written to the registry.";
	}
	return result;
}