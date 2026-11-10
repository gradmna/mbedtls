#include <emscripten.h>
#include <stddef.h>
#include <stdint.h>
#include "mbedtls/ssl.h"
#include "mbedtls/entropy.h"
#include "mbedtls/ctr_drbg.h"

// clang-format off
EM_JS(void, setSize, (char*nm, size_t sz), {
	__mbedtls_setSize__(mbedtls.UTF8ToString(arguments[0]), arguments[1]);
});
// clang-format on

void _getSizes() {
	#define _STR(x) #x
	#define _SSO(t) setSize(_STR(t), sizeof(t))
	#include "sizes.c"
	#undef _SSO
	#undef _STR
}