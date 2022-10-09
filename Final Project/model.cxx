#include "model.hxx"
#include <cmath>
#include <iostream>
///make class for piece with field for kind of piece, color, and position
// (probably with x and y coords, if the index is higher than a multiple of 8
// then the y coordinate needs to adjust accordingly and

Model::Model()

{
    Model::Piece bRook1(Model::Piecename::rook,
                        Model::Player::dark, 0, 0, true);
    Model::Piece bRook2(Model::Piecename::rook,
                        Model::Player::dark, 7, 0, true);
    Model::Piece wRook1(Model::Piecename::rook,
                        Model::Player::light, 0, 7, true);
    Model::Piece wRook2(Model::Piecename::rook,
                        Model::Player::light, 7, 7, true);
    Model::Piece bBishop1(Model::Piecename::bishop,
                          Model::Player::dark, 2, 0, true);
    Model::Piece bBishop2(Model::Piecename::bishop,
                          Model::Player::dark, 5, 0, true);
    Model::Piece wBishop1(Model::Piecename::bishop,
                          Model::Player::light, 2, 7, true);
    Model::Piece wBishop2(Model::Piecename::bishop,
                          Model::Player::light, 5, 7, true);
    Model::Piece bKnight1(Model::Piecename::knight,
                          Model::Player::dark, 1, 0, true);
    Model::Piece bKnight2(Model::Piecename::knight,
                          Model::Player::dark, 6, 0, true);
    Model::Piece wKnight1(Model::Piecename::knight,
                          Model::Player::light, 1, 7, true);
    Model::Piece wKnight2(Model::Piecename::knight,
                          Model::Player::light, 6, 7, true);
    Model::Piece bKing(Model::Piecename::king,
                       Model::Player::dark, 4, 0, true);
    Model::Piece wKing(Model::Piecename::king,
                       Model::Player::light, 4, 7, true);
    Model::Piece bQueen(Model::Piecename::queen,
                        Model::Player::dark, 3, 0, true);
    Model::Piece wQueen(Model::Piecename::queen,
                        Model::Player::light, 3, 7, true);
    Model::Piece bPawn1(Model::Piecename::pawn,
                        Model::Player::dark, 0, 1, true);
    Model::Piece bPawn2(Model::Piecename::pawn,
                        Model::Player::dark, 1, 1, true);
    Model::Piece bPawn3(Model::Piecename::pawn,
                        Model::Player::dark, 2, 1, true);
    Model::Piece bPawn4(Model::Piecename::pawn,
                        Model::Player::dark,3, 1, true);
    Model::Piece bPawn5(Model::Piecename::pawn,
                        Model::Player::dark, 4, 1, true);
    Model::Piece bPawn6(Model::Piecename::pawn,
                        Model::Player::dark, 5, 1, true);
    Model::Piece bPawn7(Model::Piecename::pawn,
                        Model::Player::dark, 6, 1, true);
    Model::Piece bPawn8(Model::Piecename::pawn,
                        Model::Player::dark, 7, 1, true);
    Model::Piece wPawn1(Model::Piecename::pawn,
                        Model::Player::light, 0, 6, true);
    Model::Piece wPawn2(Model::Piecename::pawn,
                        Model::Player::light, 1, 6, true);
    Model::Piece wPawn3(Model::Piecename::pawn,
                        Model::Player::light, 2, 6, true);
    Model::Piece wPawn4(Model::Piecename::pawn,
                        Model::Player::light, 3, 6, true);
    Model::Piece wPawn5(Model::Piecename::pawn,
                        Model::Player::light, 4, 6, true);
    Model::Piece wPawn6(Model::Piecename::pawn,
                        Model::Player::light, 5, 6, true);
    Model::Piece wPawn7(Model::Piecename::pawn,
                        Model::Player::light, 6, 6, true);
    Model::Piece wPawn8(Model::Piecename::pawn,
                        Model::Player::light, 7, 6, true);
    Model::Piece blank1(Model::Piecename::empty,
                        Model::Player::neither, 0, 2, false);
    Model::Piece blank2(Model::Piecename::empty,
                        Model::Player::neither, 1, 2, false);
    Model::Piece blank3(Model::Piecename::empty,
                        Model::Player::neither, 2, 2, false);
    Model::Piece blank4(Model::Piecename::empty,
                        Model::Player::neither, 3, 2, false);
    Model::Piece blank5(Model::Piecename::empty,
                        Model::Player::neither, 4, 2, false);
    Model::Piece blank6(Model::Piecename::empty,
                        Model::Player::neither, 5, 2, false);
    Model::Piece blank7(Model::Piecename::empty,
                        Model::Player::neither, 6, 2, false);
    Model::Piece blank8(Model::Piecename::empty,
                        Model::Player::neither, 7, 2, false);
    Model::Piece ablank1(Model::Piecename::empty,
                         Model::Player::neither, 0, 3, false);
    Model::Piece ablank2(Model::Piecename::empty,
                         Model::Player::neither, 1, 3, false);
    Model::Piece ablank3(Model::Piecename::empty,
                         Model::Player::neither, 2, 3, false);
    Model::Piece ablank4(Model::Piecename::empty,
                         Model::Player::neither, 3, 3, false);
    Model::Piece ablank5(Model::Piecename::empty,
                         Model::Player::neither, 4, 3, false);
    Model::Piece ablank6(Model::Piecename::empty,
                         Model::Player::neither, 5, 3, false);
    Model::Piece ablank7(Model::Piecename::empty,
                         Model::Player::neither, 6, 3, false);
    Model::Piece ablank8(Model::Piecename::empty,
                         Model::Player::neither, 7, 3, false);
    Model::Piece cblank1(Model::Piecename::empty,
                         Model::Player::neither, 0, 4, false);
    Model::Piece cblank2(Model::Piecename::empty,
                         Model::Player::neither, 1, 4, false);
    Model::Piece cblank3(Model::Piecename::empty,
                         Model::Player::neither, 2, 4, false);
    Model::Piece cblank4(Model::Piecename::empty,
                         Model::Player::neither, 3, 4, false);
    Model::Piece cblank5(Model::Piecename::empty,
                         Model::Player::neither, 4, 4, false);
    Model::Piece cblank6(Model::Piecename::empty,
                         Model::Player::neither, 5, 4, false);
    Model::Piece cblank7(Model::Piecename::empty,
                         Model::Player::neither, 6, 4, false);
    Model::Piece cblank8(Model::Piecename::empty,
                         Model::Player::neither, 7, 4, false);
    Model::Piece dblank1(Model::Piecename::empty,
                         Model::Player::neither, 0, 5, false);
    Model::Piece dblank2(Model::Piecename::empty,
                         Model::Player::neither, 1, 5, false);
    Model::Piece dblank3(Model::Piecename::empty,
                         Model::Player::neither, 2, 5, false);
    Model::Piece dblank4(Model::Piecename::empty,
                         Model::Player::neither, 3, 5, false);
    Model::Piece dblank5(Model::Piecename::empty,
                         Model::Player::neither, 4, 5, false);
    Model::Piece dblank6(Model::Piecename::empty,
                         Model::Player::neither, 5, 5, false);
    Model::Piece dblank7(Model::Piecename::empty,
                         Model::Player::neither, 6, 5, false);
    Model::Piece dblank8(Model::Piecename::empty,
                         Model::Player::neither, 7, 5, false);


    board =
            {{bRook1, bKnight1, bBishop1, bQueen, bKing, bBishop2, bKnight2,bRook2},
             {bPawn1,  bPawn2,  bPawn3,  bPawn4,  bPawn5,  bPawn6,  bPawn7,  bPawn8},
             {blank1,  blank2,  blank3,  blank4,  blank5,  blank6,  blank7,  blank8},
             {ablank1, ablank2, ablank3, ablank4, ablank5, ablank6, ablank7,ablank8},
             {cblank1, cblank2, cblank3, cblank4, cblank5, cblank6, cblank7,cblank8},
             {dblank1, dblank2, dblank3, dblank4, dblank5, dblank6, dblank7,dblank8},
             {wPawn1,  wPawn2,  wPawn3,  wPawn4,  wPawn5, wPawn6,  wPawn7,   wPawn8},
             {wRook1, wKnight1, wBishop1, wQueen, wKing, wBishop2, wKnight2, wRook2}
            };
}
Model::Piece::Piece(Piecename piecename, Player player, int x, int y, bool
alive)
    :  name(piecename),
    color(player),
    x(x), // i mod8
    y(y), // i//8
    alive(alive)
{}

