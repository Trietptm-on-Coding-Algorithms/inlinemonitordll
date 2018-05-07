#include "monitor_io.h"

#include <mutex>

using namespace std;


HANDLE WINAPI MyCreateFileW(
    __in      LPCWSTR lpFileName,
    __in      DWORD dwDesiredAccess,
    __in      DWORD dwShareMode,
    __in_opt  LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    __in      DWORD dwCreationDisposition,
    __in      DWORD dwFlagsAndAttributes,
    __in_opt  HANDLE hTemplateFile)
{
    auto targets = getTargetsIO();
    auto original = reinterpret_cast < decltype(MyCreateFileW) * >
                    (targets[reinterpret_cast<void *>(MyCreateFileW)]);
    HANDLE result = original(lpFileName, dwDesiredAccess, dwShareMode,
                             lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes,
                             hTemplateFile);

    return result;
}

HookingTarget & getTargetsIO()
{
    static HookingTarget hookingTargets{};
    static mutex criticalProc{};

    lock_guard<mutex> criticalProcLock(criticalProc);

    if (!hookingTargets.empty()) {
        return hookingTargets;
    }

    hookingTargets[reinterpret_cast<void *>(MyCreateFileW)] =
        reinterpret_cast<void *>(CreateFileW);

    return hookingTargets;
}