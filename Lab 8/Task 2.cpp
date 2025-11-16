#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
using namespace std;

class Combatant {
public:
    string name;
    int health;
    int attackPower;
    
    Combatant(string n = "", int h = 0, int ap = 0) : name(n), health(h), attackPower(ap) {}
    
    bool operator<(const Combatant& other) const {
        return name < other.name;
    }
    
    bool operator>(const Combatant& other) const {
        return name > other.name;
    }
    
    bool operator==(const Combatant& other) const {
        return name == other.name;
    }
};

struct Node {
    Combatant data;
    Node* left;
    Node* right;
    Node(Combatant val) : data(val), left(NULL), right(NULL) {}
};

class CombatBST {
private:
    Node* root;

    Node* insert(Node* node, Combatant val) {
        if (node == NULL) {
            return new Node(val); }
        if (val < node->data) {
            node->left = insert(node->left, val); } 
		else if (val > node->data) {
            node->right = insert(node->right, val); }
        return node;
    }

    Node* find_min(Node* node) {
        while (node && node->left != NULL) {
            node = node->left; }
        return node;
    }

    Node* delete_node(Node* node, Combatant val) {
        if (node == NULL) {
			return NULL; }  
        if (val < node->data) {
            node->left = delete_node(node->left, val); } 
		else if (val > node->data) {
            node->right = delete_node(node->right, val); } 
		else {
            if (node->left == NULL && node->right == NULL) {
                delete node;
                return NULL; } 
			else if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp; } 
			else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp; } 
			else {
                Node* temp = find_min(node->right);
                node->data = temp->data;
                node->right = delete_node(node->right, temp->data); } }
        return node;
    }

    void inorder(Node* node) {
        if (node != NULL) {
            inorder(node->left);
            cout << node->data.name << "(" << node->data.health << "HP) ";
            inorder(node->right); }
    }

    bool search(Node* node, Combatant val) {
        if (node == NULL) {
			return false; }
        if (node->data == val) {
			return true; }
        if (val < node->data) {
			return search(node->left, val); }
        return search(node->right, val);
    }

    int countNodes(Node* node) {
        if (node == NULL) {
			return 0; }
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

public:
    CombatBST() : root(NULL) {}

    void insert(Combatant val) {
        root = insert(root, val);
    }

    void remove(Combatant val) {
        root = delete_node(root, val);
    }

    Combatant getFrontline() {
        if (root == NULL) {
            throw runtime_error("Tree is empty"); }
        Node* minNode = find_min(root);
        return minNode->data;
    }

    void removeFrontline() {
        if (root == NULL) {
			return; }
        Combatant frontline = getFrontline();
        remove(frontline);
    }

    bool isEmpty() {
        return root == NULL;
    }

    void displayTeam() {
        if (root == NULL) {
            cout << "None";
            return; }
        inorder(root);
    }

    bool contains(Combatant val) {
        return search(root, val);
    }

    int size() {
        return countNodes(root);
    }

    void updateCombatant(Combatant oldVal, Combatant newVal) {
        remove(oldVal);
        insert(newVal);
    }
};

class BattleQuestGame {
private:
    CombatBST playerTeam;
    CombatBST enemyTeam;
    int round;
    int numHeroes;
    int numEnemies;
    
    int getRandomDamage() {
        return rand() % 5;
    }
    
    void displayTeams() {
        cout << "=== CURRENT TEAMS ===" << endl;      
        cout << "HEROES: ";
        playerTeam.displayTeam();
        cout << endl;      
        cout << "ENEMIES: ";
        enemyTeam.displayTeam();
        cout << endl << "====================" << endl;
    }

    void initializeTeams() {
        cout << "\n=== INITIALIZE PLAYER TEAM ===" << endl;
        cout << "Enter details for " << numHeroes << " heroes:" << endl;      
        for (int i = 0; i < numHeroes; i++) {
            string name;
            int health, attackPower;          
            cout << "\nHero " << (i + 1) << ":" << endl;
            cout << "Name: ";
            cin >> name;
            cout << "Health: ";
            cin >> health;
            cout << "Attack Power: ";
            cin >> attackPower;          
            playerTeam.insert(Combatant(name, health, attackPower));
            cout << "Hero " << name << " added to the team" << endl;
        }      
        cout << "\n=== INITIALIZE ENEMY TEAM ===" << endl;
        cout << "Enter details for " << numEnemies << " enemies:" << endl;      
        for (int i = 0; i < numEnemies; i++) {
            string name;
            int health, attackPower;           
            cout << "\nEnemy " << (i + 1) << ":" << endl;
            cout << "Name: ";
            cin >> name;
            cout << "Health: ";
            cin >> health;
            cout << "Attack Power: ";
            cin >> attackPower;          
            enemyTeam.insert(Combatant(name, health, attackPower));
            cout << "Enemy " << name << " added to the team" << endl; }
    }

public:
    BattleQuestGame() : round(1) {
        srand(time(0));       
        cout << "=== BATTLEQUEST: BST ARENA ===" << endl;
        cout << "Welcome to the BattleQuest game!" << endl;     
        cout << "\nEnter number of heroes for player team: ";
        cin >> numHeroes;
        cout << "Enter number of enemies for enemy team: ";
        cin >> numEnemies;       
        initializeTeams();  
        cout << "\nTeams have been initialized. Ready for battle!" << endl;
    }

