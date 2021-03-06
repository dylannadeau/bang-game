Bang! is a Wild West-themed card game, designed by Emiliano Sciarra and released by Italian publisher daVinci Editrice in 2002.

This C++ implementation, developed by Matouš Skála as a semestral work in the course Programming and Algorithmics 2 at FIT CTU, is inspired by the original game rules, but it is a little bit simplified.

![Bang! Game Screenshot](http://matousskala.cz/files/bang_screenshot.png)

The architecture is based on a client–server model. When a user hosts a game, GameServer is started as a separate process on his computer. Then all the users (even the host himself) are connecting with GameClient to that server via TCP stream sockets. Each client keeps 2 opened connections – one for synchronous two-way communication (API) and the other one for game state change events from the server. The port on which server is running must be accessible by other players' computers.

This is a free software. You can redestribute it under the terms of the MIT License – see LICENSE.

For instructions how to run this, see INSTALL.

Report bugs to the author – Matouš Skála <skalamat@fit.cvut.cz>.
