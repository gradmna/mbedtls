#include <emscripten.h>
#include <stddef.h>
#include <stdint.h>
#include "mbedtls/net_sockets.h"
#include "mbedtls/ssl.h"
#include "mbedtls/error.h"
#include "psa/crypto.h"

// clang-format off
EM_JS(void, setSize, (char*, size_t), {
	__mbedtls__.setSize(UTF8ToString(arguments[0]), arguments[1])
});
// clang-format on

void _getSizes() {
	#define __STR(a) #a
	#define _STR(a) __STR(a)
	#define _SSO(t) setSize(__STR(t), sizeof(t))
	#include "hmm.c"
	#undef _SSO
	#undef __STR
	#undef _STR
}
