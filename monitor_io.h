#pragma once

#include <windows.h>
#include <tuple>
#include <vector>

typedef std::vector < std::tuple<void *, void *> > HookingTarget;

HookingTarget & getTargetsIO();
