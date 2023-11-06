#pragma once

#include <string>
#include "TightVnc/inttypes.h"

UINT8* EncryptVncPassword(std::string password, int size);