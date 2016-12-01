#pragma once

class AES
{
public:


    AES(unsigned char* key);
    unsigned char* encrypt(unsigned char* plaintext);
    unsigned char* decrypt(unsigned char* ciphertext);

    void print(unsigned char* state);
    void print(unsigned char state[][4]);

private:
    static unsigned char sbox[256];
    static unsigned char invsbox[256];

    unsigned char w[11][4][4];                  //expanded key
    unsigned char key[16];

    void ByteSub(unsigned char state[][4]);
    void ShiftRow(unsigned char state[][4]);
    void MixColumn(unsigned char state[][4]);
    void AddRoundKey(unsigned char state[][4],unsigned char k[][4]);

    void InvByteSub(unsigned char state[][4]);
    void InvShiftRow(unsigned char state[][4]);
    void InvMixColumn(unsigned char state[][4]);

    void KeyExpansion(unsigned char* key, unsigned char w[][4][4]);
    unsigned char FFmul(unsigned char a, unsigned char b);           //multiplication in finite field GF(2^8)
};
