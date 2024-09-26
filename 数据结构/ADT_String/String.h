//
// Created by WAHAHA on 2023/10/19.
//

#ifndef ADT_STRING_STRING_H
#define ADT_STRING_STRING_H

#define bool int
#define true 1
#define false 0

#define INIT_CAPACITY 20

// 堆分配存储
typedef struct String {
    char *ch;
    int length;
    int capacity;
} String, *StringPtr;

// make , expand capacity and destroy
StringPtr make_empty_string(void);
bool expand_string(StringPtr s);
bool destroy_string(StringPtr s);

// check status
bool is_empty_string(StringPtr s);
bool is_full_string(StringPtr s);
int length_string(StringPtr s);
int capacity_string(StringPtr s);

// String & String operation
StringPtr assign_string(StringPtr s, char *ch, int length);
StringPtr copy_string(StringPtr dest, StringPtr s);
StringPtr concat_string(StringPtr s1, StringPtr s2);
StringPtr substring_string(StringPtr s, int pos, int len);
StringPtr insert_string(StringPtr dest, int pos, StringPtr src);

// String & char* operation
StringPtr copy_string_from_char(StringPtr src, char *ch);
StringPtr concat_string_from_char(StringPtr s1, char *ch);
StringPtr insert_string_from_char(StringPtr src, int pos, char *ch);

char* to_char_array(StringPtr s);

// String & char operation
StringPtr insert_at(StringPtr src, int pos, char ch);
StringPtr delete_string(StringPtr src, int pos, int len);

// match operation
// return the index of all matched substring
int *index_of(StringPtr str, StringPtr p);
int *index_of_KMP(StringPtr str, StringPtr p);
void get_next(StringPtr patt, int *next);

// IO operation
void print_string(StringPtr s);
char char_at(StringPtr s, int pos);

#endif //ADT_STRING_STRING_H
