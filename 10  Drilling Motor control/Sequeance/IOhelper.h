#ifndef IOhelper
#define IOhelper
//Match names with Arduino pin number
//Match Output
#undef PL1
#undef PL2
#undef PL3
#undef PL4

#define SOL1 2
#define SOL2 3
#define SOL3 4
#define SOL4 5
#define SOL5 6
#define M1 7
#define M2 8
#define BUZZ 9
#define PL1 10
#define PL2 11
#define PL3 12
#define PL4 48

//Match Input
#define CS1 20
#define CS2 21
#define CS3 22
#define CS4 23
#define CS5 24
#define CS6 25
#define CS7 26
#define CS8 27
#define S1 28
#define S2 29
#define S3 30
#define S4 31

#define BUTTON_RESET 40
#define BUTTON_START 41
#define BUTTON_STOP  42

//Match another name
#define CONVEYOR   M2
#define CONV CONVETOR
#define RED_LAMP    PL1
#define YELLOW_LAMP PL2
#define GREEN_LAMP  PL3
#define BLUE_LAMP   PL4

//Input
#define Read(x) digitalRead(x)

#define Read_CS1() Read(CS1)
#define Read_CS2() Read(CS2)
#define Read_CS3() Read(CS3)
#define Read_CS4() Read(CS4)
#define Read_CS5() Read(CS5)
#define Read_CS6() Read(CS6)
#define Read_CS7() Read(CS7)
#define Read_CS8() Read(CS8)
#define Read_S1()  Read(S1)
#define Read_S2()  Read(S2)
#define Read_S3()  Read(S3)
#define Read_S4()  Read(S4)

#define ON 1
#define OFF 0

#define STOP 1
#define START 0

//#define sol1(x) x ? digitalWrite(SOL1, HIGH); OutputsStatus |= 0x0001;:digitalWrite(SOL1, LOW); OutputsStatus &= ~0x0001;
//#define sol2(x) x ? digitalWrite(SOL2, HIGH); OutputsStatus |= 0x0002;:digitalWrite(SOL2, LOW); OutputsStatus &= ~0x0002;
//#define sol3(x) x ? digitalWrite(SOL3, HIGH); OutputsStatus |= 0x0004;:digitalWrite(SOL3, LOW); OutputsStatus &= ~0x0004;
//#define sol4(x) x ? digitalWrite(SOL4, HIGH); OutputsStatus |= 0x0008;:digitalWrite(SOL4, LOW); OutputsStatus &= ~0x0008;
//#define sol5(x) x ? digitalWrite(SOL5, HIGH); OutputsStatus |= 0x0010;:digitalWrite(SOL5, LOW); OutputsStatus &= ~0x0010;
//#define m1(x) x ? digitalWrite(M1, HIGH); OutputsStatus |= 0x0020;:digitalWrite(M1, LOW); OutputsStatus &= ~0x0020;
//#define m2(x) x ? digitalWrite(M2, HIGH); OutputsStatus |= 0x0040;:digitalWrite(M2, LOW); OutputsStatus &= ~0x0040;
//#define conveyor(x) x ? digitalWrite(M2, HIGH); OutputsStatus |= 0x0040;:digitalWrite(M2, LOW); OutputsStatus &= ~0x0040;
//#define conv(x) x ? digitalWrite(M2, HIGH); OutputsStatus |= 0x0040;:digitalWrite(M2, LOW); OutputsStatus &= ~0x0040;
//#define pl1(x) x ? digitalWrite(PL1, HIGH); OutputsStatus |= 0x080;}digitalWrite(PL1, LOW); OutputsStatus &= ~0x0080;
//#define pl2(x) x ? digitalWrite(PL2, HIGH); OutputsStatus |= 0x0100;:digitalWrite(PL2, LOW); OutputsStatus &= ~0x0100;
//#define pl3(x) x ? digitalWrite(PL3, HIGH); OutputsStatus |= 0x0200;:digitalWrite(PL3, LOW); OutputsStatus &= ~0x0200;
//#define pl4(x) x ? digitalWrite(PL4, HIGH); OutputsStatus |= 0x0400;:digitalWrite(PL4, LOW); OutputsStatus &= ~0x0400;

extern unsigned char Outputs[12];
extern unsigned char Sensors[12];
extern volatile unsigned int OutputsStatus;
#endif
