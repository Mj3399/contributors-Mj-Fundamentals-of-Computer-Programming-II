#include "controller.hxx"

int
main()
{
    Controller().run();

    return 0;
}
//Instructions for game:
// all the specifications can be observed by playing chess as one would
// normally play chess, all the pieces move according to how i specificed
// they should in the specification list and the game state as well works by
// ending when a king is captured or ends as a draw when only two kings are
// left on the board.