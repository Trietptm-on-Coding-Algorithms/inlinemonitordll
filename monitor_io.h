#pragma once

#include <windows.h>
#include <map>

typedef std::map<void *, void *> HookingTarget;

HookingTarget & getTargetsIO();