void Model::Piece::set_location(int newx, int newy) {
    x = newx;
    y = newy;
}
bool Model::Piece::live() {
    return alive;
}
//ASK ABOUT CHANGING TO KILL THE KING CHESS

bool Model::occupied(int x, int y){
    if(board[y][x].name == Model::Piecename::empty){
        return false;
    }
    return true;
}

bool Model::intheway(Piece piece, int newx, int newy){
    //piece.x, piece. y
    //for i; i + piece.x < newx
    if (piece.name == Model::Piecename::bishop) {
        if(piece.x < newx && piece.y < newy){
            int i = piece.x + 1;
            int j = piece.y + 1;
            while(i <newx && j < newy ){
                if(occupied(i, j)){
                    return true;
                }
                i++;
                j++;
            }

        }
        if(piece.x < newx && piece.y > newy){
            int i = piece.x + 1;
            int j = piece.y - 1;
            while(i <newx && j > newy ){
                if(occupied(i, j)){
                    return true;
                }
                i++;
                j--;
            }

        }
        if(piece.x > newx && piece.y < newy){
            int i = piece.x - 1;
            int j = piece.y + 1;
            while(i >newx && j < newy ){
                if(occupied(i, j)){
                    return true;
                }
                i--;
                j++;
            }

        }
        if(piece.x > newx && piece.y > newy) {
            int i = piece.x - 1;
            int j = piece.y - 1;
            while(i >newx && j > newy ){
                if(occupied(i, j)){
                    return true;
                }
                i--;
                j--;
            }

        }

    }
    if (piece.name == Model::Piecename::rook) {
        if(piece.x < newx && piece.y == newy){
            int i = piece.x + 1;
            int j = piece.y;
            while(i <newx){
                if(occupied(i, j)){
                    return true;
                }
                i++;
            }

        }
        if(piece.y > newy && piece.x == newx){
            int i = piece.x;
            int j = piece.y - 1;
            while(j > newy ){
                if(occupied(i, j)){
                    return true;
                }
                j--;
            }

        }
        if(piece.x > newx && piece.y == newy){
            int i = piece.x - 1;
            int j = piece.y;
            while(i >newx){
                if(occupied(i, j)){
                    return true;
                }
                i--;
            }

        }
        if(piece.y < newy && piece.x == newx){
            int i = piece.x;
            int j = piece.y + 1;
            while( j < newy ){
                if(occupied(i, j)){
                    return true;
                }
                j++;
            }

        }
    }
    if (piece.name == Model::Piecename::queen) {
        if(piece.x < newx && piece.y == newy){
            int i = piece.x + 1;
            int j = piece.y;
            while(i <newx ){
                if(occupied(i, j)){
                    return true;
                }
                i++;
            }

        }
        if(piece.y > newy && piece.x == newx){
            int i = piece.x;
            int j = piece.y - 1;
            while(j > newy ){
                if(occupied(i, j)){
                    return true;
                }
                j--;
            }

        }
        if(piece.x > newx && piece.y == newy){
            int i = piece.x - 1;

            while(i >newx ){
                if(occupied(i, piece.y)){
                    return true;
                }
                i--;

            }

        }
        if(piece.y < newy && piece.x == newx){

            int j = piece.y + 1;
            while( j < newy ){
                if(occupied(piece.x, j)){
                    return true;
                }
                j++;
            }

        }
        if(piece.x < newx && piece.y < newy){
            int i = piece.x + 1;
            int j = piece.y + 1;
            while(i <newx && j < newy ){
                if(occupied(i, j)){
                    return true;
                }
                i++;
                j++;
            }

        }
        if(piece.x < newx && piece.y > newy){
            int i = piece.x + 1;
            int j = piece.y - 1;
            while(i <newx && j > newy ){
                if(occupied(i, j)){
                    return true;
                }
                i++;
                j--;
            }

        }
        if(piece.x > newx && piece.y < newy){
            int i = piece.x - 1;
            int j = piece.y + 1;
            while(i >newx && j < newy ){
                if(occupied(i, j)){
                    return true;
                }
                i--;
                j++;
            }

        }
        if(piece.x > newx && piece.y > newy) {
            int i = piece.x - 1;
            int j = piece.y - 1;
            while(i >newx && j > newy ){
                if(occupied(i, j)){
                    return true;
                }
                i--;
                j--;
            }

        }
    }
    return false;
}

