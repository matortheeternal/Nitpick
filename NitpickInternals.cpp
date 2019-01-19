#pragma warning(disable : 4005)
#include "NitpickInternals.h"

IDebugLog gLog("Nitpick.log");

static uint32_t INI_COLLECTION_LOAD_START = 0x00AFEE53;
static uint32_t INI_COLLECTION_LOAD_END = 0x00AFEE74;

_DefineHookHdlr(INICollectionLoadSetting, INI_COLLECTION_LOAD_START);

void StartPickingNit()
{
	_MemHdlr(INICollectionLoadSetting).WriteJump();
}

static char s_GetPrivateProfileStringAuxBuffer[0x8000] = {0};		// large enough, I should think

#define _hhName	INICollectionLoadSetting
_hhBegin()
{
	_hhSetVar(Retn, INI_COLLECTION_LOAD_END);
	__asm
	{
		push    0x8000
		lea	eax, s_GetPrivateProfileStringAuxBuffer
		push	eax
		push	ecx
		lea     edx, [esp + 0x74]
		push    edx
		lea     eax, [esp + 0x38]
		push    eax
		call    ebp	// GetPrivateProfileStringA
		lea	ecx, s_GetPrivateProfileStringAuxBuffer
		jmp	[_hhGetVar(Retn)]
	}
}
