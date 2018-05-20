#include "globals.h"

FILE * g_log = nullptr;
HookedProcs hooked{};
void * OrgCreateFileW = nullptr;