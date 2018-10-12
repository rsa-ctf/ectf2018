; Hello everyone and welcome to revme0 reversing challange!
; This might probably be your first reversing challenge, so we will quickly cover assembly language basics before going further. 
; 
; 1. Most of our machines use Intel processors. So, we will have a peek at Intel Assembly Language. 
; 2. We will look at 32-bit Intel Assembly Language. 
;
; //========================32-bit Intel Assembly Basics!!============================//
;
; Look at the following disgram: 
;
; 1. A Register is a memory unit on the processor chip. 
; 2. It has 8 General Purpose Registers - eax, ebx, ecx, edx, esi, edi, esp, ebp. 
; 3. 2 Special Registers - eflags and eip - you don't have to worry about these 2 right now. 
;
; 4. EACH of the 8 General Purpose Registers(GPRs) are 32-bit / 4-bytes in size.  
; 5. Along with these registers, you also have RAM / Main Memory where variables are stored. 
; 6. So, the processor is aware of 2 memory units: (i) Set of Registers  (ii) Main Memory
; 
; 7. That was about the Memory units available to the processor. Now, let us talk about Arithmetic and Logic Unit(ALU)
; 8. Every single processor has a ALU which has hardware to do computations like add, subtract, multiply, divide numbers. It will have a lot of other stuff also. 
; 
; 9. These are like a processor's legs, hands, other functional parts. But it has to have a brain to make sure all these peripheral parts function properly. 
; 10. The Brain of the Processor is the hardware known as Control Unit which makes the processor function properly. 
; 
; 11. So, our looks something like like this: 
;
;
;       --------------------------
;       | CENTRAL PROCESSING UNIT|
;       |        (Processor)     |
;       |  ====================  |
;       |  |  CONTROL UNIT    |  |
;       |  ====================  |
;       |  ====================  |
;       |  |      ALU         |  |
;       |  ====================  |
;       |  ====================  |
;       |  | Registers-on chip|  |
;       |  ====================  |
;       --------------------------
;                 |   |
;          ====================    
;          |RandomAccessMemory|                
;          |    Main Memory   |              
;          ====================
;
;
; 12. If you consider our human body, along with Processor(Brain), other functional units(Hands, Legs, etc.,), there are Input and Output Units also. 
;       If they are not there, how will you take the data in and how will you output it back? 
; 
; 13. In the same way, There are Input and Output Devices connected to it. Now, Let us look at the diagram: 
;
;
;                 --------------------------
;                 | CENTRAL PROCESSING UNIT|
;                 |        (Processor)     |
;                 |  ====================  |
;                 |  |  CONTROL UNIT    |  |
;    =======      |  ====================  |      ========
;    |Input|----->|  ====================  |----->|Output|
;    =======      |  |      ALU         |  |      ========
;                 |  ====================  |
;                 |  ====================  |
;                 |  | Registers-on chip|  |
;                 |  ====================  |
;                 --------------------------
;                           |   |
;                    ====================    
;                    |RandomAccessMemory|                
;                    |    Main Memory   |              
;                    ====================
;
;
; 14. We have our system ready. There should be some way to talk to it. Assembly Language is the ONLY  way to do it. 
; 15. Assembly Language is the only way you can talk to a processor and get your job done. 
; 16. That is why, we will extend our theory into some practical instructions. 
;
;
; //===========================Memory Instructions============================// 
; 
; >>>Registers and Main Memory has data. Let us see how data can be stored, loaded , copied etc.,  
;
; 1. mov instruction: 
;
; Syntax: mov Operand1, Operand2
;
; * Content in Operand2 is COPIED into Operand1. Right to Left - Remember! - mov doesn't move content. It copies the content. 
; * Operand1 can be a Register or a Memmory Location. 
; * Operand2 can be a Register, Memory Location or a Constant Value. 
; * Note that both operands CANNOT be Memory locations. 
;
; Eg1: mov eax, esi     : Content in esi register is copied into register eax. 
; Eg2: mov edx, 0x1234  : Constant value 0x1234 is copied into register edx.
; Eg3: mov edi, Address : The Address of the Memory Location is copied into edi. - Address is copied, not the data at the memory location. 
; Eg4: mov edi, [Address]: Here, Data at Address is copied into edi. - Look at the square brackets. 
;
; 2. push instruction: 
;
; Syntax: push Operand
;
; * There is a stack segment in the Memory Unit where variables are stored. push and pop are the instructions used to move data into and out of the Stack. 
; * That instruction pushes the Content in the Operand onto the stack. 
; * Operand can be a Register, Memory Location or a Constant Value. 
;
; 3. pop instruction: 
;
; Syntax: pop Operand
;
; * The Value at the top of the stack is moved(literally moved, not copied) into the Operand. 
; * For this reason, Operand can be a Register or a Memory Location. 
;
; Look at this diagram: 
;
;   |   94r8    | <----- esp                  |           |                             |   aaaa    | <---- esp
;   |   a134    |                             |   a134    | <----- esp                  |   a134    |
;   |   1234    |            pop edx          |   1234    |             push aaaa       |   1234    |
;   |   qwer    |      -------------------->  |   qwer    |       ------------------->  |   qwer    |
;   |   asdf    |                             |   asdf    |                             |   asdf    |
;   |   8888    |                             |   8888    |                             |   8888    |
;   |   q924    |                             |   q924    |                             |   q924    |
;   |   owee    | <---- ebp                   |   owee    | <---- ebp                   |   owee    | <---- ebp
;                                         edx = 94r8
;
; This is how stack works. 
; esp - Stack Pointer always points to the TOP of the Stack. 
; ebp - Base Pointer always points to the Base of the Stack. 
;
; NOTE that when you push or pop, ebp is not changing - it remains the same. But it is the esp which is changing. - IMPORTANT!
; You will get more clarity as you solve more challenges. 
;
; //=========================ALU Instructions============================//
;   
; There are a lot of instructions: Let us look at 2 instructions: 
;
; 1. add instruction: 
;
; Syntax: add Operand1, Operand2
;
; * Add values in Operand1 and Operand2 and stores the result in Operand1. Note, the left register is the Destination register. 
; * Operand1 can be a Register or a Memory Location because a value has to be stored there. 
; * Operand2 can be anything - a Register, Memory Location or an Constant Value. 
; 
; 2. inc instruction: 
;
; Syntax: inc Operand
;
; * Increments the Value present in the Operand.
; * Operand has to be a Register / Memory Location.  
;
;
; There are so many ALU instructions like sub, mul(Multiply), div(Divide) etc., which you will have to google and find out more. 
;
; NOTE: 
; 
; 1. Byte - 1 byte
; 2. Word - 2 bytes
; 3. Double Word / Dword - 4 bytes
; 4. QuadWord / Qword - 8 bytes. 
;
;
; With this, we will end the tutorial.  
; 
; NOTE: This was just an introduction. You will learn more as you solve more challenges.  
;
; Now, to the challenge!


section .text
    global _start

_start:

    mov eax, 0x00
    mov ebx, 0x00
    mov ecx, 0x00
    mov edx, 0x00
    mov esi, 0x00
    mov edi, 0x00

    mov eax, 0x10
    add ebx, 0x123
    or ecx, 0xabc
    xor eax, ebx
    inc eax
    dec ebx
    xor ebx, eax
    mov esi, ebx
    mov edi, eax
    and eax, ecx

; What is the ascii value in register eax at this point?

_exit:
    mov eax, 0x01
    mov ebx, 0x00
    int 0x80






    



















