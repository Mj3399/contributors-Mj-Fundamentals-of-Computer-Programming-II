#pragma once

#include "model.hxx"
#include "iostream"

class View
{
public:
    explicit View(Model const& model);

    void draw(ge211::Sprite_set& set);

    using Position = ge211::Posn<int>;

    View::Position
    board_to_screen(
            Position logical )
    const;

    View::Position
    screen_to_board (
            View::Position physical )

    const;
private:
    Model const& model_;
    ge211::Rectangle_sprite const tile;
    ge211::Rectangle_sprite const wintile;
    ge211::Rectangle_sprite const drawtile;
    ge211::Font sans{"sans.ttf", 16};
    ge211::Image_sprite WRook;
    ge211::Image_sprite BRook;
    ge211::Image_sprite BBishop;
    ge211::Image_sprite WBishop;
    ge211::Image_sprite BKing;
    ge211::Image_sprite WKing;
    ge211::Image_sprite BQueen;
    ge211::Image_sprite WQueen;
    ge211::Image_sprite BPawn;
    ge211::Image_sprite WPawn;
    ge211::Image_sprite BKnight;
    ge211::Image_sprite WKnight;

};