bool Model::valid_move(Piece piece, int newx, int newy)
{
//NO TEAM KILLING, so we need to add for every piece if occupied(newx, newy) &&
//board[newx][newy].color == color return false
    if((!(((newx > 7 || newx < 0) || ((newy>7) || newy<0))
    ||(newx == piece.x && newy == piece.y)) || board[newy][newx].color !=
    piece.color)){
        if (piece.name == Model::Piecename::empty) {
            return false;
        }
        if (piece.name == Model::Piecename::bishop) {
            if (!intheway(piece, newx, newy)){
                if ((newx - piece.x) == 0) {
                    return (false);
                }
                return (((newy - piece.y) / (newx - piece.x) == 1) ||
                        ((newy - piece.y) / (newx - piece.x) == -1));
            }
        }
        if (piece.name == Model::Piecename::king) {
            //if check fails rewrite with inequalities
            return (((newx == (piece.x + 1)) && (newy == (piece.y + 1)))
                    || ((newx == (piece.x + 1)) && (newy == (piece.y - 1)))
                    || ((newx == (piece.x - 1)) && (newy == (piece.y - 1)))
                    || ((newx == (piece.x - 1)) && (newy == (piece.y + 1)))
                    || ((newx == (piece.x + 1)) && (newy == piece.y))
                    || ((newx == (piece.x)) && (newy == (piece.y + 1)))
                    || ((newx == (piece.x - 1)) && (newy == piece.y))
                    || ((newx == (piece.x)) && (newy == (piece.y - 1))));

        }
        //ISSUE FOR BISHOPS AND QUEEN WITH DIVIDING BY ZERO
        //
        if (piece.name == Model::Piecename::queen) {
            if (!intheway(piece, newx, newy)){
                if ((newx - piece.x) == 0) {
                    return ((newx == piece.x) || (newy == piece.y));
                }
                if (newy - piece.y == 0) {
                    return ((newx == piece.x) || (newy == piece.y));
                }
                return ((newy - piece.y) / (newx - piece.x) == 1) ||
                       ((newy - piece.y) / (newx - piece.x) == -1);
            }
        }
        if (piece.name == Model::Piecename::rook) {

            if (!intheway(piece, newx, newy)){
                return (newx == piece.x || newy == piece.y);
            }
        }
        if (piece.name == Model::Piecename::knight) {
            return (((newx == (piece.x + 1)) && (newy == (piece.y + 2)))
                    || ((newx == (piece.x + 1)) && (newy == (piece.y - 2)))
                    || ((newx == (piece.x - 1)) && (newy == (piece.y - 2)))
                    || ((newx == (piece.x - 1)) && (newy == (piece.y + 2)))
                    || ((newx == (piece.x + 2)) && (newy == (piece.y + 1)))
                    || ((newx == (piece.x - 2)) && (newy == (piece.y + 1)))
                    || ((newx == (piece.x - 2)) && (newy == (piece.y - 1)))
                    || ((newx == (piece.x + 2)) && (newy == (piece.y - 1))));
        }
        if (piece.name == Model::Piecename::pawn) {
            if(piece.color == Model::Player::light){
                if(!(occupied(newx, newy))){
                    if((newx == piece.x) && (newy == (piece.y - 1))){
                        return true;
                    }

                }
                if(occupied(newx, newy)){
                    if(board[newy][newx].color == Model::Player::dark) {
                        if (((newx == piece.x + 1) &&
                             (newy == (piece.y - 1))) || (
                                    (newx == piece.x - 1) &&
                                    newy == (piece.y - 1))) {
                            return true;
                        }
                    }
                }
            }
            if(piece.color == Model::Player::dark){
                if(!(occupied(newx, newy))){
                    if((newx == piece.x) && (newy == (piece.y + 1))){
                        return true;
                    }

                }
                if(occupied(newx, newy)) {
                    if(board[newy][newx].color == Model::Player::light) {
                        if (((newx == piece.x + 1) && newy == (piece.y + 1)) ||
                            (
                                    (newx == piece.x - 1) &&
                                    newy == (piece.y + 1))) {
                            return true;
                        }
                    }
                }
            }

        }
    }
    return false;
}


