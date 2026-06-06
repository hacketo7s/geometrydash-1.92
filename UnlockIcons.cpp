#include "MinHook.h"
#include <Windows.h>

namespace gd {
    class IconType {};
    class GameManager {};
}

typedef bool(__thiscall* tIconUnlocked)(gd::GameManager*, int, gd::IconType);
typedef bool(__thiscall* tColorUnlocked)(gd::GameManager*, int, bool);

tIconUnlocked oIsIconUnlocked = nullptr;
tColorUnlocked oIsColorUnlocked = nullptr;

uintptr_t gameManagerIsIconUnlockedOffset = 0x66b10;
uintptr_t gameManagerIsColorUnlockedOffset = 0x66df0;
uintptr_t gdBase;

// MSVC doesn't support using __thiscall directly. So you have to replicate it by using it __fastcall.
// This works because __thiscall passes the pointer to the object instance to the ecx register and everything else onto the stack
// While __fastcall passes argument1 and argument2 into the ecx and edx registers respectively
// We don't need the edx register but __fastcall requires that you pass it so we pass in a dummy void* pointer

bool __fastcall hkUnlockIcons(gd::GameManager* self, void* edx, int key, gd::IconType type) {
    oIsIconUnlocked(self, key, type); 
    
    return true; 
}

bool __fastcall hkUnlockColors(gd::GameManager* self, void* edx, int id, bool isSecondary) {
    oIsColorUnlocked(self, id, isSecondary);
    
    return true;
}

void SetupHook() {
    MH_Initialize();
    gdBase = reinterpret_cast<uintptr_t>(GetModuleHandleA(nullptr));

    LPVOID targetAddress = reinterpret_cast<LPVOID>(gdBase + gameManagerIsIconUnlockedOffset);
    MH_CreateHook(targetAddress, reinterpret_cast<LPVOID>(&hkUnlockIcons), reinterpret_cast<LPVOID*>(&oIsIconUnlocked));

    targetAddress = reinterpret_cast<LPVOID>(gdBase + gameManagerIsColorUnlockedOffset);
    MH_CreateHook(targetAddress, reinterpret_cast<LPVOID>(&hkUnlockColors), reinterpret_cast<LPVOID*>(&oIsColorUnlocked));
    
    MH_EnableHook(MH_ALL_HOOKS);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        SetupHook();
    }
    return TRUE;
}
