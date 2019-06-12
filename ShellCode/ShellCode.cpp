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
			printf("%02x ", data);
		}
		printf("\n");
	}
}