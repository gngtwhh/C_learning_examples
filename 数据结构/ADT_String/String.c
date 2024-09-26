//
// Created by WAHAHA on 2023/10/19.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "String.h"

// make , expand capacity and destroy
StringPtr make_empty_string(void) {
    StringPtr s = (StringPtr) malloc(sizeof(String));
    if (s == NULL) {
        printf("malloc failed!\n");
        exit(1);
    }
    s->ch = (char *) malloc(sizeof(char) * INIT_CAPACITY);
    if (s->ch == NULL) {
        printf("malloc failed!\n");
        exit(1);
    }
    s->length = 0;
    s->capacity = INIT_CAPACITY;
    return s;
}

bool expand_string(StringPtr s) {
    char *temp = (char *) realloc(s->ch, sizeof(char) * s->capacity * 2);
    if (NULL == temp) {
        printf("realloc failed!\n");
        exit(1);
    }
    s->ch = temp;
    s->capacity *= 2;
    return true;
}

bool destroy_string(StringPtr s) {
    free(s->ch);
    free(s);
    return true;
}

// check status
bool is_empty_string(StringPtr s) {
    return s->length == 0 ? true : false;
}

bool is_full_string(StringPtr s) {
    return s->length == s->capacity ? true : false;
}

int length_string(StringPtr s) {
    return s->length;
}

int capacity_string(StringPtr s) {
    return s->capacity;
}

// String & String operation
StringPtr assign_string(StringPtr s, char *ch, int length) {
    while (capacity_string(s) < length) {
        expand_string(s);
    }
    for (int i = 0; i < length; ++i) {
        s->ch[i] = ch[i];
    }
    s->length = length;
    return s;
}

StringPtr copy_string(StringPtr dest, StringPtr s) {
    return assign_string(dest, s->ch, s->length);
}

StringPtr concat_string(StringPtr s1, StringPtr s2) {
    while (capacity_string(s1) < length_string(s1) + length_string(s2)) {
        expand_string(s1);
    }
    int origin_length = length_string(s1);
    for (int i = 0; i < length_string(s2); ++i) {
        s1->ch[origin_length + i] = s2->ch[i];
    }
    s1->length += s2->length;
    return s1;
}

StringPtr substring_string(StringPtr s, int pos, int len) {
    // pos为逻辑下标,从1开始,这里转为数组下标
    pos -= 1;

    if (pos < 0 || pos >= length_string(s) || len < 0 ||
        len > length_string(s) - pos) {
        printf("substring failed!\n");
        return NULL;
    }
    StringPtr sub = make_empty_string();
    while (capacity_string(sub) < len) {
        expand_string(sub);
    }
    for (int i = 0; i < len; ++i) {
        sub->ch[i] = s->ch[pos + i];
    }
    sub->length = len;
    return sub;
}

StringPtr insert_string(StringPtr dest, int pos, StringPtr src) {
    // pos为逻辑下标,从1开始,这里转为数组下标
    pos -= 1;

    if (pos < 0 || pos >= length_string(dest)) {
        printf("insert failed!\n");
        return NULL;
    }
    while (capacity_string(dest) < length_string(dest) + length_string(src)) {
        expand_string(dest);
    }
    dest->length += length_string(src);
    int expanded_length = length_string(dest);
    for (int i = length_string(src) - 1, j = 0; i >= 0; --i, ++j) {
        dest->ch[expanded_length - 1 - j] = dest->ch[pos + i];
    }
    for (int i = 0; i < length_string(src); ++i) {
        dest->ch[pos + i] = src->ch[i];
    }
    return dest;
}

// String & char* operation
StringPtr copy_string_from_char(StringPtr src, char *ch) {
    return assign_string(src, ch, strlen(ch));
}

StringPtr concat_string_from_char(StringPtr s1, char *ch) {
    //注意内存泄漏
    StringPtr s2 = make_empty_string();
    copy_string_from_char(s2, ch);
    concat_string(s1, s2);
    destroy_string(s2);
    return s1;
}

