// to logger
#include <fstream>
#include <string>
//#include <exception>

class logger {
    
public:
    
    virtual void logger_startup () = 0;
    
    virtual void logger_write_data () = 0;
};

class logger_console {
    
    std::string filename = "game_data";
    
public:
    
    void logger_startup () {                                    // create file if not availible
        
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


