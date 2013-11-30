#include "module.h"

struct M {

    char* delim;
    char* get_delim () const { return delim; }
    void set_delim (char* v) { delim = v; }

    M (){
        delim = ":";
    }

    int set (const char* key, const char* val) {
        std::cout << "export " << key << "=\"" << val << "\";\n";
        return 0;
    }

    int append_path(const char* key, const char* path) {
        return update_path( APPEND, key, path);
    }
    int prepend_path(const char* key, const char* path) {
        return update_path( PREPEND, key, path);
    }
    int remove_path(const char* key, const char* path) {
        return update_path( REMOVE, key, path);
    }

    int update_path( PathAction action, const char* key, const char* path) {
        char *token;
        std::vector<std::string> vec_paths;

        char *cur_env = getenv (key);
        token = strtok( cur_env, delim );

        while( token != NULL ){
            vec_paths.push_back(token);
            token = strtok( NULL, delim );
        }

        for ( int i = 0; i < vec_paths.size(); ++i){
            std::cout << vec_paths[i] << "\n";
        }
    }
};


int main(int argc, char *argv[]) {

    int error;
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    using namespace luabridge;
    getGlobalNamespace (L)
        .beginClass <M> ("M")
            .addConstructor <void (*) (void)> ()
            .addProperty ("delim", &M::get_delim, &M::set_delim) //FIXME
            .addFunction ("set", &M::set)
            .addFunction ("append_path", &M::append_path)
            .addFunction ("prepend_path", &M::prepend_path)
            .addFunction ("remove_path", &M::remove_path)
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
