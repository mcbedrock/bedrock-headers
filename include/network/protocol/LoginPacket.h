#pragma once

#include "Packet.h"
#include <cstdint>

struct LoginData;
struct WebToken;
struct LoginPacket : Packet {
	int32_t protocol;
	char pad[0x4];
	LoginData *data;
};
static_assert(offsetof(LoginPacket, protocol) == 0x24);
struct LoginData {
	WebToken *cData1;
	WebToken *cData2;
	WebToken *skinData;
};
struct WebToken {

};