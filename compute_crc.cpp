#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string> 
#include <iostream>
#include <chrono>
using namespace std;
uint32_t crc32_update(uint32_t crc , uint8_t data){
    static const uint32_t crc32_polynomial = 0x4C11DB7;
    crc ^= (data << 24);

    for (int i = 0; i<8 ; i++){
        if (crc & 0x80000000){
            crc = (crc << 1) ^ crc32_polynomial;
        }
        else{
            crc = crc << 1;
        }
    }
    return crc;
}
uint32_t computeCRC32(string str){
    uint32_t crc = 0xFFFFFFFF;
    uint8_t* data = (uint8_t*)str.c_str();
    for (size_t i = 0; i < str.length();i++){
        crc=crc32_update(crc,data[i]);
    }
    crc = ~crc;
    return crc;
}
