#include "RegistryWriter.h"
#include "TightVnc/inttypes.h"
#include <iostream>
#include <wtypes.h>
#include "HelpWriter.h"
#include <ShlObj_core.h>
#include <string>

using namespace std;

int WriteEncryptedPassword(std::string regTarget, UINT8* encryptedPassword, int size)
{
	HKEY baseKey = nullptr;

	if (_strcmpi(regTarget.c_str(), "machine") == 0)
	{
		if (!IsUserAnAdmin())
		{
			cout << "Process must be run as administrator to write to HKLM.";
			return 1;
		}
		baseKey = HKEY_LOCAL_MACHINE;
	}
	else if (_strcmpi(regTarget.c_str(), "user") == 0)
	{
		baseKey = HKEY_CURRENT_USER;
	}
	else
	{
		cout << "Invalid argument (machine/user)." << endl;
		WriteHelp();
		return 1;
	}

	LPCWSTR subkeyPath = L"Software\\TightVNC\\Server";
	HKEY serverKey = nullptr;

	LSTATUS result = RegCreateKeyW(HKEY_CURRENT_USER, subkeyPath, &serverKey);

	if (result != ERROR_SUCCESS)
	{
		cout << "Failed to open TightVNC's Server registry key. Error: " << result;
		return 1;
	}

	LPCWSTR valueName = L"Password";

	result = RegSetValueEx(serverKey, valueName, 0, REG_BINARY, encryptedPassword, size);

	if (result != ERROR_SUCCESS)
	{
		cout << "Failed to write the encrypted password to the registry. Error: " << result;
		RegCloseKey(serverKey);
		return 1;
	}

	RegCloseKey(serverKey);
	return 0;
}