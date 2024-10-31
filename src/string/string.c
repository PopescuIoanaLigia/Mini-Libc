// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	const char *s;
	char *d;
	for( d = destination, s = source; *s != '\0'; d++, s++ )
	{
		*d = *s;
	}
	*d = '\0';
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	const char *s;
	char *d;
	for( d = destination, s = source; *s != '\0' && len != 0 ; d++, s++ )
	{
		*d = *s;
		len--;
	}
	while( len > 0 )
	{
		*d = '\0';
		d++;
		len--;
	}
	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	const char *s;
	char *d = destination;
	while( *d != '\0' )
		d++;
	for( s = source; *s != '\0' ; s++, d++ )
	{
		*d = *s;
	}
	*d = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	const char *s;
	char *d = destination;
	while( *d != '\0' )
		d++;
	for( s = source; *s != '\0' && len ; s++, d++, len-- )
	{
		*d = *s;
	}
	*d = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	const char *s1 = str1;
	const char *s2 = str2;
	while( *s1 == *s2 && *s1 != '\0' && *s2 != '\0')
	{
		s1++;
		s2++;
	}
	if( *s1 == '\0' && *s2 == '\0' )
		return 0;
	else
		return *s1 - *s2;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	const char *s1 = str1;
	const char *s2 = str2;
	while( *s1 == *s2 && *s1 != '\0' && *s2 != '\0' && len)
	{
		s1++;
		s2++;
		len--;
	}
	if( len == 0 )
		return 0;
	else
		return *s1 - *s2;
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
	/* TODO: Implement strchr(). */
	const char *s = str;
	while( *s )
	{
		if( *s == (char)c )
			return (char *)s;
		s++;
	}

	if (c == '\0') {
        return (char *)s;
    }
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	const char *s = str;
	char *ret = NULL;
	while( *s )
	{
		if( *s == (char)c )
			ret = (char *)s;
		s++;
	}

	if (c == '\0') {
        return (char *)s;
    }

	return ret;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	const char *h = haystack;
	const char *n = needle;

	if (*needle == '\0') {
        return (char *)haystack;
    }

    for (; *h != '\0'; h++) {
        const char *h1 = h;
		n = needle;
        while (*h1 != '\0' && *n != '\0' && *h1 == *n) {
            h1++;
            n++;
        }

        if (*n == '\0') {
            return (char *)h;
        }
    }
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	const char *h = haystack;
	const char *n = needle;
	char *ret = NULL;

	if (*needle == '\0') {
        return (char *)haystack;
    }

    for (; *h != '\0'; h++) {
        const char *h1 = h;
		n = needle;
        while (*h1 != '\0' && *n != '\0' && *h1 == *n) {
            h1++;
            n++;
        }

        if (*n == '\0') {
            ret = (char *)h;
        }
    }

    return ret;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	char *d = (char *)destination;
    const char *s = (const char *)source;

    for (size_t i = 0; i < num; i++) {
        d[i] = s[i];
    }
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
    char *d = (char *)destination;
    const char *s = (const char *)source;

    if ( d < s ) {
        for ( size_t i = 0; i < num; i++ ) {
            d[i] = s[i];
        }
    } else {
        for ( size_t i = num; i > 0; i-- ) {
            d[i - 1] = s[i - 1];
        }
    }

    return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	const unsigned char *p1 = (const unsigned char *)ptr1;
    const unsigned char *p2 = (const unsigned char *)ptr2;

    for ( ; num; p1++, p2++, num-- ) {
        if ( *p1 != *p2 ) {
            return *p1 - *p2;
        }
    }

    return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	unsigned char *s = (unsigned char *)source;
	unsigned char c = (unsigned char)value;

	for( ; num; s++, num--)
	{
		*s = c;
	}
	return source;
}
