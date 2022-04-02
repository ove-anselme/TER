#ifndef __COMMUNICATION__
#define __COMMUNICATION__

typedef struct DataStructure {
    char a[32];
    int b;
    float c;
    bool d;
} DataStructure;

void Comm_Init(void);

void pair();

void send();

void receive();


#endif