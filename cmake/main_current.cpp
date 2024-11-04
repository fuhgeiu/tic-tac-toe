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
        user_interface::main_menu main_menu;
        
        main_menu.prompt();
        main_menu.get_game_mode();
        
        user_interface::instantiate_players players(main_menu.game_mode);
        
        players.instantiate_player1();
        players.instantiate_player2();
        
        auto *temp_player = new core_data::player::human('0');
        
        std::cout << temp_player->player_symbol_is();
        
        auto *game = new core_data::game::game_data(players.get_player1(),players.get_player1(),players.get_player2(),9);

        bool q = true;
        while (q) {
            
            game->print_board_board_data();                                      // print board
            
            
            std::cout << "\n\nTurn -> " << game->current_player_status();        // starting player
            
            std::cout << "\nenter a spot\n:";
            
            game->get_set_spot();                                                // get player spot and validate and update
            
            std::cout << "spot validated\n";
            
            game->switch_player();                                               // switch player
            
            std::cout << "player symbol switched\n";
            
            
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
                
                if (t == 0) {q = false; w = false;}
            }
        }
        
        
    }
    
    // prompt if user wants to play again
}

