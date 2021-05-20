/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** Pacman
*/

#include "Pacman.hpp"

Pacman::Pacman(): GameModule()
{
    this->_clock = std::chrono::system_clock::now();
    this->_startClock = std::chrono::system_clock::now();
    this->_level = 1;
    this->_doorOpened = false;
    this->_outsideGhosts = 0;
    this->_timeGhost = 0.0f;
    this->_init();
}

void Pacman::_init(void)
{
    this->_configureSettings();
    this->_createTiles();
    this->_createObjects();
    this->_doorOpened = false;
    this->_changeDoor();
    this->reset();
}

void Pacman::_createTiles(void)
{
    std::ifstream file("./assets/pacman/maps/pacman_" + std::to_string(this->_level) + ".map");
    std::string line;
    int y = 0;
    int x = 0;

    if (!file.is_open()) {
        throw ObjectError("Can't open the map file");
    }
    while (std::getline(file, line)) {
        x = 0;
        for (char c : line) {
            if (c == '#') {
                this->_tiles.push_back(this->_createWall(x, y));
            } else {
                this->_tiles.push_back(this->_createFloor(x, y));
            }
            x += 1;
        }
        y += 1;
    }
    if (this->_tiles.size() <= 0) {
        throw ObjectError("There's no tiles on pacman map");
    }
}

void Pacman::_createObjects(void)
{
    std::ifstream file("./assets/pacman/maps/pacman_" + std::to_string(this->_level) + ".map");
    std::string line;
    int y = 0;
    int x = 0;
    bool ghostSpawn = false;
    bool piece = false;
    bool player = false;

    if (!file.is_open()) {
        throw ObjectError("Can't open the map file");
    }
    while (std::getline(file, line)) {
        x = 0;
        for (char c : line) {
            switch (c) {
                case '.': // Point
                    this->_objects.push_back(this->_createPiece(x, y));
                    piece = true;
                    break;
                case 'P': // Player
                    if (player)
                        throw ObjectError("There's already a player spawn point");
                    this->_playerSpawn = Vector2i(x, y) * 32;
                    this->_objects.push_back(this->_createPlayer(x, y));
                    player = true;
                    break;
                case 'o': // Fruit
                    this->_objects.push_back(this->_createFruit(x, y));
                    break;
                case '!': // Ghost spawn
                    if (ghostSpawn)
                        throw ObjectError("There's already a ghost spawn point");
                    this->_ghostSpawn.x = x * 32;
                    this->_ghostSpawn.y = y * 32;
                    ghostSpawn = true;
                    break;
                default:
                    break;
            }
            x += 1;
        }
        y += 1;
    }
    if (this->_objects.size() <= 0) {
        throw ObjectError("There's no objects on pacman map");
    }
    if (!piece || !player || !ghostSpawn) {
        throw ObjectError("A map must contain at least 1 piece, a unique player spawn and a unique ghost spawn");
    }
    this->_objects.push_back(this->_createGhost(this->_ghostSpawn.x, this->_ghostSpawn.y, 1));
    this->_objects.push_back(this->_createGhost(this->_ghostSpawn.x, this->_ghostSpawn.y, 2));
    this->_objects.push_back(this->_createGhost(this->_ghostSpawn.x, this->_ghostSpawn.y, 3));
    this->_objects.push_back(this->_createGhost(this->_ghostSpawn.x, this->_ghostSpawn.y, 4));
}

Object Pacman::_createGhost(int x, int y, int ghostType)
{
    Object ghost;

    ghost.setCoords(this->_ghostSpawn);
    ghost.setContent(Content::ENEMY);
    ghost.setColor(Vector3i(255, 255, 255));
    ghost.setWalkable(true);
    ghost.setSize(32);

    switch (ghostType) {
        case 1:
            ghost.setFilePath(this->_settings.getAssetsFolderPath() + "greenghost");
            break;
        case 2:
            ghost.setFilePath(this->_settings.getAssetsFolderPath() + "redghost");
            break;
        case 3:
            ghost.setFilePath(this->_settings.getAssetsFolderPath() + "yellowghost");
            break;
        default:
            ghost.setFilePath(this->_settings.getAssetsFolderPath() + "blueghost");
            break;
    }
    this->_ghostOldPos.push_back(Vector2i(this->_ghostSpawn));

    return ghost;
}

