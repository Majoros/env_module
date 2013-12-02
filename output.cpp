        if(replace){
            if(action == PREPEND){
                std::cout << "export " << key << "=\"" << path;
            }
            else{
                std::cout << "export " << key << "=\"";
            }
            for ( unsigned int i = 0; i < cur_paths.size(); ++i){
                if(action == PREPEND){
                    std::cout << path_delim << cur_paths[i];
                }
                else{
                    std::cout << cur_paths[i] << path_delim;
                }
            }
            if(action == PREPEND){
                std::cout << "\"";
            }
            else{
                std::cout << path << "\"";
            }
        }
        else{
            if(action == PREPEND){
                std::cout << "export " << key << "=\"" << path << path_delim << "$" << key << "\"";
            }
            else{
                std::cout << "export " << key << "=\"" << "$" << key << path_delim << path << "\"";
            }
        }
        std::cout << "\n";
        return 0;
