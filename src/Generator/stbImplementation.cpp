unsigned char * pngCompress(unsigned char *data, int data_len, int *out_len, int quality);

#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STBIW_ZLIB_COMPRESS pngCompress //Own compression function using zlib
#include "stb_image_write.h"
#include "zlib.h"

unsigned char * pngCompress(unsigned char *data, int data_len, int *out_len, int quality) {
    unsigned long size = compressBound(data_len);
    unsigned char * out = new unsigned char[size];

    if (compress(out, &size, data, data_len) == Z_OK) {
        if (out_len) *out_len = size;
        return out;
    } else {
        *out_len = 0;
        delete out;   
        return NULL;
    }
}