unsigned char * pngCompress(unsigned char *data, int data_len, int *out_len, int quality);

#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STBIW_ZLIB_COMPRESS pngCompress
#include "stb_image_write.h"

unsigned char * pngCompress(unsigned char *data, int data_len, int *out_len, int quality) {

}