#pragma once

#include "TightVnc/inttypes.h"
#include <string>

int WriteEncryptedPassword(std::string regTarget, UINT8* encryptedPassword, int size);