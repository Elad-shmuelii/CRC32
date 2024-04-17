#include <iostream>
#include <string>
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 

u_int32_t crc32(const char*s,size_t n){
        u_int32_t crc = 0xFFFFFFFF;

        for (size_t i=0;i<n;i++){
                char ch=s[i];
                for(size_t j=0;j<8;j++){
                        u_int32_t b=(ch^crc)&1;
                        crc>>=1;
                        if(b){
                                crc=crc^0XEDB88321;
                        }
                        ch>>=1;
                }
        }
        return ~crc;
}
