#include "lua_class.h"
#include "module.h"


M::M (void){
    path_action = UPDATE;
    path_delim = ":";

    struct utsname sys_info_tmp;
    uname(&sys_info_tmp);
    sys_info["SYSNAME"] = sys_info_tmp.sysname;
    sys_info["NODENAME"] = sys_info_tmp.nodename;
    sys_info["RELEASE"] = sys_info_tmp.release;
    sys_info["VERSION"] = sys_info_tmp.version;
    sys_info["MACHINE"] = sys_info_tmp.machine;
    sys_info["DOMAINNAME"] = sys_info_tmp.domainname;

    get_loaded();
}

const char *M::sysinfo(const char *type){
    if(sys_info.find(type) == sys_info.end()){
        return "";
    }
    return sys_info[type].c_str();
}

void M::set(const char* key, const char* val) {
    env_vars[key] = val;
}

void M::unset(const char* key) {
    return;
}

int M::is_loaded(const char* modules) {
    return loaded(IS_LOADED, modules);
}
int M::not_loaded(const char* modules) {
    return loaded(NOT_LOADED, modules);
}
int M::required(const char* modules) {
    return loaded(REQUIRED, modules);
}
int M::conflicts(const char* modules) {
    return loaded(CONFLICTS, modules);
}

int M::loaded( Loaded_Action action, const char* modules) {

    char *token;
    char *str

    str = new char [strlen(modules)];
    strncpy( str, modules, strlen(modules));

    token = strtok( str, "," );
    while( token != NULL ){
        // Loop through loaded vecotr and do your checks
        // depending on the action passed in.
        if(action == IS_LOADED or action == REQUIRED){
        }
        else if( action == NOT_LOADED or action == CONFLICTS){
        }
        token = strtok( NULL, ",");
    }
    delete str;
    return 1;
}


int M::append_path(const char* key, const char* path) {
    return update_path( APPEND, key, path);
}

int M::prepend_path(const char* key, const char* path) {
    return update_path( PREPEND, key, path);
}

int M::remove_path(const char* key, const char* path) {
    get_paths(key);
    for ( unsigned int i = 0; i < env_paths[key].size(); ++i){
        if( path == env_paths[key][i] ){
            env_paths[key].erase(env_paths[key].begin() + i);
        }
    }
}

int M::update_path(PathAction action, const char* key, const char* path) {
    get_paths(key);
    int replace = 0;
    for ( unsigned int i = 0; i < env_paths[key].size(); ++i){
        if( env_paths[key][i] == path ){
            if( path_action == LEAVE){
                // path already there so simply leaving it alone
                return 0;
            }else if( path_action == UPDATE ){
                // path already there removing so we can update it
                // with out having duplicates.
                // not breaking so we can remove pre-existing
                // duplicates as well.
                std::cout << "Removing: " << env_paths[key][i] << "\n";
                env_paths[key].erase(env_paths[key].begin() + i);
                replace = 1;
                //since we are removing this we want to check the value that
                //is now in its place.
                i--;
            }
            else{
                // Errr.... #FIXME: add error handling
            }
        }
    }

}

void M::get_paths(const char* key) {

    int replace = 1;
    if (env_paths.find(key) == env_paths.end()){
        return;
    }

    std::vector<std::string> vec_paths;
    char *token;
    char *str;

    char *cur_env = getenv (key);

    str = new char [strlen(cur_env)];
    strncpy( str, cur_env, strlen(cur_env));

    token = strtok(str, path_delim );
    while( token != NULL ){
        vec_paths.push_back(token);
        token = strtok( NULL, path_delim );
    }
    env_paths[key] = vec_paths;
    delete str;
}

void M::get_loaded() {

    char *token;
    char *loaded_modules;

    char *cur_env = getenv("LOADED_MODULES");

    loaded_modules = new char [strlen(cur_env)];
    strncpy( loaded_modules, cur_env, strlen(cur_env));

    token = strtok(loaded_modules, ":" );
    while(token != NULL){
        loaded.push_back(token);
        token = strtok(NULL, path_delim);
    }
    delete loaded_modules;
}
