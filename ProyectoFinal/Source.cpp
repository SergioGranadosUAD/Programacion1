#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void StartGame();
void SaveGame();
void LoadGame();
void ExitGame();

void ToLowerString(string& s);

int main() {
	bool salida = true;
	cout << "Bienvenido a este juego de aventura de texto sencillo." << endl;
	cout << "Escriba 'Iniciar' para empezar una nueva partida." << endl;
	cout << "Escriba 'Continuar' para cargar una partida anteriormente guardada." << endl;
	cout << "Escriba 'Salir' para terminar el programa." << endl;

	while (salida) {
		string seleccion = "";
		cout << "> ";
		cin >> seleccion;
		ToLowerString(seleccion);

		if (seleccion == "iniciar") {
			cout << "Iniciar" << endl;
		}
		else if (seleccion == "continuar") {
			cout << "Continuar" << endl;
		}
		else if (seleccion == "salir") {
			cout << "Se ha terminado el programa." << endl;
			salida = false;
		}
		else {
			cout << "Se introdujo una palabra no reconocida." << endl;
		}

		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}

	return 0;
}

void StartGame();
void SaveGame();
void LoadGame();
void ExitGame();

void ToLowerString(string& s) {
	for (char& c : s) {
		c = tolower(c);
	}
}
