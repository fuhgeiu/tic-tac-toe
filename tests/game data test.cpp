#include "game data.hpp"
#include <iostream>
#include <cassert>


int main () {

// instantiate object with full constructer
    core_data::game::game_data game2('o','o','x');

// test current player switching
    for (size_t i = 0; i < 10; i++) {

        assert(game2.current_player_statusC () == 'o');                      // get current player/starting player

        game2.switch_playerC();                                             // switch player symbol

        assert(game2.current_player_statusC() == 'x');                       // get current player

        game2.switch_playerC();                                              // switch player symbol
    }


// instantiate player data object
    auto *player1 = new core_data::player::player_data('u');                 // player 1

    auto *player2 = new core_data::player::player_data('v');                 // player 2
// instantiate game data
    core_data::game::game_data game3(player1,player1,player2);            // instantiate, call constructor (ptr,ptr,ptr)

// test current player switching
    for (size_t i = 0; i < 10; i++) {

        assert(game3.current_player_status () == 'u');                      // get current player/starting player

        game3.switch_player ();                                             // switch player symbol

        assert(game3.current_player_status () == 'v');                       // get current player

        game3.switch_player ();                                              // switch player symbol
    }

    game3.create_board_new(9);

    assert(game3.test_board_contianer() == true);

    game3.print_board_game_data();





    delete player1;  player1 = nullptr;
    delete player2;  player2 = nullptr;



}