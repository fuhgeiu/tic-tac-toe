
#include "game data.hpp"
#include <cassert>
//#include <sstream>


int main () {

    auto *board_temp = new core_data::board::board_data(9);

    assert(board_temp->index_operator_data(3) == '4');

    assert(board_temp->index_operator_data(8) == '9');

    assert(board_temp->test_board_contianer() == true);

    // instantiate player data object
    auto *player1 = new core_data::player::player_data('u');                 // player 1

    auto *player2 = new core_data::player::player_data('v');                 // player 2

    auto *game4 = new core_data::game::game_data(player1,player2,9);

    assert (game4->acess_data(4) == '5');

    assert(game4->test_board_contianer() == true);

    core_data::board::board_data temp3 (9);

    temp3.print_board();

    game4->print_board_board_data();

    temp3.range();
}