#include "module.h"
#include "lua_class.h"

int main(int argc, char *argv[]) {

    int error;
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

	using namespace luabridge;
    getGlobalNamespace (L)
        .beginClass <M> ("M")
            .addConstructor <void (*) (void)> ()
            .addFunction ("set", &M::set)
            .addFunction ("unset", &M::unset)
            .addFunction ("append_path", &M::append_path)
            .addFunction ("prepend_path", &M::prepend_path)
            .addFunction ("remove_path", &M::remove_path)
            .addFunction ("is_loaded", &M::is_loaded)
            .addFunction ("sysinfo", &M::sysinfo)
        .endClass ();

    error = luaL_loadfile(L, argv[1])||
            lua_pcall(L, 0, LUA_MULTRET, 0);;
    if (error) {
        fprintf(stderr, "%s", lua_tostring(L, -1));
        lua_pop(L, 1);  /* pop error message from the stack */
    }

    lua_close(L);
    return 0;
}
