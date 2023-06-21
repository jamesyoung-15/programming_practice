#include "sha1.h"
#include "base64.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>


int main()
{
    //  WebSocket key generated done by combining received web socket key with code to create magic string, then hash it with SHA-1 and return base64 encoding of the hash

    //  Create new SHA1 info and hash it
	sha1nfo s;
	uint32_t a;
	sha1_init(&s);
	char code[] = "258EAFA5-E914-47DA-95CA-C5AB0DC85B11\0";
    // char clientKey[] = "dGhlIHNhbXBsZSBub25jZQ=="; 
    char clientKey[] = "dGhlIHNhbXBsZSBub25jZQ==";
    char magicString[strlen(code)+strlen(clientKey)];
    sprintf(magicString, "%s%s", clientKey,code);
	sha1_write(&s, magicString, strlen(magicString));
    uint8_t * b = sha1_result(&s);

    // Store result, result is in hex and has 160 bits
    char string_result[40]={0};
    for(int i=0;i<20;i++)
    {
        char temp[5]={0};
        sprintf(temp,"%02x",b[i]);
        strcat(string_result,temp);
    }
    // Convert from hex to binary, then binary to base64
    char  binary_result[160]={0};  
    hexToBin(string_result,binary_result);
    char base64_result[40]={0};
    binToBase64(binary_result,base64_result);

    printf("\nInput key: %s\n",magicString);
    printf("\nSHA-1 Hash: %s\n",string_result);
    printf("\nHash in Binary: %s\n",binary_result);
    printf("\nBase64 of hash: %s\n\n",base64_result);

    char response[300]={0};
	sprintf(response,"HTTP/1.1 101 Switching Protocols\r\nUpgrade: websocket\r\nConnection: Upgrade\r\nSec-WebSocket-Accept: %s",base64_result);
    printf("%li",strlen(response));
    printf("\n%s\n\n",response);

}