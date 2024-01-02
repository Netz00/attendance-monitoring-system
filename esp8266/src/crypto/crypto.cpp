#include "crypto.h"

constexpr char masterKey[] PROGMEM = "w86vn@rpfA O+S"; // Use 8 random characters or more

void getKey(uint8_t *derivedKey, int derivedKeyLen, uint8_t *hkdfSalt)
{
    // Generate the key to use for HMAC and encryption
    experimental::crypto::HKDF hkdfInstance(FPSTR(masterKey), (sizeof(masterKey)) - 1, hkdfSalt, sizeof(hkdfSalt)); // (sizeof masterKey) - 1 removes the terminating null value of the c-string
    hkdfInstance.produce(derivedKey, derivedKeyLen);
}