Model::Player
Model::other_player(Model::Player player)
{
    switch (player) {
    case Model::Player::light:
        return Model::Player::dark;
    case Model::Player::dark:
        return Model::Player::light;
    default:
        return player;
    }
}

bool
Model::onlytwokings(){
    int x = 0;
    for (std::vector<Model::Piece> p: board){
        for(Model::Piece pi: p){
            if(pi.name != Model::Piecename::king && pi.name !=
            Model::Piecename::empty) {
                x++;
            }
        }
    }
    return(x == 0);
}
bool
Model::twokings(){
    int x = 0;
    for (std::vector<Model::Piece> p: board){
        for(Model::Piece pi: p){
            if(pi.name == Model::Piecename::king){
                x++;
            }
        }
    }
    return(x == 2);
}
bool
Model::oneking(){
    int x = 0;
    for (std::vector<Model::Piece> p: board){
        for(Model::Piece pi: p){
            if(pi.name == Model::Piecename::king){
                x++;
            }
        }
    }
    return(x == 1);
}

void
Model::promotepawn(Piece piece)
{
    int ax= piece.x;
    int ay = piece.y;

    if (piece.name == Model::Piecename::pawn){
        if(piece.color == Model::Player::light){
            if (piece.y == 0){
                board[ay][ax].name = Model::Piecename::queen;
            }
        }
        if(piece.color == Model::Player::dark){
            if(piece.y == 7){
                board[ay][ax].name = Model::Piecename::queen;
            }
        }
    }
    return;
}
void
Model::advance_turn_()
{
    turn_ = other_player(turn());
    if(onlytwokings()){
        set_game_over_();
    }
    else if(oneking()){
        set_game_over_();
    }
    else{
        return;
    }

}

