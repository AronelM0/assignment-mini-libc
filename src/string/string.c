// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
   int i;
   for ( i = 0; source[i] != '\0'; i++) {
        destination[i] = source[i];
   }
   	destination[i] = '\0';

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{	
	int i;
	for (i = 0; i < len && source[i] != '\0'; i++) {
        destination[i] = source[i];
    }

    for ( ; i < len; i++) {
        destination[i] = '\0';
    }
	return destination;
}

char *strcat(char *destination, const char *source)
{
	int i = 0;
    int j = 0;

    while (destination[i] != '\0') {
        i++;
    }

    while (source[j] != '\0') {
        destination[i] = source[j];
        i++;
        j++;
    }
    destination[i] = '\0';

    return destination;
	
}

char *strncat(char *destination, const char *source, size_t len)
{
	int i = 0;
    int j = 0; 

    while (destination[i] != '\0') {
        i++;
    }

    while (source[j] != '\0' && j < len) {
        destination[i] = source[j];
        i++;
        j++;
    }

    destination[i] = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	int i = 0;

    while (str1[i] != '\0' && str1[i] == str2[i]) 
        i++;
       
    if (str1[i] == str2[i]) 
        return 0; 
    
    else if (str1[i] < str2[i]) 
        return -1; 
 
    return 1;
	
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	int i = 0;

    while (i < len && str1[i] == str2[i] && str1[i] != '\0') {
        i++;
    }

    if (i == len) 
        return 0;
    
    if (str1[i] == str2[i])        
        return 0; 
    
    else if (str1[i] < str2[i]) 
        return -1;

    return 1; 
    
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	int i = 0;

    while (str[i] != '\0') {
        if (str[i] == c) 
            return (char *)&str[i];

        i++;
    }


    if (str[i] == c) 
        return (char *)&str[i]; 
    
    return NULL;
}

char *strrchr(const char *str, int c)
{
	char *ultima_gasire = NULL;
    int i = 0;

    // Parcurgem string-ul
    while (str[i] != '\0') {
        if (str[i] == c)         
           ultima_gasire = (char *)&str[i]; 
        
        i++;
    }


    if (str[i] == c) 
        ultima_gasire = (char *)&str[i]; 
    
    return ultima_gasire;
}

char *strstr(const char *haystack, const char *needle)
{
    int i, j;

    if (needle[0] == '\0') 
        return (char *)haystack;
    
    for (i = 0; haystack[i] != '\0'; i++) {
        for (j = 0; needle[j] != '\0'; j++) {
            if (haystack[i + j] == '\0' || haystack[i + j] != needle[j]) {
                break; 
            }
        }
        if (needle[j] == '\0') 
            return (char *)&haystack[i];      
    }

    return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
    int i, j;
    char *ultima_gasire = NULL; 

    if (needle[0] == '\0') {
        for (i = 0; haystack[i] != '\0'; i++) {
        }
        return (char *)&haystack[i];
    }

    for (i = 0; haystack[i] != '\0'; i++) {
        for (j = 0; needle[j] != '\0'; j++) {
            if (haystack[i + j] == '\0' || haystack[i + j] != needle[j]) {
                break;
            }
        }

        if (needle[j] == '\0') {
            ultima_gasire = (char *)&haystack[i];
        }
    }

    return ultima_gasire;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	char *d = (char *)destination;
    const char *s = (const char *)source;
    int i;

    for (i = 0; i < num; i++) {
        d[i] = s[i];
    }
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	char *d = (char *)destination;
    const char *s = (const char *)source;
    int i;
    if (d > s) {
        for (i = num; i > 0; i--) {
            d[i - 1] = s[i - 1];
        }
    }
    else {
        for (i = 0; i < num; i++) {
            d[i] = s[i];
        }
    }
    
    return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	const unsigned char *p1 = (const unsigned char *)ptr1;
    const unsigned char *p2 = (const unsigned char *)ptr2;
    int i;

    for (i = 0; i < num; i++) {
        if (p1[i] != p2[i]) {
            if (p1[i] < p2[i]) {
                return -1;
            } else {
                return 1;
            }
        }
    }

    return 0;
}

void *memset(void *source, int value, size_t num)
{
    unsigned char *s = (unsigned char *)source;
    unsigned char v = (unsigned char)value;
    int i;

    for (i = 0; i < num; i++) {
        s[i] = v;
    }

    return source;
}
