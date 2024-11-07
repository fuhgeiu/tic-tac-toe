#include "game_data.hpp"
#include "user interface.hpp"

/*
    1) core_data::game_data (player1*, player2*)
    2) core_data::game_data (player1*, player2*, size of board)

    _____________________________________________________________________________________________________________
    1) constructor will pass in pointers to objects from player_data, and stored in game_data object
    2) constructor will call board_data class to be instantiated and size of board to be passed and game_data class
       will store pointer to board obj, board object constructor will create a container of passed size


 */


int main () {
    
    bool w = true;
    
    while (w) {
        
        // show main menu and get selection on what game mode
//        user_interface::main_menu main_menu;
        auto *main_menu = new user_interface::main_menu;                                // to dispaly main menu and store game mode
        
        main_menu->prompt();                                                    // prompt for a game mode
        main_menu->get_game_mode();                                             // method to assign main_menu.game_mode
        
        auto *players = new user_interface::instantiate_players(main_menu->game_mode);     //Warning! players will not be mutible
        
//      players->instantiate_player1(true);                              // method to instantiate a player::player_data* type const object
//      players->instantiate_player2(true);                              // method to instantiate a player::player_data* type const object
        players->instantiate_player1();
        std::cout << "\n\n";
        players->instantiate_player2();
        
        // const flag availible
        auto *game = new core_data::game::game_data(players->get_player1(),players->get_player2(),players->get_player1(),9);
        
//  to instantiate passign in const object, use bool flag
//        auto *game = new core_data::game::game_data(players->get_player1(),players->get_player1(),players->get_player2(),9,true);
        
        delete players;                                                     // delete object for onstantiating players
        delete main_menu;                                                   // delete main_menu object
        
        bool q = true;
        while (q) {                                                         // start of game loop
            
            std::cout << "\n\n";
            game->print_board_board_data();                                      // print board
            
            std::cout << "\n\nTurn -> " << game->current_player_status();        // starting player
            std::cout << std::endl;
            
            game->get_set_spot();                                                // get player spot and validate and update
            
//            std::cout << "spot validated\n";
            
            game->switch_player();                                               // switch player
            
//            std::cout << "player symbol switched\n";
            
            
            if (game->get_win() == '\0') {}
            
            else {game->print_board_board_data(); std::cout << "\n\nplayer :" << game->get_win() << " WON";
                
                std::cout << "\nplay another game?, yes(1) no (0) \n";
                
                int t;
                
                while (true) {
                    
                    std::cin >> t;
                    if (std::cin.fail() || t < 0 || t > 1) {std::cout << "wrong input\n"; std::cin.clear(); std::cin.ignore(1000000);}
                    else break;
                }
                
                if (t == 1) {
                    
                    delete game;
                    q = false;
                }
                
                if (t == 0) {w = false; break;}
            }
        }
        
        
    }
    
    // prompt if user wants to play again
}

