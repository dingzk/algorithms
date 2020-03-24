#ifndef _UNICODE_H_
#define _UNICODE_H_

#define UNICODE_MAIN

#ifdef __cplusplus
extern "C" {
#endif
int utf8_decode(const char *utf8, unsigned bytes, unsigned short *ucs2, unsigned words);
int utf8_encode(const unsigned short *ucs2, unsigned words, char *utf8, unsigned bytes);

int utf8_normalize(unsigned char *utf8, unsigned bytes);

#ifdef __cplusplus
}
#endif
#endif
