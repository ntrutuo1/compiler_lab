#ifndef __SCANNER_H__
#define __SCANNER_H__

#include "token.h"
#include "charcode.h"

#define MAX_IDENT_LEN 15

// Các biến toàn cục được dùng trong scanner.c
extern int lineNo;
extern int colNo;
extern int currentChar;

// Mảng định nghĩa loại ký tự
extern CharCode charCodes[];

// Các hàm xử lý ký tự
void skipBlank(void);
void skipComment(void);

// Các hàm đọc token
Token* readIdentKeyword(void);
Token* readNumber(void);
Token* readConstChar(void);
Token* getToken(void);

// Hàm in token
void printToken(Token *token);

// Hàm scan toàn bộ file
int scan(char *fileName);

#endif
