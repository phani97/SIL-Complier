FREE1:
PUSH BP
MOV BP,SP
PUSH R0
PUSH R0
MOV R0, BP
MOV R1, 3
SUB R0, R1
MOV R5,[R0]
//OUT R5
MOV R1,BP
MOV R0,1
ADD R1,R0
MOV [R1],R5
//MOV R4,[96]
//OUT R4
//HALT
L4:
MOV R1,BP
MOV R0,1
ADD R1,R0
MOV R0,[R1]
//OUT R0
MOV R1 , -1
//MOV R2,[R0]
//OUT R2
NE R0,R1
//OUT R0 
JZ R0 , L5

MOV R1,BP
MOV R0,1
ADD R1,R0
MOV R0,[R1]
MOV R2,[R1]

MOV R2, [R2]

MOV R1,BP
MOV R0,1
ADD R1,R0
MOV [R1],R2


JMP L4
L5:

MOV R3,[256]

MOV R0, BP
MOV R1, 3
SUB R0, R1
MOV R0,[R0]
MOV [R0],R3

MOV R0, BP
MOV R1, 3
SUB R0, R1
MOV R4,[R0]
MOV [256],R4

//OUT R4//

MOV R1,BP
MOV R2,2
SUB R1,R2
MOV R5,-1
MOV [R1],R5

POP R0
POP R0
MOV BP,[SP]
POP R0
RET