StringPtr insert_string_from_char(StringPtr src, int pos, char *ch) {
    // pos为逻辑下标,从1开始,这里转为数组下标
    pos -= 1;

    //注意内存泄漏
    StringPtr s = make_empty_string();
    copy_string_from_char(s, ch);
    insert_string(src, pos, s);
    destroy_string(s);
    return src;
}

char *to_char_array(StringPtr s) {
    char *ch = (char *) malloc(sizeof(char) * (length_string(s) + 1));
    if (ch == NULL) {
        printf("malloc failed!\n");
        exit(1);
    }
    for (int i = 0; i < length_string(s); ++i) {
        ch[i] = s->ch[i];
    }
    ch[length_string(s)] = '\0';
    return ch;
}

// String & char operation
StringPtr insert_at(StringPtr src, int pos, char ch) {
    // pos为逻辑下标,从1开始,这里转为数组下标
    pos -= 1;

    if (pos < 0 || pos >= length_string(src)) {
        printf("insert failed!\n");
        return NULL;
    }
    while (capacity_string(src) < length_string(src) + 1) {
        expand_string(src);
    }
    src->length += 1;
    int expanded_length = length_string(src);
    for (int i = expanded_length - 1; i > pos; --i) {
        src->ch[i] = src->ch[i - 1];
    }
    src->ch[pos] = ch;
    return src;
}

StringPtr delete_string(StringPtr src, int pos, int len) {
    // pos为逻辑下标,从1开始,这里转为数组下标
    pos -= 1;

    if (pos < 0 || pos >= length_string(src) || len < 0 ||
        len > length_string(src) - pos) {
        printf("delete failed!\n");
        return NULL;
    }
    for (int i = pos; i < length_string(src) - len; ++i) {
        src->ch[i] = src->ch[i + len];
    }
    src->length -= len;
    return src;
}

// match operation
// return the index of all matched substring
int *index_of(StringPtr str, StringPtr p) {
    int *index = (int *) malloc(sizeof(int) * length_string(str));
    if (index == NULL) {
        printf("malloc failed!\n");
        exit(1);
    }
    int index_length = 0;
    for (int i = 0; i < length_string(str); ++i) {
        if (str->ch[i] == p->ch[0]) {
            int j = 0;
            for (; j < length_string(p); ++j) {
                if (str->ch[i + j] != p->ch[j]) {
                    break;
                }
            }
            if (j == length_string(p)) {
                index[index_length++] = i + 1;
            }
        }
    }
    index[index_length] = -1;
    return index;
}

int *index_of_KMP(StringPtr str, StringPtr p) {
    int len1 = length_string(str), len2 = length_string(p);
    int *next = (int *) malloc(sizeof(int) * len2);
    int *index = (int *) malloc(sizeof(int) * len2);
    int index_length = 0;

    // 求next数组
    get_next(p, next);

    // KMP匹配
    int j = 0;
    for (int i = 0; i < len1; ++i) {
        while (j > 0 && str->ch[i] != p->ch[j])
            j = next[j];
        if (str->ch[i] == p->ch[j])
            ++j;
        if (j == len2)
            index[index_length++] = i - len2 + 2;
    }
    // 末尾标记
    index[index_length] = -1;
    // 释放内存
    free(next);
    return index;
}

void get_next(StringPtr patt, int *next) {
    int j = 0;
    next[1] = 0;
    int len = length_string(patt);
    char *p = patt->ch;
    for (int i = 2; i <= len; ++i) {
        while (j > 0 && p[i - 1] != p[j])
            j = next[j];
        if (p[i - 1] == p[j])
            j++;
        next[i] = j;
    }
}

// IO operation
void print_string(StringPtr s) {
    for (int i = 0; i < length_string(s); ++i) {
        printf("%c", s->ch[i]);
    }
    printf("\n");
}

char char_at(StringPtr s, int pos) {
    // pos为逻辑下标,从1开始,这里转为数组下标
    pos -= 1;
    if (pos < 0 || pos >= length_string(s)) {
        printf("char_at failed!\n");
        return -1;
    }
    return s->ch[pos];
}