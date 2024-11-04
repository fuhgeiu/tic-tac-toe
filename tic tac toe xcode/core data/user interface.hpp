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
            if (std::cin.fail() || game_mode > 1) {
                std::cout << "invalid data\n";
                std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else break;
        }
        if (game_mode == 0) std::cout << "you selected CLASSIC\n";
            else std::cout << "you selected BATTLE\n";
    }
    
};  // end of class main menu


class instantiate_players {
    
    size_t game_mode;
    size_t player_type;
    core_data::player::player_data* player1;                        // player1 points to object of player_data::player* type
    core_data::player::player_data* player2;                        // player2 points to object of player_data::player* type
    const core_data::player::player_data* const_player1;                  // const version
    const core_data::player::player_data* const_player2;                  // const version
    
public:
    
    instantiate_players (size_t game_mode) {this->game_mode = game_mode;}
    
public:
    
    core_data::player::player_data* get_player1 () {return player1;}
    
    core_data::player::player_data* get_player2 () {return player2;}
    
    const core_data::player::player_data* get_player1 (bool const_flag) {return const_player1;}
    
    const core_data::player::player_data* get_player2 (bool const_flag) {return const_player2;}
    
    void dispaly_character_options () {
        
        std::cout << "Battle game mode\n"
        << "\n 2 choices in characters \n"
        << "1 --<~> Alchemist   ->> can swap 2 marks on the board or make regular move\n"
        << "2 (-(-- Paladin     ->> can shift existing mark to adjacent spot or make regular move\n";
    }
    
    size_t get_character_type () {
        
        size_t player_type;

        while (true) {
            
            std::cin >> player_type;
            if (std::cin.fail() || player_type > 1) {
                std::cout << "invalid data\n";
                std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else break;
        }
        return player_type;
    }
    
    char get_player_symbol() {
        char player_symbol;
        size_t verify;
        
        std::cout << "Enter your player symbol (only the first character will be used) \n";
        
        while (true) {
            std::cin >> player_symbol;
            if (std::cin.fail() || player_symbol == '\n') {
                std::cout << "Invalid data. Try again.\n";
                std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            
            std::cout << "Is this the correct symbol: " << player_symbol << "? (0) No, (1) Yes\n";
            
            while (true) {
                std::cin >> verify;
                if (std::cin.fail() || verify < 0 || verify > 1) {
                    std::cout << "Invalid data. Enter 0 (No) or 1 (Yes): ";
                    std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                } else break;
            }
            if (verify == 1) break;
        }
        return player_symbol;
    }
    
    // player symbolsc cant be the same
    // use getline
    
    void instantiate_player1 () {
        
        if (game_mode == 1) {
            
            std::cout << "player 1 choose your character\n";
            dispaly_character_options();                        // prompt character type options
            
            size_t char_type = get_character_type();
            
            char symbol = get_player_symbol();
        
            if (char_type == 1) {player1 = new core_data::player::alchemist(symbol);}          // alchemist
            if (char_type == 0) {player1 = new core_data::player::paladin(symbol);}          //
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
        
            if (char_type == 1) {const_player1 = new const core_data::player::alchemist(symbol);}          // alchemist
            if (char_type == 0) {const_player1 = new const core_data::player::paladin(symbol);}          //
        }
        
        if (game_mode == 0) {const_player1 = new const core_data::player::human('o');}      // temporary change
    }
    
    void instantiate_player2 () {
        
        if (game_mode == 1) {
            
            std::cout << "player 2 choose your character\n";
            dispaly_character_options();
            
            char symbol = get_player_symbol();
            
            size_t char_type = get_character_type();
            
            if (char_type == 1) {player2 = new core_data::player::alchemist(symbol);}          // alchemist
            if (char_type == 0) {player2 = new core_data::player::paladin(symbol);}          // temporary change to alchemist
        }
        
        if (game_mode == 0) {player2 = new core_data::player::human('x');}              // temporary change to alchemist
    }
    
// const version
    void instantiate_player2 (bool const_flag) {
        
        if (game_mode == 1) {
            
            std::cout << "player 2 choose your character\n";
            dispaly_character_options();
            
            char symbol = get_player_symbol();
            
            size_t char_type = get_character_type();
            
            if (char_type == 1) {const_player2 = new const core_data::player::alchemist(symbol);}          // alchemist
            if (char_type == 0) {const_player2 = new const core_data::player::paladin(symbol);}          // temporary change to alchemist
        }
        
        if (game_mode == 0) {const_player2 = new const core_data::player::human('x');}              // temporary change to alchemist
    }
    
};



















}  // end of namespace user_interface