    void playGame() {
        cout << "\n=== BATTLE BEGINS ===" << endl;       
        while (!playerTeam.isEmpty() && !enemyTeam.isEmpty()) {
            playRound();
            round++;            
            if (!playerTeam.isEmpty() && !enemyTeam.isEmpty()) {
                cout << "Press Enter to continue to next round...";
                cin.ignore();
                cin.get();
                cout << endl; } } 
        declareWinner();
    }

private:
    void playRound() {
        cout << "\n=== ROUND " << round << " ===" << endl;
        displayTeams();
        
        if (!playerTeam.isEmpty() && !enemyTeam.isEmpty()) {
            Combatant attacker = playerTeam.getFrontline();
            Combatant defender = enemyTeam.getFrontline();         
            cout << "\n--- PLAYER ATTACK ---" << endl;
            cout << "Attacker: " << attacker.name << " (" << attacker.health << "HP)" << endl;
            cout << "Defender: " << defender.name << " (" << defender.health << "HP)" << endl;           
            int damage = attacker.attackPower + getRandomDamage();
            cout << "Damage dealt: " << damage << " (Base: " << attacker.attackPower << " + Random: " << (damage - attacker.attackPower) << ")" << endl;          
            defender.health -= damage;
            cout << defender.name << "'s HP: " << (defender.health + damage) << " -> " << defender.health << endl;          
            if (defender.health <= 0) {
                cout << "?? " << defender.name << " has been defeated!" << endl;
                enemyTeam.removeFrontline(); } 
			else {
                enemyTeam.remove(defender);
                enemyTeam.insert(defender); } }
        
        if (!playerTeam.isEmpty() && !enemyTeam.isEmpty()) {
            Combatant attacker = enemyTeam.getFrontline();
            Combatant defender = playerTeam.getFrontline();          
            cout << "\n--- ENEMY COUNTER-ATTACK ---" << endl;
            cout << "Attacker: " << attacker.name << " (" << attacker.health << "HP)" << endl;
            cout << "Defender: " << defender.name << " (" << defender.health << "HP)" << endl;           
            int damage = attacker.attackPower + getRandomDamage();
            cout << "Damage dealt: " << damage << " (Base: " << attacker.attackPower << " + Random: " << (damage - attacker.attackPower) << ")" << endl;            
            defender.health -= damage;
            cout << defender.name << "'s HP: " << (defender.health + damage) << " -> " << defender.health << endl;    
            if (defender.health <= 0) {
                cout << "?? " << defender.name << " has been defeated!" << endl;
                playerTeam.removeFrontline(); } 
			else {
                playerTeam.remove(defender);
                playerTeam.insert(defender); } }
        
        cout << "\n=== END OF ROUND " << round << " ===" << endl;
        displayTeams();
    }

    void declareWinner() {
        cout << "\n=== BATTLE CONCLUSION ===" << endl;
        if (playerTeam.isEmpty() && enemyTeam.isEmpty()) {
            cout << "Draw! Both teams have been eliminated!" << endl; } 
		else if (playerTeam.isEmpty()) {
            cout << "DEFEAT! The enemy team has won the battle!" << endl; } 	
		else {
            cout << "VICTORY! The heroes have won the battle!" << endl; }      
        cout << "\n=== FINAL STATISTICS ===" << endl;
        cout << "Total rounds fought: " << (round - 1) << endl;
        cout << "Surviving heroes: " << playerTeam.size() << endl;
        cout << "Surviving enemies: " << enemyTeam.size() << endl;      
        if (!playerTeam.isEmpty()) {
            cout << "Remaining heroes: ";
            playerTeam.displayTeam();
            cout << endl; }
        if (!enemyTeam.isEmpty()) {
            cout << "Remaining enemies: ";
            enemyTeam.displayTeam();
            cout << endl; }
    }
};

int main() {
    BattleQuestGame game;
    game.playGame();
    return 0;
}
