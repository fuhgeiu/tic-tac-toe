#include <iostream>


//  user interface.hpp
//  tic tac toe xcode
//
//  Created by Alex Carnes on 10/27/24.
//

namespace user_interface {


struct main_menu {
    
    size_t game_mode;                      // store game mode as a public member

    void prompt () {std::cout << "main menu\n" << "play \n" << "\n Classic (0)" << "\n Battle mode (1)\n";}
    
    void get_game_mode () {
        
        while (true) {
    
            std::cin >> game_mode;
            
            if (std::cin.fail()) {
                std::cout << "invalid data\n";
                std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            
            if (game_mode != 0 && game_mode != 1) {
                
                std::cout << "must be either a 1 or 0\n";
                continue;
            }
            else break;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (game_mode == 0) std::cout << "you selected CLASSIC\n\n";
            else std::cout << "you selected BATTLE\n\n";
    }
    
};  // end of class main menu


class instantiate_players {
    
    size_t game_mode;
    char Player1_symbol = '\n';
    core_data::player::player_data* player1 = nullptr;                    // player1 points to object of player_data::player* type
    core_data::player::player_data* player2 = nullptr;                    // player2 points to object of player_data::player* type
    const core_data::player::player_data* const_player1 = nullptr;        // const version
    const core_data::player::player_data* const_player2 = nullptr;        // const version
    
public:
    
    instantiate_players (size_t game_mode) {this->game_mode = game_mode;}
    
public:
    
    core_data::player::player_data* get_player1 () {
        
        try { if (player1 == nullptr) throw c_exception::runtime::acess_nullptr("player1 is not initilized \n cannot assign a nullptr");
            
        } catch (c_exception::runtime::acess_nullptr& e) {std::cout << "error :" << e.what() << std::endl;}

        return player1;
    }
    
    core_data::player::player_data* get_player2 () {
        
        try {if (player2 == nullptr) throw c_exception::runtime::acess_nullptr("player2 is not initilized \n cannot assign a nullptr");
            
        } catch (c_exception::runtime::acess_nullptr& e) {std::cout << "error" << e.what() << std::endl;}
        
        return player2;
        
    }
    
    const core_data::player::player_data* get_player1 (bool const_flag) {return const_player1;}
    
    const core_data::player::player_data* get_player2 (bool const_flag) {return const_player2;}
    
    void dispaly_character_options () {
        
        std::cout
        << "(1) --<~> Alchemist   ->> can swap 2 marks on the board\n"
        << "(2) (-(-- Paladin     ->> can shift existing mark to adjacent spot\n\n";
    }
    
    size_t get_character_type () {
        
        size_t player_type;

        while (true) {
            
            std::cin >> player_type;
            if (std::cin.fail() || (player_type != 1 && player_type != 2)) {
                std::cout << "invalid data\n";
                std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else break;
        } std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return player_type;
    }
    
    char get_player_symbol() {
        
        char player_symbol;
        size_t verify;
        
        while (true) {
            
            std::string input;
            std::cout << "Enter your player symbol (only the first character will be used) \n";
            
            std::getline(std::cin,input);
            if (input.empty() || input[0] == ' ') {
                std::cout << "cannot be a blank space\n";
                continue;
            }
            
            if (input[0] >= '0' && input[0] <= '9') {std::cout << "do not enter a number"; continue;}
            
            if (Player1_symbol != '\n') {
                
                if (input[0] == Player1_symbol) {std::cout << "symbol cannot be the same as player1\n"; continue;}
            }
            
            player_symbol = input[0];
            
            while (true) {
                
                std::cout << "Is this the correct symbol: " << player_symbol << " (0) No, (1) Yes\n";
                std::cin >> verify;
                if (std::cin.fail() || (verify != 0 && verify != 1)) {
                    std::cout << "Invalid data";
                    std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                } else break;
            } std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (verify == 1) break;
        }
        return player_symbol;
    }
    
    void instantiate_player1 () {
        
        if (game_mode == 1) {
            
            std::cout << "player 1 choose your character\n";
            dispaly_character_options();                        // prompt character type options
            
            size_t char_type = get_character_type();
            
            char symbol = get_player_symbol();
            Player1_symbol = symbol;
        
            if (char_type == 1) {player1 = new core_data::player::alchemist(symbol);}          // alchemist
            if (char_type == 2) {player1 = new core_data::player::paladin(symbol);}          //
        }
        
        if (game_mode == 0) {player1 = new core_data::player::human('o');}      // temporary change
    }
    
// const version
    void instantiate_player1 (bool const_flag) {                            // const version
        
        if (game_mode == 1) {
            
            std::cout << "player 1 choose your character\n";
            dispaly_character_options();                        // prompt character type options
            
            size_t char_type = get_character_type();
        
            char symbol = get_player_symbol();
            Player1_symbol = symbol;
        
            if (char_type == 1) {const_player1 = new const core_data::player::alchemist(symbol);}          // alchemist
            if (char_type == 2) {const_player1 = new const core_data::player::paladin(symbol);}          //
        }
        
        if (game_mode == 0) {const_player1 = new const core_data::player::human('o');}      // temporary change
    }
    
    void instantiate_player2 () {
        
        if (game_mode == 1) {
            
            std::cout << "player 2 choose your character\n";
            dispaly_character_options();
            
            size_t char_type = get_character_type();            // returns a value it shouldnt
            
            char symbol = get_player_symbol();
            
            if (char_type == 1) {player2 = new core_data::player::alchemist(symbol);}          // alchemist
            if (char_type == 2) {player2 = new core_data::player::paladin(symbol);}          // temporary change to alchemist
        }
        
        if (game_mode == 0) {player2 = new core_data::player::human('x');}              // temporary change to alchemist
    }
    
// const version
    void instantiate_player2 (bool const_flag) {
        
        if (game_mode == 1) {
            
            std::cout << "player 2 choose your character\n";
            dispaly_character_options();
            
            size_t char_type = get_character_type();
            
            char symbol = get_player_symbol();
            
            if (char_type == 1) {const_player2 = new const core_data::player::alchemist(symbol);}          // alchemist
            if (char_type == 2) {const_player2 = new const core_data::player::paladin(symbol);}       // temporary change to alchemist
        }
        
        if (game_mode == 0) {const_player2 = new const core_data::player::human('x');}              // temporary change to alchemist
    }
    
};



















}  // end of namespace user_interface




