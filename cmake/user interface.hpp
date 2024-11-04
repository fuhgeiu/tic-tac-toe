#include <iostream>
//  user interface.hpp
//  tic tac toe xcode
//
//  Created by Alex Carnes on 10/27/24.
//

namespace user_interface {


struct main_menu {
    
    size_t game_mode;

    void prompt () {std::cout << "main menu\n" << "play \n" << "\n Classic (0)" << "\n Battle mode (1)\n";}
    
    void get_game_mode () {
        
        size_t game_mode;
        while (true) {
            std::cin >> game_mode;
            if (std::cin.fail() || game_mode < 0 || game_mode > 1)
                {std::cout << "invalid data\n"; std::cin.clear(); std::cin.ignore(10000);}
            else break;
        }
    }
    
};  // end of class main menu


class instantiate_players {
    
    size_t game_mode;
    size_t player_type;
    core_data::player::player_data* player1;
    core_data::player::player_data* player2;
    
public:
    
    instantiate_players (size_t game_mode) {this->game_mode = game_mode;}
    
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
            if (std::cin.fail() || player_type < 0 || player_type > 1)
                {std::cout << "invalid data\n"; std::cin.clear(); std::cin.ignore(10000);}
            else break;
        }
        return player_type;
    }
    
    char get_player_symbol () {
        
        char player_symbol;
        size_t verify;
        
        std::cout << "enter your player symbol will only take in 1st character \n";
        
        while (true) {
            
            std::cin >> player_symbol;
            if (std::cin.fail()) {std::cout << "invalid data"; std::cin.clear(); std::cin.ignore(100000);}
            std::cout << "is this the correct symbol" << player_symbol << " (0) no, (1) yes\n";
            
            while (true) {
                
                std::cin >> verify;
                if (std::cin.fail() || player_type < 0 || player_type > 1)
                {std::cout << "invalid data\n"; std::cin.clear(); std::cin.ignore(10000);}
            }
            
            if (verify == 1) break;
        }
        return player_symbol;
    }
    
    core_data::player::player_data* get_player1 () {return player1;}
    
    core_data::player::player_data* get_player2 () {return player2;}
    
    void instantiate_player1 () {
        
        if (this->game_mode == 1) {
            
            std::cout << "player 1 choose your character\n";
            dispaly_character_options();                        // prompt character type options
            
            char symbol = get_player_symbol();
            
            size_t char_type = get_character_type();
        
            if (char_type == 1) {player1 = new core_data::player::alchemist(symbol);}          // alchemist
            if (char_type == 0) {player1 = new core_data::player::paladin(symbol);}          // paladin
        }
        
        if (this->game_mode == 0) {player1 = new core_data::player::human('o');}
    }
    
    void instantiate_player2 () {
        
        if (this->game_mode == 1) {
            
            std::cout << "player 2 choose your character\n";
            dispaly_character_options();
            
            char symbol = get_player_symbol();
            
            size_t char_type = get_character_type();
            
            if (char_type == 1) {player1 = new core_data::player::alchemist(symbol);}          // alchemist
            if (char_type == 0) {player1 = new core_data::player::paladin(symbol);}          // paladin
        }
        
        if (this->game_mode == 0) {player2 = new core_data::player::human('x');}
        
    }
    
    
    
    
};



















}  // end of namespace user_interface




