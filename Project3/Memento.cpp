 // � ������� ���� �� ���� ������� ������ ����� �� ���� � �� ������������� ������ �������� ������� ��� ������������ ���.
 // �� ����� ������������ ������� "������" ��� ���������� ��������� ���� � �������������� ��� ��� ����������� ������ � ����������� ���������.

#include <iostream>
#include <string>
#include <vector>

// ������ (Memento)
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

// ������������ ������ (Originator)
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
        std::cout << "������� �����: " << currentPlayer << std::endl;
        std::cout << "������� ������ 1: " << player1Resources << std::endl;
        std::cout << "������� ������ 2: " << player2Resources << std::endl;
    }
};

// ��������� (Caretaker)
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
//    game.playTurn("����� 1", 10, 8);
//    history.addSnapshot(game.createSnapshot());
//
//    game.playTurn("����� 2", 14, 5);
//    history.addSnapshot(game.createSnapshot());
//
//    game.playTurn("����� 1", 12, 9);
//
//    std::cout << "������� ��������� ����:" << std::endl;
//    game.displayStatus();
//
//    // �������������� ������� ���������
//    game.restoreSnapshot(history.getSnapshot(0));
//    std::cout << "\n��������������� ��������� ����:" << std::endl;
//    game.displayStatus();
//
//    return 0;
//}
