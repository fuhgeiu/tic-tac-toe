#include <iostream>
#include <sstream>
#include "stream.hpp"

namespace core_data {
// class to disaply board data, with user defined settings and
    namespace board {

class board_data {

    char* m_data = nullptr;                                                 // warning! nullptr, cannot call destructor
    size_t m_length;
    strm::range_cond *range_spot = nullptr;                                 // warning nullptr, cannot call destructor

public:

   board_data () = default;

   board_data (size_t cont_size) { m_length = cont_size; create_board_data_container(cont_size);
       strm::range_cond *cond =  new strm::range_cond(static_cast<int>(cont_size+1),0); range_spot = cond;
   }

   ~ board_data () { delete m_data; }                                      // warning! undeifned if m_data is a nullptr

   void create_board_data_container (size_t length) {                             // warning! only pass in unsigned int

      m_data = new char[length]; m_length = length;                               // warning! new allocated array

      for (size_t i = 0; i < length; i++) { m_data[i] = static_cast <char> ((i+1)+'0'); }    // assign numbers to each
      strm::range_cond *cond =  new strm::range_cond(static_cast<int>(length+1),0); range_spot = cond;
   }

   char index_operator_data (size_t index)  { return m_data[index]; }

   void print_board () {                                    // for 3 by 3 with 1d array

       for (size_t i = 0; i < 3; i++) {

           for (size_t j = 0; j < 3; j++) {                    // print elements number of collum times

               std::cout << m_data[i*3+j];
               if (j < 2) std::cout << " | ";
           }
           if (i < 2) std::cout << "\n--+---+--\n";
       }
   }

   void range ()  { range_spot->output_range(); }

   void get_spot_validated (char current_player,char player1, char player2) {

       size_t spot = strm::get(std::cin, (*range_spot));

       while (m_data[spot-1] == player1 || m_data[spot-1] == player2) {

           std::cout << "spot is taken\n";
           spot = strm::get(std::cin, *range_spot);
       }
       m_data[static_cast<size_t> (spot)-1] = current_player;
   }

   




   // only for test
    bool test_board_contianer () {

        bool is_correct = true;
        char expected[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

        for (int i = 0; i < m_length; ++i) {
            if (m_data[i] != expected[i]) {
                std::cout << "Error at index " << i << ": expected " << expected[i] << ", got " << m_data[i] << std::endl;
                is_correct = false;
            }
        }
        return is_correct;
    }

}; // end of class board
} // end of namespace board


} // end of namespace core_data


