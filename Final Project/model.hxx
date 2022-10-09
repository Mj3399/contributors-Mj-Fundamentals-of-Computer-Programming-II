#pragma once

#include <ge211.hxx>
#include <string>
///make class for piece with field for kind of piece, color, and position
// (probably with x and y coords, if the index is higher than a multiple of 8
// then the y coordinate needs to adjust accordingly and
class Model
{
public:
    Model();
    bool is_game_over() const
    { return turn() == Player::neither; }
    enum class Player
    {
        dark,
        light,
        neither,


    };
    Player turn() const
    { return turn_; }
    Player winner() const
    { return winner_; }
    Player other_player(Player);
    Player turn_   = Player::light;
    Player winner_ = Player::neither;
    enum class Piecename
    {
        rook,
        bishop,
        king,
        queen,
        pawn,
        empty,
        knight

    };
    struct Piece {
        //data memember
        Piecename name;
        Player color;
        int x; //i mod8
        int y; // i//8
        bool alive;

        //constructors
        Piece(Piecename piecename, Player player, int x, int y, bool alive);

        //member functions
        bool live();
        void set_location(int newx, int newy);


    };
    std::vector<std::vector<Model::Piece>> board;
    bool occupied(int x, int y);
    bool twokings();
    bool oneking();
    bool onlytwokings();
    bool intheway(Piece piece, int newx, int newy);
    bool valid_move(Piece piece, int newx, int newy);
    void advance_turn_();
    void promotepawn(Piece p);
    void swap(Model::Piece a, Model::Piece b);
    void play_move(ge211::Posn<int> positiona, ge211::Posn<int> positionb);
    void set_game_over_();
    void capture(Model::Piece a);
};
