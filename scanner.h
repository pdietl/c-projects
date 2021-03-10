#ifndef SCANNER_H
#define SCANNER_H

/* VERSION 1.3
 *
 * scanner.h - public interface to scanner.c, the scanner module
 */

int readInt(FILE *);
double readReal(FILE *);
char readChar(FILE *);
char readRawChar(FILE *);
char *readString(FILE *);
char *readToken(FILE *);
char *readLine(FILE *);
int stringPending(FILE *);

#endif
