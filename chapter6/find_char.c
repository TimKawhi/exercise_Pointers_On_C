/*
** Find the first occurrence in 'str' of any of the characters in 'chars' and 
** return a pointer to that location. If none are found, or if 'str' or 'chars'
** are NULL pointers, a NULL pointer is retruned. 
*/

#define NULL 0

char *find_char(char const *str, char const *chars) {

	char *cp = NULL;
	if (str != NULL && chars != NULL) {
		for (; *chars != '\0'; chars++) {
			for (cp = (char *)str; cp != '\0';cp++) {
				if (*cp == *str)
					return (char *)str;
			}
		}
	}

	return NULL;
}

