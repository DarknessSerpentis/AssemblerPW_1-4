
#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    char string[256];
    char result[256] = "\n";
    int First;
    int Len;
    char EmptyString[] = " ";
    char f[] = "%s";
    char fd[] = "%d";
    std::cout << "������� ������:";
    char outFStr[256] = "������� ������, � �������� ����� ������ �����������: ";
    char outSStr[256] = "������� ����� ���������: ";

    __asm
    {
        lea esi, string

        push esi

        lea ecx, f

        push ecx

        call scanf

        add esp, 8

        lea ebx, outFStr

        push ebx

        lea ecx, f

        push ecx

        call printf

        add esp, 8

        lea ebx, First

        push ebx

        lea ecx, fd

        push ecx

        call scanf

        add esp, 8

        lea ebx, outSStr

        push ebx

        lea ecx, f

        push ecx

        call printf

        add esp, 8

        lea ebx, Len

        push ebx

        lea ecx, fd

        push ecx

        call scanf

        add esp, 8

        lea ecx, fd
        mov ecx, -1
        dec esi

        push edx
        mov edx, First

        lea ecx, fd
        mov ecx, -1
        dec esi

        lea ebx, string
        push ebx
        dec ebx

        LengthStr :
        inc ecx
            inc ebx
            mov al, [ebx]
            cmp al, 0
            jnz LengthStr
            push ecx

            StartCopy :
        cmp First, 0
            jge LengthCopy

            mov First, 0

            LengthCopy :
            cmp Len, 0
            jl StrNoChange

            FirstBiggerLength :
        cmp First, ecx
            jg StrNoChange

            add edx, Len

            CheckLengthCopy :

        cmp edx, ecx
            jbe Later
            mov edx, ecx

            Later :
        add esp, 8
            mov ecx, -1
            dec esi

            lea esi, [string]
            lea edi, [result]
            push edi
            dec esi

            mov edx, First

            Write :
        inc esi
            inc ecx
            cmp ecx, edx
            jne Write

            add edx, Len

            ContinueWrite :
        inc ecx
            lodsb
            stosb
            cmp ecx, edx
            jne ContinueWrite

            jmp End

            StrNoChange :
        add esp, 8
            mov ecx, -1
            dec esi
            lea esi, [EmptyString]
            lea edi, [result]
            push edi

            ContinueNoChange :
        lodsb
            stosb
            cmp al, 0
            jnz ContinueNoChange

            End :
        pop edi
            pop esi
    }
    std::cout << "���������: ";
    std::cout << result;
}

