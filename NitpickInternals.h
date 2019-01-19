#pragma once

#include "skse/PluginAPI.h"
#include "skse/skse_version.h"
#include "skse/GameTypes.h"
#include "skse/GameForms.h"

#include "[Libraries]/SME Sundries/MemoryHandler.h"

#include <fstream>
#include <string>
#include <list>

using namespace SME;
using namespace SME::MemoryHandler;

extern IDebugLog		gLog;

void StartPickingNit(void);

_DeclareMemHdlr(INICollectionLoadSetting, "removes the 0x100-char limit placed on string settings");