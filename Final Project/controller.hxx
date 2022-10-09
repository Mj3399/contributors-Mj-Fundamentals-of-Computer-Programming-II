#pragma once

#include "model.hxx"
#include "view.hxx"

#include <ge211.hxx>

class Controller : public ge211::Abstract_game
{
public:
    Controller();
    ge211::Posn<int> positiondown;
    ge211::Posn<int> positionmouse;
    void on_mouse_up(ge211::Mouse_button button, ge211::Posn<int> position)
    override;
    void on_key_down(ge211::Key) override;

    void on_mouse_down(ge211::Mouse_button button, ge211::Posn<int> position)
    override;

    void on_mouse_move(ge211::Posn<int>) override;
protected:
    void draw(ge211::Sprite_set& set) override;
    ge211::geometry::Dims<int> initial_window_dimensions() const override;
private:
    Model model_;
    View view_;

};
