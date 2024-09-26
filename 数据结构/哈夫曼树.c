#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 根据字符集的大小来确定保存树的数组长度
#define CHAR_COUNT 128
#define MAX_SIZE (((CHAR_COUNT)*2-1)+(CHAR_COUNT)+1)

typedef struct {
    char ch;
    int weight;
} Code;

typedef struct {
    char ch;
    int weight;
    int parent;
    int left, right;
} HufTreeNode;
HufTreeNode HuffmanTree[MAX_SIZE];
Code *codes;
char **HuffCode;
int code_len; // 字符集大小
int already_init = 0; // 检查是否已经初始化

void select(int n, int *s1, int *s2) {
    int min;
    //找第一个最小值
    for (int i = 1; i <= n; i++) {
        if (HuffmanTree[i].parent == 0) {
            min = i;
            break;
        }
    }
    for (int i = min + 1; i <= n; i++) {
        if (HuffmanTree[i].parent == 0 &&
            HuffmanTree[i].weight < HuffmanTree[min].weight)
            min = i;
    }
    *s1 = min; //第一个最小值给s1
    //找第二个最小值
    for (int i = 1; i <= n; i++) {
        if (HuffmanTree[i].parent == 0 && i != *s1) {
            min = i;
            break;
        }
    }
    for (int i = min + 1; i <= n; i++) {
        if (HuffmanTree[i].parent == 0 &&
            HuffmanTree[i].weight < HuffmanTree[min].weight && i != *s1)
            min = i;
    }
    *s2 = min; //第二个最小值给s2
}


void create_HuffTree(Code *codes, int n) {
    printf("creating huff tree ...\n");

    int m = 2 * n - 1; // 哈夫曼树总结点数

    // 初始化森林(单独的n个结点)
    for (int i = 1; i <= n; ++i) {
        HuffmanTree[i].ch = codes[i].ch;
        HuffmanTree[i].weight = codes[i].weight;
        HuffmanTree[i].parent = 0; // 自己就是树根
    }

    // 构建哈夫曼树
    for (int i = n + 1; i <= m; ++i) {
        int s1, s2;
        select(i - 1, &s1, &s2); // 在[1,i-1]下标范围内(闭区间)查找两个最小值(权值)
        HuffmanTree[i].weight = HuffmanTree[s1].weight +
                                HuffmanTree[s2].weight; //i的权重是s1和s2的权重之和
        HuffmanTree[s1].parent = i;
        HuffmanTree[s2].parent = i;
        HuffmanTree[i].left = s1;
        HuffmanTree[i].right = s2;
    }
    printf("done...\n");
}

void create_HuffCode(int n) {
    HuffCode = (char **) malloc(sizeof(char *) * (n + 1)); // 用于保存编码表
    char *temp = (char *) malloc(sizeof(char) * n); // 临时存储当前字符的编码
    temp[n - 1] = '\0'; // 每次都从这个地方结尾---相当于向右对齐
    for (int i = 1; i <= n; ++i) {
        int start = n - 1; // 向上回溯,编码取反
        int cur = i; // 当前要进行编码的字符
        int parent = HuffmanTree[i].parent; // 当前结点的父亲
        while (parent) {
            // 检查该字符在左子树还是右子树
            if (HuffmanTree[parent].left == cur)
                temp[--start] = '0';
            else
                temp[--start] = '1';
            cur = parent; // 继续向上回溯
            parent = HuffmanTree[cur].parent;
        }
        HuffCode[i] = (char *) malloc(
                sizeof(char) * (n - start)); // (n-1)-start+1
        strcpy(HuffCode[i], temp + start);
    }
    free(temp);
}