Object Pacman::_createPiece(int x, int y)
{
    Object piece;

    piece.setCoords(Vector2i(x, y) * 32);
    piece.setContent(Content::COLLECTABLE);
    piece.setColor(Vector3i(255, 255, 255));
    piece.setWalkable(true);
    piece.setActive(true);
    piece.setFilePath(this->_settings.getAssetsFolderPath() + "piece");
    piece.setSize(32);
    return piece;
}

Object Pacman::_createFruit(int x, int y)
{
    Object fruit;

    fruit.setCoords(Vector2i(x, y) * 32);
    fruit.setContent(Content::COLLECTABLE);
    fruit.setColor(Vector3i(255, 255, 255));
    fruit.setWalkable(true);
    fruit.setActive(true);
    fruit.setFilePath(this->_settings.getAssetsFolderPath() + "fruit");
    fruit.setSize(32);
    return fruit;
}

Object Pacman::_createPlayer(int x, int y)
{
    Object player;

    player.setCoords(Vector2i(x, y) * 32);
    player.setContent(Content::PLAYER);
    player.setColor(Vector3i(255, 255, 255));
    player.setWalkable(true);
    player.setActive(true);
    player.setFilePath(this->_settings.getAssetsFolderPath() + "player");
    player.setSize(32);
    return player;
}

Object Pacman::_createFloor(int x, int y)
{
    Object floor;

    floor.setCoords(Vector2i(x, y) * 32);
    floor.setContent(Content::FLOOR);
    floor.setColor(Vector3i(0, 0, 0));
    floor.setWalkable(true);
    floor.setActive(true);
    floor.setFilePath(this->_settings.getAssetsFolderPath() + "floor");
    floor.setSize(32);
    return floor;
}

Object Pacman::_createWall(int x, int y)
{
    Object wall;

    wall.setCoords(Vector2i(x, y) * 32);
    wall.setContent(Content::WALL);
    wall.setColor(Vector3i(255, 255, 255));
    wall.setWalkable(false);
    wall.setActive(true);
    wall.setFilePath(this->_settings.getAssetsFolderPath() + "wall");
    wall.setSize(32);
    return wall;
}

void Pacman::_configureSettings(void)
{
    this->_settings.setAssetsFolderPath("./assets/pacman/img/");
    this->_settings.setMusicPath("./assets/pacman/songs/pacman_song.wav");
    this->_settings.setScene(Scene::GAME);
    this->_settings.setScore(0);
}

void Pacman::_changeDoor(void)
{
    Object tile;

    for (Object t : this->_tiles) {
        if (t.getCoords() == Vector2i(this->_ghostSpawn.x, this->_ghostSpawn.y + 32)) {
            tile = t;
            break;
        }
    }

    if (this->_doorOpened) {
        tile.setFilePath(this->_settings.getAssetsFolderPath() + "floor");
        tile.setContent(Content::FLOOR);
        tile.setWalkable(true);
    } else {
        tile.setFilePath(this->_settings.getAssetsFolderPath() + "wall");
        tile.setContent(Content::WALL);
        tile.setWalkable(false);
    }
}

bool Pacman::update(Vector2i mouse, char key)
{
    this->handleMouseEvent(mouse);
    this->handleKeyEvent(key);

    auto now_time = std::chrono::system_clock::now();
    std::chrono::duration<double> difference = now_time - this->_startClock;

    if (this->_timeGhost >= 5.0f) {
        this->_timeGhost = 0.0f;
        if (this->_outsideGhosts < 4) {
            int ghostInd = this->_getIndexGhost(this->_outsideGhosts + 1);
            this->_objects.at(ghostInd).setCoords(Vector2i(this->_playerSpawn));
            this->_outsideGhosts += 1;
        }
    }
    difference = now_time - this->_clock;
    if (difference.count() >= 0.25) {
        this->_timeGhost += 0.25f;
        this->_clock = std::chrono::system_clock::now();
        this->_movePlayer();
        this->_moveGhost(1);
        this->_moveGhost(2);
        this->_moveGhost(3);
        this->_moveGhost(4);
    }
    return true;
}

void Pacman::_movePlayer(void)
{
    std::size_t index = 0;
    Vector2i positions;
    bool enemyOnCase = false;

    for (Object obj : this->_objects) {
        if (obj.getContent() == Content::PLAYER) {
            break;
        }
        index += 1;
    }
    positions = this->_objects.at(index).getCoords();
    Vector2i backup = Vector2i(this->_velocity);
    positions += this->_velocity * 32;
    this->_velocity = Vector2i(backup);

    if (!this->_isAWall(positions)) {
        std::vector<Object> objects = this->_getObjectsAtPosition(positions);
        for (Object obj : objects) {
            if (obj.getContent() == Content::ENEMY) {
                enemyOnCase = true;
                this->_objects.at(index).setCoords(this->_playerSpawn);
                this->reset();
                break;
            }
        }
        if (!enemyOnCase) {
            this->_objects.at(index).setCoords(positions);
            std::size_t i = 0;
            for (Object obj : this->_objects) {
                if (obj.getCoords() == positions) {
                    if (obj.getContent() == Content::COLLECTABLE && obj.isActive()) {
                        this->_objects.at(i).setActive(false);
                        this->_settings.setScore(this->_settings.getScore() + 1);
                        // Regarder si c'est un fruit
                    }
                }
                i += 1;
            }
        }
    }
}

void Pacman::_moveGhost(int ghost)
{
    int indexGhost = this->_getIndexGhost(ghost);
    std::vector<Vector2i> possiblePositions = this->_getPossiblePaths(this->_objects.at(indexGhost).getCoords());
    Vector2i nextPos = Vector2i(-1, -1);

    std::size_t index = 0;
    for (Object object : this->_objects) {
        if (object.getContent() == Content::PLAYER) {
            break;
        }
        index++;
    }
    Vector2i playerPositions = this->_objects.at(index).getCoords();

    if (possiblePositions.size() == 1) {
        nextPos = possiblePositions.at(0);
    } else {
        std::vector<Vector2i>::iterator it = std::find(possiblePositions.begin(), possiblePositions.end(), this->_ghostOldPos.at(ghost - 1));
        if (it != possiblePositions.end()) {
            possiblePositions.erase(it);
        }
        std::srand(std::time(NULL));
        nextPos = possiblePositions.at(std::rand() % possiblePositions.size());
    }
    this->_ghostOldPos.at(ghost - 1).x = this->_objects.at(indexGhost).getCoords().x;
    this->_ghostOldPos.at(ghost - 1).y = this->_objects.at(indexGhost).getCoords().y;
    // if (possiblePositions.size() > 1) {
    //     nextPos = this->_calculatePath(possiblePositions, playerPositions, this->_objects.at(indexGhost).getCoords());
    // } else {
    //     nextPos = possiblePositions.at(0);
    // }

    this->_objects.at(indexGhost).setCoords(nextPos);

    if (playerPositions == nextPos) {
        this->_objects.at(index).setCoords(this->_playerSpawn);
        this->reset();
    }
}

std::vector<Vector2i> Pacman::_getPossiblePaths(Vector2i ghostPositions)
{
    std::vector<Vector2i> positions;

    for (Object tile : this->_tiles) {
        if (!this->_isAWall(tile.getCoords())) {
            Vector2i coords = Vector2i(tile.getCoords());
            if (coords == Vector2i(ghostPositions.x + 32, ghostPositions.y)) {
                positions.push_back(coords);
            } else if (coords == Vector2i(ghostPositions.x - 32, ghostPositions.y)) {
                positions.push_back(coords);
            } else if (coords == Vector2i(ghostPositions.x, ghostPositions.y + 32)) {
                positions.push_back(coords);
            } else if (coords == Vector2i(ghostPositions.x, ghostPositions.y - 32)) {
                positions.push_back(coords);
            }
        }
    }
    return positions;
}

int Pacman::_getIndexGhost(int ghost)
{
    int count = 0;
    int index = 0;

    for (Object obj : this->_objects) {
        if (obj.getContent() == Content::ENEMY) {
            count += 1;
            if (ghost == count) {
                return index;
            }
        }
        index += 1;
    }
    throw ObjectError("This ghost cannot be found.");
}

bool Pacman::_isAWall(Vector2i positions)
{
    for (Object tile : this->_tiles) {
        if (tile.getCoords() == positions) {
            if (!tile.isActive())
                continue;
            if (tile.getContent() == Content::WALL || !tile.isWalkable()) {
                return true;
            }
        }
    }
    return false;
}

std::vector<Object> Pacman::_getObjectsAtPosition(Vector2i position)
{
    std::vector<Object> objects;

    for (Object obj : this->_objects) {
        if (obj.getCoords() == position) {
            objects.push_back(obj);
        }
    }
    return objects;
}

void Pacman::handleKeyEvent(char key)
{
    switch (key) {
        case 'z':
            this->_velocity = Vector2i(0, -1);
            break;
        case 's':
            this->_velocity = Vector2i(0, 1);
            break;
        case 'q':
            this->_velocity = Vector2i(-1, 0);
            break;
        case 'd':
            this->_velocity = Vector2i(1, 0);
            break;
        default:
            break;
    }
}