void Model::swap(Model::Piece a, Model::Piece b){
    int ax= a.x;
    int ay = a.y;
    int bx = b.x;
    int by = b.y;
    board[ay][ax] = b;
    board[by][bx] = a;
    board[ay][ax].x = ax;
    board[ay][ax].y = ay;
    board[by][bx].x = bx;
    board[by][bx].y = by;

}

void Model::capture(Model::Piece a){
    int ax= a.x;
    int ay = a.y;
    board[ay][ax].name = Model::Piecename::empty;
    board[ay][ax].color = Model::Player::neither;
}

void
Model::set_game_over_()
{
    turn_ = Model::Player::neither;
    if(onlytwokings()){
        winner_ = Model::Player::neither;
    } else {
        for (std::vector<Model::Piece> p: board) {
            for (Model::Piece pi: p) {
                if (pi.name == Model::Piecename::king) {
                    winner_ = pi.color;
                }
            }
        }
    }

}

void Model::play_move(ge211::Posn<int> positiona, ge211::Posn<int> positionb){
    Piece boardpiece = board[positiona.y][positiona.x];
    if(turn() == boardpiece.color) {
        if (valid_move(boardpiece, positionb.x, positionb.y)) {
            if (!occupied(positionb.x, positionb.y)) {
                swap(board[positiona.y][positiona.x], board[positionb.y]
                [positionb.x]);
                promotepawn(board[positionb.y]
                            [positionb.x]);
                advance_turn_();


            } else {
                if(occupied(positionb.x, positionb.y)){
                    if(board[positionb.y]
                       [positionb.x].color
                       == other_player(turn())){
                        capture(board[positionb.y][positionb.x]);
                        swap(board[positiona.y][positiona.x], board[positionb.y]
                        [positionb.x]);
                        promotepawn(board[positionb.y]
                                    [positionb.x]);
                        advance_turn_();

                    }

                }
            }

        }


    }
    return;
}



//}
//ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK,
//PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN,
//BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK,
//BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK,
//BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK,
//BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK,
//PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN,
//ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK};