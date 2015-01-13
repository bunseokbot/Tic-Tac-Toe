#include <stdio.h>

/*
 Tic-Tac-Toe Execution File Disassemble source description
 Author : bunseokbot@bob (admin@smishing.kr)
*/

int main(void) {
    
    int v1;
    
    //000513DC    8DBD 10FFFFFF   LEA EDI,[EBP-0F0]
    //000513E2    B9 3C000000     MOV ECX,3C
    //000513E7    B8 CCCCCCCC     MOV EAX,CCCCCCCC
    //000513EC    F3:AB           REP STOS DWORD PTR ES:[EDI]
    //set memory
    memset(&v1, 0xCC, 0xF0);

    //000513EE    C745 F8 0000000 MOV DWORD PTR SS:[EBP-8],0
    int v2;
    
    //000513F5    C745 EC 0000000 MOV DWORD PTR SS:[EBP-14],0
    int v3;
    
    //000513FC    C745 E0 0000000 MOV DWORD PTR SS:[EBP-20],0
    int v4;
    
    //00051403    C745 D4 0000000 MOV DWORD PTR SS:[EBP-2C],0
    //0005140A    C745 D4 0000000 MOV DWORD PTR SS:[EBP-2C],0
    int i;
    
    //00051411   /EB 09           JMP SHORT 0005141C
    //00051413   |8B45 D4         MOV EAX,DWORD PTR SS:[EBP-2C]
    //00051416   |83C0 01         ADD EAX,1
    //00051419   |8945 D4         MOV DWORD PTR SS:[EBP-2C],EAX
    for (i=0; ; ++i) {
        //0005141C    837D D4 09      CMP DWORD PTR SS:[EBP-2C],9
        //00051420    0F8D 81000000   JGE 000514A7
        if (i < 9) {
            //아 귀찮아 안해
            //그냥 화면 뿌려줌
            //총 게임에서 놓을 수 있는 횟수가 9번이므로 9번 플레이 하게 된다.
            //PUSH ECX
            //PUSH OFFSET 0005573C;%d %d
            //CALL DWORD PTR DS:[582B8];
            scanf("%d %d", &v2, &v3);
            //입력 받음
        }
    }
    
    //0005146B    FF15 B8820500   CALL DWORD PTR DS:[582B8]
    //00051471    83C4 0C         ADD ESP,0C
    //00051474    3BF4            CMP ESI,ESP
    //00051476    E8 CFFCFFFF     CALL 0005114A
    //0005114A(); <- 함수 호출함, 인자 없음
    
    //0005147B    8B45 F8         MOV EAX,DWORD PTR SS:[EBP-8]
    //0005147E    50              PUSH EAX ;v4
    //0005147F    8B4D E0         MOV ECX,DWORD PTR SS:[EBP-20]
    //00051482    51              PUSH ECX ;v3
    //00051483    8B55 EC         MOV EDX,DWORD PTR SS:[EBP-14]
    //00051486    52              PUSH EDX ;v2 거꾸로 들어가는 이유는 나중에 들어간 것이 먼저 나오는 방식이므로
    //00051487    E8 97FBFFFF     CALL 00051023
    //00051023(v2, v3, v4); <- 함수 호출함, 인자 3개 받음
    
    //0005148C    83C4 0C         ADD ESP,0C
    //0005148F    8B45 F8         MOV EAX,DWORD PTR SS:[EBP-8]
    //00051492    50              PUSH EAX
    //00051493    E8 85FCFFFF     CALL 0005111D
    //00051498    83C4 04         ADD ESP,4
    //0005149B    83F8 01         CMP EAX,1
    /*if (0005111D(v4) != 0) {
        continue;
    }*/
    
    //getchar 호출 몇번 하고 함수 종료함
    
    //사실 분석하기는 별로 안어려운데 컴파일한 사람이 디버그 모드로 컴파일해서 그냥 분석하기 귀찮았다 젠장
    
}
