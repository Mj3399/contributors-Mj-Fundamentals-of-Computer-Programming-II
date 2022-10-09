#include "view.hxx"

using Color = ge211::Color;

static int const grid_size = 100;
//colors
Color const black{0,0,0};
Color const white{255,255,255};
Color const green{0,120,0};
Color const red{255,0,0};
Color const miniblack{40,40,40};
Color const miniwhite{210,210,210};
Color const grey{190,190,190};

View::View(Model const& model)
        : model_(model),
        tile({90, 90}, white),
          wintile({90, 90}, green),
          drawtile({90, 90}, black),
          WRook("WRook.jpg"),
          BRook("BRook.jpg"),
          BBishop("BBishop.jpg"),
          WBishop("WBishop.jpg"),
          BKing("BKing.jpg"),
          WKing("WKing.jpg"),
          BQueen("BQueen.jpg"),
          WQueen("WQueen.jpg"),
          BPawn("BPawn.jpg"),
          WPawn("WPawn.jpg"),
          BKnight("BKnight.jpg"),
          WKnight("WKnight.jpg")

{ }

View::Position
View::board_to_screen(
        Position logical )
const
{
    logical = {logical.x * grid_size, logical.y * grid_size};
    return logical;
}


View::Position
View :: screen_to_board (
        View :: Position physical )
const
{
    physical = {physical.x / grid_size, physical.y / grid_size};
    return physical;
}
void
View::draw(ge211::Sprite_set& set)
{
    for (std::vector<Model::Piece> p: model_.board){
        for(Model::Piece pi: p){
            if (pi.name == Model::Piecename::bishop && pi.color ==
                                                       Model::Player::dark) {
                set.add_sprite(BBishop, board_to_screen({pi.x, pi.y}), 1);

            }
            if (pi.name == Model::Piecename::king && pi.color ==
                                                     Model::Player::dark) {
                //if check fails rewrite with inequalities
                set.add_sprite(BKing, board_to_screen({pi.x, pi.y}), 1);

            }
            if (pi.name == Model::Piecename::queen && pi.color ==
                                                      Model::Player::dark) {
                set.add_sprite(BQueen, board_to_screen({pi.x, pi.y}), 1);
            }
            if (pi.name == Model::Piecename::rook && pi.color ==
                                                     Model::Player::dark) {
                set.add_sprite(BRook, board_to_screen({pi.x, pi.y}), 1);
            }
            if (pi.name == Model::Piecename::knight && pi.color ==
                                                       Model::Player::dark) {
                set.add_sprite(BKnight, board_to_screen({pi.x, pi.y}), 1);
            }
            if (pi.name == Model::Piecename::pawn && pi.color ==
                                                     Model::Player::dark) {
                set.add_sprite(BPawn, board_to_screen({pi.x, pi.y}), 1);
            }
            if (pi.name == Model::Piecename::bishop && pi.color ==
                                                       Model::Player::light) {
                set.add_sprite(WBishop, board_to_screen({pi.x, pi.y}), 1);

            }
            if (pi.name == Model::Piecename::king && pi.color ==
                                                     Model::Player::light) {
                //if check fails rewrite with inequalities
                set.add_sprite(WKing, board_to_screen({pi.x, pi.y}), 1);

            }
            if (pi.name == Model::Piecename::queen && pi.color ==
                                                      Model::Player::light) {
                set.add_sprite(WQueen, board_to_screen({pi.x, pi.y}), 1);
            }
            if (pi.name == Model::Piecename::rook && pi.color ==
                                                     Model::Player::light) {
                set.add_sprite(WRook, board_to_screen({pi.x, pi.y}), 1);
            }
            if (pi.name == Model::Piecename::knight && pi.color ==
                                                       Model::Player::light) {
                set.add_sprite(WKnight, board_to_screen({pi.x, pi.y}), 1);
            }
            if (pi.name == Model::Piecename::pawn && pi.color ==
                                                     Model::Player::light) {
                set.add_sprite(WPawn, board_to_screen({pi.x, pi.y}), 1);
            }

            set.add_sprite(tile, board_to_screen({pi.x, pi.y}), 0);
            if(model_.winner_ != Model::Player::neither){
                if(pi.name == Model::Piecename::king){
                    set.add_sprite(wintile, board_to_screen({pi.x, pi.y}), 0);
                }

            }

        }

    }
    int x = 0;
    for (std::vector<Model::Piece> p: model_.board){
        for(Model::Piece pi: p){
            if(pi.name != Model::Piecename::king){
                x++;
            }
        }
    }
    if(x == 0){
        for (std::vector<Model::Piece> p: model_.board) {
            for (Model::Piece pi: p) {
                if (pi.name == Model::Piecename::king) {
                    set.add_sprite(drawtile, board_to_screen({pi.x, pi.y}), 0);
                }
            }
        }
    }
}
