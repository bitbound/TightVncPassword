# TightVncPassword

A console app that lets you set new passwords for TightVNC in a non-interactive environment.  The password is encrypted using the same C++ code from the TightVNC repository.

```
TightVncPassword

Encrypts a new password for TightVNC and sets it in the registry.

Syntax: TightVncPassword.exe {password} {machine/user}

Password:
  The first argument should be an 8-character password.  Passwords longer than 8 characters will get trimmed, and only the first 8 will get saved to the registry.

Machine/User:
  The second argument should be literally "machine" or "user". If "machine", the password will be saved to HKLM and apply to the service.  If "user", it will be saved to HKCU and only apply when tvnserver.exe is run in "app" mode.
```
