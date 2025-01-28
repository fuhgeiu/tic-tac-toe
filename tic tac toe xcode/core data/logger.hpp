// to logger
#include <fstream>
#include <string>
#include <unistd.h>         // for unix systems
#include <limits.h>
//#include <exception>

class logger {
    
public:
    
    virtual void logger_startup () = 0;
    
    virtual void logger_write_data () = 0;
};

class logger_console {
    
    std::string filename = "logfile.txt";
    
public:
    
    void logger_startup () {                                    // create file if not availible
        
        char cwd[PATH_MAX];
        if (getcwd(cwd, sizeof(cwd)) != nullptr) {
            std::cout << "Current working directory: " << cwd << '\n';
        } else {
            perror("getcwd() error");
        }
        
        std::fstream file(filename, std::ios::out);
        
        file.close();
    }
    
    void logger_write_gamesplayed (size_t games) {
        
        std::fstream file(filename, std::ios::app);
        
        file << "number of games played " << games << std::endl;
        
        file.close();
    }
    
    void write_game_win_status (int win) {
        
        std::fstream file(filename, std::ios::app);
        
        if (win == 0) {file << "player tie \n";}
        if (win == 1) {file << "player one won \n";}
        if (win == 2) {file << "player two won \n";}
        
        file.close();
    }
    
};


