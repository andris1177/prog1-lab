/*
Írj függvényt, mely átvesz egy stringet, és az abban található szavakat megfordítja! A szavak szóközzel vannak elválasztva egymástól. 
A függvény neve legyen reverse_words. A paraméterként kapott stringet helyben módosítsd, ne készíts róla másolatot!

Például: "a teve iszik" -> "a evet kizsi"

Ha a függvényt parancssorból teszteled, figyelj arra, hogy ha ott beírsz egy szöveget, majd Enter-t ütsz, a szöveg végén ott lesz az újsor karakter is. 
Az alábbi tesztelő main függvény eltávolítja az újsor karaktert a beolvasott sztringből.


#include <stdio.h>
#include <string.h>
	
enum { BUFFERSIZE = 128 };

int main(void) {
	char buffer[BUFFERSIZE], *c;
	fgets(buffer, BUFFERSIZE, stdin);   // read from stdin until newline
	c = strchr(buffer, '\n');           // replace newline with '\0'
	if (c != NULL)
		*c = '\0';
	reverse_words(buffer);              // call user function
	printf("%s", buffer);               // print the modified string
	return 0;
}
*/

#include <stdio.h>
#include <string.h>

enum { BUFFERSIZE = 128 };

void reverse_words(char str[])
{
    int end;
    int start = 0;
    for (int i = 0; i <= strlen(str); i++)
    {
        if (str[i] == ' ' || str[i] == '\0')
        {
            end = i-1;   

            while (start < end)
            {
                char temp = str[start];
                str[start] = str[end];
                str[end] = temp;
                start++;
                end--;
            }

            start = i + 1;
        }
    }
}

int main(void) 
{
	char buffer[BUFFERSIZE], *c;
	fgets(buffer, BUFFERSIZE, stdin);   // read from stdin until newline
	c = strchr(buffer, '\n');           // replace newline with '\0'
	if (c != NULL)
		*c = '\0';
	reverse_words(buffer);              // call user function
	printf("%s\n", buffer);               // print the modified string
	return 0;
}