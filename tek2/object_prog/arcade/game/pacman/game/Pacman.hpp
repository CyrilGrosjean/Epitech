/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include <fstream>
#include <chrono>
#include <algorithm>
#include <math.h>
#include "../exceptions/PacmanException.hpp"
#include "../../../includes/GameModule.hpp"
#include "../../../includes/Object.hpp"
#include "../../../includes/Settings.hpp"

class Pacman : public GameModule {
    public:
        Pacman();
        ~Pacman();

        bool update(Vector2i mouse, char key) override;
        void handleKeyEvent(char key) override;
        void reset(void) override;

    private:
        void _init(void);
        void _createTiles(void);
        void _createObjects(void);
        void _configureSettings(void);
        void _movePlayer(void);
        void _moveGhost(int ghost);
        bool _isAWall(Vector2i positions);
        std::vector<Object> _getObjectsAtPosition(Vector2i positions);
        Object _createWall(int x, int y);
        Object _createFloor(int x, int y);
        Object _createPiece(int x, int y);
        Object _createFruit(int x, int y);
        Object _createPlayer(int x, int y);
        Object _createGhost(int x, int y, int ghost);
        void _changeDoor(void);

        int _getIndexGhost(int ghost);
        std::vector<Vector2i> _getPossiblePaths(Vector2i ghostPositions);
        Vector2i _calculatePath(std::vector<Vector2i> possiblePaths, Vector2i playerPos, Vector2i ghostPos);

        int _level;
        Vector2i _ghostSpawn;
        Vector2i _playerSpawn;
        Vector2i _velocity;
        bool _doorOpened;
        std::chrono::_V2::system_clock::time_point _clock;
        std::chrono::_V2::system_clock::time_point _startClock;
        std::vector<Vector2i> _ghostOldPos;

        int _outsideGhosts;
        float _timeGhost;
};

#endif /* !PACMAN_HPP_ */
