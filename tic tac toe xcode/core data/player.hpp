


namespace core_data {


    namespace player {

// interface for players, include methods of validation and of gettign character symbol
class player_data {
    
public:

    virtual ~player_data () = default;

    virtual char& player_symbol_is () = 0;                       // refernce to char player symbol    mutable player_symbol
    
    virtual const char& player_symbol_is () const = 0;           // return a const refernce to char player symbol non mutable
    
    virtual void display_menu (core_data::board::board_data*) const = 0;           // prompt the charter types rules and abilities
    
    virtual void validate (core_data::board::board_data*) const = 0;             // to get a valid spot
    
}; // end of class


class human : public player_data {

    char player_symbol;

public:
    
    human () = default;
    human (char symbol) {player_symbol = symbol;}
    
    char& player_symbol_is () override {return player_symbol;}
    
    const char& player_symbol_is () const override {return player_symbol;}
    
    void display_menu (core_data::board::board_data* board) const override {
        
        std::cout << "Enter a number " << board->range_lower()  << " - " << board->range_upper()  << std::endl;
    }
        
    void validate (core_data::board::board_data* board) const override {
        
        size_t board_spot;
        
        while (true) {
            
            std::cout << "spot {";
            std::cin >> board_spot;
            if (std::cin.fail()) {
                std::cout << "invalid input\n"; std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            
            while (true) {
                if (board->range_validation(board_spot) != true) {
                    
                    std::cout << "the spot is taken choose again\n";
                } else break;
            }
        } board->set_board_data(board_spot, player_symbol);
        
    } // end of validate
    
}; // end of human class

    
class computer : public player_data {
    
    char player_symbol = 'c';

public:

    computer () = default;
    computer (char symbol) {player_symbol = symbol;}

    char& player_symbol_is () override {return player_symbol;}
    
    const char& player_symbol_is () const override {return player_symbol;}
    
    void display_menu (core_data::board::board_data* board) const override {std::cout << "computer is playing";}
    
    void validate (core_data::board::board_data* board) const override {return ;}
    
}; // end of class computer

    
class alchemist : public player_data {
    
    char player_symbol;
        
public:
    
    alchemist () = default;
    alchemist (char symbol) {player_symbol = symbol;}
    
    char& player_symbol_is () override {return player_symbol;}
    
    const char& player_symbol_is () const override {return player_symbol;}
    
    void display_menu (core_data::board::board_data* board) const override {
        
        std::cout << "Alchemist ----<>(( ( \n";
        if (board->alchemist_special_availible()) std::cout << "normal move (0) \nspecial ability availbile, swap marks (1)\n";
            else std::cout << " normal move, select spot to mark\n";
    }
    
    void validate (core_data::board::board_data* board) const override {
        
        size_t mode;
        size_t board_spot;
        size_t swap1, swap2;
        
        if (board->alchemist_special_availible()) {             // if enough spots on board to use special ability
            
            std::cout << "enter a mode :";
            
            while (true) {                                      // to get mode
                
                std::cin >> mode;
                
                if (std::cin.fail()) {
                    
                    std::cout << "invalid input try again\n";
                    std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                } else break;
            } // end of loop
        } // end of if special
        
        if (mode == 1) {                                        // if special ability chosen
            
            std::cout << "enter 1st mark to swap \n";
            
            while (true) {                                      // to get mode
                
                std::cin >> swap1;
                
                if (std::cin.fail()) {
                    
                    std::cout << "invalid input try again\n";
                    std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                } continue;
                
                std::cout << "enter 2nd mark to swap\n";
                while (true) {                                      // to get mode
                    
                    std::cin >> swap2;
                    
                    if (std::cin.fail()) {
                        
                        std::cout << "invalid input try again\n";
                        std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    } continue;
                    
                    if (board->compare_symbols(player_symbol, swap2)) {std::cout << "cannot swap spots with identical symbols\n";}
                    else break;
                }
            }  board->swap_marks(swap1,swap2);
        }
        
        while (true) {
            
            std::cout << "spot {";
            std::cin >> board_spot;
            if (std::cin.fail()) {
                std::cout << "invalid input\n"; std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            
            while (true) {
                if (board->range_validation(board_spot) != true) {
                    
                    std::cout << "the spot is taken choose again\n";
                } else break;
            }
        } board->set_board_data(board_spot, player_symbol);
    } // end of validate
    
}; // end of class alchamest
    
    
class paladin : public player_data {
        
    char player_symbol;
    
public:
    
    paladin () = default;
    paladin (char symbol) {player_symbol = symbol;}
    
    char& player_symbol_is () override {return player_symbol;}
    
    const char& player_symbol_is () const override {return player_symbol;}
    
    void display_menu (core_data::board::board_data* board) const override {
        
        std::cout << "Palidin <><<<+-- \n";
        if (board->palidin_special_availible()) std::cout << "normal move (0) \nPalidin dpecial move availible (1)\n";
        else std::cout << "normal move, select spot to mark\n";
    }
 
    void validate (core_data::board::board_data* board) const override {
        
        
        
        
        
        
        
        
        
        
    }
        
        
}; // end of class paladin

    } // end of namespace player

} // namespace core_data

