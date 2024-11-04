


namespace core_data {

    namespace player {

// interface for players, include methods of validation and of gettign character symbol
class player_data {
    
public:

    virtual ~player_data () {};

    virtual const char player_symbol_is () = 0;                 // get player symbol
                                                                // get spot validated according to the character mode rules
    
}; // end of class


class human : public player_data {

    char player_symbol;

public:
    
    human () = default;
    human (char symbol) {player_symbol = symbol;}

    const char player_symbol_is () {return player_symbol;}
}; // end of human class

class computer : public player_data {
    
    char player_symbol = 'c';

public:

    computer () = default;
    computer (char symbol) {player_symbol = symbol;}

    const char player_symbol_is () {return player_symbol;}
    
}; // end of class computer
    
// battle tic tac toe players
// include player special abilities and rules in the player class itself
    
// rules of players 
    
    
class alchemist : public player_data {
    
    char player_symbol;
        
public:
    
    alchemist () = default;
    alchemist (char symbol) {player_symbol = symbol;}
    
    const char player_symbol_is () {return player_symbol;}
        
        
}; // end of class alchamest
    
class paladin : public player_data {
        
    char player_symbol;
    
public:
    
    paladin () = default;
    paladin (char symbol) {player_symbol = symbol;}
    
    const char player_symbol_is () {return player_symbol;}
        
        
}; // end of class paladin

    } // end of namespace player

}

