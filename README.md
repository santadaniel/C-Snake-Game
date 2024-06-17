## Game:
The game is written in C programing language. It presents the game using SDL, which is a cross-platrform<br />
development library. It also uses SDL2_gfx library, it is mainly used for drawing primitive figures. The game<br />
starts  by  opening  a  window  and  generating the game.  At the moment the game instantly  starts  with two<br />
snakes, a yellow and a blue one. It also generates a food in the map, the coordinate of the food  is different<br />
from the coordinates of the snakes, so the food will not generate into one of the snakes. If a snake runs<br />
into a food, the food disappears, a new food is created and the snake that ate the food grows by 1. Currently<br />
the game lacks of a menu, an ending, a logic that forbids the snakes running out the map or running into each <br />
other.<br />

# In order to see what each function and struct does, open: Files->File List->choose a header.# C-Snake-Game
