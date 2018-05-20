#pragma once
#include <stdint.h>
#include <cstdio>
#include <map>

typedef std::map<void *, void **> HookedProcs;

extern FILE * g_log;
extern HookedProcs hooked;
extern void * OrgCreateFileW;