void init() {
    //指定字符集大小
    printf("请输入字符集大小: ");
    scanf("%d", &code_len);
    int n = code_len;

    // 输入字符集
    codes = (Code *) malloc(sizeof(Code) * (n + 1));
    printf("请依次输入字符及其权值:\n");
    while (getchar() != '\n');
    for (int i = 1; i <= n; ++i) {
        while ((codes[i].ch = getchar()) == ' ' || codes[i].ch == '\n');
        scanf("%d", &codes[i].weight);
    }

    // 关键代码
    create_HuffTree(codes, n);

    // 文件操作
    // 保存哈夫曼树
    FILE *HufTreeFile = fopen("hfmTree", "wb");
    fwrite(HuffmanTree, sizeof(HufTreeNode), MAX_SIZE, HufTreeFile);
    fclose(HufTreeFile);
}

void encode() {
    int n = code_len;

    create_HuffCode(n);

    // 哈夫曼编码结果输出
    printf("哈夫曼编码结果:\n");
    for (int i = 1; i <= n; ++i)
        printf("%c | %s\n", codes[i].ch, HuffCode[i]);

    // 进行编码
    printf("请输入一行明文:");
    char str[100];
    scanf("%s", str);
    int len = strlen(str);
    char *result = (char *) malloc(sizeof(char) * (len * n + 1));
    int index = 0;
    for (int i = 0; i < len; ++i) {
        int j = 1;
        while (codes[j].ch != str[i]) ++j;
        strcpy(result + index, HuffCode[j]);
        index += strlen(HuffCode[j]);
    }
    result[index] = '\0';

    // 原文编码结果输出
    printf("编码结果:\n%s\n", result);

    // 存入文件CodeFile
    FILE *CodeFile = fopen("CodeFile", "wb");
    fwrite(result, sizeof(char), strlen(result), CodeFile);
    // fwrite(&n, sizeof(int), 1, CodeFile);
    fclose(CodeFile);

    // 释放内存
    for (int i = 1; i < n + 1; ++i) // 注意第一个指针并未分配!
        free(HuffCode[i]);
    free(HuffCode);
}

void decode() {
    // 如果已经初始化则直接从内存读取哈夫曼树
    if (already_init) {
        printf("从内存读取哈夫曼树...\n");
    } else {
        // 从文件读取哈夫曼树
        printf("从文件读取哈夫曼树...\n");
        FILE *HufTreeFile = fopen("hfmTree", "rb");
        fread(HuffmanTree, sizeof(HufTreeNode), MAX_SIZE, HufTreeFile);
        fread(&code_len, sizeof(int), 1, HufTreeFile);
        fclose(HufTreeFile);
    }

    int n = code_len;
    create_HuffCode(n);

    // 打开文件
    FILE *CodeFile = fopen("CodeFile", "rb");
    // 计算编码串长度
    fseek(CodeFile, 0, SEEK_END);
    int len = ftell(CodeFile);
    fseek(CodeFile, 0, SEEK_SET);

    // 为结果分配内存,最长不超过len
    char *result = (char *) malloc(sizeof(char) * (len + 1));
    int idx = 0;

    // 写入字符数组
    char *enc = (char *) malloc(sizeof(char) * (len + 1));
    fread(enc, sizeof(char), len, CodeFile);
    for (int i = 0; i < len;) {
        for (int j = 1; j <= n; ++j) {
            if (strncmp(enc + i, HuffCode[j], strlen(HuffCode[j])) == 0) {
                result[idx++] = codes[j].ch;
                i+= strlen(HuffCode[j]);
                break;
            }
        }
    }
    result[idx] = '\0';

    // 输出结果
    printf("解码结果:\n%s\n", result);

    // 销毁内存
    free(result);
    free(enc);
    free(HuffCode);
}

int main() {
    int ch;
    while (1) {
        printf("1:初始化    2:编码    3:解码    4:退出\n>>>");
        scanf("%d", &ch);
        if (ch == 1) {
            init();
            already_init = 1;
        } else if (ch == 2) {
            if (!already_init) {
                printf("请先初始化!\n");
                continue;
            }
            encode();
        } else if (ch == 3) {
            if (!already_init) {
                printf("请先初始化!\n");
                continue;
            }
            decode();
        } else if (ch == 4) {
            if (already_init)
                free(codes);
            break;
        } else {
            printf("输入错误!\n");
        }
    }
    return 0;
}