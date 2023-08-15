 // В простой игре на двух игроков игроки ходят по полю и по определенному закону собирают ресурсы или обмениваются ими.
 // Мы можем использовать паттерн "Снимок" для сохранения состояния игры и восстановления его для возможности отката к предыдущему состоянию.

#include <iostream>
#include <string>
#include <vector>

// Снимок (Memento)
class GameSnapshot {
private:
    std::string currentPlayer;
    int player1Resources;
    int player2Resources;

public:
    GameSnapshot(const std::string& currPlayer, int p1Res, int p2Res)
        : currentPlayer(currPlayer), player1Resources(p1Res), player2Resources(p2Res) {}

    std::string getCurrentPlayer() const {
        return currentPlayer;
    }

    int getPlayer1Resources() const {
        return player1Resources;
    }

    int getPlayer2Resources() const {
        return player2Resources;
    }
};

// Оригинальный объект (Originator)
class BoardGame {
private:
    std::string currentPlayer;
    int player1Resources;
    int player2Resources;

public:
    void playTurn(const std::string& currPlayer, int p1Res, int p2Res) {
        currentPlayer = currPlayer;
        player1Resources = p1Res;
        player2Resources = p2Res;
    }

    GameSnapshot createSnapshot() const {
        return GameSnapshot(currentPlayer, player1Resources, player2Resources);
    }

    void restoreSnapshot(const GameSnapshot& snapshot) {
        currentPlayer = snapshot.getCurrentPlayer();
        player1Resources = snapshot.getPlayer1Resources();
        player2Resources = snapshot.getPlayer2Resources();
    }

    void displayStatus() const {
        std::cout << "Текущий игрок: " << currentPlayer << std::endl;
        std::cout << "Ресурсы игрока 1: " << player1Resources << std::endl;
        std::cout << "Ресурсы игрока 2: " << player2Resources << std::endl;
    }
};

// Хранитель (Caretaker)
class GameHistory {
private:
    std::vector<GameSnapshot> snapshots;

public:
    void addSnapshot(const GameSnapshot& snapshot) {
        snapshots.push_back(snapshot);
    }

    GameSnapshot getSnapshot(int index) const {
        return snapshots[index];
    }
};

//int main() {
//
//    setlocale(LC_ALL, "Russian");
//    BoardGame game;
//    GameHistory history;
//
//    game.playTurn("Игрок 1", 10, 8);
//    history.addSnapshot(game.createSnapshot());
//
//    game.playTurn("Игрок 2", 14, 5);
//    history.addSnapshot(game.createSnapshot());
//
//    game.playTurn("Игрок 1", 12, 9);
//
//    std::cout << "Текущее состояние игры:" << std::endl;
//    game.displayStatus();
//
//    // Восстановление первого состояния
//    game.restoreSnapshot(history.getSnapshot(0));
//    std::cout << "\nВосстановленное состояние игры:" << std::endl;
//    game.displayStatus();
//
//    return 0;
//}
