#include "controller.hxx"
#include "iostream"
Controller::Controller()
        : view_(model_),
          positiondown(0,0),
            positionmouse(0,0)
{ }

void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set);
}


void
Controller::on_mouse_up(
        ge211::Mouse_button button, ge211::Posn<int>
positionb)
{
    std::cout << view_.screen_to_board(positiondown);
    std::cout << view_.screen_to_board(positionb);
    model_.play_move(view_.screen_to_board(positiondown), view_
    .screen_to_board(positionb));
}

void
Controller::on_mouse_down(
        ge211::Mouse_button button, ge211::Posn<int>
positiona)
{
    positiondown = positiona;

}

void
Controller::on_mouse_move(ge211::Posn<int> position)
{
    positionmouse = position;
}
void
Controller::on_key_down(ge211::Key key)
{
    if (key == ge211::Key::code(' ')) {
        model_.advance_turn_();
    }
}

ge211::geometry::Dims<int>
Controller::initial_window_dimensions() const
{
    return {1000,1000};
}