void Pacman::reset()
{
    this->_clock = std::chrono::system_clock::now();
    this->_startClock = std::chrono::system_clock::now();
    this->_settings.setScore(0);
    this->_objects.at(this->_getIndexGhost(1)).setCoords(this->_ghostSpawn);
    this->_objects.at(this->_getIndexGhost(2)).setCoords(this->_ghostSpawn);
    this->_objects.at(this->_getIndexGhost(3)).setCoords(this->_ghostSpawn);
    this->_objects.at(this->_getIndexGhost(4)).setCoords(this->_ghostSpawn);
    this->_outsideGhosts = 0;
    this->_timeGhost = 0.0f;

    this->_doorOpened = false;
    this->_changeDoor();

    std::size_t i = 0;
    for (Object tile : this->_tiles) {
        if (!tile.isActive()) {
            this->_tiles.at(i).setActive(true);
        }
    }
    i = 0;
    for (Object object : this->_objects) {
        if (!object.isActive()) {
            this->_objects.at(i).setActive(true);
        }
        if (object.getContent() == Content::PLAYER) {
            this->_objects.at(i).setCoords(this->_playerSpawn);
        }
        i++;
    }
}

Vector2i Pacman::_calculatePath(std::vector<Vector2i> possiblePaths, Vector2i playerPos, Vector2i ghostPos)
{
    Vector2i tmpGhost;
    bool found = false;

    std::vector<Vector2i> visited;
    std::vector<Vector2i> posWithPathChoice;
    std::vector<Vector2i> possiblePathsGhost;
    std::vector<int> length;

    for (Vector2i startPos : possiblePaths) {
        found = false;
        visited.clear();
        posWithPathChoice.clear();
        possiblePathsGhost.clear();
        tmpGhost = Vector2i(startPos);

        while (!found) {
            possiblePathsGhost = this->_getPossiblePaths(tmpGhost); // Possibilités de chemin.

            // Si le fantôme est aux coordonnées du joueur
            if (tmpGhost == playerPos) {
                length.push_back(sqrt(pow(tmpGhost.x - startPos.x, 2) + pow(tmpGhost.y - startPos.y, 2)));
                found = true;
                continue;
            }

            // Si pos du fantôme dans la liste, on supprime.
            std::vector<Vector2i>::iterator it = std::find(possiblePathsGhost.begin(), possiblePathsGhost.end(), ghostPos);
            if (it != possiblePathsGhost.end()) {
                possiblePathsGhost.erase(it);
            }

            // Si la position n'est pas visitée on l'ajoute à la liste.
            it = std::find(visited.begin(), visited.end(), tmpGhost);
            if (it == visited.end()) {
                visited.push_back(Vector2i(tmpGhost));
            }

            // Si carrefour à cet endroit, on le supprime.
            it = std::find(posWithPathChoice.begin(), posWithPathChoice.end(), tmpGhost);
            if (it != posWithPathChoice.end()) {
                posWithPathChoice.erase(it);
            }

            // Boucle sur tous les chemins possibles
            bool tmp = false;
            for (Vector2i pos : possiblePathsGhost) {
                if (std::find(visited.begin(), visited.end(), pos) == visited.end()) { // Si le chemin n'est pas visité
                    posWithPathChoice.push_back(Vector2i(tmpGhost)); // On ajoute ce carrefour possible.
                    tmpGhost = Vector2i(pos); // On change la position du fantôme
                    tmp = true; // On indique qu'un chemin a été trouvé
                    break;
                }
            }
            if (tmp) { // Si un chemin a été trouvé on redémarre la boucle aux nouvelles pos
                continue;
            }

            if (posWithPathChoice.size() > 0) { // Si il reste des carrefours, on se déplace dessus
                tmpGhost = posWithPathChoice.at(posWithPathChoice.size() - 1);
                continue;
            } else { // Il n'y a plus de carrefours donc plus de chemins possibles par ici.
                length.push_back(99999);
                found = true;
                continue;
            }
        }
    }

    int index = 0;
    int indexMin = 0;
    int valMin = length.at(0);
    for (int val : length) {
        if (val < valMin) {
            valMin = val;
            indexMin = index;
        }
        index++;
    }
    return (Vector2i(possiblePaths.at(indexMin).x, possiblePaths.at(indexMin).y));
}

Pacman::~Pacman()
{
}
