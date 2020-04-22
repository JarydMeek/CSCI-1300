#include "../Pokemon.cpp"

using namespace std;

int main () {
    //test the majority of the pokemon class
    Pokemon poke1(10, 20, 30, 40, 50, "Water", "Fire");
    cout << poke1.getHP() << endl;
    cout << poke1.getAttack() << endl;
    cout << poke1.getDefense() << endl;
    cout << poke1.getSpeed() << endl;
    cout << poke1.getType1() << endl;
    cout << poke1.getType2() << endl;


    //makes sure the levelup function respects the max for each pokemon
    Pokemon poke2(10, 9, 8, 7, 10, "Water", "Electricity");
    poke2.levelUp();
    cout << poke2.getAttack() << endl;
    cout << poke2.getDefense() << endl;
    poke2.levelUp();
    cout << poke2.getAttack() << endl;
    cout << poke2.getDefense() << endl;
}