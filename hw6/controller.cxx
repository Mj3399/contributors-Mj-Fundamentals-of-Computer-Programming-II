#include "controller.hxx"

Controller::Controller(int size)
        : Controller(size, size)
{ }

Controller::Controller(int width, int height)
        : model_(width, height),
          view_(model_),
          positionmouse(0,0)
{ }

void
Controller::draw(ge211::Sprite_set& sprites)
{
    view_.draw(sprites, positionmouse);
}

View::Dimensions
Controller::initial_window_dimensions() const
{
    return view_.initial_window_dimensions();
}

std::string
Controller::initial_window_title() const
{
    return view_.initial_window_title();
}

void
Controller::on_mouse_up(ge211::Mouse_button, ge211::Posn<int> position)
{

    const Move* movep = model_.find_move(view_.screen_to_board(position));
    if (movep == nullptr) {
        return;
    }
    model_.play_move(movep->first);

}

// Informs the model of the mouse position (and thus the desired paddle
// position) via `Model::paddle_to(Position)`.
//
// NOTE: This can be done in 1 line as well.
void
Controller::on_mouse_move(ge211::Posn<int> position)
{
    positionmouse = position;


}

