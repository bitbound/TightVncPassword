#include "HelpWriter.h"
#include <iostream>

using namespace std;

void WriteHelp()
{
	cout << "TightVncPassword" << endl << endl;
	cout << "Encrypts a new password for TightVNC and optionally sets it in the registry." << endl << endl;
	cout << "Syntax: TightVncPassword.exe {password} [{machine/user}]" << endl << endl;

	cout
		<< "Password:" << endl
		<< "  The first argument should be an 8-character password.  Passwords "
		<< "longer than 8 characters will get trimmed, and only the first 8 "
		<< "will get saved to the registry." << endl << endl;

	cout
		<< "Machine/User (optional):" << endl
		<< "  If specified, the encrypted password will be written to the registry. "
		<< "If \"machine\", the password will be saved to HKLM and apply to the "
		<< "service.  If \"user\", it will be saved to HKCU and only apply when "
		<< "tvnserver.exe is run in \"app\" mode." << endl;
}