#include "game_data.hpp"

/*
    1) core_data::game_data (player1*, player2*)
    2) core_data::game_data (player1*, player2*, size of board)

    _____________________________________________________________________________________________________________
    1) constructor will pass in pointers to objects from player_data, and stored in game_data object
    2) constructor will call board_data class to be instantiated and size of board to be passed and game_data class
       will store pointer to board obj, board object constructor will create a container of passed size




 */


int main () {


    auto *player1 = new core_data::player::player_data('o');          // player1 data
    auto *player2 = new core_data::player::player_data('x');          // player2 data
    auto *game1 = new core_data::game::game_data(player1,player2,9);   // game data   2)

    game1->set_curernt_player(player1);                            // set current player (player::data *player)

// loop {
    bool q = true;

    while (q) {

        game1->print_board_board_data();                                      // print board

        std::cout << "\n\nTurn -> " << game1->current_player_status();        // starting player
        std::cout << "\nenter a spot\n:";

        game1->get_set_spot();                                                // get player spot and validate and update

        game1->switch_player();                                               // switch player

        // check if player won



    }


    // if player won, than delete and there destructors called
    delete player1;
    delete player2;
    delete game1;

}


// prompt if user wants to play again


