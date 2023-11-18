#pragma once

#include "TightVnc/inttypes.h"
#include <string>

void TrimString(std::string& str);

std::string ToHexString(UINT8* encryptedPassword, int size);