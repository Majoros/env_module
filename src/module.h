#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <string>

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include "LuaBridge/LuaBridge.h"
#include "LuaBridge/RefCountedPtr.h"
#include "LuaBridge/RefCountedObject.h"

enum PathAction {
    APPEND = 0,
    PREPEND,
    REMOVE
};

enum PathExists {
    LEAVE = 0,
    UPDATE
};

//typedef void (*path_action_dt)(void);
//static path_action_dt exec_action[] = {
//}
