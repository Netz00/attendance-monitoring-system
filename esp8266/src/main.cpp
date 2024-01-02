#include "main.h"

MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance

/*
 * Helper routine to dump a byte array as hex values to Serial.
 */
void dump_byte_array(byte *buffer, byte bufferSize)
{
  for (byte i = 0; i < bufferSize; i++)
  {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
}

int getID(uint8_t *uidArray, int lenght)
{
  if (!mfrc522.PICC_ReadCardSerial())
    // Since a PICC placed get Serial and continue
    return 0;

  for (int i = 0; i < lenght; i++)
  {
    uidArray[i] = mfrc522.uid.uidByte[i];
  }

  // mfrc522.PICC_HaltA(); // Stop reading

  return 1;
}

/*
 * Try using the PICC (the tag/card) with the given key to access block 12
 * @return true when the given key worked, false otherwise.
 */
bool read_block(MFRC522::MIFARE_Key *key, byte *blockData)
{
  bool result = false;
  byte block = 12;
  MFRC522::StatusCode status;

  // Serial.println(F("Authenticating using key A..."));
  status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_B, block, key, &(mfrc522.uid));
  if (status != MFRC522::STATUS_OK)
  {
    Serial.print(F("PCD_Authenticate() failed: "));
    // Serial.println(mfrc522.GetStatusCodeName(status));
    return false;
  }

  // Read block
  byte byteCount = 16 + 2;
  status = mfrc522.MIFARE_Read(block, blockData, &byteCount);
  if (status != MFRC522::STATUS_OK)
  {
    // Serial.print(F("MIFARE_Read() failed: "));
    // Serial.println(mfrc522.GetStatusCodeName(status));
  }
  else
  {
    // Successful read
    result = true;
    Serial.print(F("Success with key:"));
    dump_byte_array((*key).keyByte, MFRC522::MF_KEY_SIZE);
    Serial.println();
    // Dump block data
    Serial.print(F("Block "));
    Serial.print(block);
    Serial.print(F(":"));
    dump_byte_array(blockData, 16);
    Serial.println();
  }
  Serial.println();

  mfrc522.PICC_HaltA();      // Halt PICC
  mfrc522.PCD_StopCrypto1(); // Stop encryption on PCD
  return result;
}

void setup()
{
  Serial.begin(9600); // Initialize serial communications with the PC
  while (!Serial)
    ; // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)

  initWifiConnection();

  SPI.begin();                       // Init SPI bus
  mfrc522.PCD_Init();                // Init MFRC522
  delay(4);                          // Optional delay. Some board do need more time after init to be ready, see Readme
  mfrc522.PCD_DumpVersionToSerial(); // Show details of PCD - MFRC522 Card Reader details
  Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));

  setLight(RESET);
}

void loop()
{
  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  if (!mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }

  int idLen = 4;
  uint8_t uidArray[idLen] = {0};

  if (getID(uidArray, idLen) != 0)
  {

    uint8_t derivedKey[MFRC522::MF_KEY_SIZE]{0};

    getKey(derivedKey, MFRC522::MF_KEY_SIZE, uidArray);

    Serial.println();

    dump_byte_array(derivedKey, MFRC522::MF_KEY_SIZE);
    Serial.println();

    Serial.print("Card detected, UID: ");
    dump_byte_array(uidArray, idLen);

    Serial.println();

    // Try the known default keys
    MFRC522::MIFARE_Key key; // {0x76, 0x92, 0x44, 0x8D, 0x63, 0xA2};

    for (byte i = 0; i < MFRC522::MF_KEY_SIZE; i++)
      key.keyByte[i] = derivedKey[i];

    byte JMBAG[16 + 2];

    read_block(&key, JMBAG);

    if (sendMessage(JMBAG, 16))
    {
      setLight(POSITIVE);
      play(1);
    }
    else
    {
      setLight(NEGATIVE);
      play(0);
    }

    setLight(RESET);
  }
}
