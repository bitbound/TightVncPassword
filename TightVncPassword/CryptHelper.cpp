#include "TightVNC\VncPassCrypt.h"
#include "CryptHelper.h"
#include "StringHelper.h"
#include <iostream>
#include <string>
#include "combaseapi.h"
#include "TightVnc/VncPassCrypt.h"

UINT8* EncryptVncPassword(std::string password, int size)
{
	TrimString(password);

	int passwordLen = password.length();

	UINT8* plainText = new UINT8[size];
	UINT8* encryptedPassword = new UINT8[size];

	for (int i = 0; i < size; i++)
	{
		if (i < passwordLen) {
			plainText[i] = static_cast<UINT8>(password[i]);
		}
		else {
			plainText[i] = 0;
		}
	}

	VncPassCrypt::getEncryptedPass(encryptedPassword, plainText);

	delete[] plainText;

	return encryptedPassword;
}